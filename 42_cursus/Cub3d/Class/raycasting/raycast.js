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

var	grid = new Map();

function	setup()
{
	// todo: initialize all objects
	createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function	update()
{
	// todo: update all game objects before we render the next frame
}

function	draw()
{
	// todo: render all abjects frame by frame
	update();
	grid.render();
}

/*  */

class	Player
{
	x;		//X axis (j)
	y;		//Y axis (i)
	radius;		//size of the player on the map, representid by circle
	turnDirection = 0;		// -1 if left, +1 if right
	walkDirection = 0;		// -1 if back, +1 if front
	rotationAngle = Math.PI / 2;		//pointing downward at the beginning
	moveSpeed = 3.0;		//speed of the walking of the player
							//number of pixel per frame to increase or decrease
	rotationSpeed = 3 * (Math.PI / 180);		//number of degree per frame to increase or decrease

}