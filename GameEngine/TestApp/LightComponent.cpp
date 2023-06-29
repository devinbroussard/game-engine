#include "LightComponent.h"
#include "GameGraphics/gl_core_4_4.h"
#include "Vector4.h"

LightComponent::LightComponent(GameGraphics::Material material, unsigned int index, GameMath::Vector3 direction)
	: TransformComponent()
{
	m_material = material;
	m_index = index;
	m_direction = direction;
}

void LightComponent::onDraw()
{
	glUniform4f(
		10 + m_index,
		m_material.ambient.x,
		m_material.ambient.y,
		m_material.ambient.z,
		1
	);
	glUniform4f(
		15 + m_index,
		m_material.diffuse.x,
		m_material.diffuse.y,
		m_material.diffuse.z,
		1
	);
	glUniform4f(
		20 + m_index,
		m_material.specular.x,
		m_material.specular.y,
		m_material.specular.z,
		1
	);

	glUniform3f(
		25 + m_index,
		m_direction.x,
		m_direction.y,
		m_direction.z
	);

	glUniform3f(
		30 + m_index,
		getGlobalPosition().x,
		getGlobalPosition().y,
		getGlobalPosition().z
	);
}
