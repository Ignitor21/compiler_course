#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "sim.h"

static SDL_Renderer *Renderer = NULL;
static SDL_Window *Window = NULL;

void sim_init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    Window = SDL_CreateWindow("Raytracing!", 100, 100, X_SIZE, Y_SIZE, SDL_WINDOW_SHOWN);
    if (!Window)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	exit(1);
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!Renderer)
    {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
	exit(1);
    }
}

void sim_exit(void)
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void sim_flush(void)
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
}

int sim_should_quit(void)
{
    SDL_Event event;
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT) 
        return 1;

    SDL_Delay(5);
    SDL_RenderPresent(Renderer);
    return 0;
}

void sim_put_pixel(int x, int y, int argb)
{
    Uint8 a = argb >> 24;
    Uint8 r = (argb >> 16) & 0xFF;
    Uint8 g = (argb >> 8) & 0xFF;
    Uint8 b = argb & 0xFF;
    SDL_SetRenderDrawColor(Renderer, r, g, b, a);
    SDL_RenderDrawPoint(Renderer, x, y);
}

void sim_draw_line(int x0, int y0, int x1, int y1, int argb)
{
    Uint8 a = argb >> 24;
    Uint8 r = (argb >> 16) & 0xFF;
    Uint8 g = (argb >> 8) & 0xFF;
    Uint8 b = argb & 0xFF;

    SDL_SetRenderDrawColor(Renderer, r, g, b, a);
    SDL_RenderDrawLine(Renderer, x0, y0, x1, y1);
}

int sim_sqrt(int x)
{
    return sqrt(x);    
}
