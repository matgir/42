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
camera.position.z = 2.4;
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Mouse Tracking Controls (ultra soft)
const mouse = { x: 0, y: 0 };
const target = { x: 0, y: 0 };

const mouseMoveHandler = (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;
    mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
};
window.addEventListener('mousemove', mouseMoveHandler);

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

// Particle Torus Geometry
const particleCount = 5000;
const positions = new Float32Array(particleCount * 3);
const originalAngles = [];

const r0 = 1.5;
const loopDuration = 20;

for (let i = 0; i < particleCount; i++) {
    const angle = Math.random() * Math.PI * 2;
    const tubeAngle = Math.random() * Math.PI * 2;
    originalAngles.push({ angle, tubeAngle });
}

const geometry = new THREE.BufferGeometry();
geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));

const material = new THREE.PointsMaterial({ color: 0x0000FF, size: 0.007 });
const particles = new THREE.Points(geometry, material);
scene.add(particles);

// Clock and Animation
const clock = new THREE.Clock();

const tick = () => {
    const elapsedTime = clock.getElapsedTime();
    const t = (elapsedTime % loopDuration) / loopDuration * Math.PI * 2;
    const dynamicRadius = r0 + 0.3 * Math.sin(t);
    const dynamicTube = 0.6 + 0.2 * Math.cos(t);

    // Smooth camera motion (very very soft)
    target.x += (mouse.x - target.x) * 0.01;
    target.y += (mouse.y - target.y) * 0.01;

    const radius = 2.4;
    const angleX = target.x * Math.PI * 0.4;
    const angleY = target.y * Math.PI * 0.15;

    camera.position.x = radius * Math.sin(angleX);
    camera.position.z = radius * Math.cos(angleX);
    camera.position.y = radius * Math.sin(angleY);

    camera.lookAt(0, 0, 0);

    const positions = geometry.attributes.position.array;
    for (let i = 0; i < particleCount; i++) {
        const original = originalAngles[i];

        const inwardSpiral = 0.005 * elapsedTime;
        const spiralTubeAngle = original.tubeAngle + inwardSpiral;

        const r = dynamicRadius + dynamicTube * Math.cos(spiralTubeAngle);
        const x = r * Math.cos(original.angle);
        const y = r * Math.sin(original.angle);
        const z = dynamicTube * Math.sin(spiralTubeAngle);

        positions[i * 3] = x;
        positions[i * 3 + 1] = y;
        positions[i * 3 + 2] = z;
    }
    geometry.attributes.position.needsUpdate = true;

    // Donut style rotation (very slow)
    particles.rotation.x += 0.0001;
    particles.rotation.y += 0.00015;
    particles.rotation.z += 0.00005;

    renderer.render(scene, camera);
    window.animationFrameId = requestAnimationFrame(tick);
};

tick();

return function cleanup() {
    console.log("cleanup 8_point_donut.js");
    
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
        material.dispose();
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
