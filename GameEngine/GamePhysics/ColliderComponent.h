#pragma once
#include "GameCore\TransformComponent.h"

namespace GamePhysics
{
    class RigidBodyComponent;
    class ColliderComponent :
        public GameCore::TransformComponent
    {
    public:
        ColliderComponent() {};
        ColliderComponent(GamePhysics::RigidBodyComponent* rigidBody) { m_rigidBody = rigidBody; }

        /// <summary>
        /// Called inside the fixedUpdate method.
        /// </summary>
        /// <param name="m_fixedTimestep"></param>
        void onFixedUpdate(float m_fixedTimestep) override {};

        /// <summary>
        /// Checks for collision with another collider. Meant to be inherited.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        virtual bool checkForCollision(class SphereColliderComponent* otherCollider) { return false; }
        /// <summary>
        /// Checks for collision with another collider. Meant to be inherited.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        virtual bool checkForCollision(class BoxColliderComponent* otherCollider) { return false; }
        /// <summary>
        /// Checks for collision with another collider. Meant to be inherited.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        virtual bool checkForCollision(ColliderComponent* otherCollider) { return false; }
        /// <summary>
        /// Checks for collision with another collider. Meant to be inherited.
        /// </summary>
        /// <returns>Whether or not a collision occured.</returns>
        virtual bool checkForCollision(class PlaneColliderComponent* otherCollider) { return false; }

        /// <summary>
        /// Returns this components rigid body if it has one.
        /// </summary>
        /// <returns></returns>
        GamePhysics::RigidBodyComponent* getRigidBody() { return m_rigidBody; }

    private:
        GamePhysics::RigidBodyComponent* m_rigidBody = nullptr;
    };
}