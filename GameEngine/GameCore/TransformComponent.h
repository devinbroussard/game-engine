#pragma once
#include "Component.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "List.h"

namespace GameCore {
    class TransformComponent :
        public Component
    {
    public: 
        TransformComponent();

        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        void setLocalPosition(GameMath::Vector3 position);
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Vector3 getLocalPosition(); 

        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Vector3 getGlobalPosition();

        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        void setLocalRotation(GameMath::Vector3 rotation);
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Vector3 getLocalRotation();
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        void setLocalScale(GameMath::Vector3 scale);
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Vector3 getLocalScale();
        
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        void setParent(TransformComponent* parent);
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        TransformComponent* getParent();

        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Matrix4 getLocalMatrix();
        /// <summary>
        /// Getters and setters change the variable in the method name.
        /// </summary>
        GameMath::Matrix4 getGlobalMatrix();

        /// <summary>
        /// Updates the translation, rotation, and scale of the matrices.
        /// </summary>
        void updateMatrices();

    private:
        /// <summary>
        /// The parent transform. The parent's transform will be the origin for this transform.
        /// </summary>
        TransformComponent* m_parent = nullptr;
        List<TransformComponent*> m_children;

        GameMath::Vector3 m_translation = { 0, 0, 0 };
        GameMath::Vector3 m_rotation = { 0, 0, 0 };
        GameMath::Vector3 m_scale = { 1, 1, 1 };
        /// <summary>
        /// The matrix based on the shared global axis.
        /// </summary>
        GameMath::Matrix4 m_globalMatrix;
        /// <summary>
        /// The matrix based on this transform's parent axis.
        /// </summary>
        GameMath::Matrix4 m_localMatrix;
    };
}


