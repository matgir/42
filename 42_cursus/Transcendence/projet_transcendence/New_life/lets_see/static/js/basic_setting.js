








    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////
    ////////////////////////////////////GOOD//////////////////////////////


    export function initialize() {




        document.addEventListener('DOMContentLoaded', function() {
            document.getElementById('navigation').classList.add('fade-in');
        });


        
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
        const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
        camera.position.set(0, 0, 0);
        camera.lookAt(0, 0, 0);
        scene.add(camera);
        
        // Renderer
        const renderer = new THREE.WebGLRenderer({
            canvas: canvas,
            antialias: true
        });
        renderer.setSize(sizes.width, sizes.height);
        renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
        
        // Lumière nécessaire pour le MeshStandardMaterial


        const light = new THREE.PointLight(0xffffff, 1, 100);
        light.position.set(0, 0, 10);
        scene.add(light);
        scene.add(new THREE.AmbientLight(0x404040));

        const pointLight1 = new THREE.PointLight(0xaa00Af, 3, 50); // Violet
        pointLight1.position.set(5, 5, 5);
        
        const pointLight2 = new THREE.PointLight(0x0Affaa, 3, 50); // Vert
        pointLight2.position.set(-5, -5, 5);
        
        const ambientLight = new THREE.AmbientLight(0x404040, 2);
        
        const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
        directionalLight.position.set(1, 1, 1);
        
        scene.add(pointLight1, pointLight2, ambientLight, directionalLight);
        
        // Tunnel - Torus Knot Geometry
        const geometry = new THREE.TorusKnotGeometry(5, 1, 100, 16); 
        const material = new THREE.MeshStandardMaterial({
            color: 0x0000ff,
            transparent: true,
            opacity: 0, // Commence avec une opacité de 0
            side: THREE.DoubleSide,
            metalness: 0.9,
            roughness: 0.5,
            wireframe: true
            
        });
        const torusKnot = new THREE.Mesh(geometry, material);
        scene.add(torusKnot);
        torusKnot.scale.set(1.4, 1.4, 1.4);
        
        // Animation de l'opacité
        const fadeInDuration = 10; // Durée du fondu en secondes
        let fadeStartTime = null;
        const fadeInDuration2 = 5; // Durée du fondu en secondes
        let fadeStartTime2 = null;
        
            camera.position.x = Math.sin(6) * 6;
                camera.position.y = Math.cos(6) * 6;
                camera.position.z = 6 * 0.5;
        // Animate
        const clock = new THREE.Clock();
        setTimeout(() => {
            const elapsedTimet = clock.getElapsedTime();
            console.log(elapsedTimet); // Environ 2.0 après 2 secondes
        }, 2000);

         
        const angleT = 0.16 * 0.0055;
       
        let end_x = Math.sin(angleT) * -6;


        torusKnot.rotation.x = angleT; 
        let end_y = Math.cos(angleT) * 6;
        let end_z = angleT  *  -0.5 + 1;


      
        const knotStartY = -35;
        const knotEndY = 0;
        const knotFallDuration = 6; 

        const knotStartX = -15;
        const knotEndX = 0;

        const knotStartZ = 15;
        const knotEndZ = 0;

        const knot_rZ = -2.75;
        const knot_rendZ = 1.7;


        torusKnot.position.y = knotStartY; 
        torusKnot.position.x = knotStartX; 
        torusKnot.position.z = knotStartZ; 


        function easeOutCubic(t) {
            return 1 - Math.pow(1 - t, 3);
        }
        
            
        torusKnot.rotation.x = -0.1;
        torusKnot.rotation.y = 0.02;
        torusKnot.rotation.z = 0.15;

        const targetRotationX = -0.1;
        const targetRotationY = 0.02;
        const targetRotationZ = 0.02;



        const tick = () => {
            const elapsedTime = clock.getElapsedTime();
            
            // Gestion du fondu d'entrée
            if (fadeStartTime === null) {
                fadeStartTime = elapsedTime;
            }
            
            const fadeProgress = Math.min((elapsedTime - fadeStartTime) / fadeInDuration, 1);
            material.opacity = fadeProgress;
        
            // Animation de la caméra
            const radius = 6;
            // const angle = elapsedTime * 0.0055;
            const angle = elapsedTime * 0.0055;
            // camera.position.x = angle * 0.5;
        
            

            camera.position.x = Math.sin(angle) * radius;
            camera.position.y = Math.cos(angle) * radius;
            camera.position.z = angle ;
            camera.lookAt(0, 0, 0);


            const rawProgress = Math.min(elapsedTime / knotFallDuration, 1);
            const knotFallProgress = easeOutCubic(rawProgress);
            
            torusKnot.position.y = knotStartY + (knotEndY - knotStartY) * knotFallProgress;
            torusKnot.position.x = knotStartX + (knotEndX - knotStartX) * knotFallProgress;
            torusKnot.position.z = knotStartZ + (knotEndZ - knotStartZ) * knotFallProgress;
            
            // torusKnot.rotation.x =  0;
            // torusKnot.rotation.x += 0.0001;
            // torusKnot.rotation.y -= 0.00005;
            // torusKnot.rotation.z -= 0.00005;


            torusKnot.rotation.x = knot_rZ + (targetRotationX - knot_rZ) * knotFallProgress;
            // torusKnot.rotation.y = knot_rZ + (targetRotationY - knot_rZ) * knotFallProgress ;
            // torusKnot.rotation.z = knot_rZ + (targetRotationZ - knot_rZ) * knotFallProgress;


            // torusKnot.rotation.z = 0;


            // Rendu
            renderer.render(scene, camera);
            window.animationFrameId = window.requestAnimationFrame(tick);
        };
        
        // Lancer l'animation
        tick();


        

        // Gestion du redimensionnement
        const resizeHandler = () => {
            sizes.width = window.innerWidth;
            sizes.height = window.innerHeight;
            camera.aspect = sizes.width / sizes.height;
            camera.updateProjectionMatrix();
            renderer.setSize(sizes.width, sizes.height);
            renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
        };
        window.addEventListener('resize', resizeHandler);
        
        // Fonction de nettoyage
        return function cleanup() {
            console.log("cleanup basic_setting.js");
            
            if (renderer) {
                renderer.dispose();
                if (renderer.domElement) {
                    renderer.domElement.remove();
                }
            }
            
            if (scene) {
                scene.children.forEach(child => {
                    if (child.geometry) child.geometry.dispose();
                    if (child.material) {
                        if (Array.isArray(child.material)) {
                            child.material.forEach(m => m.dispose());
                        } else {
                            child.material.dispose();
                        }
                    }
                });
            }
            
            window.removeEventListener('resize', resizeHandler);
            if (window.animationFrameId) {
                cancelAnimationFrame(window.animationFrameId);
            }
        };
    }
    
    window.currentModuleCleanup = initialize();






    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////
    //////////////////////////////////////GOOD//////////////////////////////




// export function initialize() {
//     // Canvas
//     const canvas = document.querySelector('canvas.webgl');
    
//     // Scene
//     const scene = new THREE.Scene();
    
//     // Sizes
//     const sizes = {
//         width: window.innerWidth,
//         height: window.innerHeight
//     };
    
//     // Camera
//     const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
//     camera.position.set(0, 0, 5); // Placer la caméra au centre du torus knot
//     camera.lookAt(0, 0, 0); // Oriente la caméra vers l'intérieur du tunnel
//     scene.add(camera);
    
//     // Renderer
//     const renderer = new THREE.WebGLRenderer({
//         canvas: canvas,
//         antialias: true
//     });
//     renderer.setSize(sizes.width, sizes.height);
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    
//     // Tunnel - Torus Knot Geometry
//     const geometry = new THREE.TorusKnotGeometry(5, 1, 100, 16); 
//     const material = new THREE.MeshBasicMaterial({
//         color: 0x0000ff, 
//         wireframe: true, 
//         side: THREE.DoubleSide 
//     });
//     const torusKnot = new THREE.Mesh(geometry, material);
//     scene.add(torusKnot);
    
//     let moveStarted = false; // Indique si le mouvement a commencé
    
//     function moveCameraDown(camera, startTime, moveDuration = 2) {
//         const elapsedTime = new THREE.Clock().getElapsedTime();
    
//         if (!moveStarted) {
//             if (elapsedTime - startTime >= 3) {
//                 moveStarted = true;  // Le mouvement commence après 3 secondes
//             } else {
//                 return;  // Attendre encore
//             }
//         }
    
//         const progress = Math.min((elapsedTime - startTime - 3) / moveDuration, 1);
    
//         camera.position.y = 5 - progress * 2; 
    
//         if (progress === 1) {
//             moveStarted = false; 
//         }
//     }
    
//     // Animate
//     const clock = new THREE.Clock();
//     const tick = () => {
//         const elapsedTime = clock.getElapsedTime();
    
//         const radius = 6;
//         const angle = elapsedTime * 0.005;
    
//         // Appliquer un léger mouvement de caméra basé sur la souris
//         camera.position.x = Math.sin(angle) * radius ;  // Ajouter un léger décalage basé sur la souris
//         camera.position.y = Math.cos(angle) * radius ;  // Ajouter un léger décalage basé sur la souris
//         camera.position.z = angle * 0.5;
    
//         camera.lookAt(0, 0, 0);  // Garder la caméra orientée vers le centre
    
//         // Rendu
//         renderer.render(scene, camera);
//         window.animationFrameId = window.requestAnimationFrame(tick);
//     };
    
//     // Lancer l'animation
//     tick();
    
//     // Extract resize handler for cleanup
//     const resizeHandler = () => {
//         sizes.width = window.innerWidth;
//         sizes.height = window.innerHeight;
//         camera.aspect = sizes.width / sizes.height;
//         camera.updateProjectionMatrix();
//         renderer.setSize(sizes.width, sizes.height);
//         renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
//     };
//     window.addEventListener('resize', resizeHandler);
    
    
    
//     // Add cleanup function
//     return function cleanup() {
//         console.log("cleanup basic_setting.js");
        
//         // Only remove our specific canvas
//         const canvas = document.querySelector('canvas.webgl');
//         if (canvas) {
//             canvas.remove();
//         }
        
//         // Clean up THREE.js resources
//         if (renderer) {
//             renderer.dispose();
//             if (renderer.domElement) {
//                 renderer.domElement.remove();
//             }
//         }
        
//         // Clean up geometries and materials
//         if (scene) {
//             scene.children.forEach(child => {
//                 if (child.geometry) {
//                     child.geometry.dispose();
//                 }
//                 if (child.material) {
//                     if (Array.isArray(child.material)) {
//                         child.material.forEach(material => material.dispose());
//                     } else {
//                         child.material.dispose();
//                     }
//                 }
//             });
//         }
        
//         window.removeEventListener('resize', resizeHandler);
        
//         if (window.animationFrameId) {
//             cancelAnimationFrame(window.animationFrameId);
//         }
//     }
//     }
    
    
//     window.currentModuleCleanup = initialize();
    
    
    