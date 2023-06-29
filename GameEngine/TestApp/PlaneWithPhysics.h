#pragma once
#include "GamePhysics\PhysicsEntity.h"
#include "Vector4.h",
#include "Vector2.h"

namespace GameCore
{
    class TransformComponent;
}

namespace GameGraphics
{
    class PlaneComponent;
}

namespace GamePhysics
{
    class PlaneColliderComponent;
}


namespace TestApp
{
    class PlaneWithPhysics :
        public GamePhysics::PhysicsEntity
    {
    public:
        PlaneWithPhysics(
            GameMath::Vector2 normalizedDirection, 
            float radius = 10.0f,
            float mass = 1.0f, 
            GameMath::Vector4 color = { 1.0f, 1.0f, 1.0f, 1.0f }
        );
        ~PlaneWithPhysics();

        void setNormalizedDirection(GameMath::Vector2 normalizedDirection);
        void setRadius(float radius);
    private:
        GameGraphics::PlaneComponent* m_plane = nullptr;
        GamePhysics::PlaneColliderComponent* m_planeCollider = nullptr;
    };
}

