#include "pch.h"
#include "Scene.h"
#include "Entity.h"
#include "GamePhysics/ColliderComponent.h"
#include <GameGraphics/Material.h>
#include <GameGraphics/gl_core_4_4.h>

bool GameCore::Scene::addEntity(Entity* entity)
{
	if (Scene* oldScene = entity->getScene())
	{
		oldScene->removeEntity(entity);
	}

	entity->setScene(this);
	entity->added();
	return m_entities.pushFront(entity);
}

bool GameCore::Scene::removeEntity(Entity* entity)
{
	entity->setScene(nullptr);
	entity->removed();
	return m_entities.remove(entity);
}

bool GameCore::Scene::addCollider(GamePhysics::ColliderComponent* collider)
{
	if (Scene* oldScene = collider->getScene())
	{
		oldScene->removeCollider(collider);
	}
	//collider->setScene(this);
	return m_colliders.pushFront(collider);
}

bool GameCore::Scene::removeCollider(GamePhysics::ColliderComponent* collider)
{
	//collider->setScene(nullptr);
	return m_colliders.remove(collider);
}

void GameCore::Scene::onStart()
{
}

void GameCore::Scene::onUpdate(float deltaTime)
{
	for (Entity* entity : m_entities)
	{
		entity->update(deltaTime);
	}
}

void GameCore::Scene::onDraw()
{
	for (Entity* entity : m_entities)
	{
		entity->draw();
	}
}

void GameCore::Scene::onEnd()
{
}

void GameCore::Scene::onFixedUpdate(float fixedTimestep)
{
	for (Entity* entity : m_entities)
	{
		entity->fixedUpdate(fixedTimestep);
	}

	checkForCollision(fixedTimestep);
}

void GameCore::Scene::checkForCollision(float fixedTimestep)
{
	for (auto i = m_colliders.begin(); i != m_colliders.end(); i++)
	{
		for (auto j = i; j != m_colliders.end(); j++)
		{
			if (i == j) continue;
			if ((*i)->checkForCollision(*j))
			{
				(*i)->getOwner()->collision(*j);
			}
		}
	}
}
