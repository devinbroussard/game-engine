#pragma once
#include "GameCore/Entity.h"

namespace GamePhysics
{
    class RigidBodyComponent;
    class ColliderComponent;

    class PhysicsEntity :
        public GameCore::Entity
    {
    public:
        PhysicsEntity(float mass);
        PhysicsEntity(float mass, float radius);
        ~PhysicsEntity();

        /// <summary>
        /// Called inside the collision method.
        /// </summary>
        /// <param name="collider"></param>
        void onCollision(GamePhysics::ColliderComponent* collider) override;
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        RigidBodyComponent* getRigidBody() { return m_rigidBody; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        ColliderComponent* getCollider() { return m_collider; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setCollider(ColliderComponent* collider) { m_collider = collider; }

    private:
        RigidBodyComponent* m_rigidBody;
        ColliderComponent* m_collider;
    };
}