// Canvas
export function initialize() {
console.log("init pong.js");
const canvas = document.querySelector('canvas.webgl-pong');
if (!canvas) {
    console.error('Pong canvas not found');
    return;
}

//VARIABLES SETTINGS
const scoreChoice = 2; // 1 = 3 points, 2=6p, 3=10p
const colorConfigChoice = 3; 
const levelChoice = 2; // 1=easy 3=hard
let bonus_ok = 0;


let count_victories = 0;
let count_failures = 0;

//BONUS
let sceneRotationTarget = 0; // en radians
let sceneRotationProgress = 0; // progression de l’interpolation
let rotating = false;
let flipState = false; // savoir si on est retourné ou pas
let rotation = 0



////////////////////////////////////////////////////////////////////////////
//##     ##    ###    ######## ######## ########  ####    ###    ##       //
//###   ###   ## ##      ##    ##       ##     ##  ##    ## ##   ##       //
//#### ####  ##   ##     ##    ##       ##     ##  ##   ##   ##  ##       //
//## ### ## ##     ##    ##    ######   ########   ##  ##     ## ##       //
//##     ## #########    ##    ##       ##   ##    ##  ######### ##       //
//##     ## ##     ##    ##    ##       ##    ##   ##  ##     ## ##       //
//##     ## ##     ##    ##    ######## ##     ## #### ##     ## ######## //
////////////////////////////////////////////////////////////////////////////

const default_color = new THREE.Color("#000000")

// === CONFIGURATION SELECTOR ===
// Change à 1, 2 ou 3 pour changer le style

let backgroundColor, trailColors, paddle, paddle2, cageMaterial;

if (colorConfigChoice === 1) {
    backgroundColor = "#050205";
    
    trailColors = [
        new THREE.Color("#1733ff"),
        new THREE.Color("#00fff8"),
        new THREE.Color("#9e4aff"),
        new THREE.Color("#1733ff"),
        new THREE.Color("#00fff8"),
        new THREE.Color("#9e4aff"),
        new THREE.Color("#ea00be"),
        new THREE.Color("#9e4aff"),
        new THREE.Color("#00fff8"),
    ];
    
    paddle = new THREE.MeshStandardMaterial({
        color: '#9F59ff',
        wireframe: true,
        metalness: 0.2,
    });
    
    paddle2 = new THREE.MeshStandardMaterial({
        color: '#1f50fF',
        wireframe: true,
        metalness: 0.2,
    });
    
    cageMaterial = new THREE.MeshStandardMaterial({
        color: '#00fff8',
        wireframe: true,
        metalness: 0.2,
    });
    
} else if (colorConfigChoice === 2) {
    backgroundColor = "#190cc1";
    
    trailColors = [
        new THREE.Color("#ffffff"),
        new THREE.Color("#ffffff"),
        new THREE.Color("#ff630f"),
        new THREE.Color("#ff630f"),
    ];
    
    paddle = new THREE.MeshStandardMaterial({
        color: '#06ffff',
        wireframe: true,
        metalness: 0.5,
        roughness: 1,
    });
    
    paddle2 = new THREE.MeshStandardMaterial({
        color: '#ff60ef',
        wireframe: true,
        metalness: 0.4,
        roughness: 0.5,
    });
    
    cageMaterial = new THREE.MeshStandardMaterial({
        color: '#ffffff',
        wireframe: true,
        metalness: 0.2,
    });
    
} else if (colorConfigChoice === 3) {
    backgroundColor = "#050205";
    
    trailColors = [
        new THREE.Color("#ffffff"),
        new THREE.Color("#ffffff"),
        new THREE.Color("#ffffff"),
        new THREE.Color("#ffffff"),
        new THREE.Color("#ff6620"),
        new THREE.Color("#ffbd2e"),
        new THREE.Color("#ff6620"),
        new THREE.Color("#ffffff"),
    ];
    
    paddle = new THREE.MeshStandardMaterial({
        color: '#0886FD',
        wireframe: true,
        metalness: 0.4,
        roughness: 0.5,
    });
    
    paddle2 = new THREE.MeshStandardMaterial({
        color: '#00BDBA',
        wireframe: true,
        metalness: 0.4,
        roughness: 0.5,
    });
    
    cageMaterial = new THREE.MeshStandardMaterial({
        color: '#ffffff',
        wireframe: true,
        metalness: 0.2,
    });
}


// 8888888 888b    888 8888888 888888888
//   888   88888b  888   888      888     
//   888   888  Y88888   888      888     
//   888   888   Y8888   888      888     
// 8888888 888    Y888 8888888    888    


let paddle_level;
let hauteur;

if (levelChoice === 1) {
    paddle_level = 4;
    hauteur = 8;
} else if (levelChoice === 2) {
    paddle_level = 2.5;
    hauteur = 8.5;
} else if (levelChoice === 3) {
    paddle_level = 1;
    hauteur = 9;
}




let maxScore;

if (scoreChoice === 1) {
    maxScore = 3;
} else if (scoreChoice === 2) {
    maxScore = 6;
} else if (scoreChoice === 3) {
    maxScore = 10;
}

document.getElementById("n_round").textContent = maxScore;
                                       
// Scene
const scene = new THREE.Scene()
scene.background = new THREE.Color(backgroundColor);

const sceneGroup = new THREE.Group();
scene.add(sceneGroup);


//physics 
const world = new CANNON.World()
world.gravity.set(0, 0, 0)


const normal = new THREE.MeshStandardMaterial
({
    color : '#9F59ff',
    wireframe : true,
    side :  THREE.BackSide
})

normal.receiveShadow = true; 
normal.castShadow = true; 

const normal2 = new THREE.MeshStandardMaterial(
{
    color : '#1f50fF',
    wireframe : true,
    side :  THREE.BackSide
})
normal2.receiveShadow = true; 
normal2.castShadow = true; 


const defaultMaterial = new CANNON.Material('default')
const defaultContactMaterial = new CANNON.ContactMaterial(
    defaultMaterial,
    defaultMaterial,
    {
        friction: 0,
        restitution: 1
    }
)
world.addContactMaterial(defaultContactMaterial)
world.defaultContactMaterial = defaultContactMaterial




/////////////////////////////////////////////////////
// ########   #######  ##    ## ##     ##  ######  //
// ##     ## ##     ## ###   ## ##     ## ##    ## //
// ##     ## ##     ## ####  ## ##     ## ##       //
// ########  ##     ## ## ## ## ##     ##  ######  //
// ##     ## ##     ## ##  #### ##     ##       ## //
// ##     ## ##     ## ##   ### ##     ## ##    ## //
// ########   #######  ##    ##  #######   ######  //
/////////////////////////////////////////////////////

const cubes = [];
const zMax = 11;
const yMax = 10;
let cubeReady = true;

function createRotatingWireCube(scene) {
    if (!cubeReady) return;
    cubeReady = false;

    const size = 0.7;
    const geometry = new THREE.BoxGeometry(size, size, size);
    const material = new THREE.MeshBasicMaterial({
        color: 0x44FFff,
        wireframe: true,
        transparent: true,
        opacity: 1,
    });
    const cube = new THREE.Mesh(geometry, material);

    cube.position.x = 0;
    cube.position.y = Math.random() * yMax * 2 - yMax;
    cube.position.z = Math.random() * zMax * 2 - zMax;

    // cube.scale.set(0.1, 0.1, 0.1);
    sceneGroup.add(cube);

    cubes.push({ mesh: cube, createdAt: performance.now(), exploded: false });

    const bounceStart = performance.now();
    function bounceAnimation(time) {
        const t = Math.min((time - bounceStart) / 1000, 1);
        const scale = easeOutBounce(t);
        cube.scale.set(scale, scale, scale);
        if (t < 1) requestAnimationFrame(bounceAnimation);
        else cube.scale.set(0.9, 0.9, 0.9);
    }
    requestAnimationFrame(bounceAnimation);
}


function explodeAndRemoveCube(cubeObj, scene) {
 
    if (cubeObj.exploded) return;
    cubeObj.exploded = true;

    const cube = cubeObj.mesh;
    const start = performance.now();
    const bounceDuration = 600;
    const fadeDuration = 400;
    
    const minScale = 0.6;
    const maxScale = 1.4;
    const bounces = 2;

    const startColor = new THREE.Color(0x44ffff);
    const endColor = new THREE.Color(0xff00ff);

    function bounceEase(t) {
        // Oscille entre minScale et maxScale sur t ∈ [0,1]
        const bounce = Math.sin(t * Math.PI * bounces) * (1 - t); 
        return minScale + (maxScale - minScale) * Math.abs(bounce);
    }

    function animateBounce() {
        const elapsed = performance.now() - start;
        const t = Math.min(elapsed / bounceDuration, 1);

        const scale = bounceEase(t);
        cube.scale.set(scale, scale, scale);

        // Transition de couleur
        cube.material.color = startColor.clone().lerp(endColor, t);

        if (t < 1) {
            requestAnimationFrame(animateBounce);
        } else {
            // Disparition
            const fadeStart = performance.now();
            function fadeOut() {
                const fadeElapsed = performance.now() - fadeStart;
                const f = Math.min(fadeElapsed / fadeDuration, 1);
                const fadeScale = maxScale * (1 - f);
                cube.scale.set(fadeScale, fadeScale, fadeScale);
                cube.material.opacity = 0.7 * (1 - f);

                if (f < 1) {
                    requestAnimationFrame(fadeOut);
                } else {
                    scene.remove(cube);
                    const index = cubes.indexOf(cubeObj);
                    if (index !== -1) cubes.splice(index, 1);

                    // Recréation après 10s
                    setTimeout(() => {
                        cubeReady = true;
                        createRotatingWireCube(scene);
                    }, 15000);
                }
            }
            requestAnimationFrame(fadeOut);
        }
    }
    requestAnimationFrame(animateBounce);
}

if( bonus_ok == 1)
{
    setTimeout(() => {
        createRotatingWireCube(scene);
    }, 25000);
}


function stopCubeGeneration() {
    if (cubeGeneratorInterval) {
        clearInterval(cubeGeneratorInterval);
        cubeGeneratorInterval = null;
    }
}


////////////////////////////////////////////////////////////
// ######  ########  ##     ## ######## ########  ########//
//##    ## ##     ## ##     ## ##       ##     ## ##      //
//##       ##     ## ##     ## ##       ##     ## ##      //
// ######  ########  ######### ######   ########  ######  //
//      ## ##        ##     ## ##       ##   ##   ##      //
//##    ## ##        ##     ## ##       ##    ##  ##      //
// ######  ##        ##     ## ######## ##     ## ########//
////////////////////////////////////////////////////////////


const sphereGeometry = new THREE.SphereGeometry(0.8, 15, 10);
const edges = new THREE.EdgesGeometry(sphereGeometry);
const sphereMaterial = new THREE.LineBasicMaterial({
    color: '#00fff8',  // Couleur des arêtes
    linewidth: 2       // Largeur des lignes
});
const mesh = new THREE.LineSegments(edges, sphereMaterial);
mesh.castShadow = true;


mesh.scale.set(0.5, 0.5, 0.5)

const shape = new CANNON.Sphere(0.5)
const body = new CANNON.Body(
{
    mass: 1.3,
    position: new CANNON.Vec3(22,0,0),
    shape: shape,
    material: defaultMaterial,
    velocity: new CANNON.Vec3(-5, 0, 0)
})

world.addBody(body)



mesh.position.copy(body.position)
sceneGroup.add(mesh)
sphereGeometry.attributes.position.needsUpdate = true;
const ecart = 12;

//////////////////////////////////////////////////////////////////////////
//########     ###    ########  ######## ####  ######  ##       ########//
//##     ##   ## ##   ##     ##    ##     ##  ##    ## ##       ##      //
//##     ##  ##   ##  ##     ##    ##     ##  ##       ##       ##      //
//########  ##     ## ########     ##     ##  ##       ##       ######  //
//##        ######### ##   ##      ##     ##  ##       ##       ##      //
//##        ##     ## ##    ##     ##     ##  ##    ## ##       ##      //
//##        ##     ## ##     ##    ##    ####  ######  ######## ########//
//////////////////////////////////////////////////////////////////////////

const numberOfParticles = 120000;

const speed = 0.0017; // Vitesse de déplacement des particules
const positions = new Float32Array(numberOfParticles * 3);  // Un tableau pour les positions des particules
const velocities = new Float32Array(numberOfParticles * 3);  // Un tableau pour les vitesses des particules


const colors = new Float32Array(numberOfParticles * 3);
// Ajouter des particules à la géométrie avec une direction aléatoire
for (let i = 0; i < numberOfParticles; i++) {
    if (isNaN(positions[i * 3]) || isNaN(velocities[i * 3])) {
        console.error("NaN detected in animation loop!", i);
        // Réinitialiser la particule
        positions[i * 3] = 0;
        velocities[i * 3] = minSpeed;
    }


    // Positionner aléatoirement les particules dans une zone définie 
    
    const x = (Math.random() * 2 - 1) * 4;  // Plage de x : [-spread, spread]
    const y = (Math.random() * 2 - 1) * 8 ;  // Plage de y : [-spread, spread]
    const z = (Math.random() * 2 - 1) * 10;  // Plage de z : [-spread, spread]

        // Vérifie si les positions sont des valeurs valides (pas NaN)
        if (isNaN(x) || isNaN(y) || isNaN(z)) {
            console.error("Position NaN détectée", i, x, y, z);
        }
    

    positions[i * 3] = x;
    positions[i * 3 + 1] = y;
    positions[i * 3 + 2] = z;

    //vitesse aléatoire
    velocities[i * 3] = (Math.random() - 0.5) * speed * 0.1;
    velocities[i * 3 + 1] = (Math.random() - 0.5) * speed * 0.1;
    velocities[i * 3 + 2] = (Math.random() - 0.5) * speed * 0.1;


    // Couleur initiale
   colors[i * 3] = default_color.r
   colors[i * 3 + 1] = default_color.g// Vert
   colors[i * 3 + 2] = default_color.b
   
   const friction = 0.99;
   const minSpeed = 0.00015; 
   
   velocities[i * 3] = Math.max(velocities[i * 3] * friction, minSpeed);
   velocities[i * 3 + 1] = Math.max(velocities[i * 3 + 1] * friction, minSpeed);
   velocities[i * 3 + 2] = Math.max(velocities[i * 3 + 2] * friction, minSpeed);
    //turbulences
    const turbulenceStrength = 0.02; // Force des turbulences
    velocities[i * 3] += (Math.random() - 0.5) * turbulenceStrength;
    velocities[i * 3 + 1] += (Math.random() - 0.5) * turbulenceStrength;
    velocities[i * 3 + 2] += (Math.random() - 0.5) * turbulenceStrength;
}

const smokeGeometry = new THREE.BufferGeometry();
smokeGeometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
smokeGeometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));

const particleShaderMaterial = new THREE.ShaderMaterial(
{
    uniforms: {
        uColor: { value: new THREE.Color("#3b45ff") },
        uOpacity: { value: 0.0

         },
        uMaxOpacity: { value: 0.45 },
        uInterpolationFactor: { value: 0.0 },
        uTime: { value: 0.0 },
        // Ajout des uniformes manquants
        uSpherePos: { value: new THREE.Vector3() },
        uInfluenceRadius: { value: 2 },
        uNewColor: { value: new THREE.Color("#3b45ff") },
        uDefaultColor: { value: new THREE.Color("#00fff8") }

    },
    vertexShader: `
        varying vec3 vPosition; // Déclaration varying
        void main() {
            vPosition = position; // Passe la position au fragment shader
            gl_PointSize = 0.9;
            gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
        }
    `,
    fragmentShader: `
        varying vec3 vPosition;
        uniform vec3 uSpherePos;
        uniform float uInfluenceRadius;
        uniform vec3 uNewColor;
        uniform vec3 uDefaultColor;
        uniform float uOpacity;
        uniform float uMaxOpacity; // Nouvel uniform pour l'opacité maximale

    void main() {
        // Calcul de la distance entre la particule et la sphère
        float dist = distance(vPosition, uSpherePos);
        
        // Applique un rayon d'influence doublé
        float influence = smoothstep(uInfluenceRadius * 5.0, 0.0, dist); // Rayon doublé
        
        // Interpolation de couleur (plus la particule est proche, plus elle prend la nouvelle couleur)
        vec3 finalColor = mix(uDefaultColor, uNewColor, influence);
        
        // Interpolation de l'opacité
        float finalOpacity = mix(uOpacity, uMaxOpacity, influence);
        
        // Calcul du point alpha pour la forme de la particule
        vec2 coord = gl_PointCoord * 2.0 - 1.0;
        float alpha = smoothstep(0.8, 0.0, dot(coord, coord));
        
        // Applique la couleur et l'opacité au fragment
        gl_FragColor = vec4(finalColor, pow(alpha, 0.5) * finalOpacity);
    }
    `,
    transparent: true,
    depthWrite: false,
    blending: THREE.AdditiveBlending
});




let currentColorIndex = 0; 
let interpolationFactor = 0; 
const colorChangeInterval = 6000;
// const trailColors = [
    
//   new THREE.Color("#1733ff"),
//   new THREE.Color("#00fff8"),
//   new THREE.Color("#9e4aff"),
//   new THREE.Color("#1733ff"),
//   new THREE.Color("#00fff8"),
//   new THREE.Color("#9e4aff"),
//   new THREE.Color("#ea00be"),
//   new THREE.Color("#9e4aff"),
//   new THREE.Color("#00fff8"),

// ]; 


let lastColorChangeTime = Date.now();
  
const smoke = new THREE.Points(smokeGeometry,particleShaderMaterial)
sceneGroup.add(smoke);

    smokeGeometry.attributes.position.needsUpdate = true;
    sphereGeometry.attributes.position.needsUpdate = true;
    
////////////////////////////////////////////////////////////////////////////////////////////////////
//########  ##          ###    ##    ##  ######   ########   #######  ##     ## ##    ## ######## //
//##     ## ##         ## ##    ##  ##  ##    ##  ##     ## ##     ## ##     ## ###   ## ##     ##//
//##     ## ##        ##   ##    ####   ##        ##     ## ##     ## ##     ## ####  ## ##     ##//
//########  ##       ##     ##    ##    ##   #### ########  ##     ## ##     ## ## ## ## ##     ##//
//##        ##       #########    ##    ##    ##  ##   ##   ##     ## ##     ## ##  #### ##     ##//
//##        ##       ##     ##    ##    ##    ##  ##    ##  ##     ## ##     ## ##   ### ##     ##//
//##        ######## ##     ##    ##     ######   ##     ##  #######   #######  ##    ## ######## //
////////////////////////////////////////////////////////////////////////////////////////////////////



const floorShape = new CANNON.Box(new CANNON.Vec3(4, paddle_level/2, 0.05));
const floorBody = new CANNON.Body({
    mass: 0,
    shape: floorShape,
    material: defaultMaterial,
    position: new CANNON.Vec3(0, 0, ecart) 
})
world.addBody(floorBody);
const floor = new THREE.Mesh(new THREE.BoxGeometry(3, paddle_level, 0.7, 1 ,1), paddle)
floor.position.set(0, 0, ecart);
floor.wireframe = true
floor.position.copy(floorBody.position)
scene.add(floor);



const floorShape2 = new CANNON.Box(new CANNON.Vec3(4, paddle_level/2, 0.05));
const floorBody2 = new CANNON.Body({
    mass: 0,
    shape: floorShape2,
    material: defaultMaterial,
    position: new CANNON.Vec3(0, 0, -ecart)
});
world.addBody(floorBody2);
const floor2 = new THREE.Mesh(new THREE.BoxGeometry(3, paddle_level, 0.7, 1 ,1), paddle2)
floor2.position.set(0, 0, -ecart);
floor2.position.copy(floorBody2.position)
scene.add(floor2);





const planeMaterial = new THREE.MeshBasicMaterial({
    color: 0x00ff00,
    wireframe: true,
    transparent: true,
    opacity: 0,
});

const cage = new THREE.Mesh(
    new THREE.BoxGeometry(5, 20, 24 , 1, 1, 2), planeMaterial)
    sceneGroup.add(cage);
    



const planeGeometry = new THREE.PlaneGeometry(5, 24, 1, 2);
const plane = new THREE.Mesh(planeGeometry, cageMaterial);
plane.rotation.x = -Math.PI / 2;
plane.position.set(0, 10, 0);
scene.add(plane);

const planeGeometry2 = new THREE.PlaneGeometry(5, 24, 1,2);
const plane2 = new THREE.Mesh(planeGeometry2, cageMaterial);
plane2.rotation.x = -Math.PI / 2;
plane2.position.set(0, -10, 0);
scene.add(plane2);

                                /////////////// CAGE //////////////

const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () =>
{
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

//////////////////////////////////////////////////////////////////////////////
// ######   #######  ##    ## ######## ########   #######  ##        ###### //
//##    ## ##     ## ###   ##    ##    ##     ## ##     ## ##       ##    ##//
//##       ##     ## ####  ##    ##    ##     ## ##     ## ##       ##      //
//##       ##     ## ## ## ##    ##    ########  ##     ## ##        ###### //
//##       ##     ## ##  ####    ##    ##   ##   ##     ## ##             ##//
//##    ## ##     ## ##   ###    ##    ##    ##  ##     ## ##       ##    ##//
// ######   #######  ##    ##    ##    ##     ##  #######  ########  ###### //
//////////////////////////////////////////////////////////////////////////////
// Configuration des axes :
// - Z : avant/arrière (direction de jeu principale)
// - Y : haut/bas (mouvement des paddles)
// - X : non utilisé pour le gameplay (profondeur visuelle)


const keys = {};
window.addEventListener("keydown", (e) => keys[e.key.toLowerCase()] = true);
window.addEventListener("keyup", (e) => keys[e.key.toLowerCase()] = false);

// Mouvement des paddles (sur l'axe Y)
const updateBoxes = () => {
    const paddleSpeed = 0.35;
   

    // Paddle gauche (touches E/D)
    if ((keys["e"]) && floorBody.position.y < hauteur) {
        floorBody.position.y += paddleSpeed;
        floor.position.y = floorBody.position.y;
    }
    if ((keys["d"]) && floorBody.position.y > -hauteur) {
        floorBody.position.y -= paddleSpeed;
        floor.position.y = floorBody.position.y;
    }

    // Paddle droit (touches O/K)
    if ((keys["o"]) && floorBody2.position.y < hauteur) {
        floorBody2.position.y += paddleSpeed;
        floor2.position.y = floorBody2.position.y;
    }
    if ((keys["k"]) && floorBody2.position.y > -hauteur) {
        floorBody2.position.y -= paddleSpeed;
        floor2.position.y = floorBody2.position.y;
    }
}




body.velocity.set(0, 0, 20); // Déplacement initial vers l'avant (Z positif)
let gameState = 'playing'; // 'playing', 'scored', 'victory'
let resetTimer = 0;
const epsilon = 2 //tolerance pour nombre fllottant
let count = 0
let paddleHeight = paddle_level/2; 


function updateText() {
        document.getElementById("scorePlayer1").textContent = count_1;
        document.getElementById("scorePlayer2").textContent = count_2;
};

function checkCollision_paddle(ball, paddle) {

if (Math.abs(ball.position.z - paddle.position.z) < epsilon)  // balle au niveau de raquette pour collision
{ 
        if (ball.position.y >= paddle.position.y - paddleHeight && ball.position.y <= paddle.position.y + paddleHeight) {
            ball.velocity.z *= -1;  // Réverser la direction sur Z lors du rebond
        }
    if ((ball.position.y > paddle.position.y + paddleHeight) || ( ball.position.y < paddle.position.y - paddleHeight)) 
            return
    if (body.position.y < 10 || body.position.y > -10)
    { 
        if ((ball.position.y < paddle.position.y + paddleHeight) && ( ball.position.y > paddle.position.y - paddleHeight))  
        {
            ball.velocity.y *= -1;
            let impact = (ball.position.y -  paddle.position.y) / (paddleHeight / 2); //entre -1 et 1
            ball.velocity.y = impact * 7; //angle de rebond
        if (ball.position.z > paddle.position.z)
            {
                ball.velocity.z = Math.abs(ball.velocity.z); // Ball rebounding in positive Z direction
            } 
        else 
            {
                ball.velocity.z = -Math.abs(ball.velocity.z); // Ball rebounding in negative Z direction
            }
        }
    }
    
}
}

//////////////////////////////////////////////////
// ######   ######   #######  ########  ########//
//##    ## ##    ## ##     ## ##     ## ##      //
//##       ##       ##     ## ##     ## ##      //
// ######  ##       ##     ## ########  ######  //
//      ## ##       ##     ## ##   ##   ##      //
//##    ## ##    ## ##     ## ##    ##  ##      //
// ######   ######   #######  ##     ## ########//
//////////////////////////////////////////////////


function startGame() {
    // Load player names from session storage if available
    const player1Name = sessionStorage.getItem('player1Name');
    const player2Name = sessionStorage.getItem('player2Name');

    if (player1Name && player2Name) 
    {
        const name1Element = document.querySelector('.name1');
        const name2Element = document.querySelector('.name2');
        if (name1Element && name2Element) 
        {
            name1Element.textContent = player1Name;
            name2Element.textContent = player2Name;
        }
    }
    body.position.set(0, 0, 0);
    gameState = 'playing';
    const direction = Math.random() > 0.5 ? 1 : -1;
    body.velocity.set(0, 2 * direction, 20 * direction);
}

let count_1 = 0;
let count_2 = 0;
body.position.set(22,0,0);
body.velocity.set(-5, 0, 0);

let countdownInterval;
const countdownElement = document.getElementById('countdown');
const countdownNumber = countdownElement.querySelector('.countdown-number');

function updateText() {
        document.getElementById("scorePlayer1").textContent = count_1;
        document.getElementById("scorePlayer2").textContent = count_2;
        document.getElementById("victories").textContent = count_victories;
        document.getElementById("failures").textContent = count_failures;

}






function startCountdown() {
    const countdownSteps = [
        gettext("ARE YOU<br>READY?"),
        3,
        2,
        1,
        gettext("GO !")];
    let stepIndex = 0;
  
    // S'assurer que l'élément est visible au début
    countdownElement.style.display = 'block'; // ou 'flex' selon votre layout
    countdownNumber.innerHTML = countdownSteps[stepIndex];
    stepIndex++;
  
    countdownInterval = setInterval(() => {
      if (stepIndex < countdownSteps.length) {
        countdownNumber.innerHTML = countdownSteps[stepIndex];
        stepIndex++;
      } else {
        clearInterval(countdownInterval);
        setTimeout(() => {
          countdownElement.style.display = 'none'; // Cache l'élément
         
          startGame();
        }, 300);
      }
    }, 1000);
  }

function updateBall() 
{
    if(body.position.x <= 5.5 && body.velocity.x < 0 &&  gameState !== 'victory')
    {
        body.position.set(5.5, 0, 0);
        body.velocity.set(0, 0, 0);
        setTimeout(() => {
            resetAfterGoal()
        }, 1000);
    }
    checkCollision_paddle (body, floor); // Raquette gauche
    checkCollision_paddle(body, floor2); // Raquette droitea
    if (body.position.y >= 10) { 
        body.velocity.y *= -1;
        body.position.y = 9.9; 
    } 
    else if (body.position.y <= -10) { 
        body.velocity.y *= -1;
        body.position.y = -9.9; // Évite de rester pile à -10
    }
    if (body.position.z < -30)
    {   
        count_1++
        updateText()
        if (count_1 == maxScore - 1) 
            document.getElementById("scorePlayer1").classList.add("blink-bounce");
        if(count_1 == maxScore ) {
            updateText()
            count_victories++;
            updateText()
            handleVictory();
        }
        else
            resetAfterGoal()
    }
    if (body.position.z > 30 ){   
        count_2++
        updateText()
        if (count_2 == maxScore - 1) 
            document.getElementById("scorePlayer2").classList.add("blink-bounce2");
  
        if(count_2 == maxScore )
        {
            updateText()
            count_failures++;
            updateText()
            handleVictory()
        }
        else
            resetAfterGoal()
     }
}

function resetAfterGoal() {
    console.log(direction)


    gameState = 'scored';
    body.position.set(5.5, 0, 0);
    body.velocity.set(0, 0, 0);

    startCountdown();
}


function startGame() {
    // Load player names from session storage if available
    const player1Name = sessionStorage.getItem('player1Name');
    const player2Name = sessionStorage.getItem('player2Name');

    if (player1Name && player2Name) 
    {
        const name1Element = document.querySelector('.name1');
        const name2Element = document.querySelector('.name2');
        if (name1Element && name2Element) {
            name1Element.textContent = player1Name;
            name2Element.textContent = player2Name;
        }
    }
    body.position.set(0, 0, 0);
    gameState = 'playing';
    const direction = Math.random() > 0.5 ? 1 : -1;
    body.velocity.set(0, 2 * direction, 20 * direction);
}

function handleVictory() {
    // Arrête les animations de score
    let winnerName;
    
    if(count_2 == maxScore) {
        document.getElementById("scorePlayer1").classList.remove("blink-bounce");
        // Player 2 won
        winnerName = document.querySelector('.name2').textContent;
    } else {
        document.getElementById("scorePlayer2").classList.remove("blink-bounce2");
        // Player 1 won
        winnerName = document.querySelector('.name1').textContent;
    }

    // Dispatch matchEnd event with winner info
    document.dispatchEvent(new CustomEvent('matchEnd', {
        detail: {
            winner: winnerName
        }
    }));

    gameState = 'victory';
    body.position.set(-65, 0, 0);
    body.velocity.set(22, 0, 0);

    // Affiche "VICTOIRE"
    countdownElement.style.display = 'block';
    countdownNumber.textContent = "VICTOIRE";

    // Check if we're in tournament mode
    const currentMatch = sessionStorage.getItem('currentMatch');
    
    setTimeout(() => {
        countdownElement.style.display = 'none';
        
        if (!currentMatch) {
            // Only show "PRESS ENTER FOR NEW GAME" if not in tournament mode
            setTimeout(() => {
                countdownElement.style.display = 'block';
                countdownNumber.textContent = gettext("PRESS ENTER FOR NEW GAME");
            }, 800);
        } else {
            // In tournament mode, automatically reset the game
            resetGame();
        }
    }, 3000);
}


// TOUT WHIPPIN
// Et ailleurs dans votre code, gérez l'appui sur ENTER :
document.addEventListener('keydown', (e) => {
    if(e.key === 'Enter' && gameState === 'victory') {
        resetGame();
        countdownElement.style.display = 'none'; // Cache le message
    }
});

function resetGame() 
{
    document.getElementById("scorePlayer1").classList.remove("blink-bounce");
    document.getElementById("scorePlayer2").classList.remove("blink-bounce2");
    count_1 = 0;
    count_2 = 0;
    updateText();
    body.position.set(22, 0, 0);
    body.velocity.set(-5, 0, 0);
    gameState = 'waiting';
    
    // Check if we're in tournament mode
    const currentMatch = sessionStorage.getItem('currentMatch');
    if (currentMatch) {
        // Return to tournament section
        const tournamentSection = document.querySelector('.tournois-section');
        if (tournamentSection) {
            tournamentSection.scrollIntoView({ behavior: 'smooth' });
            
            // Start countdown for next match after a short delay
            setTimeout(() => {
                body.position.set(5.5, 0, 0);
                body.velocity.set(0, 0, 0);
                gameState = 'playing';
                startCountdown();
            }, 2000);
        }
    }
}

// TOUT WHIPPIN 2
//touche entree bug en entree de jeu ? pas de reinit de gamestat?
 //gameState === 'victory?????? confus ??
document.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' && gameState === 'waiting')
    {
        body.position.set(22, 0, 0);
        body.velocity.set(-5, 0, 0);
        countdownElement.classList.remove('show');

        function checkPosition() {
            if (body.position.x <= 5.5) { 
                body.position.set(5.5, 0, 0);
                body.velocity.set(0, 0, 0);
                gameState = 'playing';
                startCountdown();
            } else {
                requestAnimationFrame(checkPosition);
            }
        }
        checkPosition();
    }
});

function report(){
	if (score1 >= winningScore || score2 >= winningScore) {
		gameOver = true;

		let playerScore, opponentScore, result, opponentAlias;

		if (player1name === currentUserName) {
			playerScore = score1;
			opponentScore = score2;
			opponentAlias = player2name;
			result = score1 > score2 ? "win" : "loss";
		} else if (player2name === currentUserName) {
			playerScore = score2;
			opponentScore = score1;
			opponentAlias = player1name;
			result = score2 > score1 ? "win" : "loss";
		} else {
			console.warn("Current user not in the match");
		}

		if (result) {
			fetch(reportMatchUrl, {
				method: "POST",
				headers: {
					"Content-Type": "application/json",
					"X-CSRFToken": getCookie("csrftoken"),
				},
				body: JSON.stringify({
					result: result,
					player_score: playerScore,
					opponent_score: opponentScore,
					opponent_alias: opponentAlias
				}),
			});
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
//########  ######## ########  ##     ## ##        ######  ####  #######  ##    ##//
//##     ## ##       ##     ## ##     ## ##       ##    ##  ##  ##     ## ###   ##//
//##     ## ##       ##     ## ##     ## ##       ##        ##  ##     ## ####  ##//
//########  ######   ########  ##     ## ##        ######   ##  ##     ## ## ## ##//
//##   ##   ##       ##        ##     ## ##             ##  ##  ##     ## ##  ####//
//##    ##  ##       ##        ##     ## ##       ##    ##  ##  ##     ## ##   ###//
//##     ## ######## ##         #######  ########  ######  ####  #######  ##    ##//
////////////////////////////////////////////////////////////////////////////////////
function applyRepulsionFromFloors() {
    const repulsionStrength = 2.5; // Force de répulsion
    const repulsionDistance = 1.5; // Distance à laquelle la répulsion commence

    for (let i = 0; i < numberOfParticles; i++) {
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        if (isNaN(x) || isNaN(y) || isNaN(z)) {
            x = y = z = 0; // Réinitialiser si NaN
        }
        if (isNaN(vx) || isNaN(vy) || isNaN(vz)) {
            vx = vy = vz = 0; // Réinitialiser si NaN
        }

        const paddles = [floorBody.position, floorBody2.position];

        paddles.forEach(paddlePos => {
            let dx = x - paddlePos.x;
            let dy = y - paddlePos.y;
            let dz = z - paddlePos.z;
            let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

            if (distance > 0 && distance < repulsionDistance) {
                // Calculer la force de répulsion
                let repulsionForce = repulsionStrength / (distance * distance);
                vx += (dx / distance) * repulsionForce;
                vy += (dy / distance) * repulsionForce;
                vz += (dz / distance) * repulsionForce;
            }
        });

        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }
    smokeGeometry.attributes.position.needsUpdate = true;
}

function applyReturnForceToPaddles() {
    const returnStrengthX = 0.005; // Intensité du retour en X
    const returnStrengthY = 0.0; // Intensité du retour en Y
    const returnStrengthZ = 0.0; // Intensité du retour en Z
    const maxDistance = 2.0; // Distance maximale avant que la force commence à agir

    for (let i = 0; i < numberOfParticles; i++) {
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        // Vérification pour éviter les NaN
        if (isNaN(x) || isNaN(y) || isNaN(z)) {
            x = y = z = 0; // Réinitialiser si NaN
        }
        if (isNaN(vx) || isNaN(vy) || isNaN(vz)) {
            vx = vy = vz = 0; // Réinitialiser si NaN
        }

        // Tableau des positions des paddles
        const paddles = [floorBody.position, floorBody2.position];

        paddles.forEach(paddlePos => {
            // Calculer les distances de la particule au paddle sur chaque axe
            let dx = x - paddlePos.x;
            let dy = y - paddlePos.y;
            let dz = z - paddlePos.z;

            // Vérifier que la distance est suffisante avant de diviser
            if (Math.abs(dx) > maxDistance) {
                vx -= (dx / Math.abs(dx)) * returnStrengthX; // Ramène vers le paddle sur X
            }
            if (Math.abs(dy) > maxDistance) {
                vy -= (dy / Math.abs(dy)) * returnStrengthY; // Ramène vers le paddle sur Y
            }
            if (Math.abs(dz) > maxDistance) {
                vz -= (dz / Math.abs(dz)) * returnStrengthZ; // Ramène vers le paddle sur Z
            }
        });

        // Mettre à jour les vitesses dans le tableau
        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }
    // Marquer la géométrie comme mise à jour une seule fois après la boucle
    smokeGeometry.attributes.position.needsUpdate = true;
}



////////////////////////////////////////////////////////////////////////////////////////////////
//########  #######  ########   ######  ########    ######## #### ######## ##       ########  //
//##       ##     ## ##     ## ##    ## ##          ##        ##  ##       ##       ##     ## //
//##       ##     ## ##     ## ##       ##          ##        ##  ##       ##       ##     ## //
//######   ##     ## ########  ##       ######      ######    ##  ######   ##       ##     ## //
//##       ##     ## ##   ##   ##       ##          ##        ##  ##       ##       ##     ## //
//##       ##     ## ##    ##  ##    ## ##          ##        ##  ##       ##       ##     ## //
//##        #######  ##     ##  ######  ########    ##       #### ######## ######## ########  //
////////////////////////////////////////////////////////////////////////////////////////////////

// let interpolationFactor = 0; // Facteur d'interpolation pour les particules
// let lastColorChangeTime = Date.now(); // Temps du dernier changement de couleur
// const colorChangeInterval = 7000; // Intervalle de changement de couleur en millisecondes
let lastFrameTime = Date.now();

let sphereColorIndex = 0; // Index de couleur pour la sphère
let sphereInterpolationFactor = 0; // Facteur d'interpolation pour la sphère
function isNaNValue(value) {
    return value !== value; // NaN is the only value in JavaScript that is not equal to itself
}


function moveSmokeAvoidObject() 
{
    // console.time('moveSmokeAvoidObject'); 

    const now = Date.now();
    const deltaTime2 = (now - lastFrameTime) / 1000; // en secondes
    lastFrameTime = now;

    interpolationFactor += deltaTime2 * 0.2; // 0.2 = vitesse de transition
    if (interpolationFactor > 1) interpolationFactor = 1;

        
    const bodyPosition = body.position; // Position de la balle
    const influenceRadius = 3; // Rayon d'influence de la balle
    const attractionStrength = 0.027; // Force d'attraction
    const maxDistance = 13.5; // Distance maximale de déplacement des particules
    const airResistance = 0.99; // Résistance de l'air
    const dragCoefficient = 0.6; // Coefficient de traînée
    const spread = 10; // Limite de la zone de déplacement des particules
    const reboundFactor = 0.9; // Coefficient de rebond partiel
    const dispersionStrength = 0.0032; // Force de dispersion des particules

    // smokeGeometry.attributes.position.needsUpdate = true;

    const currentTime = Date.now();

    if (currentTime - lastColorChangeTime >= colorChangeInterval) {
        //couleur suivante
        currentColorIndex = (currentColorIndex + 1) % trailColors.length;
        lastColorChangeTime = currentTime; // Mettre à jour le temps du dernier changement
        interpolationFactor = 0; // Réinitialiser le facteur d'interpolation
    }

    // interpolation couleurs
    const currentColor = trailColors[currentColorIndex];
    const nextColor = trailColors[(currentColorIndex + 1) % trailColors.length];
    const interpolatedColor = currentColor.clone().lerp(nextColor, interpolationFactor);

    particleShaderMaterial.uniforms.uSpherePos.value.copy(body.position);
    particleShaderMaterial.uniforms.uNewColor.value = interpolatedColor;
    particleShaderMaterial.uniforms.uNewColor.value = interpolatedColor;

    particleShaderMaterial.uniforms.uInfluenceRadius.value = influenceRadius;
    // particleShaderMaterial.uniforms.uMaxOpacity.value = 0.5

    // mise a jour shader
    // particleShaderMaterial.uniforms.uColor.value = interpolatedColor;
    cageMaterial.color.lerp(interpolatedColor, 0.05); // 0.05 = vitesse de transition

    // Mettre à jour le facteur d'interpolation
    interpolationFactor += 0.001; 
    if (interpolationFactor > 1) interpolationFactor = 1;

    const sphereCurrentColor = trailColors[sphereColorIndex];
    const sphereNextColor = trailColors[(sphereColorIndex + 1) % trailColors.length];
    const sphereInterpolatedColor = sphereCurrentColor.clone().lerp(sphereNextColor, sphereInterpolationFactor);


    sphereMaterial.color.lerp(interpolatedColor, 0.05); // 0.05 = vitesse de transition
    let influenceDetected = false;



    for (let i = 0; i < numberOfParticles; i++) 
    {
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        if (isNaN(x) || isNaN(y) || isNaN(z)) {
            // console.warn(`NaN corrigé dans particule ${i}`);
            positions[i * 3] = (Math.random() - 0.5) * 4;
            positions[i * 3 + 1] = (Math.random() - 0.5) * 8;
            positions[i * 3 + 2] = (Math.random() - 0.5) * 10;
            velocities[i * 3] = (Math.random() - 0.5)  * 0.1;
            velocities[i * 3 + 1] = (Math.random() - 0.5)  * 0.1;
            velocities[i * 3 + 2] = (Math.random() - 0.5)  * 0.1;
            continue;
        }

        let dx = bodyPosition.x - x;
        let dy = bodyPosition.y - y;
        let dz = bodyPosition.z - z;
        let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

        if (distance < influenceRadius) {
            influenceDetected = true; 
            const attractionForce = (influenceRadius - distance) / influenceRadius;
            vx += (dx / distance) * attractionForce * attractionStrength * 6;
            vy += (dy / distance) * attractionForce * attractionStrength;
            vz += (dz / distance) * attractionForce * attractionStrength;
        }

        // Appliquer la résistance de l'air en fonction de la vitesse
        let speed = Math.sqrt(vx * vx + vy * vy + vz * vz);
        let drag = dragCoefficient * speed * speed; 
        let dragX = (vx / speed) * drag;
        let dragY = (vy / speed) * drag;
        let dragZ = (vz / speed) * drag;

        vx -= dragX;
        vy -= dragY;
        vz -= dragZ;

        vx *= airResistance;
        vy *= airResistance;
        vz *= airResistance;

        // Appliquer la force de dispersion aux particules de la traînée
        if (distance > influenceRadius && distance < maxDistance) 
        {
            vx += (Math.random() - 0.5) * dispersionStrength;
            vy += (Math.random() - 0.5) * dispersionStrength;
        }

        // Déplacer la particule avec la vitesse mise à jour
        x += vx;
        y += vy;
        z += vz;

        // Limiter la distance de déplacement des particules
        let distanceFromOrigin = Math.sqrt(x * x + y * y + z * z);
        if (distanceFromOrigin > maxDistance) 
        {
            let scale = maxDistance / distanceFromOrigin;
            x *= scale;
            y *= scale;
            z *= scale;
        }

        // Limiter les particules à l'intérieur de la zone fluide avec un rebond partiel
        if (x < -spread || x > spread) vx *= -reboundFactor;
        if (y < -spread || y > spread) vy *= -reboundFactor;
        if (z < -spread || z > spread) vz *= -reboundFactor;

        // Réaffecter les nouvelles positions et vitesses
        positions[i * 3] = x;
        positions[i * 3 + 1] = y;
        positions[i * 3 + 2] = z;
        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }

    smokeGeometry.attributes.position.needsUpdate = true;
    smokeGeometry.attributes.color.needsUpdate = true;

    // console.timeEnd('moveSmokeAvoidObject');
}

//////////////////////////////////////////////
//##       ####  ######   ##     ## ########//
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##        ##     ##    ##   //
//##        ##  ##   #### #########    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//######## ####  ######   ##     ##    ##   //
//////////////////////////////////////////////

const ambientLight = new THREE.AmbientLight(0xffDDff, 2.1)
sceneGroup.add(ambientLight)

const directionalLight = new THREE.DirectionalLight(0xffAAAA, 0.6)
directionalLight.castShadow = true
directionalLight.shadow.mapSize.set(1024, 1024)
directionalLight.shadow.camera.far = 15
directionalLight.shadow.camera.left = - 7
directionalLight.shadow.camera.top = 7
directionalLight.shadow.camera.right = 7
directionalLight.shadow.camera.bottom = - 7
directionalLight.position.set(5, 5, 5)
sceneGroup.add(directionalLight)

// //////////////////////////////////////////////////////////////
// // ######     ###    ##     ## ######## ########     ###    //
// //##    ##   ## ##   ###   ### ##       ##     ##   ## ##   //
// //##        ##   ##  #### #### ##       ##     ##  ##   ##  //
// //##       ##     ## ## ### ## ######   ########  ##     ## //
// //##       ######### ##     ## ##       ##   ##   ######### //
// //##    ## ##     ## ##     ## ##       ##    ##  ##     ## //
// // ######  ##     ## ##     ## ######## ##     ## ##     ## //
// //////////////////////////////////////////////////////////////

// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.set( 20, 0, 0)


sceneGroup.add(camera)


// Controls
const controls = new THREE.OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))


// ////////////////////////////////////
// //######## ####  ######  ##    ## //
// //   ##     ##  ##    ## ##   ##  //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##       #####    //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##    ## ##   ##  //
// //   ##    ####  ######  ##    ## //
// ////////////////////////////////////

// Animation pour faire tourner la caméra autour du cube
const radius = 20; // Distance entre la caméra et l'objet
const heightAmplitude = 15; // Hauteur maximale de la caméra



let lastTime = Date.now();
function measureFPS() {
    const now = Date.now();
    const delta = now - lastTime;
    const fps = 1000 / delta;
    // console.log(`FPS: ${fps.toFixed(2)}`);
    lastTime = now;
}


const clock = new THREE.Clock();
let oldElapsedTime = 0;
let isPaused = false;
let angle = 0;
let isCameraMoving = false;
let animation2Done = false;

let direction = 1; // 1 = sens normal, -1 = sens inverse
const stopAngle = Math.PI; // demi-tour
// let animation2Done = false;

function tick() {
    if (!isVisible || isPaused) return;
    const elapsedTime = clock.getElapsedTime();
    const deltaTime = elapsedTime - oldElapsedTime;
    oldElapsedTime = elapsedTime;

    camera.lookAt(scene.position);

    if (!isCameraMoving) {
        // Animation flottante pendant que la caméra n'est pas en mouvement de rotation
        mesh.rotation.x += 0.002;
        mesh.rotation.z += 0.01;
        camera.position.z = Math.sin(elapsedTime) * 0.55;
        camera.position.y = Math.cos(elapsedTime) * 0.35;
        camera.lookAt(0, 0, 0);
    }

    controls.update();
    updateBoxes();
    updateBall();
    moveSmokeAvoidObject();
    applyRepulsionFromFloors();
    applyReturnForceToPaddles();
    
    world.step(1 / 60, deltaTime, 3);

    mesh.position.copy(body.position);
    floor.position.copy(floorBody.position);
    floor2.position.copy(floorBody2.position);

    const now = performance.now();
    
    for (const cubeData of cubes) {
        const cube = cubeData.mesh;
        if (!cubeData.exploded) {
            cube.rotation.x += 0.01;
            cube.rotation.y += 0.01;
            cube.rotation.z += 0.01;
            const yClose = Math.abs(cube.position.y - mesh.position.y) < 1;
            const zClose = Math.abs(cube.position.z - mesh.position.z) < 1;
            if (yClose && zClose) {
                explodeAndRemoveCube(cubeData, scene);
                angle = 0;
            
                // Bascule entre 0 et PI (180°)
                flipState = !flipState;
                sceneRotationTarget = flipState ? Math.PI : 0;
                sceneRotationProgress = 0;
                rotating = true;
                rotation++;
            
                console.log("prout")
                console.log(rotation)
                
            }
            
        }
    }


    if(gameState === 'scored' ||  gameState === 'victory'){
        if (rotation % 2 == 1) {
            rotating = true;  // Si rotation est impair
            flipState = !flipState;
            sceneRotationTarget = flipState ? Math.PI : 0;
            sceneRotationProgress = 0;
            rotating = true;
            rotation++;
    }
    }


    if (rotating) {
        if (rotation % 2 == 1) 
             sceneRotationProgress += 0.02;
        else
           sceneRotationProgress += 0.001;
        const t = Math.min(sceneRotationProgress, 1);
        sceneGroup.rotation.y = THREE.MathUtils.lerp(sceneGroup.rotation.y, sceneRotationTarget, t);
    
        if (t >= 1) {
            rotating = false;
        }
    }
    
    
    

    // for (const cubeData of cubes) {
    //     const cube = cubeData.mesh;
    //     if (!cubeData.exploded) {
    //         cube.rotation.x += 0.01;
    //         cube.rotation.y += 0.01;
    //         cube.rotation.z += 0.01;
    //         const yClose = Math.abs(cube.position.y - mesh.position.y) < 1;
    //         const zClose = Math.abs(cube.position.z - mesh.position.z) < 1;
    //         if (yClose && zClose) {
    //             explodeAndRemoveCube(cubeData, scene);
    //             angle = 0;
    //             // if(direction === 0)
    //             //     direction = 1;
    //             // else 
    //             // direction = 0;
    //             // isCameraMoving = true;
    //         }
    //     }
    // }
    // if (!isCameraMoving) {
    //     // Animation flottante pendant que la caméra n'est pas en mouvement de rotation
    //     mesh.rotation.x += 0.002;
    //     mesh.rotation.z += 0.01;
    //     camera.position.z = Math.sin(elapsedTime) * 0.55;
    //     camera.position.y = Math.cos(elapsedTime) * 0.35;
    //     camera.lookAt(0, 0, 0);
    // }

    
    // if (isCameraMoving) {
    //     if (direction === 1) {
    //         if (angle < stopAngle) {
    //             // Distance restante avant la fin
    //             const remaining = stopAngle - angle;
    
    //             // Diminuer la vitesse quand on approche de la fin
    //             const speed = 0.02 * Math.min(1, remaining / 0.5);
    //             angle += speed;
    
    //             camera.position.x = radius * Math.cos(angle);
    //             camera.position.z = radius * Math.sin(angle);
    //             camera.position.y = heightAmplitude * Math.sin(angle);
    //             camera.lookAt(0, 0, 0);
    //         } else if (!animation2Done) {
    //             animation2Done = true;
    
    //             setTimeout(() => {
    //                 isCameraMoving = false;
    //                 animation2Done = false;
    //                 direction = -1;
    //             }, 500);
    //         }
    //     } else if (direction === -1) {
    //         if (angle > -stopAngle) {
    //             // Distance restante avant la fin
    //             const remaining = stopAngle - Math.abs(angle);
    
    //             // Diminuer la vitesse quand on approche de la fin
    //             const speed = 0.02 * Math.min(1, remaining / 0.5);
    //             angle -= speed;
    
    //             camera.position.x = radius * Math.cos(angle);
    //             camera.position.z = radius * Math.sin(angle);
    //             camera.position.y = heightAmplitude * Math.sin(angle);
    //             camera.lookAt(0, 0, 0);
    //         } else if (!animation2Done) {
    //             animation2Done = true;
    
    //             setTimeout(() => {
    //                 isCameraMoving = false;
    //                 animation2Done = false;
    //                 direction = 1;
    //             }, 500);
    //         }
    //     }
    
    
    // }
    


    
    renderer.render(scene, camera);
    animationFrameId = requestAnimationFrame(tick);
    measureFPS();
}

function easeOutBounce(x) {
    const n1 = 7.5625;
    const d1 = 2.75;
    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
}


function resetParticles() {
    // Réinitialisation des positions et vitesses
    for (let i = 0; i < numberOfParticles; i++) {
        // Nouvelles positions aléatoires
        positions[i * 3] = (Math.random() * 2 - 1) * 4;
        positions[i * 3 + 1] = (Math.random() * 2 - 1) * 8;
        positions[i * 3 + 2] = (Math.random() * 2 - 1) * 10;

        // Nouvelles vitesses aléatoires
        velocities[i * 3] = (Math.random() - 0.5) * speed * 0.1;
        velocities[i * 3 + 1] = (Math.random() - 0.5) * speed * 0.1;
        velocities[i * 3 + 2] = (Math.random() - 0.5) * speed * 0.1;

        // Réinitialisation de la couleur
        colors[i * 3] = default_color.r;
        colors[i * 3 + 1] = default_color.g;
        colors[i * 3 + 2] = default_color.b;
    }

    // Mise à jour de la géométrie
    smokeGeometry.attributes.position.needsUpdate = true;
    smokeGeometry.attributes.color.needsUpdate = true;
    
    // Réinitialisation des paramètres matériaux
    particleShaderMaterial.uniforms.uInterpolationFactor.value = 0.0;
    particleShaderMaterial.uniforms.uTime.value = 0.0;

}


window.addEventListener('keydown', (event) => {
    if (event.code === 'Space') {
        togglePause();
    }
}); 

let isVisible = false;

 
function togglePause() {
    if (isPaused) {
        isPaused = false;
        if (isVisible) {
            oldElapsedTime = clock.getElapsedTime();
            tick();
        }
    } else {
        isPaused = true;
        if (animationFrameId) {
            cancelAnimationFrame(animationFrameId);
            animationFrameId = null;
        }
    }
    smokeGeometry.attributes.position.needsUpdate = true;
}
    
tick();  // Lancer la boucle de jeu dès le début

// Add intersection observer to handle pong section visibility
const pongSection = document.querySelector('.pong-section');
let animationFrameId = null;

const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
        isVisible = entry.isIntersecting;
        pongSection.classList.toggle('visible', isVisible);
        
        if (isVisible) {
            if (!animationFrameId) {
                isPaused = false;
                oldElapsedTime = clock.getElapsedTime();
                tick(); // Start animation when section is visible
            }
        } else {
            if (animationFrameId) {
                isPaused= true;
                cancelAnimationFrame(animationFrameId); // Stop animation when section is not visible
                animationFrameId = null;
            }
        }
    });
}, { threshold: 0.5 }); // Trigger when 50% of the section is visible

observer.observe(pongSection);

// Add event listener for startGame
document.addEventListener('startGame', function() {
    // updateBall();
});

// Return cleanup function
return function cleanup() {
    observer.disconnect(); // Clean up the observer
    clearInterval(countdownInterval);
    console.log("cleanup pong.js");
    
    if (animationFrameId) {
        cancelAnimationFrame(animationFrameId);
    }
    
    // Clean up THREE.js resources
    if (renderer) {
        renderer.dispose();
        if (renderer.domElement) {
            renderer.domElement.remove();
        }
    }
    
    // Clean up geometries and materials
    if (scene) {
        scene.children.forEach(child => {
            if (child.geometry) {
                child.geometry.dispose();
            }
            if (child.material) {
                if (Array.isArray(child.material)) {
                    child.material.forEach(material => material.dispose());
                } else {
                    child.material.dispose();
                }
            }
        });
    }
}
}

window.currentModuleCleanup = initialize();
