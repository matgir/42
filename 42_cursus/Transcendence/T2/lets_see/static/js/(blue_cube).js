import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

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

// Resize handler
window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
});

// Mouse interaction
const mouse = { x: 0, y: 0 };
const target = { x: 0, y: 0 };

window.addEventListener('mousemove', (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 1;
    mouse.y = -(event.clientY / sizes.height - 0.5) * 1;
});

// Create Rubik-like cubes
const cubes = [];
const cubeSize = 9;
const spacing = 14;


const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize);
const edges = new THREE.EdgesGeometry(geometry); // Crée les arêtes du cube
const lineMaterial = new THREE.LineBasicMaterial({ color: 0x0030FF }); // Couleur des arêtes




for (let x = -1; x <= 1; x++) {
    for (let y = -1; y <= 1; y++) {
        for (let z = -1; z <= 1; z++) {
            const cube = new THREE.LineSegments(edges, lineMaterial); 


            cube.userData.basePosition = new THREE.Vector3(x * spacing, y * spacing, z * spacing);
            cube.position.copy(cube.userData.basePosition);
            scene.add(cube);
            cubes.push(cube);
        }
    }
}


// Add ambient light
const ambientLight = new THREE.AmbientLight(0x404040, 0.5);  // Light color and intensity
scene.add(ambientLight);



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
    window.requestAnimationFrame(tick);
};

tick();



