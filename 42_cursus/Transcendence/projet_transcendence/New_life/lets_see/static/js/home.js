export function initialize() {
//////////////////////////////////////////////////////////////////////////////////////////////
//##        #######     ###    ########  ######## ########     ########     ###    ######## //
//##       ##     ##   ## ##   ##     ## ##       ##     ##    ##     ##   ## ##   ##     ##//
//##       ##     ##  ##   ##  ##     ## ##       ##     ##    ##     ##  ##   ##  ##     ##//
//##       ##     ## ##     ## ##     ## ######   ########     ########  ##     ## ######## //
//##       ##     ## ######### ##     ## ##       ##   ##      ##     ## ######### ##   ##  //
//##       ##     ## ##     ## ##     ## ##       ##    ##     ##     ## ##     ## ##    ## //
//########  #######  ##     ## ########  ######## ##     ##    ########  ##     ## ##     ##//
//////////////////////////////////////////////////////////////////////////////////////////////

console.log("init home.js");
window.addEventListener('DOMContentLoaded', () => {
    const loader = document.getElementById('js-loader');
    const bar = document.querySelector('.loader-bar');
    
    if (!loader || !bar) return;
    bar.style.transform = 'scaleX(1)';
    setTimeout(() => {
    bar.classList.add('loader-bar--retract');
    bar.style.transform = 'scaleX(0)';
    
    setTimeout(() => {
        loader.classList.add('loader-overlay--fade');
        
        // Suppression après 0.7s
        setTimeout(() => {
        loader.remove();
        }, 900);
    }, 600);
    }, 800);
});

const ringPointTexture = new THREE.TextureLoader().load('/static/particles/2b.png');


// Canvas
let canvas = document.querySelector('canvas.webgl');
if (!canvas) {
    canvas = document.getElementById('background');
    if (!canvas) {
        canvas = document.createElement('canvas');
        canvas.id = 'background';
        canvas.className = 'webgl';
        document.body.appendChild(canvas);
    }
}

// Scene
const scene = new THREE.Scene()






////////////////////////////////////////////////////////////////////////////
//##     ##    ###    ######## ######## ########  ####    ###    ##       //
//###   ###   ## ##      ##    ##       ##     ##  ##    ## ##   ##       //
//#### ####  ##   ##     ##    ##       ##     ##  ##   ##   ##  ##       //
//## ### ## ##     ##    ##    ######   ########   ##  ##     ## ##       //
//##     ## #########    ##    ##       ##   ##    ##  ######### ##       //
//##     ## ##     ##    ##    ##       ##    ##   ##  ##     ## ##       //
//##     ## ##     ##    ##    ######## ##     ## #### ##     ## ######## //
////////////////////////////////////////////////////////////////////////////

// STORING POINTS
const points = [
    {
        position: new THREE.Vector3(1.55, 0.3, - 0.6),
        element: document.querySelector('.point-0')
    }
]

//physics 
const world = new CANNON.World()
world.gravity.set(0, -3.82, 0); 


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


////////////////////////////////////////////////////////////
// ######  ########  ##     ## ######## ########  ########//
//##    ## ##     ## ##     ## ##       ##     ## ##      //
//##       ##     ## ##     ## ##       ##     ## ##      //
// ######  ########  ######### ######   ########  ######  //
//      ## ##        ##     ## ##       ##   ##   ##      //
//##    ## ##        ##     ## ##       ##    ##  ##      //
// ######  ##        ##     ## ######## ##     ## ########//
////////////////////////////////////////////////////////////

const sphereGeometry = new THREE.SphereGeometry(1.6, 10, 10)
const sphereMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.3,
    roughness: 0.1,
    wireframe : true,
    color: '#FFFFFF',
    side: THREE.DoubleSide
    })

const shape = new CANNON.Sphere(0.5)
const body = new CANNON.Body({
    mass: 1.3,
    position: new CANNON.Vec3(0,0,0),
    shape: shape,
    material: defaultMaterial,
    velocity: new CANNON.Vec3(0, 0, 0)
})
// body.position.copy(position)
world.addBody(body)

const sphere = new THREE.Mesh(sphereGeometry, sphereMaterial)
sphere.castShadow = true
sphere.scale.set(0.5, 0.5, 0.5)
sphere.position.copy(body.position)
scene.add(sphere)

//////////////////////////////////////////////////////////////////////////
//########     ###    ########  ######## ####  ######  ##       ########//
//##     ##   ## ##   ##     ##    ##     ##  ##    ## ##       ##      //
//##     ##  ##   ##  ##     ##    ##     ##  ##       ##       ##      //
//########  ##     ## ########     ##     ##  ##       ##       ######  //
//##        ######### ##   ##      ##     ##  ##       ##       ##      //
//##        ##     ## ##    ##     ##     ##  ##    ## ##       ##      //
//##        ##     ## ##     ##    ##    ####  ######  ######## ########//
//////////////////////////////////////////////////////////////////////////

const params = {
    ringNumParticles: 600,
    ringRadius: 5.3,
    waveFrequency: 10,
    waveAmplitude: 0.5,
    hueMax: 300,
    size : 0.1
};

function initRandomParams() {
    params.ringNumParticles = Math.floor(Math.random() * (1000 - 300 + 1)) + 300; 
    params.ringRadius = Math.random() * (13 - 4) + 4;
    params.waveFrequency = Math.random() * (16 - 0.1) + 0.1; 
    params.waveAmplitude = Math.random() * (4 - 0.1) + 0.1;
    params.hueMax = Math.floor(Math.random() * (360 - 100 + 1)) + 100; 
    params.size = Math.random() * (0.25 - 0.18) + 0.16; 
}
initRandomParams();

let ringGeometry;


function generateParticles() {
    const count = params.ringNumParticles; 
    const pos = [];
    const colors = [];
    const solidColor = new THREE.Color(0xffffff); 
    const randomHue = Math.random(); 
    solidColor.setHSL(randomHue, 1, 0.5); 


    for (let i = 0; i < params.ringNumParticles; i++) {
        const angle = (i / params.ringNumParticles) * Math.PI * 2;

        const wave = Math.sin(angle * params.waveFrequency) * params.waveAmplitude;
        const radius = params.ringRadius + wave; // Ajout de l'onde sur le rayon

        const y = Math.cos(angle) * radius;
        const x = Math.sin(angle) * radius;
        const z = 0; // Cercle en 2D

        let color;
        if (params.ringNumParticles%3 == 0)
            color = solidColor;
        else if (params.ringNumParticles%4 == 0) 
        {

            const hue = (angle / (Math.PI * 2)) * 110; 
            color = new THREE.Color();
            color.setHSL(hue / 15, 2, 0.39);
            color.g = color.b;
        }
        else {
            const hue = (angle / (Math.PI * 2)) * params.hueMax;
            color = new THREE.Color();
            color.setHSL(hue / 360, 1, 0.5);
        }
        colors.push(color.r, color.g, color.b, 1);
        pos.push(x, y, z);

    }
    ringGeometry.setAttribute('position', new THREE.Float32BufferAttribute(pos, 3));
    ringGeometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 4));

}

function updateParticleSize()
{
    ringMaterial.size = params.size;
    ringMaterial.needsUpdate = true; 
}

ringGeometry = new THREE.BufferGeometry();
generateParticles();

const ringMaterial = new THREE.PointsMaterial({

        vertexColors: true,
        size: params.size - 1,
        transparent: true,
        opacity: 0.3,
        blending: THREE.NormalBlending,
        map: ringPointTexture,
        depthWrite: false,
        premultipliedAlpha: true,
        alphaTest: 0.1,
});

const ringParticles = new THREE.Points(ringGeometry, ringMaterial);
scene.add(ringParticles);

updateParticleSize();


// ---- RING GROUP ----
const torusRadius = 2;
const numRings = 120;

const ringGroup = new THREE.Group();

for (let i = 0; i < numRings; i++) {
    const angle = (i / numRings) * Math.PI * 2;

    const x = Math.cos(angle) * torusRadius;
    const z = Math.sin(angle) * torusRadius;
    const y = 0; // Aligné sur le plan XZ

    const ringClone = ringParticles.clone();
    ringClone.position.set(x, y, z);

    ringClone.lookAt(0, y, 0);
    ringClone.rotateY(Math.PI / 2);
    ringGroup.add(ringClone);
}
scene.add(ringGroup);

//////////////////////////////////////////////
//##       ####  ######   ##     ## ########//
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##        ##     ##    ##   //
//##        ##  ##   #### #########    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//######## ####  ######   ##     ##    ##   //
//////////////////////////////////////////////

const ambientLight = new THREE.AmbientLight(0xffffff, 2.1)
scene.add(ambientLight)

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.6)
directionalLight.castShadow = true
directionalLight.shadow.mapSize.set(1024, 1024)
directionalLight.shadow.camera.far = 15
directionalLight.shadow.camera.left = - 7
directionalLight.shadow.camera.top = 7
directionalLight.shadow.camera.right = 7
directionalLight.shadow.camera.bottom = - 7
directionalLight.position.set(5, 5, 5)
scene.add(directionalLight)

/**
 * Sizes
 */
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

const baseScreen = 1920;
function updateLogo() {
    const logo = document.querySelector('.logo');
    const width = window.innerWidth;
    const percent = width / baseScreen;
    if (percent < 0.60) {
    logo.src = "/static/logo/logo_square.png"; 
    logo.style.width = "280px";
    logo.style.left = "15%";
    } else {
    logo.src = "/static/logo/entropia9.png";
    logo.style.width = "550px";
    logo.style.left = "25%";
    }
}
window.addEventListener('load', updateLogo);

window.addEventListener('resize', () =>
{
    updateLogo();
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

//////////////////////////////////////////////////////////////
// ######     ###    ##     ## ######## ########     ###    //
//##    ##   ## ##   ###   ### ##       ##     ##   ## ##   //
//##        ##   ##  #### #### ##       ##     ##  ##   ##  //
//##       ##     ## ## ### ## ######   ########  ##     ## //
//##       ######### ##     ## ##       ##   ##   ######### //
//##    ## ##     ## ##     ## ##       ##    ##  ##     ## //
// ######  ##     ## ##     ## ######## ##     ## ##     ## //
//////////////////////////////////////////////////////////////

const camera = new THREE.PerspectiveCamera(80, sizes.width / sizes.height, 0.1, 100);

camera.position.set(0, 13, 25);
if (params.ringRadius < 8)
{
    sphere.scale.set(0.4, 0.4, 0.4);
    camera.position.set(0, 13, 15); 
}

camera.lookAt(0, 0, 9);
scene.add(camera);

// Controls / Renderer
const controls = new THREE.OrbitControls(camera, canvas)
controls.enableDamping = true

// Dans ton init Three.js :
const renderer = new THREE.WebGLRenderer({
    antialias: true,
    powerPreference: "high-performance"
    // canvas: canvas,
    // alpha: true,
});
renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);


document.body.appendChild(renderer.domElement);
document.body.style.margin = "0";  // Supprime les marges blanches du <body>
document.body.style.overflow = "hidden";  // Bloque le scroll


renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

document.body.appendChild(renderer.domElement);

scene.background = null;

const targetRotation = new THREE.Vector3();
const smoothingFactor = 0.1;

let floatAmplitude = 0.3; 
let floatSpeed = 0.02; 
let floatOffset = 0;

const mouse = new THREE.Vector2();
window.addEventListener('mousemove', (event) => {
    mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;

    targetRotation.y = mouse.x * 0.2;
    targetRotation.x = mouse.y * 0.2;
    targetRotation.z = mouse.x * -0.1;
});


// Définition de la gravité dans le monde physique
world.gravity.set(0, -9.82, 0); // Applique la gravité (accélération vers le bas)



function animateCamera() 
{
    const duration = 5;
    const startTime = Date.now();

    // Désactiver OrbitControls pendant l'animation
    controls.enabled = false;


    function update() 
    {
        const elapsedTime = (Date.now() - startTime) / 500;
        const progress = Math.min(elapsedTime / duration, 1);

        const easeProgress = easeOutQuad(progress);
        camera.position.lerpVectors(initialPosition, targetPosition, easeProgress);
        const direction = new THREE.Vector3(-2, 0, 0);
        camera.quaternion.setFromUnitVectors(new THREE.Vector3(-1, 0, 0), direction.normalize());
        
        const spherePosMoins = new THREE.Vector3(
            sphere.position.x-1.2,
            sphere.position.y + 1,
            sphere.position.z - 1
        );
        camera.lookAt(spherePosMoins);

        if (progress < 1)
            requestAnimationFrame(update);
        else 
            isAnimating = false;
    }
    update();
}

function easeOutQuad(t) { return t * (1.97 - t);}


function animateCameraAndFadeParticles() 
{
    const duration2 = 3.4; 
    const startTime = Date.now();

    function update() {
        const elapsedTime = (Date.now() - startTime) / 1000; 
        const progress = Math.min(elapsedTime / duration2, 1);

        // Interpolation de la position avec easing (rapide au début, lent à la fin)
        const easeProgress = easeOutQuad(progress);
        camera.position.lerpVectors(initialPosition, targetPosition, easeProgress);

        // Faire disparaître les particules en modifiant le canal alpha des couleurs
        const colors = ringGeometry.attributes.color.array;
    const numParticles = colors.length / 4;

        for (let i = 0; i < numParticles; i++) 
        {
            const delay = (numParticles - i) / numParticles; // Délai inversé
            const particleProgress = Math.max((progress - delay) / (1 - delay), 0); // Progression pour cette particule
            // Mettre à jour le canal alpha (a) de la particule
            colors[i * 4 + 3] = 1 - particleProgress; // Opacité diminue de 1 à 0
        }
        ringGeometry.attributes.color.needsUpdate = true; // Mettre à jour l'attribut color
        if (progress < 1)
            requestAnimationFrame(update);
        else {
            scene.remove(ringGroup);
            scene.remove(ringParticles);
            ringParticles.geometry.dispose();
            ringParticles.material.dispose();
            isAnimating = false;
        }
    }
    update();
}

////////////////////////////////////
//######## ####  ######  ##    ## //
//   ##     ##  ##    ## ##   ##  //
//   ##     ##  ##       ##  ##   //
//   ##     ##  ##       #####    //
//   ##     ##  ##       ##  ##   //
//   ##     ##  ##    ## ##   ##  //
//   ##    ####  ######  ##    ## //
////////////////////////////////////

let infinityOffset = 0;
const infinityAmplitude = 0.001;
const infinitySpeed = 0.002;
const baseYPosition = 1;
// Animate
const clock = new THREE.Clock()
let oldElapsedTime = 0

const sceneYOffset = 0;  // Décalage vers le haut

const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()
    const deltaTime = elapsedTime - oldElapsedTime
    oldElapsedTime = elapsedTime
    
    // interpoler vers rotation cible
    ringGroup.rotation.x += (targetRotation.x - ringGroup.rotation.x) * smoothingFactor * 1.5;
    ringGroup.rotation.y += (targetRotation.y - ringGroup.rotation.y) * smoothingFactor;
    ringGroup.rotation.z += (targetRotation.z - ringGroup.rotation.z) * smoothingFactor;

    ringGroup.children.forEach((ring) => 
    {
        ring.rotation.z += 0.001;
        //ring.rotation.z = 0.002; forme coupée en 2 stylée
    });

    // applique le décalage 
    ringGroup.position.y = sceneYOffset;

    // //sphere mouv
    // sphere.position.y = sceneYOffset + floatAmplitude * Math.sin(floatOffset);
    // floatOffset -= floatSpeed;


    // Flottement vertical
    sphere.position.y = baseYPosition + infinityAmplitude * Math.sin(infinityOffset);

    // Mouvement en forme de 8 (∞)
    const infinityRadius = 2; // Largeur du huit couché
    sphere.position.x = infinityRadius * Math.sin(infinityOffset);
    sphere.position.z = infinityRadius * Math.sin(infinityOffset) * Math.cos(infinityOffset);

    // Rotation sur elle-même
    sphere.rotation.y += 0.005;  // Rotation horizontale
    // sphere.rotation.x += 0.0015; // Rotation verticale

    // Mise à jour du temps
    infinityOffset -= infinitySpeed;

    if (controls.enabled) 
        controls.update();

    world.step(1 / 60, deltaTime, 3);
    renderer.render(scene, camera);
    window.animationFrameId = window.requestAnimationFrame(tick);
}

tick();

// //////////////////////////////////////////////////
// //######## ##     ## ######## ##    ## ######## //
// //##       ##     ## ##       ###   ##    ##    //
// //##       ##     ## ##       ####  ##    ##    //
// //######   ##     ## ######   ## ## ##    ##    //
// //##        ##   ##  ##       ##  ####    ##    //
// //##         ## ##   ##       ##   ###    ##    //
// //########    ###    ######## ##    ##    ##    //
// //////////////////////////////////////////////////

let isAnimating = false;
const targetPosition = new THREE.Vector3(2, 0, -4);
const initialPosition = camera.position.clone();

const boutons = document.querySelectorAll('.go_to_signup_page');

boutons.forEach(bouton => 
{
bouton.addEventListener('click', function() 
{
    console.log("signup button clicked");
    document.getElementById('signupContainer').style.display = 'block';
    document.getElementById('loginForm').style.display = 'none';
        if (!isAnimating) 
        {
                isAnimating = true;
                animateCamera();
                animateCameraAndFadeParticles();  
                // animate_bound();
        }  
});
})

//////////////////////////////////////////////////
// ######  ##       ########    ###    ##    ## //
//##    ## ##       ##         ## ##   ###   ## //
//##       ##       ##        ##   ##  ####  ## //
//##       ##       ######   ##     ## ## ## ## //
//##       ##       ##       ######### ##  #### //
//##    ## ##       ##       ##     ## ##   ### //
// ######  ######## ######## ##     ## ##    ## //
//////////////////////////////////////////////////

const clean_home = document.querySelectorAll('.vs_tournois, .pong, .avatar');

clean_home.forEach(bouton => {
bouton.addEventListener('click', function () {
    console.log("Suppression des éléments");
    localStorage.setItem('elementsSupprimes', 'true');

        // Supprimer les particules ou autres objets existants
        scene.remove(ringParticles); // Supprime les particules
        scene.remove(ringGroup); // Supprime les particules
        scene.remove(sphere); // Supprime les particules

    // Libérer la géométrie et le matériau (évite les fuites mémoire)
    ringParticles.geometry.dispose();
    if (Array.isArray(ringParticles.material)) {
        ringParticles.material.forEach(mat => mat.dispose());
    } else {
        ringParticles.material.dispose();
    }

    // Retirer le corps physique de la scène
    world.removeBody(body); // Supprime le corps physique associé à la sphère

});
});

// camera.position.y -= 2; 

return function cleanup() {
    console.log("clear home.js");
    
    // Only remove our specific canvas
    const canvas = document.getElementById('background');
    if (canvas) {
        canvas.remove();
    }
    
    // Clean up THREE.js resources
    if (renderer) {
        renderer.dispose();
        if (renderer.domElement) {
            renderer.domElement.remove();
        }
    }
    
    // Clean up geometries and materials
    if (ringGeometry) {
        ringGeometry.dispose();
    }
    
    if (ringMaterial) {
        ringMaterial.dispose();
    }
    
    // Stop animation frame
    if (window.animationFrameId) {
        cancelAnimationFrame(window.animationFrameId);
    }
}
}

window.currentModuleCleanup = initialize();

