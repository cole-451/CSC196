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
#include "Renderer/Font.h"
#include "Renderer/Text.h"


#include "Engine.h"

#include <fmod.hpp>
#include <memory>


using namespace parabellum;

int main(int argc, char* argv[]) {

   
   
    // you can dynamic cast similar objects into another. Maybe we can use this to turn enemies into players?
    

    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
	//Renderer renderer;

    //inits.
  
    getEngine().initialize();
    SDL_Init(SDL_INIT_VIDEO);
    //TODO: make this also into a unique_ptr and fix all the refrences below
	//renderer.initialize();
    getEngine().getRenderer().initialize();

    //std::unique_ptr<InputSystem> inputsys = std::make_unique<InputSystem>();
    //inputsys->initialize();
    getEngine().getInputSys().initialize();

    // create audio system
    //std::unique_ptr<audiosys> audio = std::make_unique<audiosys>();
    //audio->init();

    getEngine().getAudioSys().init();


    Time time;

    Scene scene1;


    //create vidya game
    std::unique_ptr<SpaceGame> spacegame = std::make_unique<SpaceGame>();
    
     spacegame->initialize(); 


    //Transform transform;


    //create the player

    

    void* extradriverdata = nullptr;

    std::vector<vec2> stars;
    std::vector<vec2> points;

    // loading music vector
    
    std::vector<FMOD::Sound*> sounds;

    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{random::getReal() * 1280.0f, random::getReal() * 1024.0f});
    }
	vec2 v(30, 40);


    //Font* font = new Font();
    //font->Load("Brianne_s_hand.ttf", 20);

    //std::shared_ptr<Text> text =  std::make_shared<Text>(font);
    //text->Create(getEngine().getRenderer(), "Hello World", vec3{ 1, 1, 1 });
   

    SDL_Event e;
    bool quit = false;





    //load start sound TODO: replace old calls with updated getEngine() calls
    FMOD::Sound* sound = nullptr;
    //audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound); you'll need to de-reference all of these

    //audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound); // sounds[0]
    //sounds.push_back(sound);

    //audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound); // sounds[1]
    //sounds.push_back(sound);

    //audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound); // sounds[2]
    //sounds.push_back(sound);

    //audio->playSound(sound, 0, false, nullptr);


   

    // maybe make a controller?

    //MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //update
        getEngine().getInputSys().Update();
        getEngine().getAudioSys().update();
        

        vec2 mouse = getEngine().getInputSys().getMousePos();

        
        //std::cout << getEngine().getInputSys().getMousePos().x << ","<< getEngine().getInputSys().getMousePos().y<<std::endl;
        //if (getEngine().getInputSys().GetMouseButtonPressed(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
        //    points.push_back(getEngine().getInputSys().getMousePos());
        //}
        //for (int i = 0; i < (int)points.size() - 1; i++) {
        //    // set color or random color
        //    getEngine().getRenderer().drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);//switch
        //}

        //for (int i = 0; i < (int)points.size() - 1; i++) {
        //    // set color or random color
        //    getEngine().getRenderer().drawline(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y); //switch
        //}






       /* if (getEngine().getInputSys().GetMouseButtonDown(parabellum::InputSystem::MouseButton::MOUSE_LEFT)) {
            vec2 position = getEngine().getInputSys().getMousePos();
            if (points.size() == 0) { 
                points.push_back(position); 
            }
            else if ((position - points.back()).length() > 10) { 
                points.push_back(position); 
            }
        }*/



        

        vec2 speed{ 0.1f,0.1f };
        auto i = 10;
		float length = speed.length();

        vec3 color{ 0,0,1 };
        spacegame->initialize();
        getEngine().getRenderer().setColor(color.r, color.g, color.b); //switch

        //drawing
        for (auto& star : stars) {
            star += speed; // Move each star by speed
            if (star[0] > 1280 || star[1] > 1024) {
                star.x = 0;
            }
            getEngine().getRenderer().setColor((uint8_t)random::getInt() * 255, (uint8_t)random::getInt() * (uint8_t)random::getInt() * 255, (uint8_t)0, (uint8_t)255);
            getEngine().getRenderer().drawdot(star.x, star.y); // Draw each star
        }

        
        

        //text->Draw(getEngine().getRenderer(), 40.0f, 40.0f);


        getEngine().getRenderer().setColor((uint8_t) 25, (uint8_t)25, (uint8_t)25);
        getEngine().getRenderer().clear(); // make the background black
       
        spacegame->Draw();

        getEngine().getRenderer().present(); // Render the screen
    }


    //getEngine().getRenderer().GTFO();
    
    getEngine().GTFO();
    
    return 0;
}
