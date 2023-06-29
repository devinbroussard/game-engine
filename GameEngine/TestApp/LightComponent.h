#pragma once
#include "GameCore/TransformComponent.h"
#include "GameGraphics/Material.h"
#include "Vector3.h"

class LightComponent :
	public GameCore::TransformComponent
{
public:
	LightComponent(GameGraphics::Material material, unsigned int index, GameMath::Vector3 direction);

	void onDraw() override;

private:
	GameGraphics::Material m_material;
	GameMath::Vector3 m_direction = {0, 0, 0};
	unsigned int m_index;
};