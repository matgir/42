import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

const canvas = document.querySelector('canvas.webgl');
const scene = new THREE.Scene();
scene.background = new THREE.Color('#000000');  // Background simulating the aquarium

// Camera setup
const sizes = { width: window.innerWidth, height: window.innerHeight };
const camera = new THREE.PerspectiveCamera(50, sizes.width / sizes.height, 0.1, 100);
camera.position.set(0, 0, 8);
scene.add(camera);

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas, antialias: true });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
});

scene.add(new THREE.AmbientLight(0xffffff, 0.8));
const light = new THREE.DirectionalLight(0xffffff, 0.5);
light.position.set(5, 5, 5);
scene.add(light);

// Cannon
const world = new CANNON.World({ gravity: new CANNON.Vec3(0, -0.5, 0) });  // Lower gravity for a slower fall
const defaultMaterial = new CANNON.Material("viscousMaterial");
const contactMaterial = new CANNON.ContactMaterial(defaultMaterial, defaultMaterial, {
    friction: 0.3,
    restitution: 0.4  // Soft bounces for a smooth effect
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

const MAX_BALLS = 50;

// Function to create and drop a ball
function createBall() {
    const isGreen = Math.random() < 0.08;  // 10% chance for a green ball
    const color = isGreen ? 0xFFF000 : 0x0000FF;  // Green or Blue color

    const sphereMaterial = new THREE.MeshStandardMaterial({ 
        color: color, 
        roughness: 1, 
        opacity: 1 , 
        wireframe : true
    });

    const mesh = new THREE.Mesh(sphereGeometry, sphereMaterial);
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
setInterval(createBall, 1000);

// Ball evacuation logic (when pressing 'A')
let isEvacuating = false;
let evacuatedBalls = 0;
const moveSpeed = 0.05; // Speed at which balls move when the "door" opens

function evacuateBalls() {
    if (evacuatedBalls < MAX_BALLS) {
        for (let i = 0; i < spheres.length; i++) {
            const body = bodies[i];
            const mesh = spheres[i];

            if (body.position.y < -sizes.height / 100 || Math.abs(body.position.x) > 6) {
                // Evacuate the ball by resetting it
                body.position.set(
                    (Math.random() - 0.5) * 6,
                    Math.random() * 5 + 3,
                    0
                );
                body.velocity.set(0, -0.1, 0);
                evacuatedBalls++;
            }
        }
    }
}

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

// Tick
const clock = new THREE.Clock();

function tick() {
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
    requestAnimationFrame(tick);
}
tick();
