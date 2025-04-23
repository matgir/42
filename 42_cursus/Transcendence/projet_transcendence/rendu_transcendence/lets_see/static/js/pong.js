// import * as THREE from 'three'
// import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
// import GUI from 'lil-gui'
// import CANNON, { Vec3 } from 'cannon'
// import * as CANNON from 'cannon-es'


// import { TextGeometry } from 'three/examples/jsm/geometries/TextGeometry.js'
// import { FontLoader } from 'three/examples/jsm/loaders/FontLoader.js'

// console.log(THREE.REVISION);
// // console.log("eh");

// //import { roughness } from 'three/tsl'

// /**
//  * Debug
//  */
// const gui = new GUI()
// const debugObject = {}
// //const debugObject2 = {}

// /**
//  * Base
//  */
// // Canvas
// const canvas = document.querySelector('canvas.webgl')

// // Scene
// const scene = new THREE.Scene()
// //scene.background = new THREE.Color("#fefae0");
// //scene.background = new THREE.Color("#000000")
// scene.background = new THREE.Color("#02010d")


// // const axesHelper = new THREE.AxesHelper(5) // Longueur des axes = 5 unités
// //scene.add(axesHelper)

// //physics 
// const world = new CANNON.World()
// world.gravity.set(0, 0, 0)

// /**
//  * Textures
//  */
// const textureLoader = new THREE.TextureLoader()
// const cubeTextureLoader = new THREE.CubeTextureLoader()

// const environmentMapTexture = cubeTextureLoader.load([
//     '/textures/environmentMaps/0/px.png',
//     '/textures/environmentMaps/0/nx.png',
//     '/textures/environmentMaps/0/py.png',
//     '/textures/environmentMaps/0/ny.png',
//     '/textures/environmentMaps/0/pz.png',
//     '/textures/environmentMaps/0/nz.png'

// ])

// //const default_color = new THREE.Color("#880FeE")
// const default_color = new THREE.Color("#000000")

//     // Définir un tableau de 4 couleurs (vous pouvez les modifier selon vos préférences)
//     const trailColors = [
  

//         // new THREE.Color("#0F00FF"), // Bleu
//         // new THREE.Color("#0F00FF"), // Bleu
//         // new THREE.Color("#8400eE"), // Bleu
//       //  new THREE.Color("#FFAAFB"), 

//       //rainbow
//     //     new THREE.Color("#ff0000"), // Bleu
//     //     new THREE.Color("#ff8700"), // Bleu
//     //    new THREE.Color("#deff0a"), 
//     //    new THREE.Color("#a1ff0a"), 
//     //    new THREE.Color("#0aff99"), 
//     //    new THREE.Color("#0aeffF"), 
//     //    new THREE.Color("#147df5"), 
//     //    new THREE.Color("#580aff"), 
//     //    new THREE.Color("#be0aff"), 

//        //design 1
      
//       // new THREE.Color("#ed6f3c"), 
//       new THREE.Color("#f05fF8"), 
//       new THREE.Color("#df83f7"), 
//       new THREE.Color("#e984f9"),
//       new THREE.Color("#7445fb"), 
//       new THREE.Color("#455cd0"), 

//        new THREE.Color("#31309b"), 
//        new THREE.Color("#221bFb"), 
//     //     new THREE.Color("#691338"), 
//     //   // new THREE.Color("#fc928e"), 




//     ];
//     let currentColorIndex = 0; // Index pour suivre la couleur actuelle dans le cycle
    
// const matcapTexture = textureLoader.load('/textures/matCap/3a.png'); // Remplace par le bon chemin

// //default materiel
// // const normal = new THREE.MeshNormalMaterial({
// //     castShadow : true,
// //     color : default_color,
// //     wireframe : true,
// //     receiveShadow : true,
// //     side :  THREE.BackSide
// // })

// const normal = new THREE.MeshStandardMaterial({
//     castShadow : true,
//     color : '#9F59ff',
//     wireframe : true,
//     receiveShadow : true,
//     side :  THREE.BackSide
// })

// const normal2 = new THREE.MeshStandardMaterial({
//     castShadow : true,
//     color : '#1f50fF',
//     wireframe : true,
//     receiveShadow : true,
//     side :  THREE.BackSide
// })


// const normali = new THREE.MeshDepthMaterial({
//     depthPacking: THREE.RGBADepthPacking, // Ou THREE.BasicDepthPacking
//     blending: THREE.AdditiveBlending,
//     side: THREE.DoubleSide, // Ou THREE.FrontSide / THREE.BackSide selon ton besoin
//    // depthTest: true,
//     //depthWrite: true,
//   });
  

// const paddle = new THREE.MeshStandardMaterial({
//     //color: '#00BFFF',
//     color: '#9F59ff',

//     wireframe :true,
//     metalness: 0.2,
//    // side : THREE.BackSide
// //    roughness: 0.2,
// //     envMap: environmentMapTexture,
// //     envMapIntensity: 0.5
// })

// const paddle2 = new THREE.MeshStandardMaterial({
//    // color: '#BF00FF',
//     color: '#1f50fF',

//     wireframe :true,
//     metalness: 0.2,
// })
// const cageMaterial = new THREE.MeshStandardMaterial({
//     // color: '#BF00FF',
//      color: '#00FF00',
 
//      wireframe :true,
//      metalness: 0.2,
//  })



// const toonMaterial = new THREE.MeshToonMaterial({
//    // color: 0xffcc00,   // Couleur jaune cartoon
//     //gradientMap: null,  // Utilise le shading par défaut
// })

// const normal_material = new THREE.MeshNormalMaterial()
// //normal_material.flatShading = true

// const defaultMaterial = new CANNON.Material('default')
// const defaultContactMaterial = new CANNON.ContactMaterial(
//     defaultMaterial,
//     defaultMaterial,
//     {
//         friction: 0,
//         restitution: 1
//     }
// )
// world.addContactMaterial(defaultContactMaterial)
// world.defaultContactMaterial = defaultContactMaterial

// ////////////////////////////////----SHPERE----///////////////////////////

// const sphereGeometry = new THREE.SphereGeometry(0.8, 7, 12)
// const sphereMaterial = new THREE.MeshStandardMaterial({
//     metalness: 0.3,
//     roughness: 0.1,
//     wireframe : true,
//     color: '#00FF00',
//     side: THREE.DoubleSide
//     })

// // const sphereMaterial = new THREE.MeshMatcapMaterial(    
// //     { 
// //         matcap: matcapTexture 
// //     })


// const shape = new CANNON.Sphere(0.5)
// const body = new CANNON.Body({
//     mass: 1.3,
//     position: new CANNON.Vec3(0,0,0),
//     shape: shape,
//     material: defaultMaterial,
//     velocity: new CANNON.Vec3(0, 0, 0)
// })
// // body.position.copy(position)
// world.addBody(body)

// const mesh = new THREE.Mesh(sphereGeometry, sphereMaterial)
// mesh.castShadow = true
// mesh.scale.set(0.5, 0.5, 0.5)
// mesh.position.copy(body.position)
// scene.add(mesh)

// const ecart = 12;
// //const paddleHeight = 2.5

// // let params = { paddleHeight: 2.5 };
// // let paddleHeight = 2.5


// /////////////////////////////////////////// FUMEE //////////////////////


// const numberOfParticles = 140000;
// const spread = 14;  // Plage de répartition des particules
// const speed = 0.002; // Vitesse de déplacement des particules
// const positions = new Float32Array(numberOfParticles * 3);  // Un tableau pour les positions des particules
// const velocities = new Float32Array(numberOfParticles * 3);  // Un tableau pour les vitesses des particules


// const colors = new Float32Array(numberOfParticles * 3);
// // Ajouter des particules à la géométrie avec une direction aléatoire
// for (let i = 0; i < numberOfParticles; i++) {
//     // Positionner aléatoirement les particules dans une zone définie 
    
//     const x = (Math.random() * 2 - 1) * 4;  // Plage de x : [-spread, spread]
//     const y = (Math.random() * 2 - 1) * 8 ;  // Plage de y : [-spread, spread]
//     const z = (Math.random() * 2 - 1) * 10;  // Plage de z : [-spread, spread]

//     positions[i * 3] = x;
//     positions[i * 3 + 1] = y;
//     positions[i * 3 + 2] = z;

//     // Initialisation d'une vitesse aléatoire (petite variation pour chaque direction)
//     velocities[i * 3] = (Math.random() - 0.5) * speed * 0.1;
//     velocities[i * 3 + 1] = (Math.random() - 0.5) * speed * 0.1;
//     velocities[i * 3 + 2] = (Math.random() - 0.5) * speed * 0.1;


//        // Couleur initiale (par exemple, magenta)
//    colors[i * 3] = default_color.r
//    colors[i * 3 + 1] = default_color.g// Vert
//    colors[i * 3 + 2] = default_color.b
   

//     // Application de la friction
//     const friction = 0.99; // Coefficient de friction, ajuste pour une dissipation plus ou moins forte
//     velocities[i * 3] *= friction;
//     velocities[i * 3 + 1] *= friction;
//     velocities[i * 3 + 2] *= friction;

//     // Application des turbulences
//     const turbulenceStrength = 0.02; // Force des turbulences
//     velocities[i * 3] += (Math.random() - 0.5) * turbulenceStrength;
//     velocities[i * 3 + 1] += (Math.random() - 0.5) * turbulenceStrength;
//     velocities[i * 3 + 2] += (Math.random() - 0.5) * turbulenceStrength;
// }

// // Créer un BufferGeometry pour les particules
// const smokeGeometry = new THREE.BufferGeometry();
// smokeGeometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
// smokeGeometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));



// // Créer un matériau pour les particules
// const smokeTexture = new THREE.TextureLoader().load('particles/9.png');

// const smokeMaterial = new THREE.PointsMaterial({
//     color: "#FFFFFF",
    
//     size: 0.00023,
//     transparent: true,
//     opacity: 0.4,
//     blending: THREE.AdditiveBlending,


//     map: smokeTexture,
//     alphaMap: smokeTexture,
//     vertexColors : true,
//   //  map: particleTexture,
//    // alphaTest: 0.5, // Ajustez cette valeur si nécessaire
   
//     depthWrite: false
// });
//    // opacity: Math.max(0.1, 0.5 * 0.99), // Ajustez l'opacité selon vos besoins

// // Créer le système de particules
// const smoke = new THREE.Points(smokeGeometry, smokeMaterial);
// scene.add(smoke);


//     smokeGeometry.attributes.position.needsUpdate = true;







// ////////////////////////////////////////////////// PADDLE //////////////


// // const floorShape = new CANNON.Box(new CANNON.Vec3(2, paddleHeight, 1)); 
// const floorShape = new CANNON.Box(new CANNON.Vec3(4, 2, 0.05));// Une boîte fine comme mur
// const floorBody = new CANNON.Body({
//     mass: 0,
//     shape: floorShape,
//     material: defaultMaterial,
//     position: new CANNON.Vec3(0, 0, ecart) 
// })
// world.addBody(floorBody);

// const floor = new THREE.Mesh(new THREE.BoxGeometry(3, 4, 1, 1 ,1), paddle)
  


// //floor.receiveShadow = true;
// floor.position.set(0, 0, ecart);
// floor.wireframe = true

// floor.position.copy(floorBody.position)
// scene.add(floor);

// ////////////////////////////////////////////////// PADDLE2 //////////////


// const floorShape2 = new CANNON.Box(new CANNON.Vec3(4, 2, 0.05));
// const floorBody2 = new CANNON.Body({
//     mass: 0,
//     shape: floorShape2,
//     material: defaultMaterial,
//     position: new CANNON.Vec3(0, 0, -ecart)
// });
// world.addBody(floorBody2);

// const floor2 = new THREE.Mesh(
//    //new THREE.BoxGeometry(2, paddleHeight * 2, 2, 6 ,6), 
//     new THREE.BoxGeometry(3, 4, 1, 1 ,1), paddle2)

// //floor2.receiveShadow = true;
// floor2.position.set(0, 0, -ecart);
// floor2.position.copy(floorBody2.position)
// scene.add(floor2);

// ////////////////////////////////////////////////// CAGE //////////////

// const cage = new THREE.Mesh(
// new THREE.BoxGeometry(5, 20, 24 , 1, 0, 2), cageMaterial)
// scene.add(cage);

// /**
//  * Lights
//  */
// const ambientLight = new THREE.AmbientLight(0xffffff, 2.1)
// scene.add(ambientLight)

// const directionalLight = new THREE.DirectionalLight(0xffffff, 0.6)
// directionalLight.castShadow = true
// directionalLight.shadow.mapSize.set(1024, 1024)
// directionalLight.shadow.camera.far = 15
// directionalLight.shadow.camera.left = - 7
// directionalLight.shadow.camera.top = 7
// directionalLight.shadow.camera.right = 7
// directionalLight.shadow.camera.bottom = - 7
// directionalLight.position.set(5, 5, 5)
// scene.add(directionalLight)

// /**
//  * Sizes
//  */
// const sizes = {
//     width: window.innerWidth,
//     height: window.innerHeight
// }

// window.addEventListener('resize', () =>
// {
//     sizes.width = window.innerWidth
//     sizes.height = window.innerHeight

//     camera.aspect = sizes.width / sizes.height
//     camera.updateProjectionMatrix()

//     renderer.setSize(sizes.width, sizes.height)
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
// })

// ////////////////////////////////////////////////// CONTROLE CLAVIER //////////////

// const keys = {};

// window.addEventListener("keydown", (event) => { keys[event.key] = true; });
// window.addEventListener("keyup", (event) => { keys[event.key] = false; });

// const hauteur = 8
// const updateBoxes = () => {
//     const speed = 0.35 // Vitesse du déplacement

//     if (keys["a"] && floorBody.position.y < hauteur) {
//         floorBody.position.y += speed;
//         floor.position.y = floorBody.position.y;
//     }
//     if (keys["q"] && floorBody.position.y > -hauteur) {
//         floorBody.position.y -= speed;
//         floor.position.y = floorBody.position.y;
//     }
//     if (keys["p"] && floorBody2.position.y < hauteur) {
//         floorBody2.position.y += speed;
//         floor2.position.y = floorBody2.position.y;
//     }
//     if (keys["m"] && floorBody2.position.y > -hauteur) {
//         floorBody2.position.y -= speed;
//         floor2.position.y = floorBody2.position.y;
//     }
// }

//  ////////////////////////////////////////// MOUV //////////////////////////////////////////
//  body.velocity.set(0, 0, 20); // Déplacement uniquement sur x et y

// const epsilon = 2 //tolerance pour nombre fllottant
// let count = 0
// let count_1 = 3
// let count_2 = 3


// function checkCollision_paddle(ball, paddle) {
//     let paddleHeight = 2; // longueur raquette


//    if (Math.abs(ball.position.z - paddle.position.z) < epsilon)  // balle au niveau de raquette pour collision
//     { 
//             if (ball.position.y >= paddle.position.y - paddleHeight && ball.position.y <= paddle.position.y + paddleHeight) {
//                 ball.velocity.z *= -1;  // Réverser la direction sur Z lors du rebond
//             }
//         if ((ball.position.y > paddle.position.y + paddleHeight) || ( ball.position.y < paddle.position.y - paddleHeight)) 
//                 return
//         if (body.position.y < 10 || body.position.y > -10)
//         { 
//             if ((ball.position.y < paddle.position.y + paddleHeight) && ( ball.position.y > paddle.position.y - paddleHeight))  
//             {
//                // //console.log("IMPACT")
//                // //console.log((Math.round(ball.velocity.z / 10) * 10).toFixed(1))

//                 ball.velocity.y *= -1;
//                 let impact = (ball.position.y -  paddle.position.y) / (paddleHeight / 2); //entre -1 et 1
//                 ball.velocity.y = impact * 7; //angle de rebond
//                    // Pour inverser la direction de la balle sur l'axe Z en fonction de la raquette (si elle touche la raquette 2)
//             if (ball.position.z > paddle.position.z)
//                 {
//                     ball.velocity.z = Math.abs(ball.velocity.z); // Ball rebounding in positive Z direction
//                 } 
//             else 
//                 {
//                     ball.velocity.z = -Math.abs(ball.velocity.z); // Ball rebounding in negative Z direction
//                 }
//             }
//         }
        
//     }
// }

//  function updateBall() {
     
//      checkCollision_paddle (body, floor); // Raquette gauche
//      checkCollision_paddle(body, floor2); // Raquette droitea
//      if (body.position.y >= 10) { 
//          body.velocity.y *= -1;
//          body.position.y = 9.9; // Évite de rester pile à 10
//          count++;
//          } 
//      else if (body.position.y <= -10) 
//         { 
//          body.velocity.y *= -1;
//          body.position.y = -9.9; // Évite de rester pile à -10
//         // //console.log("BAS");
//          count++;
//      }
//      //console.log(body.position.z)
//      if (body.position.z < -30)
//          {
            
//              //count_1--
//              body.position.set(0, 0, 0)
//              body.velocity.set(0, 0, 20)
//              updateText()
//              if(count_1 == 0) 
//                 {
//                  body.position.set(0, 0, 0)
//                  //console.log("prouut1")
//                  body.velocity.set(10, 0, 0)
//                  }
//          }
//      if (body.position.z > 30 )
//          {
//            //  count_2--
//              updateText2()
//              body.position.set(0, 0, 0)
//              body.velocity.set(0, 0, 20)
//              if(count_2 == 0)
//              {
//                  body.position.set(0, 0, 0)
//                 //  console.log("prouut2")
//                  body.velocity.set(10, 0, 0)
//              }
//          }
//     }
 



// ////////////////////////////////////////// TEXT //////////////////////////////////////////
 
   

// //////////////////////////////////////// TEXT //////////////////////////////////////////

// const fontLoader = new FontLoader();

// let text
// let updateText
// let score = 0

// let rotationSpeed_ = 0.20; // Vitesse de rotation
// let jumpHeight_ = 1; // Hauteur du bond
// let rotationCount_ = 0;
// let maxRotations_ = Math.PI * 2; // Une rotation complète
// let startY_;

// const textPivot = new THREE.Group();
// scene.add(textPivot);

// fontLoader.load(
//     '/fonts/helvetiker_regular.typeface.json',
//     (font) => {
//         const textGeometry = new TextGeometry(
//             score.toString(), // Affiche "0" au début
//             {
//                 font: font,
//                 size: 2,
//                 depth: 0.2,
//                 curveSegments: 2,
//                 bevelThickness: 0.03,
//                 bevelSize: 0.02,
//                 bevelOffset: 0,
//                 bevelSegments: 1
//             }
//         );

//         // Centrer la géométrie initiale
//         textGeometry.computeBoundingBox();
//         const box_ = textGeometry.boundingBox;
//         const centerX_ = (box_.max.x + box_.min.x) / 2;
//         const centerY_ = (box_.max.y + box_.min.y) / 2;
//         const centerZ_ = (box_.max.z + box_.min.z) / 2;
//         textGeometry.translate(-centerX_, -centerY_, -centerZ_);

//         text = new THREE.Mesh(textGeometry, normal);
//         text.position.set(10, -3, 8);
//         text.rotation.y = Math.PI / 2;
//         startY_ = text.position.y;

//         scene.add(text);

//         // Fonction pour mettre à jour le texte
//         updateText = function () {
//             score++;
//             text.geometry.dispose();

//             // Créer une nouvelle géométrie pour le texte
//             const newTextGeometry = new TextGeometry(score.toString(), {
//                 font: font,
//                 size: 2,
//                 depth: 0.2,
//                 curveSegments: 2,
//                 bevelThickness: 0.03,
//                 bevelSize: 0.02,
//                 bevelOffset: 0,
//                 bevelSegments: 1
//             });

//             // Centrer la nouvelle géométrie
//             newTextGeometry.computeBoundingBox();
//             const newBox = newTextGeometry.boundingBox;
//             const newCenterX = (newBox.max.x + newBox.min.x) / 2;
//             const newCenterY = (newBox.max.y + newBox.min.y) / 2;
//             const newCenterZ = (newBox.max.z + newBox.min.z) / 2;
//             newTextGeometry.translate(-newCenterX, -newCenterY, -newCenterZ);

//             // Appliquer la nouvelle géométrie au texte
//             text.geometry = newTextGeometry;

//             // Réinitialiser la rotation et démarrer l'animation
//             rotationCount_ = 0;
//             animateRotation_();
//         };

//         // Démarrer l'animation initiale
//         animateRotation_();
//     }
// );



// function animateRotation_() {
//     if (rotationCount_ < maxRotations_) {
//         // Appliquer la rotation
//         text.rotation.y += rotationSpeed_;

//         // Appliquer le bond en sinus
//         text.position.y = startY_ + Math.sin(rotationCount_) * jumpHeight_;

//         // Incrémenter le compteur de rotation
//         rotationCount_ += rotationSpeed_;

//         // Continuer l'animation
//         requestAnimationFrame(animateRotation_);
//     } else {
//         // Réinitialiser la rotation après un tour complet
//         text.rotation.y = Math.PI / 2; // ou une autre valeur initiale si nécessaire
//         rotationCount_ = 0; // Réinitialiser le compteur de rotation
//     }
// }



// //////////////////////////////////////////////////////////////////////////////////////////////   TEXT2

// let text2;
// let updateText2;
// let score2 = 0;

// // Variables pour l'animation
// let rotationSpeed = 0.20; // Vitesse de rotation
// let jumpHeight = 1; // Hauteur du bond
// let rotationCount = 0;
// let maxRotations = Math.PI * 2; // Une rotation complète
// let startY;


// const text2Pivot = new THREE.Group();
// scene.add(text2Pivot);

// fontLoader.load(
//     '/fonts/helvetiker_regular.typeface.json',
//     (font) => {
//         const text2Geometry = new TextGeometry(
//             score2.toString(), // Affiche "0" au début
//             {
//                 font: font,
//                 size: 1.9,
//                 depth: 0.2,
//                 curveSegments: 2,
//                 bevelThickness: 0.03,
//                 bevelSize: 0.02,
//                 bevelOffset: 0,
//                 bevelSegments: 1
//             }
//         );

//         // Centrer la géométrie initiale
//         text2Geometry.computeBoundingBox();
//         const box = text2Geometry.boundingBox;
//         const centerX = (box.max.x + box.min.x) / 2;
//         const centerY = (box.max.y + box.min.y) / 2;
//         const centerZ = (box.max.z + box.min.z) / 2;
//         text2Geometry.translate(-centerX, -centerY, -centerZ);

//         text2 = new THREE.Mesh(text2Geometry, normal2);
//         text2.position.set(10, -3.2, -7.8);
//         text2.rotation.y = Math.PI / 2;
//         startY = text2.position.y;

//         scene.add(text2);

//         // Fonction pour mettre à jour le text2e
//         updateText2 = function () {
//             score2 ++;
//             text2.geometry.dispose();

//             // Créer une nouvelle géométrie pour le text2e
//             const newText2Geometry = new TextGeometry(score2.toString(), {
//                 font: font,
//                 size: 2,
//                 depth: 0.2,
//                 curveSegments: 2,
//                 bevelThickness: 0.03,
//                 bevelSize: 0.02,
//                 bevelOffset: 0,
//                 bevelSegments: 1
//             });

//             // Centrer la nouvelle géométrie
//             newText2Geometry.computeBoundingBox();
//             const new2Box = newText2Geometry.boundingBox;
//             const new2CenterX = (new2Box.max.x + new2Box.min.x) / 2;
//             const new2CenterY = (new2Box.max.y + new2Box.min.y) / 2;
//             const new2CenterZ = (new2Box.max.z + new2Box.min.z) / 2;
//             newText2Geometry.translate(-new2CenterX, -new2CenterY, -new2CenterZ);

//             // Appliquer la nouvelle géométrie au texte
//             text2.geometry = newText2Geometry;

//             // Réinitialiser la rotation et démarrer l'animation
//             rotationCount = 0;
//             animateRotation();
//         };

//         // Démarrer l'animation initiale
//         animateRotation();
//     }
// );

// function animateRotation() {
//     if (rotationCount < maxRotations) {
//         // Appliquer la rotation
//         text2.rotation.y += rotationSpeed;

//         // Appliquer le bond en sinus
//         text2.position.y = startY + Math.sin(rotationCount) * jumpHeight;

//         // Incrémenter le compteur de rotation
//         rotationCount += rotationSpeed;

//         // Continuer l'animation
//         requestAnimationFrame(animateRotation);
//     } else {
//         // Réinitialiser la rotation après un tour complet
//         text2.rotation.y = Math.PI / 2; // ou une autre valeur initiale si nécessaire
//         rotationCount = 0; // Réinitialiser le compteur de rotation
//     }
// }



// //////////////////////////////////    MOUV    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// function applyRepulsionFromFloors() {
//     const repulsionStrength = 1.5; // Force de répulsion
//     const repulsionDistance = 1.5; // Distance à laquelle la répulsion commence

//     for (let i = 0; i < numberOfParticles; i++) {
//         // Récupérer les positions et vitesses des particules
//         let x = positions[i * 3];
//         let y = positions[i * 3 + 1];
//         let z = positions[i * 3 + 2];
//         let vx = velocities[i * 3];
//         let vy = velocities[i * 3 + 1];
//         let vz = velocities[i * 3 + 2];

//         // Tableau des positions des paddles
//         const paddles = [floorBody.position, floorBody2.position];

//         paddles.forEach(paddlePos => {
//             // Calculer la distance entre la particule et le paddle
//             let dx = x - paddlePos.x;
//             let dy = y - paddlePos.y;
//             let dz = z - paddlePos.z;
//             let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

//             // Si la particule est suffisamment proche du paddle
//             if (distance < repulsionDistance) {
//                 // Calculer la force de répulsion
//                 let repulsionForce = repulsionStrength / (distance * distance);
//                 vx += (dx / distance) * repulsionForce;
//                 vy += (dy / distance) * repulsionForce;
//                 vz += (dz / distance) * repulsionForce;
//             }

            
//         });

//         // Mettre à jour les vitesses dans le tableau
//         velocities[i * 3] = vx;
//         velocities[i * 3 + 1] = vy;
//         velocities[i * 3 + 2] = vz;
//     }

// }
// function applyReturnForceToPaddles() {
//     const returnStrengthX = 0.005; // Intensité du retour en X
//     const returnStrengthY = 0.0; // Intensité du retour en Y
//     const returnStrengthZ = 0.0; // Intensité du retour en Z
//     const maxDistance = 2.0; // Distance maximale avant que la force commence à agir

//     for (let i = 0; i < numberOfParticles; i++) {
//         // Récupérer les positions et vitesses des particules
//         let x = positions[i * 3];
//         let y = positions[i * 3 + 1];
//         let z = positions[i * 3 + 2];
//         let vx = velocities[i * 3];
//         let vy = velocities[i * 3 + 1];
//         let vz = velocities[i * 3 + 2];

//         // Tableau des positions des paddles
//         const paddles = [floorBody.position, floorBody2.position];

//         paddles.forEach(paddlePos => {
//             // Calculer les distances de la particule au paddle sur chaque axe
//             let dx = x - paddlePos.x;
//             let dy = y - paddlePos.y;
//             let dz = z - paddlePos.z;

//             // Appliquer une force de retour si la particule dépasse `maxDistance`
//             if (Math.abs(dx) > maxDistance) {
//                 vx -= (dx / Math.abs(dx)) * returnStrengthX; // Ramène vers le paddle sur X
//             }
//             if (Math.abs(dy) > maxDistance) {
//                 vy -= (dy / Math.abs(dy)) * returnStrengthY; // Ramène vers le paddle sur Y
//             }
//             if (Math.abs(dz) > maxDistance) {
//                 vz -= (dz / Math.abs(dz)) * returnStrengthZ; // Ramène vers le paddle sur Z
//             }
//         });

//         // Mettre à jour les vitesses dans le tableau
//         velocities[i * 3] = vx;
//         velocities[i * 3 + 1] = vy;
//         velocities[i * 3 + 2] = vz;
//     }
// }








// let interpolationFactor = 0; // Facteur d'interpolation pour les particules
// let lastColorChangeTime = Date.now(); // Temps du dernier changement de couleur
// const colorChangeInterval = 7000; // Intervalle de changement de couleur en millisecondes (3 secondes)
// let sphereColorIndex = 0; // Index de couleur pour la sphère
// let sphereInterpolationFactor = 0; // Facteur d'interpolation pour la sphère

// function moveSmokeAvoidObject() {
//     const bodyPosition = body.position; // Position de la balle
//     const influenceRadius = 3.5; // Rayon d'influence de la balle
//     const attractionStrength = 0.15; // Force d'attraction
//     const maxDistance = 12.5; // Distance maximale de déplacement des particules
//     const airResistance = 0.99; // Résistance de l'air
//     const dragCoefficient = 0.6; // Coefficient de traînée
//     const spread = 11.5; // Limite de la zone de déplacement des particules
//     const reboundFactor = 0.9; // Coefficient de rebond partiel
//     const dispersionStrength = 0.003; // Force de dispersion des particules

//     // const bodyPosition = body.position; // Position de la balle
//     // const influenceRadius = 3.7; // Rayon d'influence de la balle
//     // const attractionStrength = 0.12; // Force d'attraction
//     // const maxDistance = 18; // Distance maximale de déplacement des particules
//     // const airResistance = 0.98; // Résistance de l'air
//     // const dragCoefficient = 0.8; // Coefficient de traînée
//     // const spread = 11; // Limite de la zone de déplacement des particules
//     // const reboundFactor = 1; // Coefficient de rebond partiel
//     // const dispersionStrength = 0.003; // Force de dispersion des particules


//     // Vérifier si 3 secondes se sont écoulées depuis le dernier changement de couleur
//     const currentTime = Date.now();
//     if (currentTime - lastColorChangeTime >= colorChangeInterval) {
//         // Passer à la couleur suivante dans le cycle
//         currentColorIndex = (currentColorIndex + 1) % trailColors.length;
//         lastColorChangeTime = currentTime; // Mettre à jour le temps du dernier changement
//         interpolationFactor = 0; // Réinitialiser le facteur d'interpolation
//     }

//     // Interpoler entre la couleur actuelle et la suivante pour les particules
//     const currentColor = trailColors[currentColorIndex];
//     const nextColor = trailColors[(currentColorIndex + 1) % trailColors.length];
//     const interpolatedColor = currentColor.clone().lerp(nextColor, interpolationFactor);

//     // Interpoler entre la couleur actuelle et la suivante pour la sphère
//     const sphereCurrentColor = trailColors[sphereColorIndex];
//     const sphereNextColor = trailColors[(sphereColorIndex + 1) % trailColors.length];
//     const sphereInterpolatedColor = sphereCurrentColor.clone().lerp(sphereNextColor, sphereInterpolationFactor);

//     // Appliquer la couleur interpolée à la sphère
//     sphereMaterial.color.copy(sphereInterpolatedColor);

//     for (let i = 0; i < numberOfParticles; i++) {
//         // Récupérer les positions et vitesses des particules
//         let x = positions[i * 3];
//         let y = positions[i * 3 + 1];
//         let z = positions[i * 3 + 2];
//         let vx = velocities[i * 3];
//         let vy = velocities[i * 3 + 1];
//         let vz = velocities[i * 3 + 2];

//         // Calculer la direction d'attraction vers la balle
//         let dx = bodyPosition.x - x;
//         let dy = bodyPosition.y - y;
//         let dz = bodyPosition.z - z;
//         let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

//         // Si la particule est dans le rayon d'influence
//         if (distance < influenceRadius) {
//             const attractionForce = (influenceRadius - distance) / influenceRadius;
//             vx += (dx / distance) * attractionForce * attractionStrength * 6;
//             vy += (dy / distance) * attractionForce * attractionStrength;
//             vz += (dz / distance) * attractionForce * attractionStrength;

//             // Appliquer la couleur interpolée aux particules dans la traînée
//             colors[i * 3] = interpolatedColor.r;
//             colors[i * 3 + 1] = interpolatedColor.g;
//             colors[i * 3 + 2] = interpolatedColor.b;
//         }

//         // Appliquer la résistance de l'air en fonction de la vitesse
//         let speed = Math.sqrt(vx * vx + vy * vy + vz * vz);
//         let drag = dragCoefficient * speed * speed; // Force de traînée, proportionnelle au carré de la vitesse
//         let dragX = (vx / speed) * drag;
//         let dragY = (vy / speed) * drag;
//         let dragZ = (vz / speed) * drag;

//         // Appliquer la traînée aux vitesses
//         vx -= dragX;
//         vy -= dragY;
//         vz -= dragZ;

//         // Appliquer la résistance de l'air
//         vx *= airResistance;
//         vy *= airResistance;
//         vz *= airResistance;

//         // Appliquer la force de dispersion aux particules de la traînée
//         if (distance > influenceRadius && distance < maxDistance) {
//             vx += (Math.random() - 0.5) * dispersionStrength;
//             vy += (Math.random() - 0.5) * dispersionStrength;
//         }


//         // Déplacer la particule avec la vitesse mise à jour
//         x += vx;
//         y += vy;
//         z += vz;

//         // Limiter la distance de déplacement des particules
//         let distanceFromOrigin = Math.sqrt(x * x + y * y + z * z);
//         if (distanceFromOrigin > maxDistance) {
//             let scale = maxDistance / distanceFromOrigin;
//             x *= scale;
//             y *= scale;
//             z *= scale;
//         }


//         // Limiter les particules à l'intérieur de la zone fluide avec un rebond partiel
//         if (x < -spread || x > spread) vx *= -reboundFactor;
//         if (y < -spread || y > spread) vy *= -reboundFactor ;
//         if (z < -spread || z > spread) vz *= -reboundFactor;

//         // Réaffecter les nouvelles positions et vitesses
//         positions[i * 3] = x;
//         positions[i * 3 + 1] = y;
//         positions[i * 3 + 2] = z;
//         velocities[i * 3] = vx;
//         velocities[i * 3 + 1] = vy;
//         velocities[i * 3 + 2] = vz;
//     }

//     // Mettre à jour le facteur d'interpolation pour les particules
//     interpolationFactor += 0.001; // Ajustez cette valeur pour contrôler la vitesse de transition
//     if (interpolationFactor > 1) interpolationFactor = 1;

//     // Mettre à jour le facteur d'interpolation pour la sphère
//     sphereInterpolationFactor += 0.01; // Ajustez cette valeur pour contrôler la vitesse de transition
//     if (sphereInterpolationFactor > 1) {
//         sphereInterpolationFactor = 0;
//         sphereColorIndex = (sphereColorIndex + 1) % trailColors.length; // Passer à la couleur suivante
//     }

//     // Mettre à jour la géométrie avec les nouvelles positions et couleurs
//     smokeGeometry.attributes.position.needsUpdate = true;
//     smokeGeometry.attributes.color.needsUpdate = true;
// }

// ////////////////////////////////////////// CAMERA //////////////////////////////////////////
// /**
//  * Camera
//  */
// // Base camera
// const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
// camera.position.set( 18, 1, 0)
// scene.add(camera)


// // Controls
// const controls = new OrbitControls(camera, canvas)
// controls.enableDamping = true

// /**
//  * Renderer
//  */
// const renderer = new THREE.WebGLRenderer({
//     canvas: canvas
// })
// renderer.shadowMap.enabled = true
// renderer.shadowMap.type = THREE.PCFSoftShadowMap
// renderer.setSize(sizes.width, sizes.height)
// renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

// /**
//  * Animate
//  */
// const clock = new THREE.Clock()
// let oldElapsedTime = 0

// const tick = () =>
// {
//     const elapsedTime = clock.getElapsedTime()
//     const deltaTime = elapsedTime - oldElapsedTime
//     oldElapsedTime = elapsedTime
    
    
//     camera.position.z = Math.sin(elapsedTime) * 0.55; // Mouvement léger gauche-droite
// camera.position.y = Math.cos(elapsedTime) * 0.35; // Mouvement léger haut-bas




//     camera.lookAt(scene.position)

//     controls.update()
//     updateBoxes()
//     updateBall()
//    // moveSmoke()
//     moveSmokeAvoidObject( )
//     applyRepulsionFromFloors()
//     applyReturnForceToPaddles()
//     //updateParticlePositions()
 
    
//     world.step(1 / 60, deltaTime, 3)

//     mesh.position.copy(body.position)
//     floor.position.copy(floorBody.position)
//     floor2.position.copy(floorBody2.position)


//     const maxSpeed = 25;
//     // console.log(body.velocity)
//     //   console.log(maxSpeed)
//     if (body.velocity.length() < maxSpeed) {
//         // console.log("true")
//         body.velocity = body.velocity.unit().scale(maxSpeed);
//     }

//     // console.log(maxSpeed)
//     // if (body.velocity.z < maxSpeed) {
//     //     console.log("true")
//     //   //  body.velocity = body.velocity.unit().scale(maxSpeed);
//     //     if  (body.velocity.z < 0)
//     //         body.velocity.z =  - maxSpeed
//     //     else 
//     //          body.velocity.z =   maxSpeed

//     //     body.velocity.y =   body.velocity.y
//     //     body.velocity.x =  body.velocity.x  


//     // }
//     // console.log(body.velocity)
//     renderer.render(scene, camera)
//     window.requestAnimationFrame(tick)
// }
// tick()














import * as CANNON from 'https://cdn.jsdelivr.net/npm/cannon-es@0.20.0/dist/cannon-es.js';


// import * as THREE from 'three'
// import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
// import GUI from 'lil-gui'
// import CANNON, { Vec3 } from 'cannon'
// import * as CANNON from 'cannon-es'

// import { FontLoader } from 'https://unpkg.com/three@0.164.0/examples/jsm/loaders/FontLoader.js';
// import { TextGeometry } from 'https://unpkg.com/three@0.164.0/examples/jsm/geometries/TextGeometry.js';

// import { TextGeometry } from 'three/examples/jsm/geometries/TextGeometry.js'
// import { FontLoader } from 'three/examples/jsm/loaders/FontLoader.js'


//import { roughness } from 'three/tsl'

/**
 * Debug
 */

//const debugObject2 = {}

/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()
//scene.background = new THREE.Color("#fefae0");
//scene.background = new THREE.Color("#000000")
scene.background = new THREE.Color("#02010d")


// const axesHelper = new THREE.AxesHelper(5) // Longueur des axes = 5 unités
//scene.add(axesHelper)

//physics 
const world = new CANNON.World()
world.gravity.set(0, 0, 0)

// ////////////////////////////////////////////////////////////////////////////
// //##     ##    ###    ######## ######## ########  ####    ###    ##       //
// //###   ###   ## ##      ##    ##       ##     ##  ##    ## ##   ##       //
// //#### ####  ##   ##     ##    ##       ##     ##  ##   ##   ##  ##       //
// //## ### ## ##     ##    ##    ######   ########   ##  ##     ## ##       //
// //##     ## #########    ##    ##       ##   ##    ##  ######### ##       //
// //##     ## ##     ##    ##    ##       ##    ##   ##  ##     ## ##       //
// //##     ## ##     ##    ##    ######## ##     ## #### ##     ## ######## //
// ////////////////////////////////////////////////////////////////////////////

const textureLoader = new THREE.TextureLoader()

//const default_color = new THREE.Color("#880FeE")
const default_color = new THREE.Color("#000000")

    // Définir un tableau de 4 couleurs (vous pouvez les modifier selon vos préférences)
    const trailColors = [

       //design 1
      
      // new THREE.Color("#ed6f3c"), 
      new THREE.Color("#f05fF8"), 
      new THREE.Color("#df83f7"), 
      new THREE.Color("#e984f9"),
      new THREE.Color("#7445fb"), 
      new THREE.Color("#455cd0"), 

       new THREE.Color("#31309b"), 
       new THREE.Color("#221bFb"), 
    //     new THREE.Color("#691338"), 
    //   // new THREE.Color("#fc928e"), 

    ];
    let currentColorIndex = 0; // Index pour suivre la couleur actuelle dans le cycle
    


const normal = new THREE.MeshStandardMaterial({
    color : '#9F59ff',
    wireframe : true,
    side :  THREE.BackSide
})
normal.receiveShadow = true; 
normal.castShadow = true; 


const normal2 = new THREE.MeshStandardMaterial({
    color : '#1f50fF',
    wireframe : true,
    side :  THREE.BackSide
})
normal2.receiveShadow = true; 
normal2.castShadow = true; 

const normali = new THREE.MeshDepthMaterial({
    depthPacking: THREE.RGBADepthPacking, // Ou THREE.BasicDepthPacking
    blending: THREE.AdditiveBlending,
    side: THREE.DoubleSide, // Ou THREE.FrontSide / THREE.BackSide selon ton besoin
   // depthTest: true,
    //depthWrite: true,
  });
  

const paddle = new THREE.MeshStandardMaterial({
    //color: '#00BFFF',
    color: '#9F59ff',

    wireframe :true,
    metalness: 0.2,
   // side : THREE.BackSide
//    roughness: 0.2,
//     envMap: environmentMapTexture,
//     envMapIntensity: 0.5
})

const paddle2 = new THREE.MeshStandardMaterial({
   // color: '#BF00FF',
    color: '#1f50fF',

    wireframe :true,
    metalness: 0.2,
})
const cageMaterial = new THREE.MeshStandardMaterial({
    // color: '#BF00FF',
     color: '#00FF00',
 
     wireframe :true,
     metalness: 0.2,
 })



const toonMaterial = new THREE.MeshToonMaterial({
   // color: 0xffcc00,   // Couleur jaune cartoon
    //gradientMap: null,  // Utilise le shading par défaut
})

const normal_material = new THREE.MeshNormalMaterial()
//normal_material.flatShading = true

const defaultMaterial = new CANNON.Material('default')
const defaultContactMaterial = new CANNON.ContactMaterial(
    defaultMaterial,
    defaultMaterial,
    {
        friction: 0,
        restitution: 1
    }
)
world.addContactMaterial(defaultContactMaterial)
world.defaultContactMaterial = defaultContactMaterial

////////////////////////////////////////////////////////////
// ######  ########  ##     ## ######## ########  ########//
//##    ## ##     ## ##     ## ##       ##     ## ##      //
//##       ##     ## ##     ## ##       ##     ## ##      //
// ######  ########  ######### ######   ########  ######  //
//      ## ##        ##     ## ##       ##   ##   ##      //
//##    ## ##        ##     ## ##       ##    ##  ##      //
// ######  ##        ##     ## ######## ##     ## ########//
////////////////////////////////////////////////////////////

const sphereGeometry = new THREE.SphereGeometry(0.8, 7, 12)
const sphereMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.3,
    roughness: 0.1,
    wireframe : true,
    color: '#00FF00',
    side: THREE.DoubleSide
    })

// const sphereMaterial = new THREE.MeshMatcapMaterial(    
//     { 
//         matcap: matcapTexture 
//     })


const shape = new CANNON.Sphere(0.5)
const body = new CANNON.Body({
    mass: 1.3,
    position: new CANNON.Vec3(0,0,0),
    shape: shape,
    material: defaultMaterial,
    velocity: new CANNON.Vec3(0, 0, 0)
})
// body.position.copy(position)
world.addBody(body)

const mesh = new THREE.Mesh(sphereGeometry, sphereMaterial)
mesh.castShadow = true
mesh.scale.set(0.5, 0.5, 0.5)
mesh.position.copy(body.position)
scene.add(mesh)

const ecart = 12;
//const paddleHeight = 2.5

// let params = { paddleHeight: 2.5 };
// let paddleHeight = 2.5


//////////////////////////////////////////////////////////////////////////
//########     ###    ########  ######## ####  ######  ##       ########//
//##     ##   ## ##   ##     ##    ##     ##  ##    ## ##       ##      //
//##     ##  ##   ##  ##     ##    ##     ##  ##       ##       ##      //
//########  ##     ## ########     ##     ##  ##       ##       ######  //
//##        ######### ##   ##      ##     ##  ##       ##       ##      //
//##        ##     ## ##    ##     ##     ##  ##    ## ##       ##      //
//##        ##     ## ##     ##    ##    ####  ######  ######## ########//
//////////////////////////////////////////////////////////////////////////

const numberOfParticles = 140000;
const spread = 14;  // Plage de répartition des particules
const speed = 0.002; // Vitesse de déplacement des particules
const positions = new Float32Array(numberOfParticles * 3);  // Un tableau pour les positions des particules
const velocities = new Float32Array(numberOfParticles * 3);  // Un tableau pour les vitesses des particules


const colors = new Float32Array(numberOfParticles * 3);
// Ajouter des particules à la géométrie avec une direction aléatoire
for (let i = 0; i < numberOfParticles; i++) {
    // Positionner aléatoirement les particules dans une zone définie 
    
    const x = (Math.random() * 2 - 1) * 4;  // Plage de x : [-spread, spread]
    const y = (Math.random() * 2 - 1) * 8 ;  // Plage de y : [-spread, spread]
    const z = (Math.random() * 2 - 1) * 10;  // Plage de z : [-spread, spread]

    positions[i * 3] = x;
    positions[i * 3 + 1] = y;
    positions[i * 3 + 2] = z;

    // Initialisation d'une vitesse aléatoire (petite variation pour chaque direction)
    velocities[i * 3] = (Math.random() - 0.5) * speed * 0.1;
    velocities[i * 3 + 1] = (Math.random() - 0.5) * speed * 0.1;
    velocities[i * 3 + 2] = (Math.random() - 0.5) * speed * 0.1;


       // Couleur initiale (par exemple, magenta)
   colors[i * 3] = default_color.r
   colors[i * 3 + 1] = default_color.g// Vert
   colors[i * 3 + 2] = default_color.b
   

    // Application de la friction
    const friction = 0.99; // Coefficient de friction, ajuste pour une dissipation plus ou moins forte
    velocities[i * 3] *= friction;
    velocities[i * 3 + 1] *= friction;
    velocities[i * 3 + 2] *= friction;

    // Application des turbulences
    const turbulenceStrength = 0.02; // Force des turbulences
    velocities[i * 3] += (Math.random() - 0.5) * turbulenceStrength;
    velocities[i * 3 + 1] += (Math.random() - 0.5) * turbulenceStrength;
    velocities[i * 3 + 2] += (Math.random() - 0.5) * turbulenceStrength;
}

// Créer un BufferGeometry pour les particules
const smokeGeometry = new THREE.BufferGeometry();
smokeGeometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
smokeGeometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));



// Créer un matériau pour les particules
const smokeTexture = new THREE.TextureLoader().load('static/particles/9.png');

const smokeMaterial = new THREE.PointsMaterial({
    color: "#FFFFFF",
    
    size: 0.00023,
    transparent: true,
    opacity: 0.4,
    blending: THREE.AdditiveBlending,


    map: smokeTexture,
    alphaMap: smokeTexture,
    vertexColors : true,
  //  map: particleTexture,
   // alphaTest: 0.5, // Ajustez cette valeur si nécessaire
   
    depthWrite: false
});
   // opacity: Math.max(0.1, 0.5 * 0.99), // Ajustez l'opacité selon vos besoins

// Créer le système de particules
const smoke = new THREE.Points(smokeGeometry, smokeMaterial);
scene.add(smoke);


    smokeGeometry.attributes.position.needsUpdate = true;


////////////////////////////////////////////////////////////////////////////////////////////////////
//########  ##          ###    ##    ##  ######   ########   #######  ##     ## ##    ## ######## //
//##     ## ##         ## ##    ##  ##  ##    ##  ##     ## ##     ## ##     ## ###   ## ##     ##//
//##     ## ##        ##   ##    ####   ##        ##     ## ##     ## ##     ## ####  ## ##     ##//
//########  ##       ##     ##    ##    ##   #### ########  ##     ## ##     ## ## ## ## ##     ##//
//##        ##       #########    ##    ##    ##  ##   ##   ##     ## ##     ## ##  #### ##     ##//
//##        ##       ##     ##    ##    ##    ##  ##    ##  ##     ## ##     ## ##   ### ##     ##//
//##        ######## ##     ##    ##     ######   ##     ##  #######   #######  ##    ## ######## //
////////////////////////////////////////////////////////////////////////////////////////////////////


// const floorShape = new CANNON.Box(new CANNON.Vec3(2, paddleHeight, 1)); 
const floorShape = new CANNON.Box(new CANNON.Vec3(4, 2, 0.05));// Une boîte fine comme mur
const floorBody = new CANNON.Body({
    mass: 0,
    shape: floorShape,
    material: defaultMaterial,
    position: new CANNON.Vec3(0, 0, ecart) 
})
world.addBody(floorBody);

const floor = new THREE.Mesh(new THREE.BoxGeometry(3, 4, 1, 1 ,1), paddle)
  


//floor.receiveShadow = true;
floor.position.set(0, 0, ecart);
floor.wireframe = true

floor.position.copy(floorBody.position)
scene.add(floor);

////////////////////////////////////////////////// PADDLE2 //////////////


const floorShape2 = new CANNON.Box(new CANNON.Vec3(4, 2, 0.05));
const floorBody2 = new CANNON.Body({
    mass: 0,
    shape: floorShape2,
    material: defaultMaterial,
    position: new CANNON.Vec3(0, 0, -ecart)
});
world.addBody(floorBody2);

const floor2 = new THREE.Mesh(
   //new THREE.BoxGeometry(2, paddleHeight * 2, 2, 6 ,6), 
    new THREE.BoxGeometry(3, 4, 1, 1 ,1), paddle2)

//floor2.receiveShadow = true;
floor2.position.set(0, 0, -ecart);
floor2.position.copy(floorBody2.position)
scene.add(floor2);

////////////////////////////////////////////////// CAGE //////////////

const cage = new THREE.Mesh(
new THREE.BoxGeometry(5, 20, 24 , 1, 0, 2), cageMaterial)
scene.add(cage);



/**
 * Sizes
 */
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () =>
{
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

//////////////////////////////////////////////////////////////////////////////
// ######   #######  ##    ## ######## ########   #######  ##        ###### //
//##    ## ##     ## ###   ##    ##    ##     ## ##     ## ##       ##    ##//
//##       ##     ## ####  ##    ##    ##     ## ##     ## ##       ##      //
//##       ##     ## ## ## ##    ##    ########  ##     ## ##        ###### //
//##       ##     ## ##  ####    ##    ##   ##   ##     ## ##             ##//
//##    ## ##     ## ##   ###    ##    ##    ##  ##     ## ##       ##    ##//
// ######   #######  ##    ##    ##    ##     ##  #######  ########  ###### //
//////////////////////////////////////////////////////////////////////////////

const keys = {};

window.addEventListener("keydown", (event) => { keys[event.key] = true; });
window.addEventListener("keyup", (event) => { keys[event.key] = false; });

const hauteur = 8
const updateBoxes = () => {
    const speed = 0.35 // Vitesse du déplacement

    if (keys["a"] && floorBody.position.y < hauteur) {
        floorBody.position.y += speed;
        floor.position.y = floorBody.position.y;
    }
    if (keys["q"] && floorBody.position.y > -hauteur) {
        floorBody.position.y -= speed;
        floor.position.y = floorBody.position.y;
    }
    if (keys["p"] && floorBody2.position.y < hauteur) {
        floorBody2.position.y += speed;
        floor2.position.y = floorBody2.position.y;
    }
    if (keys["m"] && floorBody2.position.y > -hauteur) {
        floorBody2.position.y -= speed;
        floor2.position.y = floorBody2.position.y;
    }
}

 body.velocity.set(0, 0, 20); // Déplacement uniquement sur x et y


//////////////////////////////////////////////////////////////////////
//########     ###    ########  ########  ##       ########  ###### //
//##     ##   ## ##   ##     ## ##     ## ##       ##       ##    ##//
//##     ##  ##   ##  ##     ## ##     ## ##       ##       ##      //
//########  ##     ## ##     ## ##     ## ##       ######    ###### //
//##        ######### ##     ## ##     ## ##       ##             ##//
//##        ##     ## ##     ## ##     ## ##       ##       ##    ##//
//##        ##     ## ########  ########  ######## ########  ###### //
//////////////////////////////////////////////////////////////////////

const epsilon = 2 //tolerance pour nombre fllottant
let count = 0
let count_1 = 3
let count_2 = 3


function checkCollision_paddle(ball, paddle) {
    let paddleHeight = 2; // longueur raquette


   if (Math.abs(ball.position.z - paddle.position.z) < epsilon)  // balle au niveau de raquette pour collision
    { 
            if (ball.position.y >= paddle.position.y - paddleHeight && ball.position.y <= paddle.position.y + paddleHeight) {
                ball.velocity.z *= -1;  // Réverser la direction sur Z lors du rebond
            }
        if ((ball.position.y > paddle.position.y + paddleHeight) || ( ball.position.y < paddle.position.y - paddleHeight)) 
                return
        if (body.position.y < 10 || body.position.y > -10)
        { 
            if ((ball.position.y < paddle.position.y + paddleHeight) && ( ball.position.y > paddle.position.y - paddleHeight))  
            {

                ball.velocity.y *= -1;
                let impact = (ball.position.y -  paddle.position.y) / (paddleHeight / 2); //entre -1 et 1
                ball.velocity.y = impact * 7; //angle de rebond
                   // Pour inverser la direction de la balle sur l'axe Z en fonction de la raquette (si elle touche la raquette 2)
            if (ball.position.z > paddle.position.z)
                {
                    ball.velocity.z = Math.abs(ball.velocity.z); // Ball rebounding in positive Z direction
                } 
            else 
                {
                    ball.velocity.z = -Math.abs(ball.velocity.z); // Ball rebounding in negative Z direction
                }
            }
        }
        
    }
}

 function updateBall() {
     
     checkCollision_paddle (body, floor); // Raquette gauche
     checkCollision_paddle(body, floor2); // Raquette droitea
     if (body.position.y >= 10) { 
         body.velocity.y *= -1;
         body.position.y = 9.9; // Évite de rester pile à 10
         count++;
         } 
     else if (body.position.y <= -10) 
        { 
         body.velocity.y *= -1;
         body.position.y = -9.9; // Évite de rester pile à -10
         count++;
     }
     if (body.position.z < -30)
         {
            
             //count_1--
             body.position.set(0, 0, 0)
             body.velocity.set(0, 0, 20)
             updateText()
             if(count_1 == 0) 
                {
                 body.position.set(0, 0, 0)
                 body.velocity.set(10, 0, 0)
                 }
         }
     if (body.position.z > 30 )
         {
           //  count_2--
             updateText2()
             body.position.set(0, 0, 0)
             body.velocity.set(0, 0, 20)
             if(count_2 == 0)
             {
                 body.position.set(0, 0, 0)
                 body.velocity.set(10, 0, 0)
             }
         }
    }
 
 
//////////////////////////////////////////////////
//########  #######  ##    ## ########  ######  //
//##       ##     ## ###   ##    ##    ##    ## //
//##       ##     ## ####  ##    ##    ##       //
//######   ##     ## ## ## ##    ##     ######  //
//##       ##     ## ##  ####    ##          ## //
//##       ##     ## ##   ###    ##    ##    ## //
//##        #######  ##    ##    ##     ######  //
//////////////////////////////////////////////////
//8    8888 8888 88888//
//8    8www 8www   8  //
//8    8    8      8  //
//8888 8888 8      8  //
////////////////////////


const fontLoader = new THREE.FontLoader();

let text
let updateText
let score = 0

let rotationSpeed_ = 0.20; // Vitesse de rotation
let jumpHeight_ = 1; // Hauteur du bond
let rotationCount_ = 0;
let maxRotations_ = Math.PI * 2; // Une rotation complète
let startY_;

const textPivot = new THREE.Group();
scene.add(textPivot);

fontLoader.load(
    'static/fonts/helvetiker_regular.typeface.json',
    (font) => {
        const textGeometry = new THREE.TextGeometry(
            score.toString(), // Affiche "0" au début
            {
                font: font,
                size: 2,
                depth: 0.2,
                curveSegments: 2,
                bevelThickness: 0.03,
                bevelSize: 0.02,
                bevelOffset: 0,
                bevelSegments: 1
            }
        );

        // Centrer la géométrie initiale
        textGeometry.computeBoundingBox();
        const box_ = textGeometry.boundingBox;

   


        const centerX_ = (box_.max.x + box_.min.x) / 2;
        const centerY_ = (box_.max.y + box_.min.y) / 2;
        const centerZ_ = (box_.max.z + box_.min.z) / 2;
        textGeometry.translate(-centerX_, -centerY_, -centerZ_);

        text = new THREE.Mesh(textGeometry, normal);
        text.position.set(10, -3, 8);
        text.rotation.y = Math.PI / 2;
        startY_ = text.position.y;

        scene.add(text);

        // Fonction pour mettre à jour le texte
        updateText = function () {
            score++;
            text.geometry.dispose();

            // Créer une nouvelle géométrie pour le texte
            const newTextGeometry = new THREE.TextGeometry(score.toString(), {
                font: font,
                size: 2,
                depth: 0.2,
                curveSegments: 2,
                bevelThickness: 0.03,
                bevelSize: 0.02,
                bevelOffset: 0,
                bevelSegments: 1
            });

            // Centrer la nouvelle géométrie
            newTextGeometry.computeBoundingBox();
            const newBox = newTextGeometry.boundingBox;

    
            const newCenterX = (newBox.max.x + newBox.min.x) / 2;
            const newCenterY = (newBox.max.y + newBox.min.y) / 2;
            const newCenterZ = (newBox.max.z + newBox.min.z) / 2;
            newTextGeometry.translate(-newCenterX, -newCenterY, -newCenterZ);

            // Appliquer la nouvelle géométrie au texte
            text.geometry = newTextGeometry;

            // Réinitialiser la rotation et démarrer l'animation
            rotationCount_ = 0;
            animateRotation_();
        };

        // Démarrer l'animation initiale
        animateRotation_();
    }
);



function animateRotation_() {
    if (rotationCount_ < maxRotations_) {
        // Appliquer la rotation
        text.rotation.y += rotationSpeed_;

        // Appliquer le bond en sinus
        text.position.y = startY_ + Math.sin(rotationCount_) * jumpHeight_;

        // Incrémenter le compteur de rotation
        rotationCount_ += rotationSpeed_;

        // Continuer l'animation
        requestAnimationFrame(animateRotation_);
    } else {
        // Réinitialiser la rotation après un tour complet
        text.rotation.y = Math.PI / 2; // ou une autre valeur initiale si nécessaire
        rotationCount_ = 0; // Réinitialiser le compteur de rotation
    }
}


////////////////////////////////
//888b. 888 .d88b  8   8 88888//
//8  .8  8  8P www 8www8   8  //
//8wwK'  8  8b  d8 8   8   8  //
//8  Yb 888 `Y88P' 8   8   8  //
////////////////////////////////

let text2;
let updateText2;
let score2 = 0;

// Variables pour l'animation
let rotationSpeed = 0.20; // Vitesse de rotation
let jumpHeight = 1; // Hauteur du bond
let rotationCount = 0;
let maxRotations = Math.PI * 2; // Une rotation complète
let startY;


const text2Pivot = new THREE.Group();
scene.add(text2Pivot);

fontLoader.load(
    'static/fonts/helvetiker_regular.typeface.json',
    (font) => {
        const text2Geometry = new THREE.TextGeometry(
            score2.toString(), // Affiche "0" au début
            {
                font: font,
                size: 1.9,
                depth: 0.2,
                curveSegments: 2,
                bevelThickness: 0.03,
                bevelSize: 0.02,
                bevelOffset: 0,
                bevelSegments: 1
            }
        );

        // Centrer la géométrie initiale
        text2Geometry.computeBoundingBox();
        const box = text2Geometry.boundingBox;

  

        const centerX = (box.max.x + box.min.x) / 2;
        const centerY = (box.max.y + box.min.y) / 2;
        const centerZ = (box.max.z + box.min.z) / 2;
        text2Geometry.translate(-centerX, -centerY, -centerZ);

        text2 = new THREE.Mesh(text2Geometry, normal2);
        text2.position.set(10, -3.2, -7.8);
        text2.rotation.y = Math.PI / 2;
        startY = text2.position.y;

        scene.add(text2);

        // Fonction pour mettre à jour le text2e
        updateText2 = function () {
            score2 ++;
            text2.geometry.dispose();

            // Créer une nouvelle géométrie pour le text2e
            const newText2Geometry = new THREE.TextGeometry(score2.toString(), {
                font: font,
                size: 2,
                depth: 0.2,
                curveSegments: 2,
                bevelThickness: 0.03,
                bevelSize: 0.02,
                bevelOffset: 0,
                bevelSegments: 1
            });

            // Centrer la nouvelle géométrie
            newText2Geometry.computeBoundingBox();
            const new2Box = newText2Geometry.boundingBox;


        
            const new2CenterX = (new2Box.max.x + new2Box.min.x) / 2;
            const new2CenterY = (new2Box.max.y + new2Box.min.y) / 2;
            const new2CenterZ = (new2Box.max.z + new2Box.min.z) / 2;
            newText2Geometry.translate(-new2CenterX, -new2CenterY, -new2CenterZ);

            // Appliquer la nouvelle géométrie au texte
            text2.geometry = newText2Geometry;

            // Réinitialiser la rotation et démarrer l'animation
            rotationCount = 0;
            animateRotation();
        };

        // Démarrer l'animation initiale
        animateRotation();
    }
);



function animateRotation() {
    if (rotationCount < maxRotations) {
        // Appliquer la rotation
        text2.rotation.y += rotationSpeed;

        // Appliquer le bond en sinus
        text2.position.y = startY + Math.sin(rotationCount) * jumpHeight;

        // Incrémenter le compteur de rotation
        rotationCount += rotationSpeed;

        // Continuer l'animation
        requestAnimationFrame(animateRotation);
    } else {
        // Réinitialiser la rotation après un tour complet
        text2.rotation.y = Math.PI / 2; // ou une autre valeur initiale si nécessaire
        rotationCount = 0; // Réinitialiser le compteur de rotation
    }
}

////////////////////////////////////////////////////////////////////////////////////
//########  ######## ########  ##     ## ##        ######  ####  #######  ##    ##//
//##     ## ##       ##     ## ##     ## ##       ##    ##  ##  ##     ## ###   ##//
//##     ## ##       ##     ## ##     ## ##       ##        ##  ##     ## ####  ##//
//########  ######   ########  ##     ## ##        ######   ##  ##     ## ## ## ##//
//##   ##   ##       ##        ##     ## ##             ##  ##  ##     ## ##  ####//
//##    ##  ##       ##        ##     ## ##       ##    ##  ##  ##     ## ##   ###//
//##     ## ######## ##         #######  ########  ######  ####  #######  ##    ##//
////////////////////////////////////////////////////////////////////////////////////


function applyRepulsionFromFloors() {
    const repulsionStrength = 1.5; // Force de répulsion
    const repulsionDistance = 1.5; // Distance à laquelle la répulsion commence

    for (let i = 0; i < numberOfParticles; i++) {
        // Récupérer les positions et vitesses des particules
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        // Tableau des positions des paddles
        const paddles = [floorBody.position, floorBody2.position];

        paddles.forEach(paddlePos => {
            // Calculer la distance entre la particule et le paddle
            let dx = x - paddlePos.x;
            let dy = y - paddlePos.y;
            let dz = z - paddlePos.z;
            let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

            // Si la particule est suffisamment proche du paddle
            if (distance < repulsionDistance) {
                // Calculer la force de répulsion
                let repulsionForce = repulsionStrength / (distance * distance);
                vx += (dx / distance) * repulsionForce;
                vy += (dy / distance) * repulsionForce;
                vz += (dz / distance) * repulsionForce;
            }

            
        });

        // Mettre à jour les vitesses dans le tableau
        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }

}
function applyReturnForceToPaddles() {
    const returnStrengthX = 0.005; // Intensité du retour en X
    const returnStrengthY = 0.0; // Intensité du retour en Y
    const returnStrengthZ = 0.0; // Intensité du retour en Z
    const maxDistance = 2.0; // Distance maximale avant que la force commence à agir

    for (let i = 0; i < numberOfParticles; i++) {
        // Récupérer les positions et vitesses des particules
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        // Tableau des positions des paddles
        const paddles = [floorBody.position, floorBody2.position];

        paddles.forEach(paddlePos => {
            // Calculer les distances de la particule au paddle sur chaque axe
            let dx = x - paddlePos.x;
            let dy = y - paddlePos.y;
            let dz = z - paddlePos.z;

            // Appliquer une force de retour si la particule dépasse `maxDistance`
            if (Math.abs(dx) > maxDistance) {
                vx -= (dx / Math.abs(dx)) * returnStrengthX; // Ramène vers le paddle sur X
            }
            if (Math.abs(dy) > maxDistance) {
                vy -= (dy / Math.abs(dy)) * returnStrengthY; // Ramène vers le paddle sur Y
            }
            if (Math.abs(dz) > maxDistance) {
                vz -= (dz / Math.abs(dz)) * returnStrengthZ; // Ramène vers le paddle sur Z
            }
        });

        // Mettre à jour les vitesses dans le tableau
        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//########  #######  ########   ######  ########    ######## #### ######## ##       ########  //
//##       ##     ## ##     ## ##    ## ##          ##        ##  ##       ##       ##     ## //
//##       ##     ## ##     ## ##       ##          ##        ##  ##       ##       ##     ## //
//######   ##     ## ########  ##       ######      ######    ##  ######   ##       ##     ## //
//##       ##     ## ##   ##   ##       ##          ##        ##  ##       ##       ##     ## //
//##       ##     ## ##    ##  ##    ## ##          ##        ##  ##       ##       ##     ## //
//##        #######  ##     ##  ######  ########    ##       #### ######## ######## ########  //
////////////////////////////////////////////////////////////////////////////////////////////////


let interpolationFactor = 0; // Facteur d'interpolation pour les particules
let lastColorChangeTime = Date.now(); // Temps du dernier changement de couleur
const colorChangeInterval = 7000; // Intervalle de changement de couleur en millisecondes (3 secondes)
let sphereColorIndex = 0; // Index de couleur pour la sphère
let sphereInterpolationFactor = 0; // Facteur d'interpolation pour la sphère

function moveSmokeAvoidObject() {
    const bodyPosition = body.position; // Position de la balle
    const influenceRadius = 3.5; // Rayon d'influence de la balle
    const attractionStrength = 0.15; // Force d'attraction
    const maxDistance = 12.5; // Distance maximale de déplacement des particules
    const airResistance = 0.99; // Résistance de l'air
    const dragCoefficient = 0.6; // Coefficient de traînée
    const spread = 11.5; // Limite de la zone de déplacement des particules
    const reboundFactor = 0.9; // Coefficient de rebond partiel
    const dispersionStrength = 0.003; // Force de dispersion des particules



    // Vérifier si 3 secondes se sont écoulées depuis le dernier changement de couleur
    const currentTime = Date.now();
    if (currentTime - lastColorChangeTime >= colorChangeInterval) {
        // Passer à la couleur suivante dans le cycle
        currentColorIndex = (currentColorIndex + 1) % trailColors.length;
        lastColorChangeTime = currentTime; // Mettre à jour le temps du dernier changement
        interpolationFactor = 0; // Réinitialiser le facteur d'interpolation
    }

    // Interpoler entre la couleur actuelle et la suivante pour les particules
    const currentColor = trailColors[currentColorIndex];
    const nextColor = trailColors[(currentColorIndex + 1) % trailColors.length];
    const interpolatedColor = currentColor.clone().lerp(nextColor, interpolationFactor);

    // Interpoler entre la couleur actuelle et la suivante pour la sphère
    const sphereCurrentColor = trailColors[sphereColorIndex];
    const sphereNextColor = trailColors[(sphereColorIndex + 1) % trailColors.length];
    const sphereInterpolatedColor = sphereCurrentColor.clone().lerp(sphereNextColor, sphereInterpolationFactor);

    // Appliquer la couleur interpolée à la sphère
    sphereMaterial.color.copy(sphereInterpolatedColor);

    for (let i = 0; i < numberOfParticles; i++) {
        // Récupérer les positions et vitesses des particules
        let x = positions[i * 3];
        let y = positions[i * 3 + 1];
        let z = positions[i * 3 + 2];
        let vx = velocities[i * 3];
        let vy = velocities[i * 3 + 1];
        let vz = velocities[i * 3 + 2];

        // Calculer la direction d'attraction vers la balle
        let dx = bodyPosition.x - x;
        let dy = bodyPosition.y - y;
        let dz = bodyPosition.z - z;
        let distance = Math.sqrt(dx * dx + dy * dy + dz * dz);

        // Si la particule est dans le rayon d'influence
        if (distance < influenceRadius) {
            const attractionForce = (influenceRadius - distance) / influenceRadius;
            vx += (dx / distance) * attractionForce * attractionStrength * 6;
            vy += (dy / distance) * attractionForce * attractionStrength;
            vz += (dz / distance) * attractionForce * attractionStrength;

            // Appliquer la couleur interpolée aux particules dans la traînée
            colors[i * 3] = interpolatedColor.r;
            colors[i * 3 + 1] = interpolatedColor.g;
            colors[i * 3 + 2] = interpolatedColor.b;
        }

        // Appliquer la résistance de l'air en fonction de la vitesse
        let speed = Math.sqrt(vx * vx + vy * vy + vz * vz);
        let drag = dragCoefficient * speed * speed; // Force de traînée, proportionnelle au carré de la vitesse
        let dragX = (vx / speed) * drag;
        let dragY = (vy / speed) * drag;
        let dragZ = (vz / speed) * drag;

        // Appliquer la traînée aux vitesses
        vx -= dragX;
        vy -= dragY;
        vz -= dragZ;

        // Appliquer la résistance de l'air
        vx *= airResistance;
        vy *= airResistance;
        vz *= airResistance;

        // Appliquer la force de dispersion aux particules de la traînée
        if (distance > influenceRadius && distance < maxDistance) {
            vx += (Math.random() - 0.5) * dispersionStrength;
            vy += (Math.random() - 0.5) * dispersionStrength;
        }


        // Déplacer la particule avec la vitesse mise à jour
        x += vx;
        y += vy;
        z += vz;

        // Limiter la distance de déplacement des particules
        let distanceFromOrigin = Math.sqrt(x * x + y * y + z * z);
        if (distanceFromOrigin > maxDistance) {
            let scale = maxDistance / distanceFromOrigin;
            x *= scale;
            y *= scale;
            z *= scale;
        }

        // Limiter les particules à l'intérieur de la zone fluide avec un rebond partiel
        if (x < -spread || x > spread) vx *= -reboundFactor;
        if (y < -spread || y > spread) vy *= -reboundFactor ;
        if (z < -spread || z > spread) vz *= -reboundFactor;

        // Réaffecter les nouvelles positions et vitesses
        positions[i * 3] = x;
        positions[i * 3 + 1] = y;
        positions[i * 3 + 2] = z;
        velocities[i * 3] = vx;
        velocities[i * 3 + 1] = vy;
        velocities[i * 3 + 2] = vz;
    }

    // Mettre à jour le facteur d'interpolation pour les particules
    interpolationFactor += 0.001; // Ajustez cette valeur pour contrôler la vitesse de transition
    if (interpolationFactor > 1) interpolationFactor = 1;

    // Mettre à jour le facteur d'interpolation pour la sphère
    sphereInterpolationFactor += 0.01; // Ajustez cette valeur pour contrôler la vitesse de transition
    if (sphereInterpolationFactor > 1) {
        sphereInterpolationFactor = 0;
        sphereColorIndex = (sphereColorIndex + 1) % trailColors.length; // Passer à la couleur suivante
    }

    // Mettre à jour la géométrie avec les nouvelles positions et couleurs
    smokeGeometry.attributes.position.needsUpdate = true;
    smokeGeometry.attributes.color.needsUpdate = true;
}

//////////////////////////////////////////////
//##       ####  ######   ##     ## ########//
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##        ##     ##    ##   //
//##        ##  ##   #### #########    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//##        ##  ##    ##  ##     ##    ##   //
//######## ####  ######   ##     ##    ##   //
//////////////////////////////////////////////

const ambientLight = new THREE.AmbientLight(0xffffff, 2.1)
scene.add(ambientLight)

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.6)
directionalLight.castShadow = true
directionalLight.shadow.mapSize.set(1024, 1024)
directionalLight.shadow.camera.far = 15
directionalLight.shadow.camera.left = - 7
directionalLight.shadow.camera.top = 7
directionalLight.shadow.camera.right = 7
directionalLight.shadow.camera.bottom = - 7
directionalLight.position.set(5, 5, 5)
scene.add(directionalLight)

// //////////////////////////////////////////////////////////////
// // ######     ###    ##     ## ######## ########     ###    //
// //##    ##   ## ##   ###   ### ##       ##     ##   ## ##   //
// //##        ##   ##  #### #### ##       ##     ##  ##   ##  //
// //##       ##     ## ## ### ## ######   ########  ##     ## //
// //##       ######### ##     ## ##       ##   ##   ######### //
// //##    ## ##     ## ##     ## ##       ##    ##  ##     ## //
// // ######  ##     ## ##     ## ######## ##     ## ##     ## //
// //////////////////////////////////////////////////////////////

// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.set( 18, 1, 0)
scene.add(camera)


// Controls
const controls = new THREE.OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

// ////////////////////////////////////
// //######## ####  ######  ##    ## //
// //   ##     ##  ##    ## ##   ##  //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##       #####    //
// //   ##     ##  ##       ##  ##   //
// //   ##     ##  ##    ## ##   ##  //
// //   ##    ####  ######  ##    ## //
// ////////////////////////////////////

const clock = new THREE.Clock();
let oldElapsedTime = 0;
let isPaused = false;

// Fonction de boucle de jeu (tick)
function tick() {
    if (isPaused) return;  // Si le jeu est en pause, arrêter la boucle ici.

    const elapsedTime = clock.getElapsedTime();
    const deltaTime = elapsedTime - oldElapsedTime;
    oldElapsedTime = elapsedTime;

    camera.position.z = Math.sin(elapsedTime) * 0.55; // Mouvement léger gauche-droite
    camera.position.y = Math.cos(elapsedTime) * 0.35; // Mouvement léger haut-bas
    camera.lookAt(scene.position);

    controls.update();
    updateBoxes();
    updateBall();
    moveSmokeAvoidObject();
    applyRepulsionFromFloors();
    applyReturnForceToPaddles();

    world.step(1 / 60, deltaTime, 3);

    mesh.position.copy(body.position);
    floor.position.copy(floorBody.position);
    floor2.position.copy(floorBody2.position);

    const maxSpeed = 25;
    if (body.velocity.length() < maxSpeed) {
        body.velocity = body.velocity.unit().scale(maxSpeed);
    }

    renderer.render(scene, camera);
    window.requestAnimationFrame(tick);
}

// Gestion du clavier : mettre en pause avec la touche espace
window.addEventListener('keydown', (event) => {
    if (event.code === 'Space') {
        togglePause();
    }
}); 

// //////////////////////////////////////////////////
// //######## ##     ## ######## ##    ## ######## //
// //##       ##     ## ##       ###   ##    ##    //
// //##       ##     ## ##       ####  ##    ##    //
// //######   ##     ## ######   ## ## ##    ##    //
// //##        ##   ##  ##       ##  ####    ##    //
// //##         ## ##   ##       ##   ###    ##    //
// //########    ###    ######## ##    ##    ##    //
// //////////////////////////////////////////////////


// // Lier un événement de clic sur le bouton de pause
// const pauseButton = document.querySelector('.pause');  // Le bouton avec la classe .pause
// pauseButton.addEventListener('click', () => {
//     togglePause();  // Mettre en pause ou reprendre le jeu
// });

const pause = document.querySelectorAll('.pause');
pause.forEach(bouton => {
    bouton.addEventListener('click', function() {
        togglePause();
    });
});

function togglePause() {
    if (isPaused) {
        isPaused = false;
        oldElapsedTime = clock.getElapsedTime(); // Reset du temps pour éviter un gros saut
        tick();  // Relancer la boucle si le jeu reprend
    } else {
        isPaused = true;
    }
}

tick();  // Lancer la boucle de jeu dès le début
