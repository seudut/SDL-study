/*
 * 01_window.c
 */

#include <stdio.h>
//#include "01_window.h"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "Hello SDL Window";

int main (int argc, char *argv[])
{
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	return EXIT_FAILURE;
    }

    SDL_Event windowEvent;

    while (1)
    {
	// On Mac, if SDL_PollEvent is not called, the window won't show up, but on Linux it can.
	// Not sure why, http://www.dreamincode.net/forums/topic/390039-os-x-and-sdl20-window-does-not-show-up/
	if (SDL_PollEvent(&windowEvent)) {
	    if (SDL_QUIT == windowEvent.type)
		break;
	}
    }

    // Destory window
    SDL_DestroyWindow(window);
    // Quit SDL substems
    SDL_Quit();
    
    return EXIT_SUCCESS;
}


