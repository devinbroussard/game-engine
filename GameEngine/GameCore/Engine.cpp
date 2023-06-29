#include "pch.h"
#include "Engine.h"
#include "Scene.h"
#include "GameGraphics/Window.h"
#include <iostream>

GameCore::Engine::Engine(int windowWidth, int windowHeight, const char* windowTitle, int windowFrameRate, int fixedTimeStep, float r, float g, float b)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_windowName = windowTitle,
	m_windowFrameRate = windowFrameRate;
	m_physicsFrameRate = fixedTimeStep;
	m_r = r;
	m_g = g;
	m_b = b;
}

GameCore::Engine::~Engine()
{
	delete m_window;
}

void GameCore::Engine::run()
{
	start();

	 while (!m_window->shouldClose() && !m_window->escapePressed())
	 {
		 // Updates the window.
		 if (m_window)
			 m_window->update();

		 m_accumulatedTime += m_window->getDeltaTime();

		 update(m_window->getDeltaTime());
		 while (m_accumulatedTime >= getFixedTimestep())
		 {
			 fixedUpdate(getFixedTimestep());
		 }

		 draw();
	 }
	
	end();
}

void GameCore::Engine::start()
{
	m_window = new GameGraphics::Window(m_windowWidth, m_windowHeight, "WINDOW", m_r, m_g, m_b);
	m_window->open();
}

void GameCore::Engine::update(float deltaTime)
{
	if (m_currentScene) 
	{
		m_currentScene->update(deltaTime);
	}
}

void GameCore::Engine::fixedUpdate(float fixedTimestep)
{
	if (m_currentScene)
	{
		m_currentScene->fixedUpdate(fixedTimestep);
	}

	m_accumulatedTime -= getFixedTimestep();
}

void GameCore::Engine::draw()
{
	m_window->beginDrawing();
	if (m_currentScene)
	{
		m_currentScene->draw();
	}
	m_window->endDrawing();
}

void GameCore::Engine::end()
{
	m_window->close();
	delete m_window;
	m_window = nullptr;
}
