#include "pch.h"
#include "RigidBodyComponent.h"
#include "ColliderComponent.h"
#include "SphereColliderComponent.h"
#include <math.h>


GamePhysics::RigidBodyComponent::RigidBodyComponent(float mass, bool isKinematic)
{
	m_mass = mass;
	m_isKinematic = isKinematic;
}

void GamePhysics::RigidBodyComponent::onFixedUpdate(float fixedTimestep)
{
	// Does not account for rotation of scale yet

	// Calculates current position
	setLocalPosition(getLocalPosition() + m_velocity * fixedTimestep);
	// Applies gravity
	applyForce(m_gravity * m_mass, fixedTimestep);
}

void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector3 force, float fixedTimestep)
{
	if (m_isKinematic) return;

	m_acceleration = force / m_mass;
	m_velocity = m_velocity + m_acceleration * fixedTimestep;
}

float GamePhysics::RigidBodyComponent::getMass()
{
	if (m_isKinematic)
	{
		return INFINITY;
	}
	return m_mass;
}
