#pragma once
#include "Component.h"

struct GLFWwindow;

namespace GameCore
{
    class InputComponent :
        public Component
    {
    public:
        InputComponent() {};

        bool getKeyDown(char input);
        bool getKeyDown(int input);

        void onStart() override;

    private:
        GLFWwindow* m_window = nullptr;
    };
}


