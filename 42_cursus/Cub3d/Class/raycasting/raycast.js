const	TILE_SIZE = 32;
const	MAP_NUM_ROWS = 11;
const	MAP_NUM_COLS = 15;

const	WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const	WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

class	Map
{
	constructor()
	{
		this.grid = [
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
			[1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
		];
	}
	hasWallAt(x, y)
	{
		// portection to check that we are in the window
		// may not be usefull if good parsing
		if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
			return true;
		// check the position of the player in the map in tiles and not in pixels
		return (this.grid[Math.floor(y / TILE_SIZE)][Math.floor(x / TILE_SIZE)])
	}
	render()
	{
		for (var i = 0; i < MAP_NUM_ROWS; i++)
		{
			for (var j = 0; j < MAP_NUM_COLS; j++)
			{
				var tileX = j * TILE_SIZE;
				var tileY = i * TILE_SIZE;
				var tileColor = this.grid[i][j] == 1 ? "#222" : "#fff";
				stroke("#222");
				fill(tileColor);
				rect(tileX, tileY, TILE_SIZE, TILE_SIZE);
			}
		}
	}
}

class	Player
{
	constructor()
	{
		this.x = WINDOW_WIDTH / 2;		//X axis (j)
		this.y = WINDOW_HEIGHT / 2;		//Y axis (i)
		this.radius = 3;		//size of the player on the map, representid by circle
		this.turnDirection = 0;		// -1 if left, +1 if right
		this.walkDirection = 0;		// -1 if back, +1 if front
		this.rotationAngle = Math.PI / 2;		//pointing downward at the beginning
		this.moveSpeed = 2.0;		//speed of the walking of the player
								//number of pixel per frame to increase or decrease
		this.rotationSpeed = 2 * (Math.PI / 180);		//number of degree per frame to increase or decrease
	}
	update() {
		// todo; update player position based on turnedDirection and walkDirection
		// console.log(this.turnDirection);
		this.rotationAngle += this.turnDirection * this.rotationSpeed;
	
		var	moveStep = this.walkDirection * this.moveSpeed;
		var	newPlayerX = this.x + Math.cos(this.rotationAngle) * moveStep;
		var	newPlayerY = this.y + Math.sin(this.rotationAngle) * moveStep;

		// only set new player position if not colliding with map wall
		if (!grid.hasWallAt(newPlayerX, newPlayerY))
		{
			this.x = newPlayerX;
			this.y = newPlayerY;
		}
	}
	render() {
		noStroke();
		fill("red");
		circle(this.x, this.y, this.radius);
		stroke("red");
		line(
			this.x,
			this.y,
			this.x + Math.cos(this.rotationAngle) * 30,
			this.y + Math.sin(this.rotationAngle) * 30
		);
	}
}

var	grid = new Map();
var	player = new Player();

function	keyPressed()
{
	if (keyCode == UP_ARROW)
	{
		player.walkDirection = +1;
	}
	else if (keyCode == DOWN_ARROW)
	{
		player.walkDirection = -1;
	}
	else if (keyCode == RIGHT_ARROW)
	{
		player.turnDirection = +1;
	}
	else if (keyCode == LEFT_ARROW)
	{
		player.turnDirection = -1;
	}
}

function	keyReleased()
{
	if (keyCode == UP_ARROW)
	{
		player.walkDirection = 0;
	}
	else if (keyCode == DOWN_ARROW)
	{
		player.walkDirection = 0;
	}
	else if (keyCode == RIGHT_ARROW)
	{
		player.turnDirection = 0;
	}
	else if (keyCode == LEFT_ARROW)
	{
		player.turnDirection = 0;
	}
}

function	setup()
{
	// todo: initialize all objects
	createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function	update()
{
	// todo: update all game objects before we render the next frame
	/* while place of player inside grid[i][j] == 0
	if (grid.grid[Math.floor(player.y / TILE_SIZE)][Math.floor(player.x / TILE_SIZE)] == 0)
		player.update(); */
	player.update();
}

function	draw()
{
	// todo: render all abjects frame by frame
	update();
	grid.render();
	player.render();
}
