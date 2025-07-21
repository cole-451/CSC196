#include <SDL3/SDL.h>
#include <iostream>
#include "Core/random.h"
#include "Core/StringHelper.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include <vector>
#include "Input/InputSystem.h"
#include "Audio/AudioSys.h"
#include "Renderer/Model.h"
#include"Core/Time.h"
#include "Framework/Actor.h"

#include "Player.h"
#include "Framework/Scene.h"
#include "SpaceGame.h"


#include "Engine.h"

#include <fmod.hpp>
#include <memory>

using namespace parabellum;

int main(int argc, char* argv[]) {

    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
	Renderer renderer;
    //InputSystem inputsys;

    getEngine().getRenderer().initialize();


    //inits.


    SDL_Init(SDL_INIT_VIDEO);
    //TODO: make this also into a unique_ptr and fix all the refrences below
	renderer.initialize();

    std::unique_ptr<InputSystem> inputsys = std::make_unique<InputSystem>();
    inputsys->initialize();

    // create audio system
    std::unique_ptr<audiosys> audio = std::make_unique<audiosys>();
    audio->init();


    Time::Time();

    Scene scene1;


    //create model
    SpaceGame spacegame;
    


    //create the player

    Player player();

    void* extradriverdata = nullptr;

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
    //audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound); you'll need to de-reference all of these

    //audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound); // sounds[0]
    //sounds.push_back(sound);

    //audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound); // sounds[1]
    //sounds.push_back(sound);

    //audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound); // sounds[2]
    //sounds.push_back(sound);

    //audio->playSound(sound, 0, false, nullptr);


    if (inputsys->getKeyDown(SDL_SCANCODE_A)) {
    }
    // maybe make a controller?

    //MAIN LOOP
    while (!quit) {
		//time.Tick(); // Update time, if i could fucking figure it out
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //update
        inputsys->Update();
        audio->update();

        vec2 mouse = inputsys->getMousePos();

        std::cout << inputsys->getMousePos().x << ","<< inputsys->getMousePos().y<<std::endl;

        if (inputsys->GetMouseButtonPressed(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
            points.push_back(inputsys->getMousePos());
        }
        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
            renderer.drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color or random color
            renderer.drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }


        if (inputsys->getKeyDown(SDL_SCANCODE_A)) {
            tf.rotation += 1; //* time.getDeltaTime;

        }

        if (inputsys->getKeyDown(SDL_SCANCODE_Q) && !inputsys->getPrevKeyDown(SDL_SCANCODE_Q))
    
    {
        // play bass sound, vector elements can be accessed like an array with [#]
            sound = sounds[0];
            //audio->playSound(sound, 0, false, nullptr);

    }

        if (inputsys->getKeyDown(SDL_SCANCODE_W) && !inputsys->getPrevKeyDown(SDL_SCANCODE_W)) {
            sound = sounds[1];
            //audio->playSound(sound, 0, false, nullptr);
        }
        if (inputsys->getKeyDown(SDL_SCANCODE_E) && !inputsys->getPrevKeyDown(SDL_SCANCODE_E)) {
            sound = sounds[2];
            //audio->playSound(sound, 0, false, nullptr);
        }


        if (inputsys->GetMouseButtonDown(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
            vec2 position = inputsys->getMousePos();
            if (points.size() == 0) { 
                points.push_back(position); 
            }
            else if ((position - points.back()).length() > 10) { 
                points.push_back(position); 
            }
        }

        vec2 direction = { 0,0 };
        if (inputsys->getKeyDown(SDL_SCANCODE_W)) {
            return direction.y +=1;
        }

        //direction.Normalized(); fix line 95 in vector2.h


        

        vec2 speed{ 0.1f,0.1f };
        auto i = 10;
		float length = speed.length();

        vec3 color{ 0,0,1 };

        renderer.setColor(color.r, color.g, color.b);
        model->Draw(renderer, inputsys->getMousePos(),0.0f, 50.0f); // once its a pointer, this.that turns to this->that

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
