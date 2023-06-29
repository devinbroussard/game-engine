#include "ShaderProgram.h"
#include <GameGraphics/gl_core_4_4.h>
#include <fstream>
#include <iostream>

GameGraphics::ShaderProgram::~ShaderProgram()
{
    glDeleteShader(m_vertex);
    glDeleteShader(m_fragment);
    glDeleteProgram(m_program);
}

int GameGraphics::ShaderProgram::loadVertexShader(const char* location)
{
    const char* source = readFile("test.vert", NULL);
    m_vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertex, 1, &source, NULL);
    glCompileShader(m_vertex);
    delete[] source;

    int success = 0;
    glGetShaderiv(m_vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_vertex, 512, NULL, infoLog);
        std::cout << "Vertex shader complication error." << "\n";
        std::cout << infoLog << '\n';
    }
    return success;
}

int GameGraphics::ShaderProgram::loadFragmentShader(const char* location)
{
    const char* source = readFile("test.frag", NULL);
    m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragment, 1, &source, NULL);
    glCompileShader(m_fragment);
    delete[] source;

    int success = 0;
    glGetShaderiv(m_fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_fragment, 512, NULL, infoLog);
        std::cout << "Fragment shader complication error." << "\n";
        std::cout << infoLog << '\n';
    }
    return success;
}

const char* GameGraphics::ShaderProgram::readFile(const char* location, unsigned int* success)
{
    // Opens file
    FILE* file = nullptr;
    fopen_s(&file, location, "rb");
    if (!file) {
        std::cout << "error opening file" << location << '\n';
        *success = 0;
        return nullptr;
    }

    // Finds the file size
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);

    // Reads file source
    char* source = new char[size + 1];
    fseek(file, 0, SEEK_SET);
    fread_s(source, size + 1, sizeof(char), size, file);

    // Closes the file
    fclose(file);
    source[size] = 0;

    std::cout << '\n' << source << '\n';
    if (success)
        *success = 1;
    return source;
}

int GameGraphics::ShaderProgram::linkShaders()
{
    m_program = glCreateProgram();

    glAttachShader(m_program, m_vertex);
    glAttachShader(m_program, m_fragment);
    glLinkProgram(m_program);

    int success = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        std::cout << "Shader program linking error.\n";
    }
    return success;
}

void GameGraphics::ShaderProgram::use()
{
    glUseProgram(m_program);
}
