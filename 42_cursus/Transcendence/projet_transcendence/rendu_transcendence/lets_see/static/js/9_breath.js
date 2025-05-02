export function initialize() {
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
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
camera.position.z = 5; // Position plus proche de la scène
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.shadowMap.enabled = true; // Enable shadow maps

// Resize Handler
const resizeHandler = () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
};
window.addEventListener('resize', resizeHandler);

// Add Lights
const ambientLight = new THREE.AmbientLight(0x404040, 1); // Soft light
scene.add(ambientLight);

const directionalLight = new THREE.DirectionalLight(0xffffff, 1); // Main light source
directionalLight.position.set(5, 5, 5); // Position the light
directionalLight.castShadow = true; // Enable shadow
scene.add(directionalLight);

// Create Sphere from Small Cubes
const group = new THREE.Group();
const cubeGeometry = new THREE.BoxGeometry(0.3, 0.3, 0.3); // Reduced cube size
const cubeMaterial = new THREE.MeshStandardMaterial({ color: 0xff0000 }); // Red color, standard material to support shading
const particleCount = 300; // Increased number of cubes
const particles = [];

for (let i = 0; i < particleCount; i++) {
    const cube = new THREE.Mesh(cubeGeometry, cubeMaterial);

    // Position on a sphere
    const phi = Math.acos(2 * Math.random() - 1);
    const theta = 2 * Math.PI * Math.random();

    const radius = 2;
    const x = radius * Math.sin(phi) * Math.cos(theta);
    const y = radius * Math.sin(phi) * Math.sin(theta);
    const z = radius * Math.cos(phi);

    cube.userData.originalPosition = new THREE.Vector3(x, y, z);
    cube.position.copy(cube.userData.originalPosition);
    cube.castShadow = true; // Enable cube shadow
    cube.receiveShadow = true; // Enable cube shadow on the ground
    group.add(cube);
    particles.push(cube);
}

scene.add(group);

// Clock
const clock = new THREE.Clock();

// Mouse tracking for camera movement
const mouse = { x: 0, y: 0 };
const target = { x: 0, y: 0 };

const mouseMoveHandler = (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;  // from -1 to +1
    mouse.y = -(event.clientY / sizes.height - 0.5) * 2; // from -1 to +1
};
window.addEventListener('mousemove', mouseMoveHandler);

// Animate
const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    // Smooth interpolation for camera movement
    target.x += (mouse.x - target.x) * 0.1; // Slower and smoother movement
    target.y += (mouse.y - target.y) * 0.1;

    // Adjust the camera position with a fisheye effect (larger movement)
    const radius = 5;
    const angleX = target.x * Math.PI;            // Horizontal rotation
    const angleY = target.y * Math.PI / 4;        // Vertical tilt limit

    camera.position.x = radius * Math.sin(angleX);
    camera.position.z = radius * Math.cos(angleX);
    camera.position.y = radius * Math.sin(angleY);
    camera.lookAt(0, 0, 0);

    // Sphérique breathing effect on cubes with easing and light acceleration
    particles.forEach(particle => {
        const original = particle.userData.originalPosition;

        // Breathing effect with slower easing (even more slow)
        const scale = 1 + Math.sin(elapsedTime * 0.1) * 1.5; // Slower and more ample

        // Adding slight acceleration and easing for smoother return movement
        const timeFactor = Math.pow(Math.abs(Math.sin(elapsedTime * 0.2)), 2.5); // Further reduced speed and acceleration
        const amplitude = scale * timeFactor;

        particle.position.copy(original.clone().multiplyScalar(amplitude));
    });

    // Render scene
    renderer.render(scene, camera);

    // Next frame
    window.animationFrameId = window.requestAnimationFrame(tick);
};

tick();

return function cleanup() {
    console.log("cleanup 9_breath.js");
    
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
    if (cubeGeometry) {
        cubeGeometry.dispose();
    }
    
    if (cubeMaterial) {
        cubeMaterial.dispose();
    }
    
    // Remove event listeners
    window.removeEventListener('resize', resizeHandler);
    window.removeEventListener('mousemove', mouseMoveHandler);
    
    // Stop animation frame
    if (window.animationFrameId) {
        cancelAnimationFrame(window.animationFrameId);
    }
};
}

window.currentModuleCleanup = initialize();
