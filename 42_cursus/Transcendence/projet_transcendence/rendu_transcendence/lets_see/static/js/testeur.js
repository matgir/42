import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

// tick();
// Canvas
const canvas = document.querySelector('canvas.webgl');

// Scene
const scene = new THREE.Scene()

// Object
const geometry = new THREE.BoxGeometry(1, 1, 1)
const material = new THREE.MeshBasicMaterial({ color: 0xff00FF })
const mesh = new THREE.Mesh(geometry, material)
scene.add(mesh)

// Sizes
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () => {
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

// Camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.z = 3
scene.add(camera)

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

// Mouse tracking
const mouse = {
    x: 0,
    y: 0
};

const target = {
    x: 0,
    y: 0
};

window.addEventListener('mousemove', (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;  // de -1 à +1
    mouse.y = - (event.clientY / sizes.height - 0.5) * 2; // de -1 à +1
});

// Animate
const clock = new THREE.Clock()

const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    // Smooth interpolation
    target.x += (mouse.x - target.x) * 0.05;
    target.y += (mouse.y - target.y) * 0.05;

    // Calculate polar coordinates for the camera
    const radius = 3;
    const angleX = target.x * Math.PI;            // horizontal rotation
    const angleY = target.y * Math.PI / 4;        // vertical tilt limit

    camera.position.x = radius * Math.sin(angleX);
    camera.position.z = radius * Math.cos(angleX);
    camera.position.y = radius * Math.sin(angleY);

    camera.lookAt(0, 0, 0);

    // Render
    renderer.render(scene, camera);

    // Next frame
    window.requestAnimationFrame(tick);
}

tick();
