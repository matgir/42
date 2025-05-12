const gameUUID = JSON.parse(document.getElementById('game_uuid').textContent);
const username = JSON.parse(document.getElementById('username').textContent);
let gameState = 'start';
let paddle_1 = document.querySelector('.paddle_1');
let paddle_2 = document.querySelector('.paddle_2');
let board = document.querySelector('.board');
let initial_ball = document.querySelector('.ball');
let ball = document.querySelector('.ball');
let score_1 = document.querySelector('.player_1_score');
let score_2 = document.querySelector('.player_2_score');
let message = document.querySelector('.message');
let paddle_1_coord = paddle_1.getBoundingClientRect();
let paddle_2_coord = paddle_2.getBoundingClientRect();
let initial_ball_coord = ball.getBoundingClientRect();
let ball_coord = initial_ball_coord;
let board_coord = board.getBoundingClientRect();
let paddle_common =
    document.querySelector('.paddle').getBoundingClientRect();
let maxPoints = 3;
let round = 0;
let winners = [];
let randomFloat =  generateRandomFloat(0.5, 1)
let paddleSpeed = window.innerHeight * 0.015; // Adjust for desired paddle speed
let paddle1Direction = 0; // -1 for up, 1 for down, 0 for stationary
let paddle2Direction = 0;
let animationRunning = false; // To control the paddle animation loop

let lastTime = null; // To track the last frame's timestamp
let baseBallSpeed = 1
let speedMultiplier = baseBallSpeed;
let speedIncreaseInterval; // To store the interval ID
let increaseMessage;

// Ajouter un conteneur pour le message de vitesse de balle
const speedMessageContainer = document.createElement('div');
speedMessageContainer.classList.add('speed-message-container');
document.body.appendChild(speedMessageContainer);

// Créer le message
const speedMessage = document.createElement('div');
speedMessage.classList.add('message-ball-speed-style');

// Ajouter le message dans le conteneur
speedMessageContainer.appendChild(speedMessage);

message.classList.add('message-info-style');


if ( tournament === true ) {
    // Appliquer l'animation smoothAppearence uniquement au début
    board.classList.add('smooth-appearance');

    // Retirer la classe après l'animation pour éviter qu'elle ne soit rejouée
    setTimeout(() => {
        board.classList.remove('smooth-appearance');
    }, 1300); // Durée de l'animation smoothAppearence (1.3s)
    
    playRound();
    const players = getTournamentPlayers();
    addPlayersName(players.playerOne, players.playerTwo, 0);
}
else {
    // Appliquer l'animation smoothAppearence uniquement au début
    board.classList.add('smooth-appearance');

    // Retirer la classe après l'animation pour éviter qu'elle ne soit rejouée
    setTimeout(() => {
        board.classList.remove('smooth-appearance');
    }, 1300); // Durée de l'animation smoothAppearence (1.3s)
    
    addPlayersName(username, 'Player Two')
    playRound();
}


function handleKeyDown(e) {
    if (e.key === "w") {
        paddle1Direction = -1;
    }
    if (e.key === "s") {
        paddle1Direction = 1;
    }
    if (e.key === "ArrowUp") {
        paddle2Direction = -1;
    }
    if (e.key === "ArrowDown") {
        paddle2Direction = 1;
    }
}

function handleKeyUp(e) {
    if (e.key === "w" || e.key === "s") {
        paddle1Direction = 0;
    }
    if (e.key === "ArrowUp" || e.key === "ArrowDown") {
        paddle2Direction = 0;
    }
}

function updatePaddles() {
    if (paddle1Direction !== 0) {
        let newTop = paddle_1_coord.top + paddle1Direction * paddleSpeed;
        paddle_1.style.top = Math.min(
            board_coord.bottom - paddle_common.height,
            Math.max(board_coord.top, newTop)
        ) + "px";
        paddle_1_coord = paddle_1.getBoundingClientRect();
    }

    if (paddle2Direction !== 0) {
        let newTop = paddle_2_coord.top + paddle2Direction * paddleSpeed;
        paddle_2.style.top = Math.min(
            board_coord.bottom - paddle_common.height,
            Math.max(board_coord.top, newTop)
        ) + "px";
        paddle_2_coord = paddle_2.getBoundingClientRect();
    }

    // Continue animating if game is in play state
    if (gameState === "play") {
        requestAnimationFrame(updatePaddles);
    } else {
        animationRunning = false; // Stop animation when not in play state
    }
}

function playRound() {
    // Initialize the game
    document.addEventListener("keydown", handleKeyDown);
    document.addEventListener("keyup", handleKeyUp);
    document.addEventListener("keydown", createHandleKeydown);

    // Start the paddle animation if not already running
    if (!animationRunning) {
        animationRunning = true;
        updatePaddles();
    }
}

function createHandleKeydown(e) {
    if (e.key === "Enter") {
        if (gameState === "break") return;
        if (gameState === "start") {
            gameState = 'play'
            message.innerHTML = "";
            message.style.left = "42vw";

            increaseBallSpeed();

            requestAnimationFrame(() => {
                const dx = Math.floor(Math.random() * 4) + 3 + 2000;
                const dy = Math.floor(Math.random() * 4) + 3;
                const dxd = Math.floor(Math.random() * 2);
                const dyd = Math.floor(Math.random() * 2);
                moveBall(dx, dy, dxd, dyd, createHandleKeydown);
            });

            // Ensure smooth paddle movement
            if (!animationRunning) {
                animationRunning = true;
                updatePaddles();
            }
        }
    }
}

function moveBall(dx, dy, dxd, dyd, createHandleKeydown) {
    const currentTime = performance.now(); // High-resolution time for accuracy

    if (!lastTime) {
        lastTime = currentTime;
    }

    // Time difference between frames in seconds
    const deltaTime = (currentTime - lastTime) / 1000;
    lastTime = currentTime;

    // Calculate movement relative to board size
    const baseSpeed = 0.5; // Adjust this for desired speed; it's a fraction of board size per second
    const velocityX = baseSpeed * board_coord.width * deltaTime * speedMultiplier;
    const velocityY = baseSpeed * board_coord.height * deltaTime * speedMultiplier * randomFloat;

    const movementX = velocityX * (dxd === 0 ? -1 : 1);
    const movementY = velocityY * (dyd === 0 ? -1 : 1);

    // Bounce off top and bottom
    if (ball_coord.top <= board_coord.top) {
        randomFloat = generateRandomFloat(0.5, 1)
        dyd = 1;
    }
    if (ball_coord.bottom >= board_coord.bottom) {
        randomFloat = generateRandomFloat(0.5, 1)
        dyd = 0;
    }

    // Bounce off paddles
    if (
        ball_coord.left <= paddle_1_coord.right &&
        ball_coord.top >= paddle_1_coord.top &&
        ball_coord.bottom <= paddle_1_coord.bottom &&
        dxd != 1
    ) {
        randomFloat = generateRandomFloat(0.5, 1)
        dxd = 1;
    }
    if (
        ball_coord.right >= paddle_2_coord.left &&
        ball_coord.top >= paddle_2_coord.top &&
        ball_coord.bottom <= paddle_2_coord.bottom &&
        dxd != 0
    ) {
        randomFloat = generateRandomFloat(0.5, 1)
        dxd = 0;
    }

    // Reset if ball goes out of bounds
    if (
        ball_coord.left <= board_coord.left ||
        ball_coord.right >= board_coord.right
    ) {
        if (ball_coord.left <= board_coord.left) {
            score_2.innerHTML = +score_2.innerHTML + 1;
        } else {
            score_1.innerHTML = +score_1.innerHTML + 1;
        }
        resetDefaultValues();
        gameState = 'start';
        ball_coord = initial_ball_coord;
        ball.style = initial_ball.style;
        message.innerHTML = 'Press Enter to Play Pong';
        message.style.left = 38 + 'vw';
        lastTime = null; // Reset lastTime for the next round
        return;
    }

    // Move the ball
    ball.style.top = ball_coord.top + movementY + 'px';
    ball.style.left = ball_coord.left + movementX + 'px';
    ball_coord = ball.getBoundingClientRect();

    // Continue animating
    requestAnimationFrame(() => {
        moveBall(dx, dy, dxd, dyd);
        if ( score_1.innerHTML == maxPoints || score_2.innerHTML == maxPoints ) {
            gameState = 'break';
            if ( tournament == true ) {
                tournamentStrategy();
            }
            else {
                if ( score_1.innerHTML == maxPoints ) {
                    showVictoryMessage(username)
                    updateDB('add_victory');
                    updateDB('delete_game');
                }
                else {
                    showVictoryMessage("Player Two")
                    updateDB('add_defeat');
                    updateDB('delete_game');
                }
            }
        }
    });
}

function tournamentStrategy() {
    if ( round == 0 ) {
        if ( score_1.innerHTML == maxPoints )
            winners.push(players.playerOne)
        else if ( score_2.innerHTML == maxPoints)
            winners.push(players.playerTwo)
        showVictoryMessage(winners[0], players.playerThree, players.playerFour);
        displayNextGame(players.playerThree, players.playerFour);
        addPlayersName(players.playerThree, players.playerFour, round);
    }
    else if ( round == 1 ) {
        if ( score_1.innerHTML == maxPoints )
            winners.push(players.playerThree);
        else if ( score_2.innerHTML == maxPoints )
            winners.push(players.playerFour);
        showVictoryMessage(winners[1], winners[0], winners[1]);
        // displayNextGame(winners[0], winners[1]);
        addPlayersName(winners[0], winners[1], round)

    }
    else if ( round == 2 ) {
        if ( score_1.innerHTML == maxPoints ) {
            showVictoryMessage(winners[0]);
        }
        else if ( score_2.innerHTML == maxPoints ) {
            showVictoryMessage(winners[1]);
        }
        // addVictoryButtons();
    }
    score_1.innerHTML = '0'
    score_2.innerHTML = '0'
    round++;
}

function showVictoryMessage(winner, nextPlayerOne, nextPlayerTwo) {
    if (document.querySelector('.victory-overlay')) {
        return;
    }

    // Create the overlay div
    const overlayDiv = document.createElement('div');
    overlayDiv.classList.add('victory-overlay');

    // Create the victory message div
    const messageDiv = document.createElement('div');
    messageDiv.classList.add('victory-message');

    // Add the victory text
    const victoryText = document.createElement('h1');
    if (round == 2) {
        if ( winner == players.playerOne )
            updateDB('add_victory');
        else
            updateDB('add_defeat');
        victoryText.textContent = `${winner} Wins the Tournament`;
        updateDB('delete_game');
    }
    else
        victoryText.textContent = `${winner} Wins`;
    victoryText.classList.add('victory-text');
    messageDiv.appendChild(victoryText);

    // Add the victory image
    const victoryImage = document.createElement('img');
    victoryImage.src = victoryImagePath; // Use the path passed from the Django template
    victoryImage.alt = 'Victory';
    victoryImage.classList.add('victory-image');
    messageDiv.appendChild(victoryImage);
    overlayDiv.appendChild(messageDiv);
    document.body.appendChild(overlayDiv);

    if ( tournament == true) {
        if ( nextPlayerOne !== undefined && nextPlayerTwo !== undefined ) {
            setTimeout(() => {
                victoryImage.remove();
                victoryText.textContent = `${nextPlayerOne} VS ${nextPlayerTwo}`; // Trigger animation
            }, 3000);
            setTimeout(() => {
                overlayDiv.remove();
                messageDiv.remove();
                victoryText.remove();
                gameState='start'
            }, 6000);
        }
        if ( round === 2 )
            addVictoryButtons(overlayDiv, messageDiv);
    }
    else if ( tournament == false )
        addVictoryButtons(overlayDiv, messageDiv);

    setTimeout(() => {
        victoryImage.classList.add('appear'); // Trigger animation
    }, 10);
}

function addVictoryButtons(overlayDiv, messageDiv) {
    // Créez un conteneur pour les boutons
    const buttonContainer = document.createElement('div');
    buttonContainer.classList.add('button-container'); // Ajoutez une classe pour le CSS


    // Add "Play Again" button
    const playButton = document.createElement('button');
    playButton.innerText = 'Play Again';
    playButton.onclick = () => {
        window.location.href = playURL;
    };
    playButton.classList.add('victory-button');

    // Add "Home" button
    const homeButton = document.createElement('button');
    homeButton.innerText = 'Home';
    homeButton.onclick = () => {
      window.location.href = homeURL; // Use the URL passed from the Django template
    };
    homeButton.classList.add('victory-button');

    // Ajoutez les boutons au conteneur
    buttonContainer.appendChild(playButton);
    buttonContainer.appendChild(homeButton);

    // Ajoutez le conteneur de boutons au message
    messageDiv.appendChild(buttonContainer);
    overlayDiv.appendChild(messageDiv);
    document.body.appendChild(overlayDiv);
}

function resetDefaultValues() {
    message.classList.remove('message-ball-speed-style');
    message.classList.add('message-info-style');
    speedMultiplier = 1;
    speedMessage.innerHTML = ``;
    clearInterval(speedIncreaseInterval);
}

function displayNextGame() {
    // Create the overlay div
    const overlayDiv = document.createElement('div');
    overlayDiv.classList.add('victory-overlay');
}
function increaseBallSpeed() {
    clearInterval(speedIncreaseInterval);
    speedIncreaseInterval = setInterval(() => {
        if ( speedMultiplier < 2.5 )
            speedMultiplier += 0.1;
    displayIncreaseMessage();
    }, 6000);
}

function displayIncreaseMessage() {

    // Calculer le ratio de vitesse
    let ratio = speedMultiplier / baseBallSpeed;
    
    // Créer le message
    speedMessage.innerHTML = `x ${ratio.toFixed(2)}`;

    // Ajouter l'effet de glow immédiatement
    board.classList.add('board-glow-effect');
    
    // Retirer l'effet après 1000 ms (ajustez selon l'effet souhaité)
    setTimeout(() => {
        board.classList.remove('board-glow-effect');
    }, 1000);
}

function updateDB(result) {
    fetch(`/game/${result}/${gameUUID}/`, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
        }
    })
}

function generateRandomFloat(start, end) {
    /**
     * Generate a random float number within the chosen range [start, end].
     * 
     * @param {number} start - The lower bound of the range.
     * @param {number} end - The upper bound of the range.
     * @returns {number} A random float number within the range.
     */
    if (start > end) {
        throw new Error("Start must be less than or equal to end.");
    }
    return Math.random() * (end - start) + start;
}
