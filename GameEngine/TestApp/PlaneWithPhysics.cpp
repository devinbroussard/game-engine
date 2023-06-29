#include "PlaneWithPhysics.h"
#include "Vector2.h"
#include "Vector4.h"
#include "GameGraphics/PlaneComponent.h"
#include "GamePhysics/RigidBodyComponent.h"
#include "GamePhysics/PlaneColliderComponent.h"

TestApp::PlaneWithPhysics::PlaneWithPhysics(GameMath::Vector2 normalizedDirection, float radius, float mass, GameMath::Vector4 color)
	: PhysicsEntity(mass)
{
    m_plane = new GameGraphics::PlaneComponent({ 0, 1 }, 200, { 1, 0, 0, 1 });

    addComponent(m_plane);
    m_plane->setParent(getRigidBody());

    m_planeCollider =
        new GamePhysics::PlaneColliderComponent(normalizedDirection, radius, getRigidBody());
    addComponent(m_planeCollider);
    setCollider(m_planeCollider);

    getRigidBody()->setIsKinematic(true);
}

TestApp::PlaneWithPhysics::~PlaneWithPhysics()
{
    delete m_plane;
    delete m_planeCollider;
}

void TestApp::PlaneWithPhysics::setNormalizedDirection(GameMath::Vector2 normalizedDirection)
{
    m_plane->setNormalizedDirection(normalizedDirection);
    m_planeCollider->setNormalizedDirection(normalizedDirection);
}

void TestApp::PlaneWithPhysics::setRadius(float radius)
{
    m_plane->setRadius(radius);
    m_planeCollider->setRadius(radius);
}
