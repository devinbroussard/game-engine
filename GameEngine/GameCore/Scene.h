#pragma once
#include "Base.h"
#include "List.h"
#include "Vector3.h"

namespace GamePhysics
{
	class ColliderComponent;
}

namespace GameGraphics
{
	class Material;
}

namespace GameCore
{
	class Entity;

	class Scene : 
		public Base
	{
	public:
		~Scene() {};

		/// <summary>
		/// Called inside the start method.
		/// </summary>
		void onStart() override;
		/// <summary>
		/// Called inside the draw method.
		/// </summary>
		/// <param name="deltaTime"></param>
		void onUpdate(float deltaTime) override;
		/// <summary>
		/// CAlled inside the draw method.
		/// </summary>
		virtual void onDraw() override;
		/// <summary>
		/// Called inside the end method.
		/// </summary>
		virtual void onEnd() override;
		/// <summary>
		/// Called inside the fixed update method.
		/// </summary>
		/// <param name="fixedTimestep"></param>
		virtual void onFixedUpdate(float fixedTimestep);

		/// <summary>
		/// Checks for collision with entities in the scene
		/// </summary>
		/// <param name="fixedTimestep"></param>
		void checkForCollision(float fixedTimestep);

		/// <summary>
		/// Adds an entity to the entities list.
		/// </summary>
		/// <param name="entity"></param>
		/// <returns></returns>
		bool addEntity(Entity* entity);
		/// <summary>
		/// Removes an entity from the entities list.
		/// </summary>
		/// <param name="entity"></param>
		/// <returns></returns>
		bool removeEntity(Entity* entity);
		/// <summary>
		/// Adds a collider to the collider list.
		/// </summary>
		/// <param name="collider"></param>
		/// <returns></returns>
		bool addCollider(GamePhysics::ColliderComponent* collider);
		/// <summary>
		/// Removes a collider from the colliders list.
		/// </summary>
		/// <param name="collider"></param>
		/// <returns></returns>
		bool removeCollider(GamePhysics::ColliderComponent* collider);

		void setLightPosition(GameMath::Vector3 position) { m_lightPosition = position; }
		GameMath::Vector3 getLightPosition() { return m_lightPosition; }

		void setLightMaterial(GameGraphics::Material* material) { m_lightMaterial = material; }
		GameGraphics::Material* getMaterial() { return m_lightMaterial; }

		void setLightDirection(GameMath::Vector3 direction) { m_lightDirection = direction; }
		GameMath::Vector3 getLightDirection() { return m_lightDirection; }

	private:

		GameGraphics::Material* m_lightMaterial;
		GameMath::Vector3 m_lightPosition;
		GameMath::Vector3 m_lightDirection = {-1.0f, 0.0f, -0.5f};


		List<Entity*> m_entities;
		/// <summary>
		/// The colliders in the scene
		/// </summary>
		List<GamePhysics::ColliderComponent*> m_colliders;
	};
}