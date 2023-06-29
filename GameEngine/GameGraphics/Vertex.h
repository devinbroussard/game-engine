#pragma once
#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>

namespace GameGraphics
{
	/// <summary>
	/// Used for creating shapes using vertices.
	/// </summary>
	struct Vertex
	{
		GameMath::Vector3 position = { .0f, .0f, .0f };
		GameMath::Vector4 color = { 1.0f, 0.0f, 1.0f, 1.0f };
		GameMath::Vector3 normal = { 0.0f, 0.0f, 0.0f };
	};
}
