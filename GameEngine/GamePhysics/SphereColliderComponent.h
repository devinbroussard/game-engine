#pragma once
#include "ColliderComponent.h"

namespace GamePhysics
{
    class SphereColliderComponent :
        public ColliderComponent
    {
    public:
        SphereColliderComponent(float radius, GamePhysics::RigidBodyComponent* rigidBody);
        
        /// <summary>
        /// Checks for collision with the given type of collider.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        bool checkForCollision(SphereColliderComponent* otherCollider) override;
        /// <summary>
        /// Checks for collision with the given type of collider.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        bool checkForCollision(class BoxColliderComponent* otherCollider) override;
        /// <summary>
        /// Checks for collision with the given type of collider.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        bool checkForCollision(ColliderComponent* otherCollider) override;
        /// <summary>
        /// Checks for collision with the given type of collider.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        bool checkForCollision(class PlaneColliderComponent* otherCollider) override;

    private:
        float m_radius = 1.0f;
        bool m_isTrigger = false;
    };
}