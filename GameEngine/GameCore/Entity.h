#pragma once
#include "List.h"
#include "Base.h"

namespace GamePhysics
{
	class ColliderComponent;
}

namespace GameCore
{
	class Scene;

	class Entity :
		public Base
	{
	public:
		Entity();
		~Entity();

		/// <summary>
		/// Called when a component is added.
		/// </summary>
		/// <param name="component"></param>
		void addComponent(class Component* component);
		/// <summary>
		/// Called when a component is removed.
		/// </summary>
		/// <param name="component"></param>
		void removeComponent(class Component* component);
		/// <summary>
		/// Gets the scene that this entity is a part of.
		/// </summary>
		/// <returns></returns>
		Scene* getScene() { return m_scene; }
		/// <summary>
		/// Called when this entity enter collision.
		/// </summary>
		/// <param name="collider">The collider that this collision happened with.</param>
		void collision(GamePhysics::ColliderComponent* collider);

		// All "on" methods are called in the methods that match their name without the "on".

		/// <summary>
		/// Called inside the collision method.
		/// </summary>
		/// <param name="collider"></param>
		virtual void onCollision(GamePhysics::ColliderComponent* collider) {};
		/// <summary>
		/// Called inside the draw method.
		/// </summary>
		void onDraw() override;
		/// <summary>
		/// Called inside the added method.
		/// </summary>
		void onAdded() override;
		/// <summary>
		/// Called inside the removed method.
		/// </summary>
		void onRemoved() override;
		/// <summary>
		/// Called inside the update
		/// </summary>
		/// <param name="deltaTime"></param>
		void onUpdate(float deltaTime) override;
		/// <summary>
		/// Called inside the fixed update.
		/// </summary>
		/// <param name="fixedTimestep"></param>
		void onFixedUpdate(float fixedTimestep) override;

	private:
		/// <summary>
		/// Components that are attached to this entityl.
		/// </summary>
		List<class Component*> m_components;
		/// <summary>
		/// The scene that this entity is inside.
		/// </summary>
		Scene* m_scene;

		/// <summary>
		/// Sets the scene variable.
		/// </summary>
		/// <param name="scene"></param>
		void setScene(Scene* scene) { m_scene = scene; }

		friend Scene;
	};
}
