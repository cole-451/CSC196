#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"
#include "Core/StringHelper.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
//#include "Math/Vector3.h"
#include <vector>
#include "Input/InputSystem.h"
#include "Audio/AudioSys.h"
#include "Renderer/Model.h"

#include <fmod.hpp>

using namespace parabellum;

int main(int argc, char* argv[]) {
	Renderer renderer;
    InputSystem inputsys;


    //inits.
    SDL_Init(SDL_INIT_VIDEO);
	renderer.initialize();
    inputsys.initialize();

    // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);


    //create model
    std::vector<vec2> model_points{
        {-5, -5},
        {5, -5},
        {5,5},
        {-5, 5},
        {-5,-5},
    };

    // construct model with points above and preset color
    Model model{ model_points, {0,0,1} };

   
    

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata); //inits channels


    std::vector<vec2> stars;
    std::vector<vec2> points;

    // loading music vector
    
    std::vector<FMOD::Sound*> sounds;

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

    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound); // sounds[0]
    sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound); // sounds[1]
    sounds.push_back(sound);

    audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound); // sounds[2]
    sounds.push_back(sound);

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

        if (inputsys.getKeyDown(SDL_SCANCODE_Q) && !inputsys.getPrevKeyDown(SDL_SCANCODE_Q))
    
    {
        // play bass sound, vector elements can be accessed like an array with [#]
            sound = sounds[0];
            audio->playSound(sound, 0, false, nullptr);

    }
        if (inputsys.getKeyDown(SDL_SCANCODE_W) && !inputsys.getPrevKeyDown(SDL_SCANCODE_W)) {
            sound = sounds[1];
            audio->playSound(sound, 0, false, nullptr);
        }
        if (inputsys.getKeyDown(SDL_SCANCODE_E) && !inputsys.getPrevKeyDown(SDL_SCANCODE_E)) {
            sound = sounds[2];
            audio->playSound(sound, 0, false, nullptr);
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

        vec3 color{ 0,0,1 };

        renderer.setColor(color.r, color.g, color.b);
        model.Draw(renderer, inputsys.getMousePos(),math::halfPi * 0.5f, 10.0f);

        //drawing
        for (auto& star : stars) {
			star += speed; // Move each star by speed
            if (star[0] > 1280 || star[1] > 1024) {
                star.x = 0;
            }
            renderer.setColor((uint8_t)random::getrandom() * 255, (uint8_t)random::getrandom() * (uint8_t)random::getrandom() * 255, (uint8_t)0, (uint8_t)255);
			renderer.drawdot(star.x, star.y); // Draw each star
        }
		renderer.present(); // Render the screen

		renderer.clear(); // Clear the renderer

       

    }

    renderer.GTFO();
    return 0;
}
