import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';

// import * as THREE from 'three'
// //  import { OrbitControls } from 'OrbitControls.js'

// import * as THREE from 'three';
// import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';

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

