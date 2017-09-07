/*
 * 04_keyboard.c - Get the keyboard input, and print it on console.
 */

#include <stdio.h>
//#include "04_keyboard.h"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "SDL Keyboard";


int main (int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Event windowEvent;
    unsigned char quit = 0;
    
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	return EXIT_FAILURE;
    }


    while (!quit)
    {
        if (SDL_PollEvent(&windowEvent)) {
	    if (windowEvent.type == SDL_QUIT)
		quit = 1;
	    else if (windowEvent.type == SDL_KEYDOWN)
	    {
		switch (windowEvent.key.keysym.sym)
		{
		case SDLK_UP:
		    printf ("UP is pressed\n");
		    break;
		case SDLK_DOWN:
		    printf ("DOWN is pressed\n");
		    break;
		case SDLK_LEFT:
		    printf ("LEFT is pressed\n");
		    break;
		case SDLK_RIGHT:
		    printf ("RIGHT  is pressed\n");
		    break;
		case SDLK_SPACE:
		    printf ("SPACE is pressed\n");
		    break;
		case SDLK_q:
		    printf("q is pressed, will quit\n");
		    quit = 1;
		    break;
		default:
		    printf ("Others key is pressed\n");
		    break;
		}
	    }
        }
    }

    // Destory window
    SDL_DestroyWindow(window);
    // Quit SDL substems
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
