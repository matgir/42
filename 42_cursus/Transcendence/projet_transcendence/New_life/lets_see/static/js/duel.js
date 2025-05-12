export function initialize() {

  document.documentElement.scrollTop = 0; // Assurez-vous que la page commence en haut
  document.body.scrollTop = 0; // For Safari

  // Scroll the avatar section into view shortly after initialization
  // Using requestAnimationFrame helps ensure the browser is ready for layout changes
  requestAnimationFrame(() => {
    setTimeout(() => { // Small delay to ensure elements are rendered
      const avatarSection = document.querySelector('.avatar-section');
      if (avatarSection) {
        avatarSection.scrollIntoView({ behavior: 'smooth', block: 'start' });
      } else {
        console.warn("Avatar section not found for initial scroll.");
      }
    }, 100); // 100ms delay, can be adjusted
  });

  // Remove scrolling-enabled class initially
  const scrollContainer = document.querySelector('.scroll-container');
  if (scrollContainer) {
    scrollContainer.classList.remove('scrolling-enabled');
  }

  document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('section').classList.add('fade-in');
});

  
// Désactiver le défilement manuel
window.addEventListener('wheel', function(e) {
    e.preventDefault();
}, { passive: false });

window.addEventListener('keydown', function(e) {
    if (e.key === 'ArrowUp' || e.key === 'ArrowDown' || e.key === 'PageUp' || e.key === 'PageDown' || e.key === 'Space') {
        e.preventDefault();
    }
});


// Canvas
const canvas = document.querySelector('canvas.webgl-bg');
const scene = new THREE.Scene();


// SceneParamètres de taille de la fenêtre
let sizes = { width: window.innerWidth, height: window.innerHeight };

// Création de la caméra
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
camera.position.z = 5;

// Création du renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Mise à jour de la taille de la fenêtre
window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
});

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
const material = new THREE.MeshBasicMaterial({ color: 0x8E00EE, wireframe: true });
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
    window.requestAnimationFrame(tick);
};

// Lancer l'animation
tick();




//    #     #     #     #     #######     #     ######  
//   # #    #     #    # #       #       # #    #     # 
//  #   #   #     #   #   #      #      #   #   #     # 
// #     #  #     #  #     #     #     #     #  ######  
// #######   #   #   #######     #     #######  #   #   
// #     #    # #    #     #     #     #     #  #    #  
// #     #     #     #     #     #     #     #  #     # 
                                                     

window.addEventListener('load', function() {
    // Forcer le scroll tout en haut au chargement
    window.scrollTo(0, 0);
});

if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initSelection);
} else {
    initSelection();
}
 
                                                     




let card_select = 0;
function initSelection() {
   
    

    const PLAYER_COLORS = [
        { border: '#00ff00', shadow: '0 0 10px rgba(0,255,0,1)', borderWidth: '1px' },    // Joueur 2
        { border: '#00ffff', shadow: '0 0 10px rgba(0,255,255,1)', borderWidth: '1px' },  // Joueur 3
    
        
          // Joueur 4
    ];

    let selections = new Map();
    let playerSlots = [false, false]; // false means available, true means taken
    let currentPlayer = 0; // This will now just be the active player index
    let specialUser = null; // Track the special user (first selected one)

    // Supprimer la création du bouton et utiliser celui existant
    const okButton = document.getElementById('confirmButton');

    document.body.addEventListener('click', handleCardClick);
    okButton.addEventListener('click', updateInterface);

    const slotImages = document.querySelectorAll('.image_column img');
    slotImages.forEach(img => img.addEventListener('click', handleImageClick));

    function handleCardClick(event) {
        const card = event.target.closest('.character-card');
        if (!card) return;
        if (selections.has(card)) 
        {
          
            unselectCard(card);
        }
        else 
        {
            if (selections.size >= 2) return;

            selectCard(card);
        }
    }
    function handleImageClick(event) {
        const img = event.target;
        const playerIndex = Array.from(selections.keys()).findIndex(card => card.querySelector('img').src === img.src);

        if (playerIndex === -1) return; // Si aucune carte n'est liée à cette image

        const style = PLAYER_COLORS[playerIndex ];
        img.style.borderColor = style.border;
        img.style.borderStyle = 'solid'; // Ajout du border solid
        img.style.borderWidth = style.borderWidth; // Largeur du border
        img.style.boxShadow = style.shadow; // Légère ombre colorée
    }

    function getNextAvailablePlayer() {
        // Find the first available player slot
        for (let i = 0; i < 2; i++) {
            if (!playerSlots[i]) {
                return i;
            }
        }
        return -1; // No slots available
    }

    function selectCard(card) {
        // Get the next available player slot
        const playerIndex = getNextAvailablePlayer();
        if (playerIndex === -1) return; // No slots available
        
        playerSlots[playerIndex] = true; // Mark this slot as taken
        currentPlayer = playerIndex;
        
        const style = PLAYER_COLORS[currentPlayer];

        card.dataset.player = currentPlayer + 1; // Affiche 1-4 au lieu de 0-3

        card.style.borderColor = style.border;
        card.style.boxShadow = style.shadow;
        selections.set(card, currentPlayer);
        
        // Track the first selected user as the special user
        if (selections.size === 1) {
            specialUser = {
                index: currentPlayer,
                name: card.querySelector('.globo_name').textContent,
                image: card.querySelector('img').src
            };
            console.log("Special user set:", specialUser.name);
        }
        
        // Update tournament bracket name and image immediately
        const playerName = card.querySelector('.globo_name').textContent;
        const playerImage = card.querySelector('img').src;
        const playerDiv = document.querySelector(`.player${currentPlayer + 1}`);
        const playerImg = document.querySelector(`.player${currentPlayer + 1}-img`);
        if (playerDiv) {
            playerDiv.textContent = playerName;
        }
        if (playerImg) {
            playerImg.src = playerImage;
        }
        
        card_select++;
        updateButtonState();
    }

    function unselectCard(card) 
    {
        card_select--;
        updateButtonState();
        const player = selections.get(card);
        
        // Check if we're removing the special user
        if (specialUser && player === specialUser.index) {
            specialUser = null;
            console.log("Special user unselected");
        }
        
        // Free up this player slot
        playerSlots[player] = false;
        
        // Reset tournament bracket name and image
        const playerDiv = document.querySelector(`.player${player + 1}`);
        const playerImg = document.querySelector(`.player${player + 1}-img`);
        if (playerDiv) {
            playerDiv.textContent = `Globo ${player + 1}`;
        }
        if (playerImg) {
            playerImg.src = "";
        }
        
        card.style.borderColor = '#0800ffde';
        card.style.borderStyle = 'solid';
        card.style.borderWidth = '2px';
        card.style.boxShadow = 'none';
        delete card.dataset.player;
        selections.delete(card);
    }


    function updateButtonState() {
        const okButton = document.getElementById('confirmButton');
        
        if (card_select === 2) {
          okButton.classList.add('active');
          okButton.disabled = false;
        } else {
          okButton.classList.remove('active');
          okButton.disabled = true;
        }
      }
      
      
// Modifier la fonction de défilement existante
function smoothScrollToBottom() {
    const scrollContainer = document.querySelector('.scroll-container');
    const tournoisSection = document.querySelector('.tournois-section');
    
    if (scrollContainer && tournoisSection) {
        // Défilement fluide vers la section tournois
        tournoisSection.scrollIntoView({
            behavior: 'smooth',
            block: 'start'
        });
    }
}

// Garder le reste du code existant inchangé
// Fonction pour mélanger un tableau de manière aléatoire
function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]]; // Échange les éléments
    }
    return array;
}

// Fonction pour mettre à jour l'interface avec un mélange aléatoire des noms et des images
function updateInterface() {
    const selectedCards = Array.from(selections.keys());
    if (selectedCards.length === 2) {
        // Create arrays for shuffling
        const players = selectedCards.map(card => ({
            name: card.querySelector('.globo_name').textContent,
            image: card.querySelector('img').src,
            isSpecial: specialUser && card.querySelector('.globo_name').textContent === specialUser.name
        }));
        const shuffledPlayers = [...players];
        shuffleArray(shuffledPlayers);

        // Find the special user in the shuffled array
        const specialUserIndex = shuffledPlayers.findIndex(player => player.isSpecial);
        if (specialUserIndex !== -1) {
            console.log("Special user in duel:", shuffledPlayers[specialUserIndex].name);
            sessionStorage.setItem('specialUser', JSON.stringify(shuffledPlayers[specialUserIndex]));
        }

        // Update tournament bracket with shuffled players
        for (let i = 0; i < 2; i++) {
            const playerDiv = document.querySelector(`.player${i + 1}`);
            const playerImg = document.querySelector(`.player${i + 1}-img`);
            if (playerDiv) {
                playerDiv.textContent = shuffledPlayers[i].name;
            }
            if (playerImg) {
                playerImg.src = shuffledPlayers[i].image;
            }
        }
        
        // Update the pong section player names with first two shuffled names
        const name1Element = document.querySelector('.name1');
        const name2Element = document.querySelector('.name2');
        if (name1Element && name2Element) {
            name1Element.textContent = shuffledPlayers[0].name;
            name2Element.textContent = shuffledPlayers[1].name;
        }

        // Reset player slots for potential future selections
        playerSlots = [false, false];
        
        // Store shuffled players in session storage for persistence
        sessionStorage.setItem('player1Name', shuffledPlayers[0].name);
        sessionStorage.setItem('player2Name', shuffledPlayers[1].name);

        // Continue with existing tournament logic
        const tournamentSection = document.querySelector('.tournois-section');
        if (tournamentSection) {
            smoothScrollToBottom();
        }
    }
}

// Correction de la fonction updateMatchupNames
function updateMatchupNames(playerIndex, card) {
    const playerName = card.querySelector('.globo_name').textContent;
    
    // Utilisation de playerIndex + 1 pour correspondre à l'affichage
    const playerDiv = document.querySelector(`.player${playerIndex + 1}`);
    if (playerDiv) {
        playerDiv.textContent = playerName;
        // playerDiv.style.color = PLAYER_COLORS[playerIndex].border; // Ajouter une couleur si nécessaire
    }
}

// Add play button functionality
const playButton = document.getElementById('playButton');
if (playButton) {
    playButton.addEventListener('click', function() {
        const pongSection = document.querySelector('.pong-section');
        if (pongSection) {
            pongSection.scrollIntoView({ behavior: 'smooth' });
            console.log("C OK ")
        
            // Start the game after scrolling
            // setTimeout(() => {
            //     // const event = new Event('startGame');
            //     document.dispatchEvent(event);
            // }, 1000);
        }
    });
}

// Listen for match end event from pong.js
document.addEventListener('matchEnd', function(e) {
    if (e.detail && e.detail.winner) {
        // Check if special user was in the match
        const specialUser = JSON.parse(sessionStorage.getItem('specialUser') || 'null');
        if (!specialUser) return;

        const player1Name = sessionStorage.getItem('player1Name');
        const player2Name = sessionStorage.getItem('player2Name');
        
        // Only proceed if special user was in the match
        if (specialUser.name === player1Name || specialUser.name === player2Name) {
            // Get the winner's name
            const winnerName = e.detail.winner;
            const specialUserWon = winnerName === specialUser.name;
            
            console.log(`Special user ${specialUser.name} ${specialUserWon ? 'won' : 'lost'} the duel`);
            
            // Get actual scores from the game
            const score1 = parseInt(document.getElementById("scorePlayer1").textContent) || 0;
            const score2 = parseInt(document.getElementById("scorePlayer2").textContent) || 0;
            
            // Determine which score belongs to the special user
            let playerScore, opponentScore, opponentName;
            if (specialUser.name === player1Name) {
                playerScore = score1;
                opponentScore = score2;
                opponentName = player2Name;
            } else {
                playerScore = score2;
                opponentScore = score1;
                opponentName = player1Name;
            }
            
            // Report match result to server
            reportMatchToServer({
                result: specialUserWon ? 'win' : 'loose',
                player_score: playerScore,
                opponent_score: opponentScore,
                opponent_alias: opponentName
            });
        }
    }
});

}

return function cleanup() {
    console.log("cleanup tournois");
}
}

window.currentModuleCleanup = initialize();

// export function initialize() {

//   document.documentElement.scrollTop = 0; // Assurez-vous que la page commence en haut

  
// // Désactiver le défilement manuel
// window.addEventListener('wheel', function(e) {
//     e.preventDefault();
// }, { passive: false });

// window.addEventListener('keydown', function(e) {
//     if (e.key === 'ArrowUp' || e.key === 'ArrowDown' || e.key === 'PageUp' || e.key === 'PageDown' || e.key === 'Space') {
//         e.preventDefault();
//     }
// });


// // Canvas
// const canvas = document.querySelector('canvas.webgl-bg');

// // Scene
// const scene = new THREE.Scene();

// // Camera
// const sizes = {
//     width: window.innerWidth,
//     height: window.innerHeight
// };
// const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
// camera.position.z = 8; // Caméra plus proche

// // Renderer
// const renderer = new THREE.WebGLRenderer({ canvas: canvas });
// renderer.setSize(sizes.width, sizes.height);
// renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// // Enable shadows
// renderer.shadowMap.enabled = true;
// renderer.shadowMap.type = THREE.PCFSoftShadowMap; // Type de l'ombre pour un rendu plus doux

// // Handle resize
// window.addEventListener('resize', () => {
//     sizes.width = window.innerWidth;
//     sizes.height = window.innerHeight;
//     camera.aspect = sizes.width / sizes.height;
//     camera.updateProjectionMatrix();
//     renderer.setSize(sizes.width, sizes.height);
//     renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
// });

// // Parameters
// const numCubes = 45;
// const waveLength = 3; // Longueur d'onde
// const waveAmplitude = 2; // Amplitude de l'onde
// const waveSpeed = 0.2; // Vitesse de propagation de l'onde plus douce
// const oscillationSpeed = 0.6; // Vitesse de l'oscillation des cubes plus douce
// const scaleFactor = 0.9; // Facteur d'échelle des cubes
// const cubeSize = 0.6; // Taille des cubes

// // Create cubes
// const cubes = [];
// const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize , 1, 1 ,2);
// const material = new THREE.MeshStandardMaterial({
//     color: 0x0000ff, // Bleu brut
//     wireframe: true // Mode wireframe
// });

// for (let i = 0; i < numCubes; i++) {
//     const cube = new THREE.Mesh(geometry, material);
//     cube.castShadow = true; // Les cubes peuvent lancer des ombres
//     cube.receiveShadow = true; // Les cubes peuvent recevoir des ombres
//     cubes.push(cube);
//     scene.add(cube);
// }

// // Add light
// const ambientLight = new THREE.AmbientLight(0x404040, 0.8); // Lumière ambiante douce
// scene.add(ambientLight);

// // Light directionnelle
// const directionalLight = new THREE.DirectionalLight(0xffffff, 0.8); // Lumière directionnelle douce
// directionalLight.position.set(5, 5, 5); // Position de la lumière
// directionalLight.castShadow = true; // Lumière qui génère des ombres
// scene.add(directionalLight);

// // Add a ground to receive shadows
// const groundGeometry = new THREE.PlaneGeometry(100, 100);
// const groundMaterial = new THREE.ShadowMaterial({ opacity: 0.3 }); // Opacité légère pour l'ombre
// const ground = new THREE.Mesh(groundGeometry, groundMaterial);
// ground.rotation.x = -Math.PI / 2;
// ground.position.y = -2;
// ground.receiveShadow = true; // Le sol reçoit les ombres
// scene.add(ground);

// // Animate
// const clock = new THREE.Clock();

// const tick = () => {
//     const elapsedTime = clock.getElapsedTime();

//     // Update cubes along the wave path
//     cubes.forEach((cube, index) => {
//         const t = elapsedTime * waveSpeed + index * (Math.PI * 2 / numCubes);
//         const x = Math.sin(t) * waveLength;
//         const y = Math.cos(t) * waveAmplitude;

//         // Position
//         cube.position.set(x, y, index * 0.15); // Positionnement plus proche

//         // Oscillation (position)
//         cube.position.x += Math.sin(elapsedTime * oscillationSpeed + index) * 0.15; // Oscillation plus douce
//         cube.position.y += Math.cos(elapsedTime * oscillationSpeed + index) * 0.15; // Oscillation plus douce

//         // Rotation
//         cube.rotation.x = t;
//         cube.rotation.y = t;

//         // Scale
//         const scale = 1 + Math.sin(elapsedTime + index) * scaleFactor;
//         cube.scale.set(scale, scale, scale);
//     });

//     // Render the scene
//     renderer.render(scene, camera);

//     // Call the tick function recursively
//     window.requestAnimationFrame(tick);
// };

// // Start the animation loop
// tick();




// New function to report match results to server
function reportMatchToServer(matchData) {
    const sessionId = getCookie('sessionid');
    
    // Prepare fetch options with the session ID cookie
    const fetchOptions = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Cookie': `sessionid=${sessionId}`
        },
        body: JSON.stringify(matchData),
        credentials: 'include' // Include cookies in the request
    };
    
    // Send the API request
    fetch('http://localhost:8000/jeux_du_pong/report-match/', fetchOptions)
        .then(response => {
            if (!response.ok) {
                throw new Error(`HTTP error! Status: ${response.status}`);
            }
            return response.json();
        })
        .then(data => {
            console.log('Match report sent successfully:', data);
        })
        .catch(error => {
            console.error('Error sending match report:', error);
        });
}

// Helper function to get cookie by name
function getCookie(name) {
    const cookieValue = document.cookie
        .split('; ')
        .find(row => row.startsWith(name + '='))
        ?.split('=')[1];
    
    return cookieValue || '';
}



