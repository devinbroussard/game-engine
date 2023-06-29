#include "pch.h"
#include "Entity.h"
#include "Component.h"
#include "GamePhysics/ColliderComponent.h"
#include "Scene.h"

GameCore::Entity::Entity()
{
	m_components = List<Component*>();
}

GameCore::Entity::~Entity()
{
}


void GameCore::Entity::addComponent(Component* component)
{
	if (component->getOwner())
	{
		component->getOwner()->removeComponent(component);
	}

	m_components.pushFront(component);
	component->setOwner(this);
}

void GameCore::Entity::onAdded()
{
	for (Component* component : m_components)
	{
		GamePhysics::ColliderComponent* collider = dynamic_cast<GamePhysics::ColliderComponent*>(component);
		if (collider)
		{
			getScene()->addCollider(collider);
		}
	}
}

void GameCore::Entity::onFixedUpdate(float fixedTimestep)
{
	for (Component* component : m_components)
	{
		component->fixedUpdate(fixedTimestep);
	}
}

void GameCore::Entity::onUpdate(float deltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getShouldCallStart())
		{
			component->start();
		}

		component->update(deltaTime);
	}

}

void GameCore::Entity::onRemoved()
{
	for (Component* component : m_components)
	{
		GamePhysics::ColliderComponent* collider = dynamic_cast<GamePhysics::ColliderComponent*>(component);
		if (collider)
		{
			getScene()->removeCollider(collider);
		}

		component->onAdded();
	}
}

void GameCore::Entity::onDraw()
{
	for (Component* component : m_components)
	{
		component->draw();
	}
}

void GameCore::Entity::removeComponent(Component* component)
{
	m_components.remove(component);
	component->setOwner(nullptr);
}

void GameCore::Entity::collision(GamePhysics::ColliderComponent* collider)
{
	onCollision(collider);
}
