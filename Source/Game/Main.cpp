#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include <vector>

using namespace parabellum;

int main(int argc, char* argv[]) {
	Renderer renderer;
    SDL_Init(SDL_INIT_VIDEO);
	renderer.initialize();


    std::vector<vec2> stars;

    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{random::getrandomfloat() * 1280.0f, random::getrandomfloat() * 1024.0f});
    }
	vec2 v(30, 40);

	renderer.createWindow("SDL3 Project", 1280, 1024);
   

    SDL_Event e;
    bool quit = false;



    //MAIN LOOP
    while (!quit) {
		//parabellum::time::time.Tick(); // Update time, or if i could fucking figure it out
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        vec2 speed{ 0.1f,0.1f };
        auto i = 10;
		float length = speed.length();



        for (auto& star : stars) {
			star += speed; // Move each star by speed
            if (star[0] > 1280 || star[1] > 1024) {
				star.x = 0; // Reset star position if it goes off screen
			} //TODO: fix logic to reset star position
            renderer.setColor(random::getrandom() * 255, random::getrandom() * random::getrandom() * 255, 0, 255);
			renderer.drawdot(star.x, star.y); // Draw each star
        }
		renderer.present(); // Render the screen

		renderer.clear(); // Clear the renderer
       
		//renderer.setColor(0, 0, 0, 255); // Set render draw color to black
		//renderer.clear(); // Clear the renderer

		//renderer.setColor(0, 255, 0, 255); // Set render draw color to green

        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle


        //renderer.present(); // Render the screen

    }

	renderer.GTFO(); // Clean up and exit

    return 0;
}