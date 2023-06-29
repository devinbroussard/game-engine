#pragma once
#include "MeshComponent.h"

namespace GameGraphics
{
	class QuadMeshComponent :
		public MeshComponent
	{
	public:
		/// <summary>
		/// Initializes vertices.
		/// </summary>
		/// <returns>The triangle count.</returns>
		int initializeVertices() override;
	};
}
