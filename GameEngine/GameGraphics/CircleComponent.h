#pragma once
#include "GameCore/TransformComponent.h"
#include "Vector4.h"


namespace GameGraphics
{
    class CircleComponent :
        public GameCore::TransformComponent
    {
    public:
        CircleComponent(float radius, GameMath::Vector4 color);

        /// <summary>
        /// Changes the circle's color.
        /// </summary>
        void setColor(GameMath::Vector4 color) { m_color = color; }
        /// <summary>
        /// Called inside the draw method.
        /// </summary>
        void onDraw() override;

    private:
        float m_radius;
        GameMath::Vector4 m_color;
    };
}

