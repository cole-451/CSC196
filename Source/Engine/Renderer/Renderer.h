#pragma once
#include <iostream>
#include <SDL3/SDL.h>


class Renderer
{
public:
	Renderer() = default;

	bool initialize();

	bool createWindow(const std::string& name, int width, int height);

	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8  a = 185);

	void setColor(float r, float g, float b, float  a = 1.0f);

	void clear();

	void present();

	void GTFO();

	void drawline(float x1, float y1, float x2, float y2);

	void drawdot(float x, float y);



private:
	SDL_Window* current_window = nullptr;
	SDL_Renderer* renderer = nullptr;
};


