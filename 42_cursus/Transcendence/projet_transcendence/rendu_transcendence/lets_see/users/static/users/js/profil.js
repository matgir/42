
export function initialize() {
    console.log("Initializing profil.js");
    const scene = new THREE.Scene();
        // Sizes
    const sizes = {
        width: window.innerWidth,
        height: window.innerHeight
    }
    scene.background = new THREE.Color("#0000FF");

    
    const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.z = 2;


    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);

    console.log("ICI");
    const resizeHandler = () => {
        sizes.width = window.innerWidth;
        sizes.height = window.innerHeight;
        camera.aspect = sizes.width / sizes.height;
        camera.updateProjectionMatrix();
        renderer.setSize(sizes.width, sizes.height);
        renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    };
    window.addEventListener('resize', resizeHandler);

    // Geometry
    const geometry = new THREE.PlaneGeometry(1, 1, 100, 100);

    // Shader Material
    const uniforms = {
        uMouse: { value: new THREE.Vector2(0.0, 0.0) },
        uTime: { value: 0.0 }
    };

    const material = new THREE.ShaderMaterial({
        uniforms: uniforms,
        vertexShader: `
            uniform vec2 uMouse;
            uniform float uTime;
            varying vec2 vUv;

            void main() {
                vUv = uv;
                vec3 pos = position;

                float dist = distance(uv, uMouse);
                pos.z += sin(dist * 20.0 - uTime * 5.0) * 0.05 / (dist + 0.1);

                gl_Position = projectionMatrix * modelViewMatrix * vec4(pos, 1.0);
            }
        `,
        fragmentShader: `
            varying vec2 vUv;
            void main() {
                gl_FragColor = vec4(vUv, 1.0, 1.0);
            }
        `,
        side: THREE.DoubleSide
    });

    const plane = new THREE.Mesh(geometry, material);
    // scene.add(plane);

    // Controls (pour la vue)
    // const controls = new THREE.OrbitControls(camera, renderer.domElement);

    // // Event souris
    // window.addEventListener('mousemove', (event) => {
    //     uniforms.uMouse.value.x = event.clientX / window.innerWidth;
    //     uniforms.uMouse.value.y = 1.0 - event.clientY / window.innerHeight;
    // });


    // Mouse interaction
    const mouse = { x: 0, y: 0 };
    const target = { x: 0, y: 0 };
    
    const mouseMoveHandler = (event) => {
        mouse.x = (event.clientX / sizes.width - 0.5) * 2;
        mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
    };
    window.addEventListener('mousemove', mouseMoveHandler);


    const cubes = [];
    const cubeSize = 9;
    const spacing = 14;
    
    const geometry2 = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize);
    const edges = new THREE.EdgesGeometry(geometry2); // Crée les arêtes du cube
    const lineMaterial = new THREE.LineBasicMaterial({ color: 0xFFFFFF }); // Couleur des arêtes
    
    for (let x = -1; x <= 1; x++) {
        for (let y = -1; y <= 1; y++) {
            for (let z = -1; z <= 1; z++) {
                const cube = new THREE.LineSegments(edges, lineMaterial); 
    
                cube.userData.basePosition = new THREE.Vector3(x * spacing, y * spacing, z * spacing);
                cube.position.copy(cube.userData.basePosition);
                scene.add(cube);
                cubes.push(cube);
            }
        }
    }

     // Animate
    const clock = new THREE.Clock();
    
    const tick = () => {
        const elapsedTime = clock.getElapsedTime();
    
        // Smooth interpolation for camera
        target.x += (mouse.x - target.x) * 0.05;
        target.y += (mouse.y - target.y) * 0.05;
    
        const radius = 6;  // élargir pour tout voir
        const angleX = target.x * Math.PI;
        const angleY = target.y * Math.PI / 4;
    
        camera.position.x = radius * Math.sin(angleX);
        camera.position.z = radius * Math.cos(angleX);
        camera.position.y = radius * Math.sin(angleY);
        camera.lookAt(0, 0, 0);
    
        // Rubik cubes smooth motion
        cubes.forEach((cube, index) => {
            const frequency = 0.8;
            const amplitude = 0.2;
            cube.position.x = cube.userData.basePosition.x + Math.sin(elapsedTime * frequency + index) * amplitude;
            cube.position.y = cube.userData.basePosition.y + Math.cos(elapsedTime * frequency + index) * amplitude;
            cube.position.z = cube.userData.basePosition.z + Math.sin(elapsedTime * frequency + index * 0.5) * amplitude;
        });

// uniforms.uTime.value = time * 0.001;
// controls.update();
// renderer.render(scene, camera);
// requestAnimationFrame(animate);
    
        renderer.render(scene, camera);
        window.animationFrameId = window.requestAnimationFrame(tick);
    };
    
    tick();

    return function cleanup() {
        console.log("Cleaning up profil.js resources...");

        // Stop the animation frame loop
        // Assuming animationFrameId is accessible via closure from initialize
        if (typeof animationFrameId !== 'undefined' && animationFrameId !== null) {
            cancelAnimationFrame(animationFrameId);
            // animationFrameId = null; // Reset if needed elsewhere
        }

        // Remove event listeners
        // Assuming mouseMoveHandler is the named function used for the listener, accessible via closure
        if (typeof mouseMoveHandler !== 'undefined') {
             window.removeEventListener('mousemove', mouseMoveHandler);
        }
        // OrbitControls adds its own listeners; dispose() should handle them.

        // Dispose of Three.js objects (accessible via closure)
        if (typeof controls !== 'undefined' && controls) {
            controls.dispose();
        }
        if (typeof scene !== 'undefined' && scene && typeof plane !== 'undefined' && plane) {
            scene.remove(plane); // Remove mesh from scene
        }
        if (typeof geometry !== 'undefined' && geometry) {
            geometry.dispose(); // Dispose geometry
        }
        if (typeof material !== 'undefined' && material) {
            material.dispose(); // Dispose material
            // If material has textures, they might need disposal too:
            // if (material.uniforms.uTexture && material.uniforms.uTexture.value) {
            //     material.uniforms.uTexture.value.dispose();
            // }
        }
        if (typeof renderer !== 'undefined' && renderer) {
            // Remove the canvas from the DOM
            if (renderer.domElement && renderer.domElement.parentNode) {
                 renderer.domElement.parentNode.removeChild(renderer.domElement);
            }
            renderer.dispose(); // Dispose THREE.js resources associated with the renderer
            renderer.forceContextLoss(); // Helps release GPU resources
                // Remove event listeners

        window.removeEventListener('resize', resizeHandler);
        window.removeEventListener('mousemove', mouseMoveHandler);
        }

        console.log("Profil.js cleanup complete.");
    }
}

window.currentModuleCleanup = initialize();











// export function initialize() {
//     // Canvas
//     const canvas = document.querySelector('canvas.webgl');
    
//     // Scene
//     const scene = new THREE.Scene();
    
//     // Sizes
//     const sizes = {
//         width: window.innerWidth,
//         height: window.innerHeight
//     }
    
//     // Camera
//     const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100);
//     camera.position.z = 8;
//     scene.add(camera);
    
//     // Renderer
//     const renderer = new THREE.WebGLRenderer({
//         canvas: canvas,
//         antialias: true
//     });
//     renderer.setSize(sizes.width, sizes.height);
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    
    // // Resize handler
    // const resizeHandler = () => {
    //     sizes.width = window.innerWidth;
    //     sizes.height = window.innerHeight;
    //     camera.aspect = sizes.width / sizes.height;
    //     camera.updateProjectionMatrix();
    //     renderer.setSize(sizes.width, sizes.height);
    //     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    // };
    // window.addEventListener('resize', resizeHandler);
    
//     // Mouse interaction
//     const mouse = { x: 0, y: 0 };
//     const target = { x: 0, y: 0 };
    
//     const mouseMoveHandler = (event) => {
//         mouse.x = (event.clientX / sizes.width - 0.5) * 2;
//         mouse.y = -(event.clientY / sizes.height - 0.5) * 2;
//     };
//     window.addEventListener('mousemove', mouseMoveHandler);
    
//     // Create Rubik-like cubes
//     const cubes = [];
//     const cubeSize = 9;
//     const spacing = 14;
    
//     const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize);
//     const edges = new THREE.EdgesGeometry(geometry); // Crée les arêtes du cube
//     const lineMaterial = new THREE.LineBasicMaterial({ color: 0x0030FF }); // Couleur des arêtes
    
//     for (let x = -1; x <= 1; x++) {
//         for (let y = -1; y <= 1; y++) {
//             for (let z = -1; z <= 1; z++) {
//                 const cube = new THREE.LineSegments(edges, lineMaterial); 
    
//                 cube.userData.basePosition = new THREE.Vector3(x * spacing, y * spacing, z * spacing);
//                 cube.position.copy(cube.userData.basePosition);
//                 scene.add(cube);
//                 cubes.push(cube);
//             }
//         }
//     }
    
//     // Add ambient light
//     const ambientLight = new THREE.AmbientLight(0x404040, 0.5);  // Light color and intensity
//     scene.add(ambientLight);
    
//     // Animate
//     const clock = new THREE.Clock();
    
//     const tick = () => {
//         const elapsedTime = clock.getElapsedTime();
    
//         // Smooth interpolation for camera
//         target.x += (mouse.x - target.x) * 0.05;
//         target.y += (mouse.y - target.y) * 0.05;
    
//         const radius = 6;  // élargir pour tout voir
//         const angleX = target.x * Math.PI;
//         const angleY = target.y * Math.PI / 4;
    
//         camera.position.x = radius * Math.sin(angleX);
//         camera.position.z = radius * Math.cos(angleX);
//         camera.position.y = radius * Math.sin(angleY);
//         camera.lookAt(0, 0, 0);
    
//         // Rubik cubes smooth motion
//         cubes.forEach((cube, index) => {
//             const frequency = 0.8;
//             const amplitude = 0.2;
//             cube.position.x = cube.userData.basePosition.x + Math.sin(elapsedTime * frequency + index) * amplitude;
//             cube.position.y = cube.userData.basePosition.y + Math.cos(elapsedTime * frequency + index) * amplitude;
//             cube.position.z = cube.userData.basePosition.z + Math.sin(elapsedTime * frequency + index * 0.5) * amplitude;
//         });
// uniforms.uTime.value = time * 0.001;
// controls.update();
// renderer.render(scene, camera);
// requestAnimationFrame(animate);
    
//         renderer.render(scene, camera);
//         window.animationFrameId = window.requestAnimationFrame(tick);
//     };
    
//     tick();
    
//     return function cleanup() {
//         console.log("cleanup 2_pink_cubes.js");
        
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
//         scene.children.forEach(child => {
//             if (child.geometry) {
//                 child.geometry.dispose();
//             }
//             if (child.material) {
//                 if (Array.isArray(child.material)) {
//                     child.material.forEach(material => material.dispose());
//                 } else {
//                     child.material.dispose();
//                 }
//             }
//         });
        
//         // Dispose of geometries and materials explicitly
//         if (geometry) {
//             geometry.dispose();
//         }
        
//         if (lineMaterial) {
//             if (Array.isArray(lineMaterial)) {
//                 lineMaterial.forEach(material => material.dispose());
//             } else {
//                 lineMaterial.dispose();
//             }
//         }
        
//         // Remove event listeners
//         window.removeEventListener('resize', resizeHandler);
//         window.removeEventListener('mousemove', mouseMoveHandler);
        
//         // Stop animation frame
//         if (window.animationFrameId) {
//             cancelAnimationFrame(window.animationFrameId);
//         }
//     }
//     }
    
//     window.currentModuleCleanup = initialize();
    
    
    