#pragma once
#include "Base.h"

namespace GameCore
{
    class Entity;
    class Scene;
    
    class Component :
        public Base
    {
        friend Entity;

    public:
        /// <summary>
        /// Gets the component's parent entity.
        /// </summary>
        /// <returns></returns>
        Entity* getOwner() { return m_owner; }
        /// <summary>
        /// Gets the scene that the component is located in.
        /// </summary>
        /// <returns></returns>
        Scene* getScene() { return m_scene; }

        /// <summary>
        /// Called inside the added method.
        /// </summary>
        void onAdded() override;

        /// <summary>
        /// Called inside the removed method.
        /// </summary>
        void onRemoved() override;

    private:
        /// <summary>
        /// The entity that this component is attached to.
        /// </summary>
        Entity* m_owner = nullptr;

        /// <summary>
        /// Sets the entity that this component is attached to.
        /// </summary>
        /// <param name="owner"></param>
        void setOwner(Entity* owner) { m_owner = owner; }

        Scene* m_scene;
    };
}
