#include "constants.h"
#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window		*window = NULL;
SDL_Renderer	*renderer = NULL;
int				isGameRunning = FALSE;

int	initializeWindow()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (FALSE);
	}
	window = SDL_CreateWindow(
		NULL,/* WINDOW TITLE */
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_BORDERLESS
	);
	if (!window)
	{
		fprinf(stderr, "Error creating SDL window.\n");
		return FALSE;
	}

	renderer = SDL_CreateRenderer(window, -1/* get me the default driver to render */, 0);
	if (!renderer)
	{
		fprintf(stderr, "Error creating SDL renderer.\n");
		return FALSE;
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	return TRUE;
}

void	destroyWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int	main()
{
	isGameRunning = initializeWindow();

	setup();

	while(isGameRunning)
	{
		// precessInput();
		// update();
		// render();
	}

	destroyWindow();

	return 0;
}