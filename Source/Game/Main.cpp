#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"

using namespace parabellum;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


       

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

        // draw some dots
        for (int i = 0; i < 20; i++) {
			SDL_SetRenderDrawColor(renderer, random::getrandom(0, 255), random::getrandom(0, 255), random::getrandom(0, 255), random::getrandom(0, 255)); // Set render draw color to a random color
			// Render a point at a random position
			SDL_RenderPoint(renderer, random::getrandom(0, 1280), random::getrandom(0, 1024));
        }
        //draw some lines
        for (int i = 0; i < 10; i++) {
            SDL_SetRenderDrawColor(renderer, random::getrandom(0, 255), random::getrandom(0, 255), random::getrandom(0, 255), random::getrandom(0, 255)); // Set render draw color to a random color
			SDL_RenderLine(renderer, random::getrandom(0, 1280), random::getrandom(0, 1024), random::getrandom(0, 1280), random::getrandom(0, 1024));
        }

        SDL_RenderPresent(renderer); // Render the screen

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}