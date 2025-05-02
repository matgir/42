export function initialize() {
console.log("initialize");
// Initialisation de la scène et de la caméra
const canvas = document.querySelector('canvas.webgl');
const scene = new THREE.Scene();

// Paramètres de taille de la fenêtre
let sizes = { width: window.innerWidth, height: window.innerHeight };

// Création de la caméra
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
camera.position.z = 5;

// Création du renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Mise à jour de la taille de la fenêtre
const resizeHandler = () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
};
window.addEventListener('resize', resizeHandler);

// Création d'une lumière douce (lumière ambiante)
const ambientLight = new THREE.AmbientLight(0xffffff, 0.5); // Couleur blanche, intensité de 0.5
scene.add(ambientLight);

// Création d'une lumière directionnelle douce
const directionalLight = new THREE.DirectionalLight(0xf000ff, 1); // Couleur blanche, intensité de 1
directionalLight.position.set(5, 5, 5); // Position de la lumière
directionalLight.castShadow = true; // Permet à cette lumière de générer des ombres
scene.add(directionalLight);

// Création d'une lumière directionnelle additionnelle pour éclairer de l'autre côté
const directionalLight2 = new THREE.DirectionalLight(0xffffff, 0.8); // Moins intense pour adoucir l'ombre
directionalLight2.position.set(-5, -5, -5);
directionalLight2.castShadow = true;
scene.add(directionalLight2);

// Activer les ombres pour le renderer
renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap; // Type d'ombre douce

// Création d'un plan subdivisé
const geometry = new THREE.PlaneGeometry(20, 20, 30, 30); // 100x100 segments
const material = new THREE.MeshBasicMaterial({ color: 0x0000AA, wireframe: true });
const plane = new THREE.Mesh(geometry, material);
scene.add(plane);
plane.rotation.x = Math.PI * 3;

// Activer les ombres pour le plan
plane.castShadow = true; // Le plan va cast des ombres
plane.receiveShadow = true; // Le plan va recevoir des ombres

// Créer un sol pour recevoir les ombres (optionnel, si tu veux que l'ombre soit projetée sur quelque chose)
const groundGeometry = new THREE.PlaneGeometry(100, 100);
const groundMaterial = new THREE.ShadowMaterial({ opacity: 0.8 }); // Ombre douce
const ground = new THREE.Mesh(groundGeometry, groundMaterial);
ground.rotation.x = -Math.PI / 2; // Rotation du sol pour qu'il soit horizontal
ground.position.y = -2; // Positionner le sol sous le plan
ground.receiveShadow = true; // Le sol reçoit des ombres
scene.add(ground);

// Fonction d'animation
const clock = new THREE.Clock();
const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    // Animation des vertices pour créer un effet de vague organique
    const position = plane.geometry.attributes.position;
    const amplitude = 0.2; // Amplitude des vagues

    for (let i = 0; i < position.count; i++) {
        const x = position.getX(i);
        const y = position.getY(i);

        // Création des vagues sinusoïdales avec des offsets différents
        const waveX = Math.sin(x * 0.5 + elapsedTime * 0.8) * amplitude; // Vague sur l'axe X
        const waveY = Math.sin(y * 0.5 + elapsedTime * 0.7) * amplitude; // Vague sur l'axe Y

        position.setZ(i, waveX + waveY); // Déformation de la position Z
    }

    // Mise à jour des attributs de géométrie pour appliquer les changements
    position.needsUpdate = true;

    // Rendu de la scène
    renderer.render(scene, camera);

    // Requête pour l'animation suivante
    window.animationFrameId = window.requestAnimationFrame(tick);
};

// Lancer l'animation
tick();

return function cleanup() {
    console.log("cleanup choose_your_perso.js");
    
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
    
    if (groundGeometry) {
        groundGeometry.dispose();
    }
    
    if (groundMaterial) {
        groundMaterial.dispose();
    }
    
    // Remove event listeners
    window.removeEventListener('resize', resizeHandler);
    
    // Stop animation frame
    if (window.animationFrameId) {
        cancelAnimationFrame(window.animationFrameId);
    }
}
}

window.currentModuleCleanup = initialize();
