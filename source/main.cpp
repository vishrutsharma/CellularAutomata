#include <iostream>
#include <SDL.h>
#include <vector>
#include "Grid.h"
#include "Input.h"

constexpr int WINDOW_HEIGHT = 800;
constexpr int WINDOW_WIDTH = 800;


int main(int, char**){
 
    SDL_Window* window          = nullptr;
    SDL_Renderer* renderer      = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }


    window = SDL_CreateWindow("My Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH,
                              WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if(window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    Grid::GridManager gridManager;
    SDL_Rect viewport;
    viewport.w = WINDOW_WIDTH;
    viewport.h = WINDOW_HEIGHT;
    viewport.x =  INT_CAST(WINDOW_WIDTH/2 - viewport.w/2);
    viewport.y = INT_CAST(WINDOW_HEIGHT/2 - viewport.h/2);
    gridManager.Generate(20,viewport);

    Input input;
    SDL_Event e;
    bool quit = false;
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
    SDL_RenderClear(renderer);
    while (!quit) 
    {
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT) quit = true;
            input.HandleEvent(e);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
        SDL_RenderClear(renderer);
        gridManager.Render(renderer);
        gridManager.Update(input);
        SDL_RenderPresent(renderer); 
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;

}
