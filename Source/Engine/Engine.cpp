#include "Engine.h"

#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSys.h"
#include "Input/InputSystem.h"

#include <memory>
namespace parabellum {
bool Engine::initialize() {
	m_renderer = std::make_unique<Renderer>();
	m_renderer->initialize();
	m_renderer->createWindow("parabellum engine", 1280, 1024);

	m_inputsys = std::make_unique<InputSystem>();
	m_inputsys->initialize();

	m_audio = std::make_unique<audiosys>();
	m_audio->init();

	
	return true;
}

void Engine::GTFO() {
	m_audio->GTFO();
	m_inputsys->GTFO();
	m_renderer->GTFO();
}

void Engine::Draw()
{

}

void Engine::update() {
	m_time.Tick();
	m_inputsys->Update();
	m_audio->update();
}



Engine& getEngine()
{
	static Engine engine;
	return engine;
}

}