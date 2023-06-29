#pragma once
#include "GameCore/TransformComponent.h"
#include "Vector3.h"

namespace GamePhysics
{

    class RigidBodyComponent :
        public GameCore::TransformComponent
    {
    public:
        RigidBodyComponent(float mass = 1.0f, bool isKinematic = false);

        /// <summary>
        /// Called in the fixedUpdate method.
        /// </summary>
        /// <param name="fixedTimestep"></param>
        void onFixedUpdate(float fixedTimestep) override;
        /// <summary>
        /// Applies a force to this object.
        /// </summary>
        /// <param name="force"></param>
        /// <param name="deltaTime"></param>
        void applyForce(GameMath::Vector3 force, float deltaTime = 1.0f);
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        float getCoefficientOfElasticity() { return m_coeffiecntOfElasticity; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        float getMass();
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        GameMath::Vector3 getGravity() { return m_gravity; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        GameMath::Vector3 getVelocity() { return m_velocity; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setGravity(GameMath::Vector3 gravity) { m_gravity = gravity; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setAcceleration(GameMath::Vector3 acceleration) { m_acceleration = acceleration; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setVelocity(GameMath::Vector3 velocity) { m_velocity = velocity; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setMass(float mass) { m_mass = mass; }
        /// <summary>
        /// Getters and setters get or set the values of the named variable.
        /// </summary>
        void setIsKinematic(bool isKinematic) { m_isKinematic = isKinematic; }


    private:
        float m_mass = 1.0f;

        /// <summary>
        /// How bouncy this object will be.
        /// </summary>
        float m_coeffiecntOfElasticity = 1.0f;
        GameMath::Vector3 m_gravity = { 0.0f, 100.0f, 0.0f };
        GameMath::Vector3 m_acceleration = { 0.0f, 0.0f, 0.0f };
        GameMath::Vector3 m_velocity = { 0.0f, 0.0f, 0.0f };
        bool m_isKinematic = false;
    };
}