/*
 * 02_load_img.c
 */

#include <stdio.h>
//#include "02_load_img.h"
#include <SDL2/SDL.h>

// 1. As the origin bmp image which will be shown below is 600 x 600 dimensions
// but the window size here is 640x480, so the origin image will be scaled after copied
// to the window.
//
// 2. To load image with the format of .jpg, it needs to install SDL2_image.
// Use IMG_Load() instead of SDL_LoadBMP();

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "SDL Loading Image";



int main (int argc, char *argv[])
{
    SDL_Window *window = NULL;

    SDL_Surface *imgSurface = NULL;
    SDL_Surface *screenSurface = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	return EXIT_FAILURE;
    }
    screenSurface = SDL_GetWindowSurface( window );
    
    imgSurface = SDL_LoadBMP("../res/panda.bmp");
    if (imgSurface == NULL)
    {
	printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
    }

    // copy img to screen
    SDL_BlitSurface(imgSurface, NULL, screenSurface, NULL);

    // update window screen
    SDL_UpdateWindowSurface(window);

    // delay to show the window
    SDL_Delay(5000);
    // Destory window
    SDL_DestroyWindow(window);
    // Quit SDL substems
    SDL_Quit();
    
    return EXIT_SUCCESS;    
}
