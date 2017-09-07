/*
 * 03_drawing.c
 *   Drawing and Filling rectangle on the window render
 *   Refer to http://lazyfoo.net/tutorials/SDL/08_geometry_rendering/index.php
 *
 *   SDL_SetRenderDrawColor()
 *   SDL_RenderFillRect ()
 *
 *   If need more drawing functions such as circles or polygons, there is
 *   an SDL extension, SDL2_gfx, for these.
 *   
 */

#include <stdio.h>
//#include "03_drawing.h"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "SDL Drawing";

int main (int argc, char *argv[])
{

    SDL_Window *window = NULL;
    SDL_Event windowEvent;
    
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
	printf("Could not create window: %s\n", SDL_GetError());
	return EXIT_FAILURE;
    }

    SDL_Renderer* gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
               
    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    //Render red filled quad
    SDL_Rect fillRect = { WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
    SDL_RenderFillRect( gRenderer, &fillRect );

    //Render green outlined quad
    SDL_Rect outlineRect = { WINDOW_WIDTH / 6, WINDOW_HEIGHT / 6, WINDOW_WIDTH * 2 / 3, WINDOW_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );		
    SDL_RenderDrawRect( gRenderer, &outlineRect );
    
    //Draw blue horizontal line
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
    SDL_RenderDrawLine( gRenderer, 0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2 );

    //Draw vertical line of yellow dots
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
    for( int i = 0; i < WINDOW_HEIGHT; i += 4 )
    {
        SDL_RenderDrawPoint( gRenderer, WINDOW_WIDTH / 2, i );
    }

    //Update screen
    SDL_RenderPresent( gRenderer );

    while (1)
    {
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
