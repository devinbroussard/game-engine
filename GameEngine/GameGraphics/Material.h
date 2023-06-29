#pragma once
#include <Vector3.h>

namespace GameGraphics
{
	/// <summary>
	/// Used for lighting and colors.
	/// </summary>
	struct Material
	{
		GameMath::Vector3 ambient = { 0.0f, 0.0f, 1.0f};
		GameMath::Vector3 diffuse = { 0.0f, 0.0f, 1.0f };
		GameMath::Vector3 specular = { 0.8f, 0.8f, 0.8f};
	};
}


