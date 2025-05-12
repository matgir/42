// loadGameContent();
const players = {}

document.addEventListener("DOMContentLoaded",  () => {
	const containerPlayers = document.querySelector(".container-players");
	const gameContainer = document.querySelector(".game-container");

	playButton.addEventListener('click', () => {
		players.playerOne = document.getElementById("player-one").value;
		players.playerTwo = document.getElementById("player-two").value;
		players.playerThree = document.getElementById("player-three").value;
		players.playerFour = document.getElementById("player-four").value;

		if (
			!players.playerOne ||
			!players.playerTwo ||
			!players.playerThree ||
			!players.playerFour
		  ) {
			alert("Please fill in all player names.");
		  }
		else {
			containerPlayers.classList.remove("container-players");
			containerPlayers.classList.add("hidden");
			gameContainer.classList.remove("hidden");
			loadGameContent()
		}
	});
});


function loadGameContent() {
	const gameArea = document.getElementById("game-area");

    fetch(gameURL)
      .then((response) => {
        if (!response.ok) {
          throw new Error("Network response was not ok");
        }
        return response.text();
      })
      .then((html) => {
		  gameArea.innerHTML = html; // Insert the HTML into #game-area		
		  loadGameJS()
      })
      .catch((error) => {
        console.error("Failed to load game content:", error);
      });
}

function loadGameJS() {
	fetch(gameJS)
	.then((response) => {
	  if (!response.ok) {
		throw new Error("Failed to fetch the JavaScript file");
	  }
	  return response.text(); // Get the JavaScript code as text
	})
	.then((scriptContent) => {
	  // Execute the JavaScript
	  const script = document.createElement("script");
	 // Example usage:
		(async function() {
			await usleep(10000); // 500,000 microseconds = 0.5 seconds
			script.textContent = scriptContent; // Add the fetched JavaScript code
			document.body.appendChild(script); // Append the script to the document
		})();
	})
	.catch((error) => {
	  console.error("Error fetching or executing the JavaScript file:", error);
	});
}

function getTournamentPlayers() {

	return (players)
}


function usleep(microseconds) {
    /**
     * Pauses the execution for the given number of microseconds.
     *
     * @param {number} microseconds - The delay in microseconds (1 second = 1,000,000 microseconds).
     * @returns {Promise} A promise that resolves after the specified delay.
     */
    return new Promise(resolve => setTimeout(resolve, microseconds / 1000));
}
