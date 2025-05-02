export function initialize() {
const canvas = document.querySelector('canvas.webgl');
const scene = new THREE.Scene();
scene.background = new THREE.Color('#000000');  // Background simulating the aquarium

const MAX_BALLS = 100;


const creditsContainer = document.querySelector('.credits');
const totalHeight = creditsContainer.scrollHeight;
const viewportHeight = window.innerHeight;

creditsContainer.style.animationDuration = `${(totalHeight + viewportHeight) / 50}s`;


// Camera setup
const sizes = { width: window.innerWidth, height: window.innerHeight };
const camera = new THREE.PerspectiveCamera(50, sizes.width / sizes.height, 0.1, 100);
camera.position.set(0, 0, 8);
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas, antialias: true });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Resize handler
const resizeHandler = () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
};
window.addEventListener('resize', resizeHandler);

scene.add(new THREE.AmbientLight(0xffffff, 0.8));
const light = new THREE.DirectionalLight(0xffffff, 0.5);
light.position.set(5, 5, 5);
scene.add(light);

// Cannon
const world = new CANNON.World({ gravity: new CANNON.Vec3(0.02, -3, 0) });  
const defaultMaterial = new CANNON.Material("viscousMaterial");
const contactMaterial = new CANNON.ContactMaterial(defaultMaterial, defaultMaterial, {
    friction: 0.1,
    restitution: 0.63  // Soft bounces for a smooth effect
});
world.addContactMaterial(contactMaterial);

// Plane 
const glass = new CANNON.Body({
    shape: new CANNON.Plane(),
    material: defaultMaterial,
    position: new CANNON.Vec3(0, -3.7, 0),
    type: CANNON.Body.STATIC
});
glass.quaternion.setFromEuler(-Math.PI / 2, 0, 0);  // Flat plane
world.addBody(glass);

// Ball creation
const spheres = [];
const bodies = [];
const sphereGeometry = new THREE.SphereGeometry(0.4, 20, 20);




let balls_falled = 0;
// Function to create and drop a ball
function createBall() {
    if (balls_falled >= MAX_BALLS) return; // Ajout de cette condition

    balls_falled++;

    balls_falled++;
    const isGreen = Math.random() < 0.08;  // 10% chance for a green ball
    const color = isGreen ? 0xAA00FF : 0x0000FF;  // Green or Blue color

    // const sphereMaterial = new THREE.MeshStandardMaterial({ 
    //     color: color, 
    //     roughness: 1, 
    //     opacity: 1 , 
    //     wireframe : true
    // });

    // const sphereGeometry = new THREE.SphereGeometry(0.8, 15, 10);
    const edges = new THREE.EdgesGeometry(sphereGeometry);
    const sphereMaterial = new THREE.LineBasicMaterial({
        color: color ,  // Couleur des arêtes
        linewidth: 2       // Largeur des lignes
    });
    const mesh = new THREE.LineSegments(edges, sphereMaterial);
    mesh.castShadow = true;
    

    // const mesh = new THREE.Mesh(sphereGeometry, sphereMaterial);
    scene.add(mesh);

    const shape = new CANNON.Sphere(0.4);
    const body = new CANNON.Body({
        mass: 0.5,
        shape,
        material: defaultMaterial,
        position: new CANNON.Vec3(
            (Math.random() - 0.5) * 6, 
            Math.random() * 5 + 3,
            0
        )
    });
    body.velocity.set(0, -0.1, 0);
    world.addBody(body);
    spheres.push(mesh);
    bodies.push(body);
}

// Create a new ball every second
const createBallInterval = setInterval(createBall, 1000);

// Ball evacuation logic (when pressing 'A')

const moveSpeed = 0.05; // Speed at which balls move when the "door" opens



// Interaction with key "A" to move balls slowly to the right
let moveDoor = false;
let doorOpen = false;
function handleKeyPress(event) {
    if (event.key === "a" && !moveDoor) {
        moveDoor = true;
        doorOpen = !doorOpen;
    }
}

window.addEventListener('keydown', handleKeyPress);

// Ball movement when the door opens
function moveBalls() {
    if (doorOpen) {
        // Move balls slowly towards the right edge of the screen
        bodies.forEach((body) => {
            body.position.x += moveSpeed;
            if (body.position.x > sizes.width / 2) {
                body.position.x = sizes.width / 2;  // Prevent balls from going too far
            }
        });
    }
}


createBall();

// Tick
const clock = new THREE.Clock();

function tick() {
    // if(balls_falled >= 30)
        // return;
    const deltaTime = clock.getDelta();
    world.step(1 / 60, deltaTime);

    bodies.forEach((body, index) => {
        const mesh = spheres[index];

        // Move the balls if the "door" is open
        if (moveDoor) {
            moveBalls();
        }

        mesh.position.copy(body.position);
        mesh.quaternion.copy(body.quaternion);
    });

    renderer.render(scene, camera);
    window.animationFrameId = requestAnimationFrame(tick);
}
tick();

return function cleanup() {
    console.log("cleanup 4_fall.js");
    clearInterval(createBallInterval);
    
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
    if (sphereGeometry) {
        sphereGeometry.dispose();
    }
    
    // Remove event listeners
    window.removeEventListener('resize', resizeHandler);
    window.removeEventListener('keydown', handleKeyPress);
    
    // Remove physics bodies
    bodies.forEach(body => {
        world.removeBody(body);
    });
    
    // Stop animation frame
    if (window.animationFrameId) {
        cancelAnimationFrame(window.animationFrameId);
    }
}
}

window.currentModuleCleanup = initialize();
