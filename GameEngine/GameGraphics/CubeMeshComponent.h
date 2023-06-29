#pragma once
#include "MeshComponent.h"

namespace GameGraphics
{
    class CubeMeshComponent :
        public GameGraphics::MeshComponent
    {
        /// <summary>
        /// Initializes the cube's vertices.
        /// </summary>
        int initializeVertices() override;
    };
}