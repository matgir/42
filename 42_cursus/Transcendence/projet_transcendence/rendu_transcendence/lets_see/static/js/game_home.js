import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

// // import * as THREE from 'three'
// // //  import { OrbitControls } from 'OrbitControls.js'
// console.log(localStorage.getItem('elementsSupprimes'));

// const canvases = document.querySelectorAll('canvas');
// canvases.forEach(canvas => {
//     canvas.remove();
// });

// console.log("COUCOU");
const canvas = document.querySelector('canvas.webgl')

/**
 * Physics
*/
const world = new CANNON.World()

world.allowSleep = true
world.gravity.set(0, -18.82, 0)

const sol = -20

// Scene
const scene = new THREE.Scene()

/**
 * Textures
*/
const textureLoader = new THREE.TextureLoader()
const cubeTextureLoader = new THREE.CubeTextureLoader()

const environmentMapTexture = cubeTextureLoader.load([
    'static/textures/environmentMaps/0/px.png',
    'static/textures/environmentMaps/0/nx.png',
    'static/textures/environmentMaps/0/py.png',
    'static/textures/environmentMaps/0/ny.png',
    'static/textures/environmentMaps/0/pz.png',
    'static/textures/environmentMaps/0/nz.png'
])

// 2. Charger la texture

// const sphereTexture = textureLoader.load(
//     'static/textures/environmentMaps/0/scott.png', // Remplacez par le chemin de votre image
//     () => console.log("Texture chargée avec succès !"),
//     () => console.error("Erreur de chargement de la texture")
// );

const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
};

// Calcul dynamique des limites basé sur l'aspect ratio
function getScreenBounds() {
    const aspectRatio = sizes.width / sizes.height;
    return {
        left: -75 * aspectRatio,
        right: 75 * aspectRatio
    };
}
/**
 * Material
 */

// Définition des matériaux
// ////////////////////////////////////////////////////////////////////////////
// //##     ##    ###    ######## ######## ########  ####    ###    ##       //
// //###   ###   ## ##      ##    ##       ##     ##  ##    ## ##   ##       //
// //#### ####  ##   ##     ##    ##       ##     ##  ##   ##   ##  ##       //
// //## ### ## ##     ##    ##    ######   ########   ##  ##     ## ##       //
// //##     ## #########    ##    ##       ##   ##    ##  ######### ##       //
// //##     ## ##     ##    ##    ##       ##    ##   ##  ##     ## ##       //
// //##     ## ##     ##    ##    ######## ##     ## #### ##     ## ######## //
// ////////////////////////////////////////////////////////////////////////////


const plasticMaterial = new CANNON.Material('plastic');
const concreteMaterial = new CANNON.Material('concrete');



const plasticContactMaterial = new CANNON.ContactMaterial(
    plasticMaterial,
    plasticMaterial,
    {
        friction: 0.04,
        restitution: 0.9   // Un peu réaliste, mais la balle ne devrait pas s'auto-collisionner souvent
    }
);
world.addContactMaterial(plasticContactMaterial);


const restitution = 0.6
const friction =  0.2

const plasticConcreteContactMaterial = new CANNON.ContactMaterial(
    plasticMaterial,
    concreteMaterial,
    {
        friction: friction,
        restitution: restitution
    }
);
world.addContactMaterial(plasticConcreteContactMaterial);

// ////////////////////////////////////////////////////////////
// // ######  ########  ##     ## ######## ########  ########//
// //##    ## ##     ## ##     ## ##       ##     ## ##      //
// //##       ##     ## ##     ## ##       ##     ## ##      //
// // ######  ########  ######### ######   ########  ######  //
// //      ## ##        ##     ## ##       ##   ##   ##      //
// //##    ## ##        ##     ## ##       ##    ##  ##      //
// // ######  ##        ##     ## ######## ##     ## ########//
// ////////////////////////////////////////////////////////////



const spheres = []
// let spawnRight = true;
// let currentX = -75; // Position de départ à gauche
// let direction = 1;  // 1 = vers la droite, -1 = vers la gauche
// const step = 10;    // Incrément de déplacement entre chaque balle

// map: sphereTexture 



const createSphere = () => {

        const sphereShape = new CANNON.Sphere(2.2);
        const yPos = 160;
        const zPos = Math.PI;
        
        const bounds = getScreenBounds();
        const randomX = bounds.left + Math.random() * (bounds.right - bounds.left);
        const randomZ =  Math.floor(Math.random() * 10) + zPos

    
        const sphereBody = new CANNON.Body({
            mass: 1,
            position: new CANNON.Vec3(randomX, yPos, randomZ),
            shape: sphereShape,
            material: plasticMaterial
        });
    

// const sphereBody = new CANNON.Body({
//     mass: 1,
//     position: new CANNON.Vec3(currentX, yPos, zPos), // Y=30, Z=0
//     shape: sphereShape,
//     material: plasticMaterial
// });

    sphereBody.linearDamping = 0.03  // frein léger
    sphereBody.angularDamping = 0.01 
    sphereBody.timeAtRest = 0;
    sphereBody.velocity.set(0, -55, 0);
    //   // Vitesse opposée à la position (balle va vers le centre)
    //   const xVelocity = xPos > 0 ? -5 : 5; // 5 m/s vers le centre
    //   sphereBody.velocity.set(xVelocity, 0, 0);
  

    world.addBody(sphereBody)

    const sphere = new THREE.Mesh(
        new THREE.SphereGeometry(2.2, 14, 14),
        new THREE.MeshStandardMaterial({
            metalness: 0.3,
            roughness: 0.4,
            envMap: environmentMapTexture,
            envMapIntensity: 0.5,
            wireframe: true
        })
    )
    sphere.castShadow = true
    sphere.receiveShadow = true;

    scene.add(sphere)

    // currentX += step * direction;

    // // Inverser la direction si on atteint un bord
    // if (currentX >= 75 || currentX <= -75) {
    //     direction *= -1; // Inverser la direction
    // }


    spheres.push({ sphere, sphereBody })
}
createSphere()

const MAX_SPHERES = 35; // Limite maximale

// Intervalle avec gestion automatique
// const sphereInterval = setInterval(() => {
//     createSphere();
//     console.log(spheres.length)
//     if (spheres.length >= MAX_SPHERES)
//     {
//          clearInterval(sphereInterval)
//          console.log("prout")
//     }

// }, 2500);


let sphereInterval = setInterval(() => {
    createSphere();
    console.log(spheres.length)
    if (spheres.length >= MAX_SPHERES)
    {
         clearInterval(sphereInterval)
         console.log("prout")
    }
    }, 3000);



// ////////////////////////////////////////////////////
// //######## ##        #######   #######  ########  //
// //##       ##       ##     ## ##     ## ##     ## //
// //##       ##       ##     ## ##     ## ##     ## //
// //######   ##       ##     ## ##     ## ########  //
// //##       ##       ##     ## ##     ## ##   ##   //
// //##       ##       ##     ## ##     ## ##    ##  //
// //##       ########  #######   #######  ##     ## //
// ////////////////////////////////////////////////////
//Floor Body
const floorShape = new CANNON.Plane()
const floorBody = new CANNON.Body({
    mass: 0,
    position: new CANNON.Vec3(0, sol, 0),
    shape: floorShape,
    material: concreteMaterial
})

world.addBody(floorBody)
floorBody.quaternion.setFromAxisAngle(new CANNON.Vec3(- 1, 0, 0), Math.PI * 0.5)

//floor
const floor = new THREE.Mesh(
    new THREE.PlaneGeometry(400, 400, 100 , 1),
    new THREE.MeshStandardMaterial({
        color: '#dddddd',
        metalness: 0.1,  // Un peu de métal pour augmenter l'interaction avec la lumière
        roughness: 0.9,  // Beaucoup de rugosité pour rendre l'ombre plus nette
        envMap: environmentMapTexture,
        envMapIntensity: 0.2,
        wireframe : true
    })
)
floor.receiveShadow = true;
floor.rotation.x = - Math.PI * 0.5;
floor.position.y = sol;
floor.position.copy(floorBody.position);

scene.add(floor);

// //////////////////////////////////////////////
// //##       ####  ######   ##     ## ########//
// //##        ##  ##    ##  ##     ##    ##   //
// //##        ##  ##        ##     ##    ##   //
// //##        ##  ##   #### #########    ##   //
// //##        ##  ##    ##  ##     ##    ##   //
// //##        ##  ##    ##  ##     ##    ##   //
// //######## ####  ######   ##     ##    ##   //
// //////////////////////////////////////////////

const ambientLight = new THREE.AmbientLight(0xffffff, 1)
scene.add(ambientLight)

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.6)
directionalLight.castShadow = true
directionalLight.shadow.mapSize.set(2048, 2048);  // Augmente la résolution des ombres pour plus de détails
directionalLight.shadow.camera.far = 15;  // Augmente la distance de la caméra des ombres
directionalLight.shadow.camera.left = -15;
directionalLight.shadow.camera.right = 15;
directionalLight.shadow.camera.top = 15;
directionalLight.shadow.camera.bottom = -15;
directionalLight.position.set(10, 13, 10)


scene.add(directionalLight)

    
    // //////////////////////////////////////////////////////////////
    // // ######     ###    ##     ## ######## ########     ###    //
    // //##    ##   ## ##   ###   ### ##       ##     ##   ## ##   //
    // //##        ##   ##  #### #### ##       ##     ##  ##   ##  //
    // //##       ##     ## ## ### ## ######   ########  ##     ## //
    // //##       ######### ##     ## ##       ##   ##   ######### //
    // //##    ## ##     ## ##     ## ##       ##    ##  ##     ## //
    // // ######  ##     ## ##     ## ######## ##     ## ##     ## //
    // //////////////////////////////////////////////////////////////

    
    const camera = new THREE.PerspectiveCamera(90, sizes.width / sizes.height, 0.1, 125)
    // camera.position.set(-16.7, -7, -1.3);  // proche du sol et en retrait
    camera.position.set(0, -18, -35);  // proche du sol et en retrait-
    
    // camera.position.set(-12, 0, -12);  // proche du sol et en retrait
    
    // camera.lookAt(new THREE.Vector3(-6, 1, -60));  // regarde à hauteur d’homme (contre-plongée douce)?
    scene.add(camera)
    const cameraGroup = new THREE.Group();
    scene.add(cameraGroup);
    cameraGroup.add(camera);
    // cameraGroup.add(floor);
    // cameraGroup.add(floorBody);
    
    // Controls
    const controls = new THREE.OrbitControls(camera, canvas)
    controls.enableDamping = true
    controls.dampingFactor = 0.25; // Facteur de lissage des mouvements

    
    // Renderer
    const renderer = new THREE.WebGLRenderer({
        canvas: canvas
    })
    renderer.shadowMap.enabled = true
    renderer.shadowMap.type = THREE.PCFSoftShadowMap
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
    
    /**
     * Animate
     */

    let isAnimating = false;


    
function transitionCamera(duration = 8000) {
    if (isAnimating) return;
    isAnimating = true;

    // 1. Positions et rotations initiales
    const startPosition = camera.position.clone();
    const startRotation = camera.rotation.clone();
    
    // 2. Nouveaux paramètres exagérés
    const targetRotationX = startRotation.x + Math.PI * 3; // Rotation verticale extrême
    const zoomOutDistance = -150; // Distance de recul
    const skyHeight = 1000; // Hauteur du point à regarder (valeur très haute)

    const startTime = performance.now();
    
    function animate(currentTime) {
        const elapsed = currentTime - startTime;
        const progress = Math.min(elapsed / duration, 1);
        const smoothProgress = easeInOutQuint(progress);

        // Rotation verticale exagérée
        camera.rotation.x = startRotation.x + (targetRotationX - startRotation.x) * smoothProgress;
        
        // Recul progressif
        camera.position.z = startPosition.z + zoomOutDistance * smoothProgress;
        
        // Point de regard qui monte vers le ciel
        const currentLookAtY = THREE.MathUtils.lerp(0, skyHeight, smoothProgress);
        camera.lookAt(new THREE.Vector3(0, currentLookAtY, 0));

        if (progress < 1) {
            requestAnimationFrame(animate);
        } else {
            isAnimating = false;
            // Orientation finale (presque verticale)
            camera.lookAt(new THREE.Vector3(0, skyHeight, 0));
        }
    }

    function easeInOutQuint(t) {
        return t < 0.5 ? 16 * t * t * t * t * t : 1 - Math.pow(-2 * t + 2, 5) / 2;
    }
    
    requestAnimationFrame(animate);
}
    // Déclenche l'animation en appuyant sur la touche 'T'
    document.addEventListener('keydown', (event) => {
        if (event.key === 't' && !isAnimating) {
            toggleCameraControls(false);
            transitionCamera()
        }
    });


// ////////////////////////////////////
// //######## ####  ######  ##    ## //
// //   ##     ##  ##    ## ##   ##  //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##       #####    //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##    ## ##   ##  //
// //   ##    ####  ######  ##    ## //
// ////////////////////////////////////

// Variable pour contrôler l'état des mouvements de caméra
const targetRotation = new THREE.Vector3();

let cameraControlsEnabled = true;

function toggleCameraControls(enable) {
    if (controls) { // Assurez-vous que 'controls' est bien votre instance OrbitControls
        controls.enabled = enable;
    }
    cameraControlsEnabled = enable;
}

const clock = new THREE.Clock()
let oldElapsedTime = 0
// Modifiez votre boucle tick comme ceci :
const tick = () => {
    const elapsedTime = clock.getElapsedTime()
    const deltaTime = elapsedTime - oldElapsedTime
    oldElapsedTime = elapsedTime

    if (cameraControlsEnabled) {
        controls.update();
    }

    if (!isAnimating && cameraControlsEnabled) { // Ajout de la condition cameraControlsEnabled
        cameraGroup.rotation.x += (targetRotation.x - cameraGroup.rotation.x) * 0.001;
        cameraGroup.rotation.y += (targetRotation.y - cameraGroup.rotation.y) * 0.03;
        cameraGroup.rotation.z += (targetRotation.z - cameraGroup.rotation.z) * 0.03;
    }

    // ... le reste de votre fonction tick reste inchangé ...
    world.step(1 / 60, deltaTime, 3);

 
    spheres.forEach(({ sphere, sphereBody }) => {
        sphere.position.copy(sphereBody.position);
        sphere.quaternion.copy(sphereBody.quaternion);

        if (sphereBody.position.y < 0.6) {
            const randomDrift = new CANNON.Vec3(
                (Math.random() - 0.05) * 0.02,
                0,
                (Math.random() - 0.05) * 0.02
            );
            sphereBody.velocity.vadd(randomDrift, sphereBody.velocity);
        }
    });

    world.bodies.forEach(body => {
        if (body.shapes[0] instanceof CANNON.Sphere) {
            const velocity = body.velocity.length();
            if (body.position.y < 0.6 && velocity < 0.05) {
                body.timeAtRest = (body.timeAtRest || 0) + deltaTime;
                if (body.timeAtRest > 1) {
                    body.velocity.y = 0;
                    body.angularVelocity.set(0, 0, 0);
                }
            } else {
                body.timeAtRest = 0;
            }
        }
    });

    renderer.render(scene, camera);
    window.requestAnimationFrame(tick);
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

// Sizes
// const sizes = 
// {
//     width: window.innerWidth,
//     height: window.innerHeight
// }

window.addEventListener('resize', () =>
    {
        // Update sizes
        sizes.width = window.innerWidth
        sizes.height = window.innerHeight
    
        // Update camera
        camera.aspect = sizes.width / sizes.height
        camera.updateProjectionMatrix()
    
        // Update renderer
        renderer.setSize(sizes.width, sizes.height)
        renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
    })
    
    
    const mouse = new THREE.Vector2();
    window.addEventListener('mousemove', (event) => {
        if (!isAnimating) {  // Si l'animation n'est pas en cours, on laisse le mouvement de souris agir
            mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
            mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;
    
            targetRotation.y = mouse.x * 0.2;
            targetRotation.x = mouse.y * 0.2;
            targetRotation.z = mouse.x * -0.1;
        }
    });

// 2. Gestion du bouton de transition
const bouton_start = document.querySelectorAll('.start_transition');
bouton_start.forEach(bouton => {
    bouton.addEventListener('click', function() {
        if (!isAnimating) {
            // Stop la génération de sphères
            console.log("Création de sphères stoppée");
            
            clearInterval(sphereInterval);
            toggleCameraControls(false);
            transitionCamera();
        }  
    });
});

    window.addEventListener('mousemove', (event) => {
        if (!isAnimating) {   // Si pas d'animation, on laisse le mouvement agir
            mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
            mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;
    
            targetRotation.y = mouse.x * 0.2;
            targetRotation.x = mouse.y * 0.2;
            targetRotation.z = mouse.x * -0.1;
        }
    });
    
    
const boutons = document.querySelectorAll('.transition1');

boutons.forEach(bouton => 
{
    bouton.addEventListener('click', function() 
    {
        console.log("grosprout")

    });
})
    
//pas oublier de remove element d avant apres transition
