#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"
#include "Renderer/Renderer.h"

using namespace parabellum;

int main(int argc, char* argv[]) {
	Renderer renderer;
    SDL_Init(SDL_INIT_VIDEO);
	renderer.initialize();


	renderer.createWindow("SDL3 Project", 1280, 1024);
   

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


       
		renderer.setColor(0, 0, 0, 255); // Set render draw color to black
		renderer.clear(); // Clear the renderer

		renderer.setColor(0, 255, 0, 255); // Set render draw color to green
		renderer.clear(); // Clear the renderer

		renderer.present(); // Render the screen
        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle


        renderer.present(); // Render the screen

    }

	renderer.GTFO(); // Clean up and exit

    return 0;
}