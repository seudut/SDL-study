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

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	return 1;
    }

    SDL_Event event;

    while (1)
    {
	while (SDL_PollEvent(&event)) {
	}
    }


    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}


