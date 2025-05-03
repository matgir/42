// // Canvas
// const canvas = document.querySelector('canvas.webgl');

// // Scene
// const scene = new THREE.Scene();

// // Sizes
// const sizes = {
//     width: window.innerWidth,
//     height: window.innerHeight
// }

// // Camera
// const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
// camera.position.z = 8;
// scene.add(camera);

// // Renderer
// const renderer = new THREE.WebGLRenderer({
//     canvas: canvas,
//     antialias: true
// });
// renderer.setSize(sizes.width, sizes.height);
// renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// // Resize handler
// window.addEventListener('resize', () => {
//     sizes.width = window.innerWidth;
//     sizes.height = window.innerHeight;
//     camera.aspect = sizes.width / sizes.height;
//     camera.updateProjectionMatrix();
//     renderer.setSize(sizes.width, sizes.height);
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
// });

// // Mouse interaction
// const mouse = { x: 0, y: 0 };
// const target = { x: 0, y: 0 };

// window.addEventListener('mousemove', (event) => {
//     mouse.x = (event.clientX / sizes.width - 0.5) * 2;
//     mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
// });

// // Create Rubik-like cubes
// const cubes = [];
// const cubeSize = 0.9;
// const spacing = 1.05;

// const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize , 17 ,17 ,17 );
// const material = new THREE.MeshBasicMaterial({color: 0xffffff  ,wireframe: true });

// // const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize);
// // const edges = new THREE.EdgesGeometry(geometry); // Crée les arêtes du cube
// // const lineMaterial = new THREE.LineBasicMaterial({ color: 0xffffff }); // Couleur des arêtes
// // scene.add(wireframe);



// for (let x = -1; x <= 1; x++) {
//     for (let y = -1; y <= 1; y++) {
//         for (let z = -1; z <= 1; z++) {
//             // const cube = new THREE.LineSegments(edges, lineMaterial); 

//             const cube = new THREE.Mesh(geometry, material);
//             cube.userData.basePosition = new THREE.Vector3(x * spacing, y * spacing, z * spacing);
//             cube.position.copy(cube.userData.basePosition);
//             scene.add(cube);
//             cubes.push(cube);
//         }
//     }
// }


// // Add ambient light
// const ambientLight = new THREE.AmbientLight(0x404040, 0.5);  // Light color and intensity
// scene.add(ambientLight);



// // Animate
// const clock = new THREE.Clock();

// const tick = () => {
//     const elapsedTime = clock.getElapsedTime();

//     // Smooth interpolation for camera
//     target.x += (mouse.x - target.x) * 0.05;
//     target.y += (mouse.y - target.y) * 0.05;

//     const radius = 6;  // élargir pour tout voir
//     const angleX = target.x * Math.PI;
//     const angleY = target.y * Math.PI / 4;

//     camera.position.x = radius * Math.sin(angleX);
//     camera.position.z = radius * Math.cos(angleX);
//     camera.position.y = radius * Math.sin(angleY);
//     camera.lookAt(0, 0, 0);

//     // Rubik cubes smooth motion
//     cubes.forEach((cube, index) => {
//         const frequency = 0.8;
//         const amplitude = 0.2;
//         cube.position.x = cube.userData.basePosition.x + Math.sin(elapsedTime * frequency + index) * amplitude;
//         cube.position.y = cube.userData.basePosition.y + Math.cos(elapsedTime * frequency + index) * amplitude;
//         cube.position.z = cube.userData.basePosition.z + Math.sin(elapsedTime * frequency + index * 0.5) * amplitude;
//     });

//     renderer.render(scene, camera);
//     window.requestAnimationFrame(tick);
// };

// tick();

function initialize() {

// Add form action setting based on mode parameter
// Set form action based on mode parameter
const setFormAction = () => {
    const form = document.getElementById('game-settings-form');
    if (!form) return;
    
    // Use the SPA router's URL params if available, otherwise use normal URL parsing
    let params;
    if (window.getURLParams) {
        params = window.getURLParams();
    } else {
        params = new URLSearchParams(window.location.search);
    }
    
    const mode = params.get('mode');
    console.log("mode", mode);
    
    if (mode === 'duel') {
        form.action = '/duel/';
    } else if (mode === 'tournois') {
        form.action = '/tournois/';
    }
    
    console.log('Form action set to:', form.action);
};

// Call this immediately and also when DOM is loaded to make sure it works
setFormAction();
document.addEventListener('DOMContentLoaded', setFormAction);

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Sizes
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

// Camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
camera.position.z = 8;
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true
});
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.shadowMap.enabled = true; // Activer les ombres dans le renderer

// Resize handler
const resizeHandler = () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
};
window.addEventListener('resize', resizeHandler);

// Mouse interaction
const mouse = { x: 0, y: 0 };
const target = { x: 0, y: 0 };

const mouseMoveHandler = (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;
    mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
};
window.addEventListener('mousemove', mouseMoveHandler);

// Create Rubik-like cubes
const cubes = [];
const cubeSize = .9;
const spacing = 1.05;

const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize , 8 ,8 , 8);
const material = new THREE.MeshStandardMaterial({color: 0x0000FF , wireframe: false

}); // MeshStandardMaterial supporte les ombres



// Create cubes and add to scene
for (let x = -1; x <= 1; x++) {
    for (let y = -1; y <= 1; y++) {
        for (let z = -1; z <= 1; z++) {
            const cube = new THREE.Mesh(geometry, material);
            cube.userData.basePosition = new THREE.Vector3(x * spacing, y * spacing, z * spacing);
            cube.position.copy(cube.userData.basePosition);
            cube.castShadow = true; // Les cubes vont lancer des ombres
            cube.receiveShadow = true; // Les cubes peuvent recevoir des ombres
            scene.add(cube);
            cubes.push(cube);
        }
    }
}

// Add directional light with shadows
const directionalLight = new THREE.DirectionalLight(0xCCCCFF, 1);
directionalLight.position.set(3, -3, -3); // Position de la lumière
directionalLight.castShadow = true; // La lumière va projeter des ombres
directionalLight.shadow.mapSize.width = 1024;  // Qualité de l'ombre
directionalLight.shadow.mapSize.height = 1024;
directionalLight.shadow.camera.near = 0.5;
directionalLight.shadow.camera.far = 10;
directionalLight.shadow.camera.left = -5;
directionalLight.shadow.camera.right = 5;
directionalLight.shadow.camera.top = 5;
directionalLight.shadow.camera.bottom = -5;
scene.add(directionalLight);

// Lumière directionnelle de retour (backlight)
const backLight = new THREE.DirectionalLight(0x00FFF0, 1);  // Lumière douce (intensité 0.6)
backLight.position.set(3, 5, 1); // Positionnée derrière et légèrement au-dessus
backLight.castShadow = true;  // Active les ombres

// Ajouter une lumière ambiante faible pour adoucir l'effet
const ambientLight = new THREE.AmbientLight(0x404040, 0.2); // Lumière ambiante douce (intensité 0.2)
scene.add(ambientLight);

// Ajuste la caméra d'ombre pour la lumière directionnelle de retour
backLight.shadow.mapSize.width = 1024;
backLight.shadow.mapSize.height = 1024;
backLight.shadow.camera.near = 0.5;
backLight.shadow.camera.far = 10;
backLight.shadow.camera.left = -5;
backLight.shadow.camera.right = 5;
backLight.shadow.camera.top = 5;
backLight.shadow.camera.bottom = -5;

scene.add(backLight);

// Pour donner un effet d'éclat sur les bords, tu peux aussi ajouter une lumière ponctuelle douce
const pointLight = new THREE.PointLight(0xffffff, 0.4, 10);  // Faible intensité et portée
pointLight.position.set(0, 5, -5);  // Placée derrière la scène, légèrement au-dessus
scene.add(pointLight);


// Animate
const clock = new THREE.Clock();

const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    // Smooth interpolation for camera
    target.x += (mouse.x - target.x) * 0.05;
    target.y += (mouse.y - target.y) * 0.05;

    const radius = 6;  // élargir pour tout voir
    const angleX = target.x * Math.PI;
    const angleY = target.y * Math.PI / 4;

    camera.position.x = radius * Math.sin(angleX);
    camera.position.z = radius * Math.cos(angleX);
    camera.position.y = radius * Math.sin(angleY);
    camera.lookAt(0, 0, 0);

    // Rubik cubes smooth motion
    cubes.forEach((cube, index) => {
        const frequency = 0.8;
        const amplitude = 0.2;
        cube.position.x = cube.userData.basePosition.x + Math.sin(elapsedTime * frequency + index) * amplitude;
        cube.position.y = cube.userData.basePosition.y + Math.cos(elapsedTime * frequency + index) * amplitude;
        cube.position.z = cube.userData.basePosition.z + Math.sin(elapsedTime * frequency + index * 0.5) * amplitude;
    });

    renderer.render(scene, camera);
    window.animationFrameId = window.requestAnimationFrame(tick);
};

tick();

// Quand un bouton "color mode" est cliqué
document.querySelectorAll('input[name="color"]').forEach((input, index) => {
    input.addEventListener('change', () => {
      const mainContainer = document.querySelector('.settings-container');
  
      // Enlève les anciennes classes
      mainContainer.classList.remove('theme-1', 'theme-2', 'theme-3');
  
      // Ajoute la nouvelle classe selon l'index
      mainContainer.classList.add(`theme-${index + 1}`);
    });
  });
  

return function cleanup() {
    console.log("cleanup 3_blue_rubix.js");
    
    // Only remove our specific canvas
    const canvas = document.querySelector('canvas.webgl');
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
    
    // Dispose of geometries and materials explicitly
    if (geometry) {
        geometry.dispose();
    }
    
    if (material) {
        if (Array.isArray(material)) {
            material.forEach(mat => mat.dispose());
        } else {
            material.dispose();
        }
    }
    
    // Remove event listeners
    window.removeEventListener('resize', resizeHandler);
    window.removeEventListener('mousemove', mouseMoveHandler);
    
    // Stop animation frame
    if (window.animationFrameId) {
        cancelAnimationFrame(window.animationFrameId);
    }
}
}

window.currentModuleCleanup = initialize();
