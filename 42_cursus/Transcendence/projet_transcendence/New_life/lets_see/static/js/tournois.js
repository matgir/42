export function initialize() {
    // Ensure the page starts at the top visually, even before scrolling to the section
    document.documentElement.scrollTop = 0; 
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

    // Initialize scroll container state
    const scrollContainer = document.querySelector('.scroll-container');
    if (scrollContainer) {
        scrollContainer.classList.remove('scrolling-enabled');
    }

    // Disable manual scrolling initially
    window.addEventListener('wheel', function(e) {
        if (!document.querySelector('.scroll-container.scrolling-enabled')) {
            e.preventDefault();
        }
    }, { passive: false });

    window.addEventListener('keydown', function(e) {
        if (!document.querySelector('.scroll-container.scrolling-enabled') &&
            (e.key === 'ArrowUp' || e.key === 'ArrowDown' || 
             e.key === 'PageUp' || e.key === 'PageDown' || 
             e.key === 'Space')) {
            e.preventDefault();
        }
    });

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

// Scene
const scene = new THREE.Scene();
scene.background = new THREE.Color("#000005");

// Camera
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
};
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 1000);
camera.position.z = 8; // Caméra plus proche

// Renderer
const renderer = new THREE.WebGLRenderer({ canvas: canvas });
renderer.setSize(sizes.width, sizes.height);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

// Enable shadows
renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap; // Type de l'ombre pour un rendu plus doux

// Handle resize
window.addEventListener('resize', () => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight;
    camera.aspect = sizes.width / sizes.height;
    camera.updateProjectionMatrix();
    renderer.setSize(sizes.width, sizes.height);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
});

// Parameters
const numCubes = 45;
const waveLength = 3; // Longueur d'onde
const waveAmplitude = 2; // Amplitude de l'onde
const waveSpeed = 0.2; // Vitesse de propagation de l'onde plus douce
const oscillationSpeed = 0.6; // Vitesse de l'oscillation des cubes plus douce
const scaleFactor = 0.9; // Facteur d'échelle des cubes
const cubeSize = 0.6; // Taille des cubes

// Create cubes
const cubes = [];
const geometry = new THREE.BoxGeometry(cubeSize, cubeSize, cubeSize , 1, 1 ,2);
const material = new THREE.MeshStandardMaterial({
    color: 0x283aff, // Bleu brut
    wireframe: true // Mode wireframe
});

for (let i = 0; i < numCubes; i++) {
    const cube = new THREE.Mesh(geometry, material);
    cube.castShadow = true; // Les cubes peuvent lancer des ombres
    cube.receiveShadow = true; // Les cubes peuvent recevoir des ombres
    cubes.push(cube);
    scene.add(cube);
}

// Add light
const ambientLight = new THREE.AmbientLight(0x404040, 1); // Lumière ambiante douce
scene.add(ambientLight);

// Light directionnelle
const directionalLight = new THREE.DirectionalLight(0x02fff7, 1); // Lumière directionnelle douce
directionalLight.position.set(5, 27, 14);
directionalLight.castShadow = true; 
scene.add(directionalLight);

// Add a ground to receive shadows
const groundGeometry = new THREE.PlaneGeometry(100, 100);
const groundMaterial = new THREE.ShadowMaterial({ opacity: 0.42 }); 
const ground = new THREE.Mesh(groundGeometry, groundMaterial);
ground.rotation.x = -Math.PI / 2;
ground.position.y = -2;
ground.receiveShadow = true; // Le sol reçoit les ombres
scene.add(ground);

// Animate
const clock = new THREE.Clock();

const tick = () => {
    const elapsedTime = clock.getElapsedTime();

    // Update cubes along the wave path
    cubes.forEach((cube, index) => {
        const t = elapsedTime * waveSpeed + index * (Math.PI * 2 / numCubes);
        const x = Math.sin(t) * waveLength;
        const y = Math.cos(t) * waveAmplitude;

        // Position
        cube.position.set(x, y, index * 0.15); // Positionnement plus proche

        // Oscillation (position)
        cube.position.x += Math.sin(elapsedTime * oscillationSpeed + index) * 0.15; // Oscillation plus douce
        cube.position.y += Math.cos(elapsedTime * oscillationSpeed + index) * 0.15; // Oscillation plus douce

        // Rotation
        cube.rotation.x = t;
        cube.rotation.y = t;

        // Scale
        const scale = 1 + Math.sin(elapsedTime + index) * scaleFactor;
        cube.scale.set(scale, scale, scale);
    });

    // Render the scene
    renderer.render(scene, camera);

    // Call the tick function recursively
    window.requestAnimationFrame(tick);
};

// Start the animation loop
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
        { border: '#ffff00', shadow: '0 0 10px rgba(255,255,0,1)', borderWidth: '1px' } ,
        { border: '#ff00ff', shadow: '0 0 10px rgba(255,0,255,1)', borderWidth: '1px' },  // Joueur 1
        
          // Joueur 4
    ];

    let selections = new Map();
    // Replace modulo-based player tracking with an array of booleans
    let playerSlots = [false, false, false, false]; // false means available, true means taken
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
            if (selections.size >= 4) return;

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
        for (let i = 0; i < 4; i++) {
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
        
        if (card_select === 4) {
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
        // Remove scrolling-enabled class to prevent further scrolling
        scrollContainer.classList.remove('scrolling-enabled');
        // Scroll to tournament section
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
    if (selectedCards.length === 4) {
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
            console.log("Special user in tournament:", shuffledPlayers[specialUserIndex].name);
            sessionStorage.setItem('specialUser', JSON.stringify(shuffledPlayers[specialUserIndex]));
        }

        // Update tournament bracket with shuffled players
        for (let i = 0; i < 4; i++) {
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
        playerSlots = [false, false, false, false];
        
        // Store players in session storage for tournament tracking
        sessionStorage.setItem('tournamentPlayers', JSON.stringify(shuffledPlayers));
        sessionStorage.setItem('currentMatch', '0'); // First match
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

// Ajout d'un gestionnaire d'événements pour le bouton
document.getElementById('shuffleButton').addEventListener('click', function() {
    updateInterface();
});

// Add play button functionality
const playButton = document.getElementById('playButton');
if (playButton) {
    playButton.addEventListener('click', function() {
        // Hide shuffle button when starting first match
        const shuffleButton = document.getElementById('shuffleButton');
        if (shuffleButton) {
            shuffleButton.style.display = 'none';
        }
        
        // Highlight the first matchup
        highlightCurrentMatchup();

        // Enable scrolling when play button is clicked
        const scrollContainer = document.querySelector('.scroll-container');
        if (scrollContainer) {
            scrollContainer.classList.add('scrolling-enabled');
        }
        
        const pongSection = document.querySelector('.pong-section');
        if (pongSection) {
            pongSection.scrollIntoView({ behavior: 'smooth' });
        }
    });
}

// Tournament Management Functions
function advanceTournament(winner) {
    const currentMatch = parseInt(sessionStorage.getItem('currentMatch') || '0');
    const players = JSON.parse(sessionStorage.getItem('tournamentPlayers') || '[]');
    const specialUser = JSON.parse(sessionStorage.getItem('specialUser') || 'null');
    
    if (players.length !== 4) return;
    
    // Check if special user was in the match and report result
    const player1Name = sessionStorage.getItem('player1Name');
    const player2Name = sessionStorage.getItem('player2Name');
    
    if (specialUser && (player1Name === specialUser.name || player2Name === specialUser.name)) {
        const specialUserWon = winner.name === specialUser.name;
        console.log(`Special user ${specialUser.name} ${specialUserWon ? 'won' : 'lost'} match ${currentMatch}`);
        
        // Create match result object
        const matchResult = {
            match: currentMatch,
            specialUser: specialUser.name,
            opponent: specialUser.name === player1Name ? player2Name : player1Name,
            result: specialUserWon ? 'won' : 'lost',
            timestamp: new Date().toISOString()
        };
        console.log("Match result:", matchResult);
        
        // Store match results in session storage
        const matchResults = JSON.parse(sessionStorage.getItem('specialUserResults') || '[]');
        matchResults.push(matchResult);
        sessionStorage.setItem('specialUserResults', JSON.stringify(matchResults));
        
        // Get actual scores from the game
        const score1 = parseInt(document.getElementById("scorePlayer1").textContent) || 0;
        const score2 = parseInt(document.getElementById("scorePlayer2").textContent) || 0;
        
        // Determine which score belongs to the special user
        let playerScore, opponentScore;
        if (specialUser.name === player1Name) {
            playerScore = score1;
            opponentScore = score2;
        } else {
            playerScore = score2;
            opponentScore = score1;
        }
        
        // Send report to server API endpoint
        reportMatchToServer({
            result: specialUserWon ? 'win' : 'loss',
            player_score: playerScore,
            opponent_score: opponentScore,
            opponent_alias: matchResult.opponent
        });
    }
    
    // Store winner in the appropriate semifinal slot
    console.log("=============");
    if (currentMatch === 0) {
        console.log("First match")
        // First match winner goes to finals slot 1
        sessionStorage.setItem('semifinal1', JSON.stringify(winner));
        
        // Setup second match
        sessionStorage.setItem('currentMatch', '1');
        sessionStorage.setItem('player1Name', players[2].name);
        sessionStorage.setItem('player2Name', players[3].name);
        
        // Update bracket UI
        const semifinalist = document.getElementById('player_round2_match1');
        console.log("Winner of first match:", winner.name);
        console.log("Found semifinalist element:", semifinalist);
        if (semifinalist) {
            semifinalist.textContent = winner.name;
            console.log("Updated semifinalist text content");
        }
        
        // Return to tournament view and start next match
        returnToTournament(players[2], players[3]);
    } 
    else if (currentMatch === 1) {
        console.log("Second match")
        // Second match winner goes to finals slot 2
        sessionStorage.setItem('semifinal2', JSON.stringify(winner));
        
        // Setup final match
        const semifinal1 = JSON.parse(sessionStorage.getItem('semifinal1'));
        sessionStorage.setItem('currentMatch', '2');
        sessionStorage.setItem('player1Name', semifinal1.name);
        sessionStorage.setItem('player2Name', winner.name);
        
        // Update bracket UI
        const semifinalist = document.getElementById('player_round2_match2');
        console.log("Winner of second match:", winner.name);
        console.log("Found semifinalist element:", semifinalist);
        if (semifinalist) {
            semifinalist.textContent = winner.name;
            console.log("Updated semifinalist text content");
        }
        
        // Return to tournament view and start final match
        returnToTournament(semifinal1, winner);
    } 
    else if (currentMatch === 2) {
        // Final match winner
        console.log("Final match")
        const finalist = document.getElementById('player_final_match1');
        if (finalist) {
            finalist.textContent = winner.name;
            finalist.classList.add('tournament-winner');
        }
        
        // Hide play button after final match
        const playButton = document.getElementById('playButton');
        if (playButton) {
            playButton.style.display = 'none';
        }
        
        // Display final tournament results summary if special user participated
        const specialUserResults = JSON.parse(sessionStorage.getItem('specialUserResults') || '[]');
        if (specialUserResults.length > 0) {
            console.log("Tournament complete. Special user results:", specialUserResults);
            
            // If special user is the winner, add that to the results
            if (specialUser && winner.name === specialUser.name) {
                console.log(`Special user ${specialUser.name} won the tournament!`);
            }
            
            // Report the tournament completion
            reportTournamentComplete(specialUserResults);
        }
        
    }
}

function returnToTournament(player1, player2) {
    // First scroll back to tournament section
    const tournamentSection = document.querySelector('.tournois-section');
    if (tournamentSection) {
        
        // Then update UI for next match
        setTimeout(() => {
            // Update player names in pong section for the next match
            const name1Element = document.querySelector('.name1');
            const name2Element = document.querySelector('.name2');
            if (name1Element && name2Element && player1 && player2) {
                name1Element.textContent = player1.name;
                name2Element.textContent = player2.name;
            }
            
            // Highlight current matchup in the bracket
            highlightCurrentMatchup();
            
            // Auto-start next match after a delay
            // setTimeout(() => {
            //     playButton.click();
            // }, 2000);
        }, 1000);
    }
}

function highlightCurrentMatchup() {
    console.log("highlightCurrentMatchup")
    // Reset all highlights and accents
    document.querySelectorAll('.player, .player_round2').forEach(el => {
        el.classList.remove('current-match');
        el.classList.remove('player-accent1'); // Remove accent class
        el.classList.remove('player-accent2'); // Remove accent class
    });
    
    const currentMatch = parseInt(sessionStorage.getItem('currentMatch') || '0');
    
    // Apply highlight and accents based on current match
    if (currentMatch === 0) {
        document.getElementById('player_round1_match1').classList.add('current-match', 'player-accent1'); // Add accent1
        document.getElementById('player_round1_match2').classList.add('current-match', 'player-accent2'); // Add accent2
    } 
    else if (currentMatch === 1) {
        document.getElementById('player_round1_match3').classList.add('current-match', 'player-accent1'); // Add accent1
        document.getElementById('player_round1_match4').classList.add('current-match', 'player-accent2'); // Add accent2
    } 
    else if (currentMatch === 2) {
        document.getElementById('player_round2_match1').classList.add('current-match', 'player-accent1'); // Add accent1
        document.getElementById('player_round2_match2').classList.add('current-match', 'player-accent2'); // Add accent2
    }
}

// Listen for match end event from pong.js
document.addEventListener('matchEnd', function(e) {
    if (e.detail && e.detail.winner) {
        // Get the winner's info
        const winnerName = e.detail.winner;
        const players = JSON.parse(sessionStorage.getItem('tournamentPlayers') || '[]');
        console.log("Match ended - Winner name:", winnerName);
        console.log("Available players:", players);
        
        // Find winner in the players array or create a simple object
        let winner;
        if (winnerName === sessionStorage.getItem('player1Name')) {
            winner = players.find(p => p.name === winnerName) || 
                    JSON.parse(sessionStorage.getItem('semifinal1')) || 
                    { name: winnerName };
        } else {
            winner = players.find(p => p.name === winnerName) || 
                    { name: winnerName };
        }
        console.log("Constructed winner object:", winner);
        
        // Advance the tournament with the winner
        advanceTournament(winner);
    }
});

// Initialize tournament bracket highlighting when the page loads
document.addEventListener('DOMContentLoaded', function() {
    const currentMatch = sessionStorage.getItem('currentMatch');
    if (currentMatch) {
        highlightCurrentMatchup();
    }
});

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

// Also report when the tournament is complete
function reportTournamentComplete(specialUserResults) {

    if (!specialUserResults || specialUserResults.length === 0) return;
    
    const finalResult = specialUserResults[specialUserResults.length - 1];
    const isChampion = finalResult.result === 'won' && finalResult.match === 2;
    
    console.log(`Tournament complete. ${finalResult.specialUser} ${isChampion ? 'is the champion!' : 'did not win the tournament.'}`);
    
    // Get actual scores from the game
    const score1 = parseInt(document.getElementById("scorePlayer1").textContent) || 0;
    const score2 = parseInt(document.getElementById("scorePlayer2").textContent) || 0;
    
    // Determine which score belongs to the special user
    const player1Name = sessionStorage.getItem('player1Name');
    const specialUser = JSON.parse(sessionStorage.getItem('specialUser') || 'null');
    let playerScore, opponentScore;
    
    if (specialUser && specialUser.name === player1Name) {
        playerScore = score1;
        opponentScore = score2;
    } else {
        playerScore = score2;
        opponentScore = score1;
    }
    
    // Send final report with tournament summary
    reportMatchToServer({
        result: isChampion ? 'win' : 'loose',
        player_score: playerScore,
        opponent_score: opponentScore,
        opponent_alias: `FINAL_${finalResult.opponent}`,
        is_tournament_final: true
    });
}

}

return function cleanup() {
    console.log("cleanup tournois");
    window.avatarCleanup();
    window.pongCleanup();
}
}

window.currentModuleCleanup = initialize();

