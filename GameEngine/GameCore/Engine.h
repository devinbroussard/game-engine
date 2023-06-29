#pragma once
#include "pch.h"

namespace GameGraphics {
	class Window;
}

namespace GameCore {
	/// <summary>
	/// Handles running the game.
	/// </summary>
	class Engine
	{
	public:
		Engine(
			int windowWidth = 800,
			int windowHeight = 600,
			const char* windowName = "Game",
			int windowFrameRate = 60,
			int physicsFrameRate = 60,
			float r = .1f,
			float g = .1f,
			float b = .1f
		);
		~Engine();

		/// <summary>
		/// Runs the game.
		/// </summary>
		void run();
		/// <summary>
		/// Changes the game's current scene.
		/// </summary>
		/// <param name="scene">The scene to switch to.</param>
		void setCurrentScene(class Scene* scene) { m_currentScene = scene; }

	private:
		/// <summary>
		/// The window that the engine is currently using.
		/// </summary>
		GameGraphics::Window* m_window = nullptr;
		class Scene* m_currentScene = nullptr;
		int m_windowWidth, m_windowHeight, m_windowFrameRate, m_physicsFrameRate;
		const char* m_windowName;
		float m_r, m_g, m_b;

		/// <summary>
		/// Stores how much time has passed since the last fixed update.
		/// </summary>
		double m_accumulatedTime = 0;

		/// <summary>
		/// Called before the first update.
		/// </summary>
		void start();
		/// <summary>
		/// Called each frame.
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(float deltaTime);
		/// <summary>
		/// Called on a fixed basis.
		/// </summary>
		/// <param name="fixedTimestep"></param>
		void fixedUpdate(float fixedTimestep);
		/// <summary>
		/// Calls the current scene's draw method.
		/// </summary>
		void draw();
		/// <summary>
		/// Calls the current scene's end method.
		/// </summary>
		void end();
		/// <summary>
		/// Returns the fixed timestep.
		/// </summary>
		/// <returns></returns>
		float getFixedTimestep() { return 1.0f / m_physicsFrameRate; }
	};
}