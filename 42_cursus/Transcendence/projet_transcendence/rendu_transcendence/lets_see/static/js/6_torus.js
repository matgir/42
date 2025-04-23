
const canvas = document.querySelector('canvas.webgl');

const scene = new THREE.Scene();


const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}


const mouse = { x: 0, y: 0 };
const target = { x: 0, y: 0 };

window.addEventListener('mousemove', (event) => {
    mouse.x = (event.clientX / sizes.width - 0.5) * 2;
    mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
});

// Camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
camera.position.z =  Math.PI / 2;
camera.position.y =  Math.PI / 2;
camera.position.x = Math.PI / 4;


scene.add(camera);


const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true
});
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
});

// Clock
const clock = new THREE.Clock();


const springLength = 3;
const coilCount = 20;
const springRadius = 0.8;

const springGeometry = new THREE.CylinderGeometry(springRadius, springRadius, springLength, 100, coilCount, true);
const springMaterial = new THREE.MeshBasicMaterial({
    color: 0x700000,
    opacity: 0.0,
    transparent: true
});
const spring = new THREE.Mesh(springGeometry, springMaterial);
scene.add(spring);

// Rings
const ringRadius = 0.7;
const ringGeometry = new THREE.TorusGeometry(ringRadius, 0.4, 35, 35);
const ringMaterial =  new THREE.MeshBasicMaterial({ 
    // color: 0x9E4AFF,  
    // color: 0xB29DFF,  
    color: 0xCCC3FF,  

    wireframe: true,
    side: THREE.BackSide 

})
const ringMaterial_blue = new THREE.MeshBasicMaterial({ color: 0x0000FF, wireframe: true });


const ring1 = new THREE.Mesh(ringGeometry, ringMaterial);
const ring2 = new THREE.Mesh(ringGeometry, ringMaterial_blue);
scene.add(ring1);
scene.add(ring2);

// Animation loop
const speed = 0.001;
const pulseSpeed = 2;

const animate = () => {
    const elapsedTime = clock.getElapsedTime();

    // // Smooth mouse-driven camera interpolation
    // target.x += (mouse.x - target.x) * 0.005;
    // target.y += (mouse.y - target.y) * 0.05;

     // Smooth interpolation
    //  target.x += (mouse.x - target.x) * 0.05;
    //  target.y += (mouse.y - target.y) * 0.05;

    // target.x + 3;
    // target.y += (mouse.y - target.y) * 0.05;

    // const radius = 3;
    // const angleX = target.x * Math.PI;
    // const angleY = target.y * Math.PI / 4;

    // camera.position.x = radius * Math.sin(angleX);
    // camera.position.z = radius * Math.cos(angleX);
    // camera.position.y = radius * Math.sin(angleY);
    camera.lookAt(0, 0, 0);

    // Spring pulse
    const pulse = Math.sin(elapsedTime * pulseSpeed);
    spring.scale.y = 1 + pulse * 0.3;

    // Shared rotation angle
    const rotationAngle = elapsedTime * speed * Math.PI * 2 * coilCount;

    // Ring 1 - normal rotation
    const x1 = springRadius * Math.cos(rotationAngle);
    const y1 = -springLength / 2 + 0.3;
    const z1 = springRadius * Math.sin(rotationAngle);
    ring1.position.set(x1, y1, z1);
    ring1.rotation.set(rotationAngle, 1, 0.5);

    // Ring 2 - inverse rotation
    const x2 = springRadius * Math.cos(-rotationAngle);
    const y2 = -springLength / 2 + 2.0;  // un peu au-dessus
    const z2 = springRadius * Math.sin(-rotationAngle);
    ring2.position.set(x2, y2, z2);
    ring2.rotation.set(-rotationAngle, 1, 0.5);

    // Render
    renderer.render(scene, camera);

    // Next frame
    window.requestAnimationFrame(animate);
};

animate();
