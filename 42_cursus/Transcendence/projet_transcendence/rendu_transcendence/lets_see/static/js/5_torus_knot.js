import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene();

// Sizes
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
};

// Camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
camera.position.set(0, 0, 5); // Placer la caméra au centre du torus knot
camera.lookAt(0, 0, 0); // Oriente la caméra vers l'intérieur du tunnel
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true
});
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));




// // Tunnel - Torus Knot Geometry
// const geometry = new THREE.TorusKnotGeometry(5, 1, 100, 16); // Création de la géométrie
// const material = new THREE.MeshBasicMaterial({
//     color: 0x0000ff, // Bleu
//     wireframe: true, // En wireframe
//     side: THREE.DoubleSide // Voir les deux côtés


// Tunnel - Torus Knot Geometry
const geometry = new THREE.TorusKnotGeometry(5, 1, 100, 16); 
const material = new THREE.MeshBasicMaterial({
    color: 0x0000ff, 
    wireframe: true, 
    side: THREE.DoubleSide 
});
const torusKnot = new THREE.Mesh(geometry, material);
scene.add(torusKnot);

// Animate
const clock = new THREE.Clock();
const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    
    const radius = 6;
    const angle = elapsedTime * 0.01;

   
    camera.position.x = Math.sin(angle) * radius;
    camera.position.y = Math.cos(angle) * radius;
    camera.position.z = angle * 0.5; 

  
    camera.lookAt(0, 0, 0);

    // Rendu
    renderer.render(scene, camera);


    window.requestAnimationFrame(tick);
};

// Resize handler
window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
});

// Lancer l'animation
tick();
