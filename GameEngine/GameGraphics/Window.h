#pragma once

struct GLFWwindow;
namespace GameGraphics
{
	class ShaderProgram;
	class Window
	{
	public:
		Window(int width, int height, const char* title, float r, float g, float b);

		/// <summary>
		/// Begins the drawing process for the window.
		/// </summary>
		void beginDrawing();
		/// <summary>
		/// Ends the drawing process for the window.
		/// </summary>
		void endDrawing();
		/// <summary>
		/// Opens the window.
		/// </summary>
		void open();
		/// <summary>
		/// Closes the window.
		/// </summary>
		void close();
		/// <summary>
		/// Called every frame.
		/// </summary>
		void update();
		/// <summary>
		/// Whether or not this window should close.
		/// </summary>
		bool shouldClose();
		bool escapePressed();
		/// <summary>
		/// Returns the delta time using raylib's getFrameTime.
		/// </summary>
		/// <returns></returns>
		double getDeltaTime();

		/// <summary>
		/// Gets the current frame rate (per second);
		/// </summary>
		/// <returns>The current FPS.</returns>
		double getFrameRate();
		/// <summary>
		/// Sets the current frame rate in FPS.
		/// </summary>
		/// <param name="fps">The desired FPS.</param>
		void setFrameRate(int fps);

	private:
		int m_width, m_height;
		const char* m_title;
		bool m_isOpen = false;
		GLFWwindow* m_window = nullptr;
		ShaderProgram* m_shaderProgram = nullptr;
		float m_r;
		float m_g;
		float m_b;

		double m_currentTime = 0.0;
		double m_previousTime = 0.0;
	};
}

