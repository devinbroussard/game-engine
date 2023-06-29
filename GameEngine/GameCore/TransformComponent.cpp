#include "pch.h"
#include "TransformComponent.h"
#include "Matrix4.h"


GameCore::TransformComponent::TransformComponent()
{
    m_translation = { 0, 0, 0 };
    m_rotation = { 0, 0, 0 };
    m_scale = { 1, 1, 1 };
    m_globalMatrix = GameMath::Matrix4();
    m_localMatrix = GameMath::Matrix4();
}

void GameCore::TransformComponent::setLocalPosition(GameMath::Vector3 position)
{
    if (!(m_translation == position))
    {
        m_translation = position;
    }
}

GameMath::Vector3 GameCore::TransformComponent::getLocalPosition()
{
    return m_translation;
}


GameMath::Vector3 GameCore::TransformComponent::getGlobalPosition()
{
    updateMatrices();
    return GameMath::Vector3(m_globalMatrix.m03, m_globalMatrix.m13, m_globalMatrix.m23);
}

void GameCore::TransformComponent::setLocalRotation(GameMath::Vector3 rotation)
{
    m_rotation = rotation;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalRotation()
{
    return m_rotation;
}

void GameCore::TransformComponent::setLocalScale(GameMath::Vector3 scale)
{
    m_scale = scale;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalScale()
{
    return m_scale;
}

void GameCore::TransformComponent::setParent(TransformComponent* parent)
{   
    if (parent == m_parent) return;

    if (m_parent) m_children.remove(this);
    if (parent && !m_parent) parent->m_children.pushFront(this);

    m_parent = parent;

}

GameCore::TransformComponent* GameCore::TransformComponent::getParent()
{
    return m_parent;
}

GameMath::Matrix4 GameCore::TransformComponent::getLocalMatrix()
{
    updateMatrices();
    return m_localMatrix;
}

GameMath::Matrix4 GameCore::TransformComponent::getGlobalMatrix()
{
    updateMatrices();
    return m_globalMatrix;
}

void GameCore::TransformComponent::updateMatrices()
{
    GameMath::Matrix4 translation = GameMath::Matrix4::createTranslation(m_translation);
    GameMath::Matrix4 scale = GameMath::Matrix4::createScale(m_scale);

    GameMath::Matrix4 rotation =
        GameMath::Matrix4::createRotationX(m_rotation.x)
        * GameMath::Matrix4::createRotationY(m_rotation.y)
        * GameMath::Matrix4::createRotationZ(m_rotation.z);

    m_localMatrix = translation * scale * rotation;

    // Calculate the global matrix
    m_parent ? 
        m_globalMatrix = (m_parent->getGlobalMatrix()) * m_localMatrix : 
        m_globalMatrix = m_localMatrix;
}
