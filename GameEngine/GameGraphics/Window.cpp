#include "Window.h"
#include "gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"

GameGraphics::Window::Window(int width, int height, const char* title, float r, float g, float b)
{
	m_width = width;
	m_height = height;
	m_title = title;
	m_isOpen = false;
	glfwInit();
	m_r = r;
	m_g = g;
	m_b = b;
}

void GameGraphics::Window::beginDrawing()
{
	if (!m_window) return;

	glfwSwapBuffers(m_window);
	// Clear the screen and depth buffer
	glClearColor(m_r, m_g, m_b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Active shader
	m_shaderProgram->use();
}

void GameGraphics::Window::endDrawing()
{

}

void GameGraphics::Window::open()
{
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if (!m_window)
	{
		return;
	}

	glfwMakeContextCurrent(m_window);
	m_isOpen = true;

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		close();
		return;
	}
	printf("OpenGL %i.%i\n", ogl_GetMajorVersion(), ogl_GetMinorVersion());

	m_shaderProgram = new ShaderProgram();
	m_shaderProgram->loadVertexShader(
		"#version 440 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
		"}\n"
	);
	m_shaderProgram->loadFragmentShader(
		"#version 440 core \n"
		"out vec4 pixelColor;\n"
		"void main() {\n"
		"	pixelColor = vec4(1.0f, 0.f, 0.0f, 1.0f);\n"
		"}\n"
	);

	m_shaderProgram->linkShaders();
	glEnable(GL_DEPTH_TEST);

	//Enable depth test
}

void GameGraphics::Window::close()
{
	if (m_window) glfwDestroyWindow(m_window);
	m_window = nullptr;
}

void GameGraphics::Window::update()
{
	// Gets input
	glfwPollEvents();

	// Updates time
	m_previousTime = m_currentTime;
	m_currentTime = glfwGetTime();
}

bool GameGraphics::Window::shouldClose()
{
	if (!m_window)
		return true;

	return glfwWindowShouldClose(m_window);
}

bool GameGraphics::Window::escapePressed()
{
	return glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
}

double GameGraphics::Window::getDeltaTime()
{
	return m_currentTime - m_previousTime;
}

double GameGraphics::Window::getFrameRate()
{
	return m_currentTime - m_previousTime;
}

void GameGraphics::Window::setFrameRate(int fps)
{
	//SetTargetFPS(fps);
}
