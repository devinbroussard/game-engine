#pragma once
#include "GameCore/TransformComponent.h"
#include "Vector4.h"
#include "Vector2.h"

namespace GameGraphics
{
    class PlaneComponent :
        public GameCore::TransformComponent
    {
    public:
        PlaneComponent(GameMath::Vector2 normalizedDirection, float radius, GameMath::Vector4 color);

        /// <summary>
        /// Changes the direction this plane faces.
        /// </summary>
        /// <param name="direction"></param>
        void setNormalizedDirection(GameMath::Vector2 direction) { m_normalizedDirection = direction; }
        /// <summary>
        /// Changes the length of the plane.
        /// </summary>
        /// <param name="radius"></param>
        void setRadius(float radius) { m_radius = radius; }
        /// <summary>
        /// Changes the color of the plane.
        /// </summary>
        /// <param name="color"></param>
        void setColor(GameMath::Vector4 color) { m_color = color; }
        /// <summary>
        /// Called in the draw method.
        /// </summary>
        void onDraw() override;

    private:
        GameMath::Vector4 m_color;
        float m_radius;
        GameMath::Vector2 m_normalizedDirection;
    };
}