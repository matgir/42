const	TILE_SIZE = 64;
const	MAP_NUM_ROWS = 11;
const	MAP_NUM_COLS = 15;

const	WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const	WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

const	FOV_ANGLE = 60 * (Math.PI / 180);

// to change in order to adjust the thickness of our stripes
const	WALL_STRIP_WIDTH = 1;
const	NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;

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
		this.rotationSpeed = 3 * (Math.PI / 180);		//number of degree per frame to increase or decrease
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
	render()
	{
		noStroke();
		fill("red");
		circle(this.x, this.y, this.radius);
		/*stroke("red");
		line(
			this.x,
			this.y,
			this.x + Math.cos(this.rotationAngle) * 30,
			this.y + Math.sin(this.rotationAngle) * 30
		);*/
	}
}

class	Ray
{
	constructor(rayAngle)
	{
		this.rayAngle = normalizeAngle(rayAngle);
		this.wallHitX = 0;
		this.wallHitY = 0;
		this.distance = 0;
		this.wasHitVertical = false;
		
		this.isRayFacingDown = this.rayAngle > 0 && this.rayAngle < Math.PI;
		this.isRayFacingUp = !this.isRayFacingDown;

		this.isRayFacingRight = this.rayAngle < 0.5 * Math.PI || this.rayAngle > 1.5 * Math.PI;
		this.isRayFacingLeft = !this.isRayFacingRight;
	}
	cast(columnId)
	{
		var	xintercept, yintercept;
		var	xstep, ystep;

		////////////////////////////
		//HORIZONTAL RAY GRID INTERSECTION CODE
		////////////////////////////

		//console.log("isRayFacingRight?", this.isRayFacingRight);
		var	foundHorizontalWallHit = false;
		var	horizontalWallHitX = 0;
		var	horizontalWallHitY = 0;

		//find the y coordinates of the closest horizontal grid intersection
		yintercept = Math.floor(player.y / TILE_SIZE) * TILE_SIZE;
		yintercept += this.isRayFacingDown ? TILE_SIZE : 0;

		//find the x coordinates of the closest horizontal grid intersection
		xintercept = player.x + (yintercept - player.y) / Math.tan(this.rayAngle);

		//calculate the increment xstep and ystep
		ystep = TILE_SIZE;
		ystep *= this.isRayFacingUp ? -1 : 1;

		xstep = TILE_SIZE / Math.tan(this.rayAngle);
		xstep *= (this.isRayFacingLeft && xstep > 0) ? -1 : 1;
		xstep *= (this.isRayFacingRight && xstep < 0) ? -1 : 1;

		var	nextHorizontalTouchX = xintercept;
		var	nextHorizontalTouchY = yintercept;

		if (this.isRayFacingUp)
		{
			nextHorizontalTouchY--;
		}

		//increment xstep and ystep until find a wall
		while (nextHorizontalTouchX >= 0 && nextHorizontalTouchX <= WINDOW_WIDTH && nextHorizontalTouchY >= 0 && nextHorizontalTouchY <= WINDOW_HEIGHT)
		{
			if (grid.hasWallAt(nextHorizontalTouchX, nextHorizontalTouchY))
			{
				//we found a wall hit
				foundHorizontalWallHit = true;
				horizontalWallHitX = nextHorizontalTouchX;
				horizontalWallHitY = nextHorizontalTouchY;

				/*stroke("red");
				line(
					player.x,
					player.y,
					horizontalWallHitX,
					horizontalWallHitY
				);*/

				break;
			}
			else
			{
				nextHorizontalTouchX += xstep;
				nextHorizontalTouchY += ystep;
			}
		}
		////////////////////////////
		//VERTICAL RAY GRID INTERSECTION CODE
		////////////////////////////

		//console.log("isRayFacingRight?", this.isRayFacingRight);
		var	foundVerticalWallHit = false;
		var	verticalWallHitX = 0;
		var	verticalWallHitY = 0;

		//find the x coordinates of the closest vertical grid intersection
		xintercept = Math.floor(player.x / TILE_SIZE) * TILE_SIZE;
		xintercept += this.isRayFacingRight ? TILE_SIZE : 0;

		//find the y coordinates of the closest vertical grid intersection
		yintercept = player.y + (xintercept - player.x) * Math.tan(this.rayAngle);

		//calculate the increment xstep and ystep
		xstep = TILE_SIZE;
		xstep *= this.isRayFacingLeft ? -1 : 1;

		ystep = TILE_SIZE * Math.tan(this.rayAngle);
		ystep *= (this.isRayFacingUp && ystep > 0) ? -1 : 1;
		ystep *= (this.isRayFacingDown && ystep < 0) ? -1 : 1;

		var	nextVerticalTouchX = xintercept;
		var	nextVerticalTouchY = yintercept;

		if (this.isRayFacingLeft)
		{
			nextVerticalTouchX--;
		}

		//increment xstep and ystep until find a wall
		while (nextVerticalTouchX >= 0 && nextVerticalTouchX <= WINDOW_WIDTH && nextVerticalTouchY >= 0 && nextVerticalTouchY <= WINDOW_HEIGHT)
		{
			if (grid.hasWallAt(nextVerticalTouchX, nextVerticalTouchY))
			{
				//we found a wall hit
				foundVerticalWallHit = true;
				verticalWallHitX = nextVerticalTouchX;
				verticalWallHitY = nextVerticalTouchY;

				/*stroke("red");
				line(
					player.x,
					player.y,
					verticalWallHitX,
					verticalWallHitY
				);*/

				break;
			}
			else
			{
				nextVerticalTouchX += xstep;
				nextVerticalTouchY += ystep;
			}
		}
	//calculate both horizontal and vertical distances and choose smaller value
	var	horizontalHitDistance = (foundHorizontalWallHit)
	? distanceBetweenPoints(player.x, player.y, horizontalWallHitX, horizontalWallHitY)
	: Number.MAX_VALUE;

	var	verticalHitDistance = (foundVerticalWallHit)
	? distanceBetweenPoints(player.x, player.y, verticalWallHitX, verticalWallHitY)
	: Number.MAX_VALUE;

	this.wallHitX = (horizontalHitDistance < verticalHitDistance) ? horizontalWallHitX : verticalWallHitX;
	this.wallHitY = (horizontalHitDistance < verticalHitDistance) ? horizontalWallHitY : verticalWallHitY;
	this.distance = (horizontalHitDistance < verticalHitDistance) ? horizontalHitDistance : verticalHitDistance;
	this.wasHitVertical = (verticalHitDistance < horizontalHitDistance);
}
	render()
	{
		stroke("rgba(255, 0, 0, 0.3)");
		line(
			player.x,
			player.y,
			this.wallHitX,
			this.wallHitY
			//player.x + Math.cos(this.rayAngle) * 30,
			//player.y + Math.sin(this.rayAngle) * 30
		);
	}
}

var	grid = new Map();
var	player = new Player();
var	rays = [];
function	normalizeAngle(angle)
{
	angle = angle % (2 * Math.PI);
	if (angle < 0)
	{
		angle = (2 * Math.PI) + angle;
	}
	return angle;
}

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

function	castAllRays()
{
	var	columnId = 0;

	//start first ray substracting half the FOV
	var	rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

	rays = [];

	//loop all column casting the rays
	for (var i = 0; i < NUM_RAYS; i++)
	//for (var i = 0; i < 1; i++)
	{
		var	ray = new Ray(rayAngle);
		ray.cast(columnId);
		rays.push(ray);

		rayAngle += FOV_ANGLE / NUM_RAYS;

		columnId++;
	}
}

function	normalizeAngle(angle)
{
	angle = angle % (2 * Math.PI);
	if (angle < 0)
	{
		angle = (2 * Math.PI) + angle;
	}
	return angle;
}

function	distanceBetweenPoints(x1, y1, x2, y2)
{
	return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
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
	castAllRays();
}

function	draw()
{
	// todo: render all abjects frame by frame
	update();
	grid.render();
	for (ray of rays)
	{
		ray.render();
	}
	player.render();
}
