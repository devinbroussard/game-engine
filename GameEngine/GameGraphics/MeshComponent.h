#pragma once
#include "GameCore\TransformComponent.h"
#include "Material.h"

namespace GameGraphics
{
    class MeshComponent :
        public GameCore::TransformComponent
    {
    public:
        /// <summary>
        /// Deletes buffers.
        /// </summary>
        ~MeshComponent();

        /// <summary>
        /// Called in the scene's start method.
        /// </summary>
        void onStart() override;
        /// <summary>
        /// Initializes vertices and returns the number of triangles.
        /// </summary>
        virtual int initializeVertices();
        /// <summary>
        /// Called in the scene's draw method.
        /// </summary>
        void onDraw() override;

        /// <summary>
        /// Gets and sets the material.
        /// </summary>
        void setMaterial(Material material) { m_material = material; }
        /// <summary>
        /// Gets and sets the material.
        /// </summary>
        Material getMaterial() { return m_material; }

        /// <summary>
        /// Gets the vertex array object.
        /// </summary>
        /// <returns></returns>
        unsigned int getVertexArrayObject() { return m_vertexArrayObject; }

        /// <summary>
        /// Gets the tri count.
        /// </summary>
        /// <returns></returns>
        unsigned int getTriCount() { return m_triCount; }

    private:
        unsigned int m_vertexArrayObject = 0, m_vertexBufferObject = 0, m_indexBufferObject = 0;
        unsigned int m_triCount = 0;

        Material m_material;
    };
}


