// converting degrees to radians
double	deg2rad(double degrees)
{
	return (degrees * (PI / 180.0));
}

// converting radians to degrees
double	rad2deg(double radians)
{
	return (radians * (180.0 / PI));
}

// constant in our code

// field of view in radians, here 60 max use more in project
const double	FOV_ANGLE = 60.0 * (Math.PI / 180.0);

//	number of rays in your field of view, depending on your windows width (here 320)
//	maybe I'll use more in the project
const int		NUM_RAYS = 320;

// how to pass from omne ray to another when startin at 0
rayAngle += FOV_ANGLE / NUM_RAYS;

// distance between A(x, y) and B(x, y)
distanceAB = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));

// cast rays
function	catAllRays()
{
	var	columnId = 0;

	// start first ray substracting half of FOV
	var	rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

	// loop all columns casting rays
	for (var i = 0; i < NUM_RAYS; i++)
	{
		// call function to cast a single ray
		var	ray = new Ray(rayAngle);
		ray.cast(columnId);

		// next ray is last ray incremented by FOV_ANGLE / NUM_RAY
		rayAngle += FOV_ANGLE / NUM_RAYS;

		columnId++;
	}
}

//distance between de horizontal intersections
long	xstep;
//distance between de vertical  intersections
long	ystep;

// x of the closest horyzontal dot
long	xintercept;
// y of the closest horysontal dot
long	yintercept;

//Horizontal intersection steps
long	ystep = TILE_SIZE;
long	xstep = TILE_SIZE / Math.tan(rayAngle);

//vertical intersection steps
long	xsteps = TILE_SIZE;
long	ysteps = TILE_SIZE * Math.tan(rayAngle);