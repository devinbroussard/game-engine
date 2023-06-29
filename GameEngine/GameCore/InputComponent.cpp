#include "pch.h"
#include "InputComponent.h"
#include <GLFW/glfw3.h>

bool GameCore::InputComponent::getKeyDown(char input)
{
    // Convert from lower case to upper case
    if (input >= 'a' && input <= 'z')
    {
        input -= 32;
    }
    return getKeyDown((int)input);
}

bool GameCore::InputComponent::getKeyDown(int input)
{
    return glfwGetKey(m_window, input) == GLFW_PRESS;
}

void GameCore::InputComponent::onStart()
{
    Component::onStart();
    m_window = glfwGetCurrentContext();
}