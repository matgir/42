import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';



console.log("dehors");    
// let renderer;   

// const oldCanvas = document.querySelector('.webgl');
// if (oldCanvas) {
    // canvas.remove();

 

function createScene() {

    let downloadDone = false;  // état pour bloquer après 1 clic
    // Supprimer l'ancien canvas s'il existe
    // const oldCanvas = document.querySelector('.webgl');
    // if (oldCanvas) {
        // oldCanvas.remove();
    // }

    const oldCanvas = document.querySelector('.webgl');
    if (oldCanvas) {
        oldCanvas.remove();
    }

 
    // Créer et ajouter un nouveau canvas
    const canvas = document.createElement('canvas');
    canvas.classList.add('webgl');
    document.body.appendChild(canvas);

    // Créer le renderer
    const renderer = new THREE.WebGLRenderer({ canvas: canvas });
    renderer.setSize(400, 400);
    
   
        
    


// const canvas = document.querySelector('.webgl');
// const renderer = new THREE.WebGLRenderer({ canvas: canvas });
// renderer.setSize(400, 400); // Dimension du canvas


    console.log("logsdvcv");             

    


//import { roughness } from 'three/tsl'

/**
 * Debug
 */
//  const gui = new GUI()
const debugObject = {}
//const debugObject2 = {}

/**
 * Base
 */
// Canvas
// const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

//scene.background = new THREE.Color("#fefae0");d8e2dc
//scene.background = new THREE.Color("#FF00FF")

// const axesHelper = new THREE.AxesHelper(5) // Longueur des axes = 5 unités
//scene.add(axesHelper)

//physics 
const world = new CANNON.World()
world.gravity.set(0, 0, 0)

////////////////////////////////////////////////////////////////////////////
//##     ##    ###    ######## ######## ########  ####    ###    ##       //
//###   ###   ## ##      ##    ##       ##     ##  ##    ## ##   ##       //
//#### ####  ##   ##     ##    ##       ##     ##  ##   ##   ##  ##       //
//## ### ## ##     ##    ##    ######   ########   ##  ##     ## ##       //
//##     ## #########    ##    ##       ##   ##    ##  ######### ##       //
//##     ## ##     ##    ##    ##       ##    ##   ##  ##     ## ##       //
//##     ## ##     ##    ##    ######## ##     ## #### ##     ## ######## //
////////////////////////////////////////////////////////////////////////////

//normal_material.flatShading = true

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

////////////////////////////////////////
//######## ##    ## ########  ######  //
//##        ##  ##  ##       ##    ## //
//##         ####   ##       ##       //
//######      ##    ######    ######  //
//##          ##    ##             ## //
//##          ##    ##       ##    ## //
//########    ##    ########  ######  //
////////////////////////////////////////

// Geometry et Material des sphères
const sphereGeometry = new THREE.SphereGeometry(5, 10, 22);
const sphereMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.1,
    roughness: 0.1,
    wireframe: true,
    color: '#FFFFFF',
    side: THREE.DoubleSide,
});

// Geometry et Material des pupilles
const pupilGeometry = new THREE.SphereGeometry(1.2, 12, 12);
const pupilMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.1,
    roughness: 0.9,
    wireframe: false,
    color: '#000000',
    side: THREE.DoubleSide
});

// Groupe principal
const spheresGroup = new THREE.Group();
scene.add(spheresGroup);

// Fonction pour créer un œil complet
function createEye(positionX) {
    const eyeGroup = new THREE.Group();

    const sphere = new THREE.Mesh(sphereGeometry, sphereMaterial);
    sphere.castShadow = true;
    sphere.scale.set(0.5, 0.5, 0.5);

    const pupil = new THREE.Mesh(pupilGeometry, pupilMaterial);
    pupil.castShadow = true;

    const safeDistance = 5 * 0.5 - 1.2 * 0.5 - 0.05; // rayon du globe - rayon pupille - marge
    pupil.position.set(0, 1, 2.2);

    eyeGroup.add(sphere);
    eyeGroup.add(pupil);
    eyeGroup.position.set(positionX, 0, -3);

    spheresGroup.add(eyeGroup);

    return { eyeGroup, pupil };
}

// Création des deux yeux symétriques
const rightEye = createEye(9);
const leftEye = createEye(-9);

// Fonction pour déplacer les yeux aléatoirement dans les limites
function randomizeEyes() {
    const eyePositionX = Math.random() * (9 - 3) + 3; // Valeur entre 3 et 9 pour la position X
    const eyePositionY = Math.random() * ( - -3) + -3; // Valeur entre -4 et 2 pour la position Y
    const eyePositionZ = Math.random() * (4 - 3) + 3; // Z est fixé à 1 pour les deux yeux

    // Appliquer les nouvelles positions aux yeux
    rightEye.eyeGroup.position.set(eyePositionX, eyePositionY, eyePositionZ);
    leftEye.eyeGroup.position.set(-eyePositionX, eyePositionY, eyePositionZ);
}

// Appeler la fonction pour randomiser la position des yeux lors de la première initialisation de la scène
randomizeEyes();

////////////////////////////
// ######   ##     ## ####//
//##    ##  ##     ##  ## //
//##        ##     ##  ## //
//##   #### ##     ##  ## //
//##    ##  ##     ##  ## //
//##    ##  ##     ##  ## //
// ######    #######  ####//
////////////////////////////

// dat.GUI pour contrôler les yeux
// const gui = new dat.GUI();

// // Contrôles pour déplacer les yeux
// const eyePosition = {
//     x: rightEye.eyeGroup.position.x,
//     y: rightEye.eyeGroup.position.y,
//     z: rightEye.eyeGroup.position.z
// };

// gui.add(eyePosition, 'x', 3, 9).onChange((value) => {
//     rightEye.eyeGroup.position.x = value;
//     leftEye.eyeGroup.position.x = -value;
// });

// gui.add(eyePosition, 'y', 2, -4).onChange((value) => {
//     rightEye.eyeGroup.position.y = value;
//     leftEye.eyeGroup.position.y = value;
// });

// gui.add(eyePosition, 'z', 1, 1).onChange((value) => {
//     rightEye.eyeGroup.position.z = value;
//     leftEye.eyeGroup.position.z = value;
// });

// // Contrôles pour orienter les pupilles sans qu'elles sortent
// const pupilPosition = {
//     x: rightEye.pupil.position.x,
//     y: rightEye.pupil.position.y,
//     z: rightEye.pupil.position.z
// };

// const pupilFolder = gui.addFolder('Pupilles');
// pupilFolder.open();


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
    ringNumParticles: 600, // Nombre de particules dans le cercle
    ringRadius: 5.3,       // Rayon du cercle
    waveFrequency: 10,     // Fréquence de l'onde
    waveAmplitude: 0.5,    // Amplitude de l'onde
    hueMax: 300,           // Valeur initiale de hueMax
    size : 0.1,
};

function initRandomParams() {
    params.ringNumParticles = Math.floor(Math.random() * (1000 - 300 + 1)) + 300; // Entre 100 et 1000
    params.ringRadius = Math.random() * (13 - 4) + 4; // Entre 1 et 20
    params.waveFrequency = Math.random() * (16 - 0.1) + 0.1; // Entre 0.1 et 20
    params.waveAmplitude = Math.random() * (4 - 0.1) + 0.1; // Entre 0.1 et 5
    params.hueMax = Math.floor(Math.random() * (360 - 100 + 1)) + 100; // Entre 100 et 360
    params.size = Math.random() * (0.25 - 0.18) + 0.16; 
}

initRandomParams();


// Variables globales
let ringGeometry;
const ringNumParticles = 600; // Nombre de particules dans le cercle
const ringRadius = 5.3; // Rayon du cercle
const waveFrequency = 10; // Fréquence de l'onde
const waveAmplitude = 0.5; // Amplitude de l'onde

// Texture des particules
const ringPointTexture = new THREE.TextureLoader().load('static/particles/2b.png');


function generateParticles() {
     const count = params.ringNumParticles; // Initialiser count avec le nombre de particules
     const pos = [];
     const colors = [];
     const solidColor = new THREE.Color(0xffffff); // Blanc
     const randomHue = Math.random(); // Teinte aléatoire entre 0 et 1
     solidColor.setHSL(randomHue, 1, 0.5); // Couleur aléatoire vive

 
    for (let i = 0; i < params.ringNumParticles; i++) {
        const angle = (i / params.ringNumParticles) * Math.PI * 2;

        // Création d'une variation ondulée sur le rayon
        const wave = Math.sin(angle * params.waveFrequency) * params.waveAmplitude;
        const radius = params.ringRadius + wave; // Ajout de l’onde sur le rayon

        const y = Math.cos(angle) * radius;
        const x = Math.sin(angle) * radius;
        const z = 0; // Cercle en 2D

        let color;
        if (params.ringNumParticles%3 == 0) {
            color = solidColor;
        } 
        else if (params.ringNumParticles%4 == 0) {
            console.log("aloooq");
            const hue = (angle / (Math.PI * 2)) * 110; // idem //ici300
            color = new THREE.Color();
            color.setHSL(hue / 15, 2, 0.39); // division hue a modif  //ici tout
            color.g = color.b;
        }
        else {
            // Sinon, calculer la teinte en fonction de l'angle et de hueMax
            const hue = (angle / (Math.PI * 2)) * params.hueMax;
            color = new THREE.Color();
            color.setHSL(hue / 360, 1, 0.5); // Conversion HSL vers RGB
        }

        colors.push(color.r, color.g, color.b, 1);
        pos.push(x, y, z);

    }

    
//     // Retourner les positions et les couleurs
//     return { positions: pos, colors: colors };
// }

    // Mettre à jour la géométrie
    ringGeometry.setAttribute('position', new THREE.Float32BufferAttribute(pos, 3));
    ringGeometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 4));

}

// Fonction pour mettre à jour les particules
function updateParticles() {
    generateParticles();
    ringGeometry.attributes.position.needsUpdate = true; // Mettre à jour les positions
    ringGeometry.attributes.color.needsUpdate = true; // Mettre à jour les couleurs

    // Mettre à jour tous les clones dans ringGroup
    ringGroup.children.forEach((ringClone) => {
        ringClone.geometry.attributes.position.needsUpdate = true;
        ringClone.geometry.attributes.color.needsUpdate = true;
    });
}

function updateParticleSize() {
    ringMaterial.size = params.size; // Mettre à jour la taille des particules
    ringMaterial.needsUpdate = true; // Indiquer que le matériau doit être mis à jour
}

ringGeometry = new THREE.BufferGeometry();
generateParticles();

// Création des particules
const ringMaterial = new THREE.PointsMaterial({

        vertexColors: true,
        size: params.size,
        transparent: true,
        opacity: 0.3,
        blending: THREE.NormalBlending, // Essayez ce mode de blending
        map: ringPointTexture,
        depthWrite: false,
        premultipliedAlpha: true,
        alphaTest: 0.1, // Ajustez cette valeur pour éliminer les bords noirs
});


const ringParticles = new THREE.Points(ringGeometry, ringMaterial);
scene.add(ringParticles);

updateParticleSize();

// ---- Ajouter un helper d’axes ----
const axesHelper = new THREE.AxesHelper(3); // Longueur des axes
// ringParticles.add(axesHelper);

// ---- RING GROUP ----

// Ajouter 3 copies avec un décalage et une rotation unique
const torusRadius = 2; // Rayon du tore (cercle principal)
const numRings = 120; // Nombre de rings autour du tore

const ringGroup = new THREE.Group();

for (let i = 0; i < numRings; i++) {
    const angle = (i / numRings) * Math.PI * 2; // Angle en radians

    // Calcul des positions pour former un tube
    const x = Math.cos(angle) * torusRadius;
    const z = Math.sin(angle) * torusRadius;
    const y = 0; // Aligné sur le plan XZ

    const ringClone = ringParticles.clone();
    ringClone.position.set(x, y, z);

    // Faire en sorte que le ring soit perpendiculaire au tube
    ringClone.lookAt(0, y, 0); // Regarde vers l'axe du tore

    // Appliquer un quart de tour sur l'axe X
    ringClone.rotateY(Math.PI / 2); // Rotation de 90 degrés

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

// window.addEventListener('resize', () =>
// {
//     sizes.width = window.innerWidth
//     sizes.height = window.innerHeight

//     camera.aspect = sizes.width / sizes.height
//     camera.updateProjectionMatrix()

//     renderer.setSize(sizes.width, sizes.height)
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
// })

//////////////////////////////////////////////////////////////
// ######     ###    ##     ## ######## ########     ###    //
//##    ##   ## ##   ###   ### ##       ##     ##   ## ##   //
//##        ##   ##  #### #### ##       ##     ##  ##   ##  //
//##       ##     ## ## ### ## ######   ########  ##     ## //
//##       ######### ##     ## ##       ##   ##   ######### //
//##    ## ##     ## ##     ## ##       ##    ##  ##     ## //
// ######  ##     ## ##     ## ######## ##     ## ##     ## //
//////////////////////////////////////////////////////////////

const camera = new THREE.PerspectiveCamera(75, 400 / 400, 0.1, 100);

// 🔹 Placer la caméra en face de la ring (vue de dessus)
camera.position.set(0, 13, 25); // Déplacer sur l'axe Z pour voir le cercle de face

camera.lookAt(0, 0, 9);

scene.add(camera);
document.addEventListener('keydown', (event) => {
    if (event.key === 'p') { // Appuyez sur la touche 'p'
      //  console.log("Position de la caméra :", camera.position);
    }
});

// Controls
// const controls = new THREE.OrbitControls(camera, canvas)
// const controls = new THREE.OrbitControls(camera, renderer.domElement);

// controls.enableDamping = true



/**
 * Renderer
 */
// const renderer = new THREE.WebGLRenderer({ canvas: canvas });

// const canvas = document.querySelector('.webgl');
// const renderer = new THREE.WebGLRenderer({ canvas : canvas });

// renderer.setSize(400, 400);
// canvas.style.width = '400px';
// canvas.style.height = '400px';
// const renderer = new THREE.WebGLRenderer({
//     canvas: canvas,
//     alpha: true,
// })
renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
// renderer.setSize(sizes.width, sizes.height)
// renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))


// const canvas = document.querySelector('.webgl');
// const renderer = new THREE.WebGLRenderer({ canvas: canvas });

// renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));



// À mettre une seule fois :
// renderer.setSize(1200, 1200);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

const controls = new THREE.OrbitControls(camera, renderer.domElement);

controls.enableDamping = true

camera.aspect = 1;
camera.updateProjectionMatrix();

document.body.appendChild(renderer.domElement);

scene.background = null; // Rend le fond transparent
// scene.background = new THREE.Color("#FF00FF")




// Variables pour stocker la rotation cible
const targetRotation = new THREE.Vector3();

// Facteur de lissage (entre 0 et 1)
const smoothingFactor = 0.1;

let floatAmplitude = 0.3; // Amplitude du mouvement (distance maximale de montée/descente)
let floatSpeed = 0.05; // Vitesse du mouvement (plus petit pour plus de douceur)
let floatOffset = 0; // Décalage pour la sinusoïde




const mouse = new THREE.Vector2();

// Écouter les mouvements de la souris
window.addEventListener('mousemove', (event) => {
    mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;

    // Définir la rotation cible en fonction de la souris
    targetRotation.y = mouse.x * 0.2; // Rotation autour de l'axe Y
    targetRotation.x = mouse.y * 0.2; // Rotation autour de l'axe X
    targetRotation.z = mouse.x * -0.1; // Rotation autour de l'axe Z
});

////////////////////////////////////
//######## ####  ######  ##    ## //
//   ##     ##  ##    ## ##   ##  //
//   ##     ##  ##       ##  ##   //
//   ##     ##  ##       #####    //
//   ##     ##  ##       ##  ##   //
//   ##     ##  ##    ## ##   ##  //
//   ##    ####  ######  ##    ## //
////////////////////////////////////

const clock = new THREE.Clock()
let oldElapsedTime = 0

const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()
    const deltaTime = elapsedTime - oldElapsedTime
    oldElapsedTime = elapsedTime
    
    // Interpoler progressivement vers la rotation cible
    ringGroup.rotation.x += (targetRotation.x - ringGroup.rotation.x) * smoothingFactor * 1.5;
    ringGroup.rotation.y += (targetRotation.y - ringGroup.rotation.y) * smoothingFactor;
    ringGroup.rotation.z += (targetRotation.z - ringGroup.rotation.z) * smoothingFactor;

    ringGroup.children.forEach((ring) => 
        {
            ring.rotation.z += 0.001; // Rotation constante pour tous les rings

           // ring.rotation.z = 0.002; forme coupée en 2 stylée
        });
 
    // 6. Utilisation de la fonction sinus pour un mouvement plus smooth
    // sphere.position.y = floatAmplitude * Math.sin(floatOffset);

    // 7. Ralentir et accélérer en fonction de la sinusoïde
    floatOffset -= floatSpeed;  // Augmente progressivement la valeur pour un mouvement constant



   
    if (controls.enabled) {
            controls.update();
        }

    
    world.step(1 / 60, deltaTime, 3)



   
    renderer.render(scene, camera)
    window.requestAnimationFrame(tick)



}
tick()



    document.getElementById('generateImageBtn').addEventListener('click', () => {
        canvas.remove();    
    });
    document.getElementById('nop').addEventListener('click', () => {
        canvas.remove();    
    });


// Gestion du bouton de téléchargement
document.getElementById('generateImageBtn').addEventListener('click', () => {
    if (downloadDone) return;  // Bloque après 1 téléchargement

    if (renderer && scene && camera) {
        renderer.render(scene, camera);
        console.log("CARGO");

        const dataURL = renderer.domElement.toDataURL('image/png');
        const link = document.createElement('a');
        link.href = dataURL;
        link.download = 'screenshot.png';
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);

        downloadDone = true;  // bloque après ce clic
    }
});

// document.getElementById('avatar').addEventListener('click', () => {
//     canvas.remove();
 


//     if(renderer) {
//         console.log("CAREUGO");
//         renderer.dispose();
//         renderer.domElement.remove();  // supprime l'ancien canvas
//     }
    
//     // Reset du container
//     const container = document.querySelector('#your-scene-container');
//     container.innerHTML = `
//            <div class="button-container">
//         <button class="nop" id="nop">NOP</button>  
//         <button class="select" id="generateImageBtn">SELECT!</button>  
//     </div>
//     <script src="https://cdn.jsdelivr.net/npm/three@0.132.2/build/three.min.js"></script>
//     <script src="https://cdn.jsdelivr.net/npm/three@0.132.2/examples/js/controls/OrbitControls.min.js"></script>
//     <canvas class="webgl"></canvas>
//     `;  


//     createScene();

//         // Réattacher les listeners des boutons
//     document.getElementById('nop').addEventListener('click', () => {
//         console.log('NOP clicked');
//     });
//     document.getElementById('generateImageBtn').addEventListener('click', () => {
//         console.log('SELECT clicked');
//     });

//     document.getElementById('avatar').addEventListener('click', () => {
//         location.reload(); // Recharge la page
//       });
      

// });

document.getElementById('generateImageBtn').addEventListener('click', () => {
            createScene();
          });
          


// document.getElementById('nop').addEventListener('click', () => {
//     // canvas.remove();
//     createScene();
// });


}








    // avatarButton.addEventListener('click', createScene);


// document.getElementById('avatar').addEventListener('click', () => {
//     canvas.remove();
//     createScene;
// });


////////////////////////////////
//########  ##    ##  ######  //
//##     ## ###   ## ##    ## //
//##     ## ####  ## ##       //
//########  ## ## ## ##   ####//
//##        ##  #### ##    ## //
//##        ##   ### ##    ## //
//##        ##    ##  ######  //
////////////////////////////////



// const clean_avatar = document.querySelectorAll('.avatar');

// clean_avatar.forEach(bouton => {
//   bouton.addEventListener('click', function () {
//     console.log("Suppression des éléments");
//     localStorage.setItem('elementsSupprimes', 'true');

//          // Supprimer les particules ou autres objets existants
//          scene.remove(ringParticles); // Supprime les particules
//          scene.remove(ringGroup); // Supprime les particules
//          scene.remove(sphere); // Supprime les particules

//     // Libérer la géométrie et le matériau (évite les fuites mémoire)
//     ringParticles.geometry.dispose();
//     if (Array.isArray(ringParticles.material)) {
//         ringParticles.material.forEach(mat => mat.dispose());
//     } else {
//         ringParticles.material.dispose();
//     }

//     // Retirer le corps physique de la scène
//     world.removeBody(body); // Supprime le corps physique associé à la sphère

//   });
// });

// document.getElementById('avatar').addEventListener('click', () => {
//     // canvas.remove();
//     // document.querySelector('#canvas').innerHTML = '';
//     if (currentScene !== 'avatar') {
//         loadAvatarScene();
//         currentScene = 'avatar';
//     }
//     createScene();

// });




document.getElementById('nop').addEventListener('click', () => {
    // canvas.remove();
    console.log("EHHO")
    createScene();
});





// Lancer une première fois
createScene();
