#include "CircleWithPhysics.h"
#include "GameGraphics/CircleComponent.h"
#include "GamePhysics/RigidBodyComponent.h"
#include "GamePhysics/SphereColliderComponent.h"

TestApp::CircleWithPhysics::CircleWithPhysics(float radius, float mass, GameMath::Vector4 color) 
	: PhysicsEntity(mass, radius)
{
	m_circle = new GameGraphics::CircleComponent(radius, color);
	m_circle->setParent(getRigidBody());
	addComponent(m_circle);
}

TestApp::CircleWithPhysics::~CircleWithPhysics()
{
	delete m_circle;
}

void TestApp::CircleWithPhysics::onFixedUpdate(float fixedTimestep)
{
	m_circle->setColor({ 0.1f, 0.1f, 0.5f, 1.0f });
	Entity::onFixedUpdate(fixedTimestep);
}

void TestApp::CircleWithPhysics::onCollision(GamePhysics::ColliderComponent* collider)
{
	m_circle->setColor({ 0.5f, 0.1f, 0.1f, 1.0f});
	PhysicsEntity::onCollision(collider);
}
