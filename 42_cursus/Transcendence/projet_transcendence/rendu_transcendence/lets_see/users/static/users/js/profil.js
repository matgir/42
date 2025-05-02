
export function initialize() {
    console.log("Initializing profil.js");
    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.z = 2;

    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);

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
    scene.add(plane);

    // Controls (pour la vue)
    const controls = new THREE.OrbitControls(camera, renderer.domElement);

    // Event souris
    window.addEventListener('mousemove', (event) => {
        uniforms.uMouse.value.x = event.clientX / window.innerWidth;
        uniforms.uMouse.value.y = 1.0 - event.clientY / window.innerHeight;
    });

    // Animation
    function animate(time) {
        uniforms.uTime.value = time * 0.001;
        controls.update();
        renderer.render(scene, camera);
        requestAnimationFrame(animate);
    }

    animate();


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
        }

        console.log("Profil.js cleanup complete.");
    }
}

window.currentModuleCleanup = initialize();

