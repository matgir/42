function initialize() {
// Canvas
const canvas = document.querySelector('canvas.webgl');
if (!canvas) {
    console.error("Canvas element not found");
    return;
}

// Scene
const scene = new THREE.Scene();

// Object
const geometry = new THREE.BoxGeometry(1, 1, 1);
const material = new THREE.MeshBasicMaterial({ color: 0xff00FF });
const mesh = new THREE.Mesh(geometry, material);
scene.add(mesh);

// Sizes
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
};

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

// Camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
camera.position.z = 3;
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
});
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Mouse tracking
const mouse = {
    x: 0,
    y: 0
};

const target = {
    x: 0,
    y: 0
};

const mouseMoveHandler = (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;  // de -1 à +1
    mouse.y = -(event.clientY / sizes.height - 0.5) * 2; // de -1 à +1
};
window.addEventListener('mousemove', mouseMoveHandler);

// Animate
const clock = new THREE.Clock();

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
    window.animationFrameId = window.requestAnimationFrame(tick);
};

tick();

return function cleanup() {
    console.log("cleanup testeur.js");
    
    // Only remove our specific canvas
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
