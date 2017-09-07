/*
 * 05_play_audio.c - Play Music using SDL2_mixer
 *  Documentation - https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_toc.html
 *  Functions:
 *      Mix_Init ()
 *      Mix_OpenAudio ()
 *      Mix_LoadMUS ()
 *      Mix_PlayMusic ()
 *      Mix_PauseMusic ()
 *      Mix_ResumeMusic ()
 *
 *  In this sample, press <SPACE> to start/stop the music playing.
 */

#include <stdio.h>
//#include "05_play_audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char* WINDOW_TITLE = "SDL Window - playing music";

static const char *MUSIC_FILE = "test.wav";

int main (int argc, char *argv[])
{
    
    SDL_Window *window;
    // start SDL with audio support
    if(SDL_Init(SDL_INIT_AUDIO)==-1) {
        printf("SDL_Init: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    {
        // 1. sdl2_mixer init
        // load support for the OGG and MOD , MP3 sample/music formats
        int flags = MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3;
        if(!Mix_Init(flags)) {
            printf("Mix_Init: %s\n", Mix_GetError());
        }
    }

    {
        // 2. open audio device
        // open 44.1KHz, signed 16bit, system byte order,
        //      stereo audio, using 1024 byte chunks
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(2);
        }
    }


    // 3. Load music file
    // Load the MP3 file to play as music
    Mix_Music *music;
    music = Mix_LoadMUS(MUSIC_FILE);
    if (!music) {
        printf("Mix_LoadMUS music.mp3: %s\n", Mix_GetError());
    }

    printf (" Load Music success. Press <SPACE> to start/stop music playing.\n ");

    SDL_Event event;
    unsigned char quit = 0;

    while (!quit)
    {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        // Play the music
                        if (!Mix_PlayingMusic()) {
                            if (Mix_PlayMusic(music, -1) == -1) {
                                printf("Mix_PlayMusic: %s\n", Mix_GetError());
                            }
                        } else {
                            Mix_PausedMusic() ? Mix_ResumeMusic() : Mix_PauseMusic();
                        }
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
    Mix_FreeMusic(music);

    // Destory window
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
