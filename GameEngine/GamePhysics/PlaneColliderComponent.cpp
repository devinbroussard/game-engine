#include "pch.h"
#include "PlaneColliderComponent.h"
#include "ColliderComponent.h"

GamePhysics::PlaneColliderComponent::PlaneColliderComponent(GameMath::Vector2 normalizedDirection, float radius, GamePhysics::RigidBodyComponent* rigidBody)
	: ColliderComponent::ColliderComponent(rigidBody)
{
	m_normalizedDirection = normalizedDirection;
	m_radius = radius;
}

bool GamePhysics::PlaneColliderComponent::checkForCollision(ColliderComponent* otherCollider)
{
	return otherCollider->checkForCollision(this);
}
