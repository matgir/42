console.log("Pong script loaded");

const canvas = document.getElementById("pongCanvas");
if (!canvas) {
	alert("Canvas not found! Check the HTML and ID.");
}

// const canvas = document.getElementById("pongCanvas");
const ctx = canvas.getContext("2d");

// Game dimensions
const paddleWidth = 10;
const paddleHeight = 100;
const ballSize = 10;

// Paddle positions
let player1Y = canvas.height / 2 - paddleHeight / 2;
let player2Y = canvas.height / 2 - paddleHeight / 2;

// Ball position and velocity
let ballX = canvas.width / 8;
let ballY = canvas.height / 2;
let ballSpeedX = 10;
let ballSpeedY = 8;

// Input flags
let wPressed = false;
let sPressed = false;
let upPressed = false;
let downPressed = false;

// Scores
let score1 = 0;
let score2 = 0;
let gameOver = false;
const winningScore = 5;

const playAgainBtn = document.getElementById("playAgainBtn");

// Draw paddles
function drawPaddles() {
	ctx.fillStyle = "#000";
	ctx.fillRect(0, player1Y, paddleWidth, paddleHeight);
	ctx.fillRect(canvas.width - paddleWidth, player2Y, paddleWidth, paddleHeight);
}

// Draw ball
function drawBall() {
	ctx.beginPath();
	ctx.arc(ballX, ballY, ballSize, 0, Math.PI * 2);
	ctx.fillStyle = "#f00";
	ctx.fill();
	ctx.closePath();
}

// Draw scores
function drawScores() {
	ctx.font = "20px Arial";
	ctx.fillStyle = "#000";
	ctx.fillText(`${currentUserName}: ${score1}`, 50, 30);
	ctx.fillText(`P2: ${score2}`, canvas.width - 100, 30);
}

// Game loop
function draw() {
	if (gameOver) return;

	ctx.clearRect(0, 0, canvas.width, canvas.height);

	// Move paddles
	if (wPressed && player1Y > 0) player1Y -= 5;
	if (sPressed && player1Y < canvas.height - paddleHeight) player1Y += 5;
	if (upPressed && player2Y > 0) player2Y -= 5;
	if (downPressed && player2Y < canvas.height - paddleHeight) player2Y += 5;

	// Move ball
	ballX += ballSpeedX;
	ballY += ballSpeedY;

	// Bounce off top/bottom
	if (ballY + ballSize > canvas.height || ballY - ballSize < 0) {
		ballSpeedY *= -1;
	}

	// Collision with paddles
	if (ballX - ballSize < paddleWidth &&
		ballY > player1Y &&
		ballY < player1Y + paddleHeight) {
		ballSpeedX *= -1;
	}

	if (ballX + ballSize > canvas.width - paddleWidth &&
		ballY > player2Y &&
		ballY < player2Y + paddleHeight) {
		ballSpeedX *= -1;
	}

	// Score
	if (ballX < 0) {
		score2 += 1;
		resetBall();
	}
	if (ballX > canvas.width) {
		score1 += 1;
		resetBall();
	}

	drawPaddles();
	drawBall();
	drawScores();

	if (score1 >= winningScore || score2 >= winningScore) {
		gameOver = true;
		ctx.fillStyle = "#000";
		ctx.font = "40px Arial";
		ctx.textAlign = "center";
		ctx.fillText(
			score1 > score2 ? `${currentUserName} Wins !` : "Player 2 Wins !",
			canvas.width / 2,
			canvas.height / 2
		);
		playAgainBtn.style.display = "block";
		return;
	}

	requestAnimationFrame(draw);
}

function resetBall() {
	ballX = canvas.width / 2;
	ballY = canvas.height / 2;
	ballSpeedX *= -1;
	ballSpeedY = Math.random() * 4 - 2;
}

document.addEventListener("keydown", function (e) {
	if (e.key === "w") wPressed = true;
	if (e.key === "s") sPressed = true;
	if (e.key === "ArrowUp") upPressed = true;
	if (e.key === "ArrowDown") downPressed = true;
});

document.addEventListener("keyup", function (e) {
	if (e.key === "w") wPressed = false;
	if (e.key === "s") sPressed = false;
	if (e.key === "ArrowUp") upPressed = false;
	if (e.key === "ArrowDown") downPressed = false;
});

playAgainBtn.addEventListener("click", () => {
	// Reset the game
	score1 = 0;
	score2 = 0;
	player1Y = canvas.height / 2 - paddleHeight / 2;
	player2Y = canvas.height / 2 - paddleHeight / 2;
	ballX = canvas.width / 8;
	ballY = canvas.height / 2;
	ballSpeedX = 10;
	ballSpeedY = 8;
	gameOver = false;

	playAgainBtn.style.display = "none";
	draw();
});

draw();
