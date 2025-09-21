#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>

#include "sim.hxx"

static SDL_Renderer *Renderer = nullptr;
static SDL_Window *Window = nullptr;

void sim_init()
{
    SDL_Init(SDL_INIT_VIDEO);
    Window = SDL_CreateWindow("Hello World!", 100, 100, X_SIZE, Y_SIZE, SDL_WINDOW_SHOWN);
    if (Window == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	return;
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void sim_exit()
{
    SDL_Event event;
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void sim_draw_circle(int x0, int y0, int radius)
{
    SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
    for (int w = 0; w < 2 * radius; w++)
    {
        for (int h = 0; h < 2 * radius; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius))
                SDL_RenderDrawPoint(Renderer, x0 + dx, y0 + dy);
        }
    }
    SDL_RenderPresent(Renderer);
}
