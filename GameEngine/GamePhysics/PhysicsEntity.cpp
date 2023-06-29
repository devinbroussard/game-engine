#include "pch.h"
#include "PhysicsEntity.h"
#include "GamePhysics/RigidBodyComponent.h"
#include "GamePhysics/SphereColliderComponent.h"
#include "GamePhysics/PlaneColliderComponent.h"

GamePhysics::PhysicsEntity::PhysicsEntity(float mass)
{
	m_rigidBody = new GamePhysics::RigidBodyComponent(mass);
	addComponent(m_rigidBody);
	m_collider = nullptr;
}

GamePhysics::PhysicsEntity::PhysicsEntity(float mass, float radius)
{
	m_rigidBody = new GamePhysics::RigidBodyComponent(mass);
	addComponent(m_rigidBody);
	m_collider = new GamePhysics::SphereColliderComponent(radius, m_rigidBody);
	m_collider->setParent(m_rigidBody);
	addComponent(m_collider);
}

GamePhysics::PhysicsEntity::~PhysicsEntity()
{
	delete m_collider;
	delete m_rigidBody;
}

void GamePhysics::PhysicsEntity::onCollision(GamePhysics::ColliderComponent* collider)
{
	GamePhysics::SphereColliderComponent* sphereCollider = 
		dynamic_cast<GamePhysics::SphereColliderComponent*>(getCollider());

	GamePhysics::SphereColliderComponent* otherSphereCollider =
		dynamic_cast<GamePhysics::SphereColliderComponent*>(collider);

	if (sphereCollider && otherSphereCollider)
	{
		GameMath::Vector3 relativeVelocity = sphereCollider->getRigidBody()->getVelocity()
			- otherSphereCollider->getRigidBody()->getVelocity();
		GameMath::Vector3 collisionNormal = sphereCollider->getGlobalPosition() - otherSphereCollider->getGlobalPosition();
		float coefficientOfElasticity =
			(sphereCollider->getRigidBody()->getCoefficientOfElasticity()
				+ otherSphereCollider->getRigidBody()->getCoefficientOfElasticity()) / 2;
		float mass = sphereCollider->getRigidBody()->getMass();
		float otherMass = otherSphereCollider->getRigidBody()->getMass();


		float impulseForce = 
			(-(1.0f + coefficientOfElasticity) * GameMath::Vector3::dotProduct(relativeVelocity, collisionNormal))
			/(GameMath::Vector3::dotProduct(collisionNormal, collisionNormal) * (1.0f / mass + 1.0f / otherMass));
			

		sphereCollider->getRigidBody()->applyForce(collisionNormal * impulseForce);
		otherSphereCollider->getRigidBody()->applyForce(collisionNormal * -impulseForce);
		return;
	}

	GamePhysics::PlaneColliderComponent* otherPlaneCollider =
		dynamic_cast<GamePhysics::PlaneColliderComponent*>(collider);

	if (sphereCollider && otherPlaneCollider)
	{
		GamePhysics::RigidBodyComponent* rigidBody = getRigidBody();
		rigidBody->applyForce((rigidBody->getVelocity() * -1) * rigidBody->getMass());
		return;
	}
}
