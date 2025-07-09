#pragma once
#include <vector>
#include "../Math/Vector2.h"
#include <array>

namespace parabellum
{
	class InputSystem
	{
	public:
		InputSystem() = default;

		bool initialize();

		void GTFO();

		void Update();


		//KEYBOARD INPUTS:
		bool getKeyDown(uint8_t key) { return keyboard_state[key]; }
		bool getPrevKeyDown(uint8_t key) { return prev_keyboard_state[key]; }
		bool getKeyPressed(uint8_t key) { return !prev_keyboard_state[key] && keyboard_state[key]; }

		const vec2& getMousePos() const { return mouse_position; }
		const vec2& getPrevMousePos() const { return prev_mouse_position; }

		//MOUSE INPUT:

		bool GetMouseButtonDown(uint8_t button) { return mousebutton_state[button]; }
		bool GetPrevMouseButtonDown(uint8_t button) { return prev_mousebutton_state[button]; }

	private:
		std::vector<bool> keyboard_state;
		std::vector<bool> prev_keyboard_state;

		vec2 mouse_position;
		vec2 prev_mouse_position;

		std::array<bool, 3> mousebutton_state { false, false, false };
		std::array<bool, 3> prev_mousebutton_state{ false, false, false };



	};

}