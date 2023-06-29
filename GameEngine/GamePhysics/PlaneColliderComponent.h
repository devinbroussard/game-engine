#pragma once
#include "ColliderComponent.h"
#include "Vector2.h"

namespace GamePhysics
{
	class PlaneColliderComponent :
		public ColliderComponent
	{
	public:
		PlaneColliderComponent(GameMath::Vector2 normalizedDirection, float radius, GamePhysics::RigidBodyComponent* rigidBody);

		/// <summary>
		/// Checks for collision with the given type of collider.
		/// </summary>
		/// <param name="otherCollider"></param>
		/// <returns>Whether or not a collision occured.</returns>
		bool checkForCollision(class ColliderComponent* otherCollider) override;

		/// <summary>
		/// Getters and setters get or set the values of the named variable.
		/// </summary>
		GameMath::Vector2 getNormalizedDirection() { return m_normalizedDirection; }
		/// <summary>
		/// Getters and setters get or set the values of the named variable.
		/// </summary>
		float getRadius() { return m_radius; }
		/// <summary>
		/// Getters and setters get or set the values of the named variable.
		/// </summary>
		void setRadius(float radius) { m_radius = radius; }
		/// <summary>
		/// Getters and setters get or set the values of the named variable.
		/// </summary>
		void setNormalizedDirection(GameMath::Vector2 direction) { m_normalizedDirection = direction; }

	private:
		float m_radius;
		GameMath::Vector2 m_normalizedDirection;
	};
}