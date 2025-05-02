

import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

// 1. Initialisation
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// 2. Ajout d'un cube pour visualiser
const geometry = new THREE.BoxGeometry();
const material = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
const cube = new THREE.Mesh(geometry, material);
scene.add(cube);
camera.position.z = 5;
const world = new CANNON.World()

// 3. OrbitControls (test ici)
const controls = new THREE.OrbitControls(camera, renderer.domElement);
controls.enableDamping = true; // Effet fluide
controls.dampingFactor = 0.05;

// 4. Animation
function animate() {
    requestAnimationFrame(animate);
    controls.update(); // Nécessaire si damping activé
    renderer.render(scene, camera);
}
animate();
