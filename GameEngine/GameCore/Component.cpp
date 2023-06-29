#include "pch.h"
#include "Component.h"
#include "Entity.h"
#include "GamePhysics/ColliderComponent.h"
#include "Scene.h"

void GameCore::Component::onAdded()
{
	if (Entity* owner = getOwner()) 
	{
		if (Scene* scene = owner->getScene())
		{
			if (GamePhysics::ColliderComponent* thisCollider = dynamic_cast<GamePhysics::ColliderComponent*>(this))
			{
				scene->addCollider(thisCollider);
			}
		}
	}
}

void GameCore::Component::onRemoved()
{
	if (Entity* owner = getOwner())
	{
		if (Scene* scene = owner->getScene())
		{
			if (GamePhysics::ColliderComponent* thisCollider = dynamic_cast<GamePhysics::ColliderComponent*>(this))
			{
				scene->removeCollider(thisCollider);
			}
		}
	}
}

