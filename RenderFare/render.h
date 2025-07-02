#pragma once

#ifdef RENDERFARE_EXPORTS // MUST be the same name as your actual project
#define RENDER_API __declspec(dllexport)
#else
#define RENDER_API __declspec(dllimport) //says this isnt defined???
#endif
// not working.
namespace parabellum {
	RENDER_API void printMessage();
}