#pragma once

namespace GameGraphics
{
	class ShaderProgram
	{
	public:
		/// <summary>
		/// Deletes shaders and program.
		/// </summary>
		~ShaderProgram();

		/// <summary>
		/// Loads the vertex shader.
		/// </summary>
		/// <param name="location">The file path.</param>
		/// <returns>1 if successful.</returns>
		int loadVertexShader(const char* location);
		/// <summary>
		/// Loads the fragment shader.
		/// </summary>
		/// <param name="location">The file path.</param>
		/// <returns>1 if successful.</returns>
		int loadFragmentShader(const char* location);

		/// <summary>
		/// Gets the content of the given file.
		/// </summary>
		/// <param name="location">The file path.</param>
		/// <param name="success">1 if successful.</param>
		/// <returns>The content from the file.</returns>
		const char* readFile(const char* location, unsigned int* success = nullptr);
		/// <summary>
		///  Attaches shaders to shader program.
		/// </summary>
		/// <returns>1 if successful.</returns>
		int linkShaders();

		/// <summary>
		/// Calls the shader program's use method.
		/// </summary>
		void use();

	private:
		unsigned int m_vertex = 0;
		unsigned int m_fragment = 0;
		unsigned int m_program = 0;
	};
}

