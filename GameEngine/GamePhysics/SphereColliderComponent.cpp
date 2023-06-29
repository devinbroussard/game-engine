#include "pch.h"
#include "SphereColliderComponent.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
#include "PlaneColliderComponent.h"

GamePhysics::SphereColliderComponent::SphereColliderComponent(float radius, GamePhysics::RigidBodyComponent* rigidBody)
    : GamePhysics::ColliderComponent(rigidBody)
{
    m_radius = radius;
}

bool GamePhysics::SphereColliderComponent::checkForCollision(SphereColliderComponent* otherCollider)
{
    GameMath::Vector3 positionDelta = otherCollider->getGlobalPosition() - getGlobalPosition();
    float distanceBetween = positionDelta.getMagnitude();
    float combinedRadii = m_radius + otherCollider->m_radius;

    if (distanceBetween < combinedRadii)
        return true;
    
    return false;
}

bool GamePhysics::SphereColliderComponent::checkForCollision(BoxColliderComponent* otherCollider)
{
    return false;
}

bool GamePhysics::SphereColliderComponent::checkForCollision(ColliderComponent* otherCollider)
{
    return otherCollider->checkForCollision(this);
}

bool GamePhysics::SphereColliderComponent::checkForCollision(PlaneColliderComponent* otherCollider)
{
    float distanceBetween = GameMath::Vector2().dotProduct(
            GameMath::Vector2{ getGlobalPosition().x, getGlobalPosition().y },
            otherCollider->getNormalizedDirection()
        ) - otherCollider->getGlobalPosition().getMagnitude();

    bool intersection = m_radius - distanceBetween >= 0;
    float velocityOutOfPlane = GameMath::Vector2().dotProduct(
        GameMath::Vector2{getRigidBody()->getVelocity().x, getRigidBody()->getVelocity().y},
        otherCollider->getNormalizedDirection()
    );

    if (intersection && velocityOutOfPlane < 0)
    {
        return true;
    }
    return false;
}
