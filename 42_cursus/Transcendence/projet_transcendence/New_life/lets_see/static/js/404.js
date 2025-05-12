


// let renderer;   

// const oldCanvas = document.querySelector('.webgl');
// if (oldCanvas) {
    // canvas.remove();
 

    export function initialize() {
        console.log("init avatar.js");
        
        function createScene() {
            let downloadDone = false;  // état pour bloquer après 1 clic
            
            // Supprimer l'ancien canvas s'il existe
            const oldCanvas = document.querySelector('.webgl');
            if (oldCanvas) {
                oldCanvas.remove();
            }
            
            // Créer et ajouter un nouveau canvas
            const canvas = document.createElement('canvas');
            canvas.classList.add('webgl');
            document.body.appendChild(canvas);
        
            // Créer le renderer
            const renderer = new THREE.WebGLRenderer({ canvas: canvas });
            renderer.setSize(800, 800);
            
            console.log("logsdvcv");             
        
            // Scene
            const scene = new THREE.Scene();
        
            //physics 
            const world = new CANNON.World();
            world.gravity.set(0, 0, 0);
        
            // Materials
            const defaultMaterial = new CANNON.Material('default');
            const defaultContactMaterial = new CANNON.ContactMaterial(
                defaultMaterial,
                defaultMaterial,
                {
                    friction: 0,
                    restitution: 1
                }
            );
            world.addContactMaterial(defaultContactMaterial);
            world.defaultContactMaterial = defaultContactMaterial;
        
 

// Geometry et Material des sphères
const sphereGeometry = new THREE.SphereGeometry(5, 10, 22);
const sphereMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.1,
    roughness: 0.1,
    wireframe: true,
    color: '#FFFFFF',
    side: THREE.DoubleSide,
});

// Geometry et Material des pupilles
const pupilGeometry = new THREE.SphereGeometry(1.2, 12, 12);
const pupilMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.1,
    roughness: 0.9,
    wireframe: false,
    color: '#000000',
    side: THREE.DoubleSide
});


const sourcilGeometry = new THREE.CylinderGeometry(0.5, 0.5, 3 + 2 * 0.5, 12, 4, true);



const sourcilMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.1,
    roughness: 0.1,
    wireframe: true,
    color: '#FFFFFF',
    side: THREE.DoubleSide,
});

const sourcil = new THREE.Mesh(sourcilGeometry,sourcilMaterial)
sourcil.scale.set(1.5,1.5,1.5)
sourcil.position.set(1.5, 2, 0); // placer au-dessus de l’œil droit
sourcil.rotation.z = Math.PI / 2.4; // inclinaison en diagonale (30°)
// scene.add(sourcil)
// Groupe principal
const spheresGroup = new THREE.Group();
scene.add(spheresGroup);

// Fonction pour créer un œil complet
function createEye(positionX) {
    const eyeGroup = new THREE.Group();

    const sphere = new THREE.Mesh(sphereGeometry, sphereMaterial);
    sphere.castShadow = true;
    sphere.scale.set(0.5, 0.5, 0.5);

    const pupil = new THREE.Mesh(pupilGeometry, pupilMaterial);
    pupil.castShadow = true;

    const safeDistance = 5 * 0.5 - 1.2 * 0.5 - 0.05; // rayon du globe - rayon pupille - marge
    pupil.position.set(0, 1, 2.2);

    eyeGroup.add(sphere);
    eyeGroup.add(pupil);
    eyeGroup.position.set(positionX, 0, -3);

    spheresGroup.add(eyeGroup);
    

    return { eyeGroup, pupil };
}

// Création des deux yeux symétriques
const rightEye = createEye(9);
const leftEye = createEye(-9);

// Fonction pour déplacer les yeux aléatoirement dans les limites
function randomizeEyes() {
    const eyePositionX = Math.random() * (9 - 3) + 3; // Valeur entre 3 et 9 pour la position X
    const eyePositionY = Math.random() * (2 - -4) + -4; // Valeur entre -4 et 2 pour la position Y
    const eyePositionZ = Math.random() * (1 - 1) + 1; // Z est fixé à 1 pour les deux yeux

    // Appliquer les nouvelles positions aux yeux
    rightEye.eyeGroup.position.set(eyePositionX, eyePositionY - 5, eyePositionZ);
    leftEye.eyeGroup.position.set(-eyePositionX, eyePositionY - 5, eyePositionZ);
}

// Appeler la fonction pour randomiser la position des yeux lors de la première initialisation de la scène
randomizeEyes();

function createSourcilAboveEye(eyeGroup, side = 'right') {
    // const sourcilGeometry = new THREE.CapsuleGeometry(5, 0.3, 4, 20);
    const sourcilGeometry = new THREE.CylinderGeometry(0.5, 0.5, 3 + 2 * 0.5, 12, 4, true);

    const sourcilMaterial = new THREE.MeshStandardMaterial({
        metalness: 0.1,
        roughness: 0.1,
        wireframe: true,
        color: '#FFFFFF',
        side: THREE.DoubleSide,
    });

    const sourcil = new THREE.Mesh(sourcilGeometry, sourcilMaterial);
    sourcil.scale.set(1.3, 1.3, 1.3);

    // Positionner au-dessus de l’œil avec un léger décalage
    sourcil.position.copy(eyeGroup.position);
    sourcil.position.y += 3.5; // au-dessus de l’œil
        // Décalage en X pour les écarter
        const horizontalOffset = 1;
        sourcil.position.x += (side === 'right') ? horizontalOffset : -horizontalOffset;
    
    
    sourcil.position.z -= 0.5; // léger recul

    // Inclinaison : droite ou gauche
    sourcil.rotation.z = (side === 'right') ? Math.PI / 2.6 : -Math.PI / 2.6;

    scene.add(sourcil);
}

// Créer les sourcils après que les yeux ont été placés
createSourcilAboveEye(rightEye.eyeGroup, 'right');
createSourcilAboveEye(leftEye.eyeGroup, 'left');
        
            // Particle parameters
            const params = {
                ringNumParticles: 600,
                ringRadius: 5.3,
                waveFrequency: 10,
                waveAmplitude: 0.5,
                hueMax: 300,
                size: 0.1,
            };
        
            function initRandomParams() {
                params.ringNumParticles = Math.floor(Math.random() * (1000 - 300 + 1)) + 300;
                params.ringRadius = Math.random() * (13 - 4) + 4;
                params.waveFrequency = Math.random() * (16 - 0.1) + 0.1;
                params.waveAmplitude = Math.random() * (4 - 0.1) + 0.1;
                params.hueMax = Math.floor(Math.random() * (360 - 100 + 1)) + 100;
                params.size = Math.random() * (0.25 - 0.18) + 0.16; 
            }
        
            initRandomParams();
        
            // Texture des particules
            const ringPointTexture = new THREE.TextureLoader().load('/static/particles/2b.png');
            let ringGeometry = new THREE.BufferGeometry();
        
            function generateParticles() {
                const count = params.ringNumParticles;
                const pos = [];
                const colors = [];
                const solidColor = new THREE.Color(0xffffff);
                const randomHue = Math.random();
                solidColor.setHSL(randomHue, 1, 0.5);
        
                for (let i = 0; i < params.ringNumParticles; i++) {
                    const angle = (i / params.ringNumParticles) * Math.PI * 2;
        
                    const wave = Math.sin(angle * params.waveFrequency) * params.waveAmplitude;
                    const radius = params.ringRadius + wave;
        
                    const y = Math.cos(angle) * radius;
                    const x = Math.sin(angle) * radius;
                    const z = 0;
        
                    let color;
                    if (params.ringNumParticles%3 == 0) {
                        color = solidColor;
                    } 
                    else if (params.ringNumParticles%4 == 0) {
                        const hue = (angle / (Math.PI * 2)) * 110;
                        color = new THREE.Color();
                        color.setHSL(hue / 15, 2, 0.39);
                        color.g = color.b;
                    }
                    else {
                        const hue = (angle / (Math.PI * 2)) * params.hueMax;
                        color = new THREE.Color();
                        color.setHSL(hue / 360, 1, 0.5);
                    }
        
                    colors.push(color.r, color.g, color.b, 1);
                    pos.push(x, y, z);
                }
        
                ringGeometry.setAttribute('position', new THREE.Float32BufferAttribute(pos, 3));
                ringGeometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 4));
            }
        
            function updateParticles() {
                generateParticles();
                ringGeometry.attributes.position.needsUpdate = true;
                ringGeometry.attributes.color.needsUpdate = true;
        
                ringGroup.children.forEach((ringClone) => {
                    ringClone.geometry.attributes.position.needsUpdate = true;
                    ringClone.geometry.attributes.color.needsUpdate = true;
                });
            }
        
            function updateParticleSize() {
                ringMaterial.size = params.size;
                ringMaterial.needsUpdate = true;
            }
        
            generateParticles();
        
            // Création des particules
            const ringMaterial = new THREE.PointsMaterial({
                vertexColors: true,
                size: params.size,
                transparent: true,
                opacity: 0.3,
                blending: THREE.NormalBlending,
                map: ringPointTexture,
                depthWrite: false,
                premultipliedAlpha: true,
                alphaTest: 0.1,
            });
        
            const ringParticles = new THREE.Points(ringGeometry, ringMaterial);
            scene.add(ringParticles);
        
            updateParticleSize();
        
            // ---- RING GROUP ----
            const torusRadius = 2;
            const numRings = 120;
        
            const ringGroup = new THREE.Group();
        
            for (let i = 0; i < numRings; i++) {
                const angle = (i / numRings) * Math.PI * 2;
        
                const x = Math.cos(angle) * torusRadius;
                const z = Math.sin(angle) * torusRadius;
                const y = 0;
        
                const ringClone = ringParticles.clone();
                ringClone.position.set(x, y, z);
        
                ringClone.lookAt(0, y, 0);
                ringClone.rotateY(Math.PI / 2);
                ringGroup.add(ringClone);
            }
        
            scene.add(ringGroup);
        
            // Lights
            const ambientLight = new THREE.AmbientLight(0xffffff, 2.1);
            scene.add(ambientLight);
        
            const directionalLight = new THREE.DirectionalLight(0xffffff, 0.6);
            directionalLight.castShadow = true;
            directionalLight.shadow.mapSize.set(1024, 1024);
            directionalLight.shadow.camera.far = 15;
            directionalLight.shadow.camera.left = -7;
            directionalLight.shadow.camera.top = 7;
            directionalLight.shadow.camera.right = 7;
            directionalLight.shadow.camera.bottom = -7;
            directionalLight.position.set(5, 5, 5);
            scene.add(directionalLight);
        
            // Sizes
            const sizes = {
                width: 400,
                height: 400
            };
        
            // Camera
            const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
            camera.position.set(0, 13, 40);
            camera.lookAt(0, 0, 9);
            scene.add(camera);
        
            // Controls
            const controls = new THREE.OrbitControls(camera, renderer.domElement);
            controls.enableDamping = true;
        
            // Renderer settings
            renderer.shadowMap.enabled = true;
            renderer.shadowMap.type = THREE.PCFSoftShadowMap;
            renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
        
            document.body.appendChild(renderer.domElement);
        
            scene.background = null;
        
            // Target rotation
            const targetRotation = new THREE.Vector3();
            const smoothingFactor = 0.1;
        
            let floatAmplitude = 0.3;
            let floatSpeed = 0.05;
            let floatOffset = 0;
        
            const mouse = new THREE.Vector2();
        
            // Mouse movement handler
            const mouseMoveHandler = (event) => {
                mouse.x = (event.clientX / window.innerWidth) * 2 - 1;
                mouse.y = -(event.clientY / window.innerHeight) * 2 + 1;
        
                targetRotation.y = mouse.x * -0.6;
                targetRotation.x = mouse.y * -0.2;
                targetRotation.z = mouse.x * -0.1;

            rightEye.eyeGroup.rotation.copy(ringGroup.rotation);
            leftEye.eyeGroup.rotation.copy(ringGroup.rotation);
            };


            window.addEventListener('mousemove', mouseMoveHandler);
        
            // Animation loop
            const clock = new THREE.Clock();
            let oldElapsedTime = 0;
        
            const tick = () => {
                const elapsedTime = clock.getElapsedTime();
                const deltaTime = elapsedTime - oldElapsedTime;
                oldElapsedTime = elapsedTime;
                
                // Interpoler progressivement vers la rotation cible
                ringGroup.rotation.x += (targetRotation.x - ringGroup.rotation.x) * smoothingFactor * 1.5;
                ringGroup.rotation.y += (targetRotation.y - ringGroup.rotation.y) * smoothingFactor;
                ringGroup.rotation.z += (targetRotation.z - ringGroup.rotation.z) * smoothingFactor;
        
                ringGroup.children.forEach((ring) => {
                    ring.rotation.z += 0.001;
                });
            
                floatOffset -= floatSpeed;
        
                if (controls.enabled) {
                    controls.update();
                }
        
                world.step(1 / 60, deltaTime, 3);
                
                renderer.render(scene, camera);
                window.animationFrameId = window.requestAnimationFrame(tick);
            };
            
            tick();
        
            // // Event handlers for buttons
            // document.getElementById('generateImageBtn').addEventListener('click', () => {
            //     if (downloadDone) return;
        
            //     if (renderer && scene && camera) {
            //         renderer.render(scene, camera);
            //         console.log("CARGO");
        
            //         const dataURL = renderer.domElement.toDataURL('image/png');
            //         const link = document.createElement('a');
            //         link.href = dataURL;
            //         link.download = 'screenshot.png';
            //         document.body.appendChild(link);
            //         link.click();
            //         document.body.removeChild(link);
        
            //         downloadDone = true;
            //     }
            // });
        
            // document.getElementById('nop').addEventListener('click', () => {
            //     console.log("EHHO");
            //     cleanupScene();
            //     createScene();
            // });
        
            // Internal cleanup function for this scene
            function cleanupScene() {
                console.log("Cleaning up scene");
                
                // Remove canvas
                if (canvas) {
                    canvas.remove();
                }
                
                // Clean up renderer
                if (renderer) {
                    renderer.dispose();
                    if (renderer.domElement) {
                        renderer.domElement.remove();
                    }
                }
                
                // Clean up controls
                if (controls) {
                    controls.dispose();
                }
                
                // Clean up scene resources
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
                
                // Cancel animation frame
                if (window.animationFrameId) {
                    cancelAnimationFrame(window.animationFrameId);
                }
                
                // Remove event listener
                window.removeEventListener('mousemove', mouseMoveHandler);
            }
            
            // Return the cleanup function
            return cleanupScene;
        }
        
        // Start the initial scene
        const sceneCleanup = createScene();
        
        // Main cleanup function for the module
        return function cleanup() {
            console.log("cleanup avatar.js");
            
            // Call the scene's cleanup function
            if (sceneCleanup && typeof sceneCleanup === 'function') {
                sceneCleanup();
            }
            
            // Additional cleanup for any other resources
            const allCanvases = document.querySelectorAll('.webgl');
            allCanvases.forEach(canvas => {
                canvas.remove();
            });
        };
        }
        
        window.currentModuleCleanup = initialize();
        