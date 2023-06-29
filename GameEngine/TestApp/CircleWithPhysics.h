#pragma once
#include "GamePhysics/PhysicsEntity.h"
#include "Vector4.h"

namespace GameGraphics
{
    class CircleComponent;
}

namespace GamePhysics 
{
    class ColliderComponent;
}

namespace TestApp
{
    class CircleWithPhysics :
        public GamePhysics::PhysicsEntity
    {
    public:
        CircleWithPhysics(float radius = 10.0f, float mass = 1.0f, GameMath::Vector4 color = { 1.0f, 1.0f, 1.0f, 1.0f });
        ~CircleWithPhysics();

        void onFixedUpdate(float fixedTimestep) override;
        void onCollision(GamePhysics::ColliderComponent* collider) override;

    private:
        GameGraphics::CircleComponent* m_circle = nullptr;
    };
}
