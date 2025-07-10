#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include <vector>
#include "Input/InputSystem.h"

#include <fmod.hpp>

using namespace parabellum;

int main(int argc, char* argv[]) {
	Renderer renderer;
    InputSystem inputsys;



    SDL_Init(SDL_INIT_VIDEO);
	renderer.initialize();
    inputsys.initialize();

    // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);


    std::vector<vec2> stars;
    std::vector<vec2> points;

    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{random::getrandomfloat() * 1280.0f, random::getrandomfloat() * 1024.0f});
    }
	vec2 v(30, 40);

	renderer.createWindow("SDL3 Project", 1280, 1024);
   

    SDL_Event e;
    bool quit = false;



    //load start sound
    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    audio->playSound(sound, 0, false, nullptr);

    //MAIN LOOP
    while (!quit) {
		//parabellum::time::time.Tick(); // Update time, or if i could fucking figure it out
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //update
        inputsys.Update();
        audio->update();

        vec2 mouse = inputsys.getMousePos();

        std::cout << inputsys.getMousePos().x << ","<< inputsys.getMousePos().y<<std::endl;

        if (inputsys.GetMouseButtonPressed(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
            points.push_back(inputsys.getMousePos());
        }
        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
            renderer.drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
            renderer.drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }


        if (inputsys.getKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "morgan is annoying." << std::endl;
        }


        if (inputsys.GetMouseButtonDown(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
            vec2 position = inputsys.getMousePos();
            if (points.size() == 0) { 
                points.push_back(position); 
            }
            else if ((position - points.back()).length() > 10) { 
                points.push_back(position); 
            }
        }


        

        vec2 speed{ 0.1f,0.1f };
        auto i = 10;
		float length = speed.length();



        //drawing
        for (auto& star : stars) {
			star += speed; // Move each star by speed
            if (star[0] > 1280 || star[1] > 1024) {
                star.x = 0;
            }
            renderer.setColor(random::getrandom() * 255, random::getrandom() * random::getrandom() * 255, 0, 255);
			renderer.drawdot(star.x, star.y); // Draw each star
        }
		renderer.present(); // Render the screen

		renderer.clear(); // Clear the renderer
       

    }

    renderer.GTFO();
    return 0;
}
