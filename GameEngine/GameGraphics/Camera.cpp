#include "Camera.h"
#include "GameCore/TransformComponent.h"
#include <GameGraphics/gl_core_4_4.h>
#include <Matrix4.h>

GameGraphics::Camera::Camera(float fieldOfView, float aspectRatio, float nearClipDistance, float farClipDistance)
{
	m_fieldOfView = fieldOfView;
	m_aspectRatio = aspectRatio;
	m_nearClipDistance = nearClipDistance;
	m_farClipDistance = farClipDistance;

	m_transform = new GameCore::TransformComponent();
	addComponent(m_transform);
}

float GameGraphics::Camera::getFieldOfViewDegrees()
{
	return m_fieldOfView * 180.0f * (2.0f * acosf(0.0f)) / 180.0f;
}

void GameGraphics::Camera::setFieldOfViewDegrees(float degrees)
{
	m_fieldOfView = degrees * (2.0f * acosf(0.0f * acosf(0.0f)) / 180.0f);
}

GameMath::Matrix4 GameGraphics::Camera::getViewMatrix()
{
	return m_transform->getGlobalMatrix();
}

GameMath::Matrix4 GameGraphics::Camera::getProjectionMatrix()
{
	float a = m_aspectRatio;
	float fov = m_fieldOfView;
	float f = m_farClipDistance;
	float n = m_nearClipDistance;

	// The projection
	return GameMath::Matrix4(
		1.0f / (a * tanf(fov / 2.0f)), 0.0f,				    0.0f,				0.0f,
		0.0f,						   1.0f / tanf(fov / 2.0f), 0.0f,				0.0f,
		0.0f,						   0.0f,				    -(f + n) / (f - n), -(2 * f * n) / (f - n),
		0.0f,						   0.0f,					-1.0f,				0.0f
	);
}
GameCore::TransformComponent* GameGraphics::Camera::getTransform()
{
	return m_transform;
}

void GameGraphics::Camera::onDraw()
{
	GameMath::Vector3 position = getTransform()->getGlobalPosition();
	glUniform3f(9, position.x, position.y, position.z);

	// Should be put inside the scene's draw method.

	// Sets the view matrix
	GameMath::Matrix4 view = getViewMatrix();
	view.m03 *= -1.0f;
	view.m13 *= -1.0f;
	glUniformMatrix4fv(1, 1, GL_TRUE, &(view.m00));

	// Set the projection matrix
	GameMath::Matrix4 projection = getProjectionMatrix();
	glUniformMatrix4fv(2, 1, GL_TRUE, &(projection.m00));

	Entity::onDraw();
}

void GameGraphics::Camera::onStart()
{
	GameMath::Vector3 position = getTransform()->getGlobalPosition();
	glUniform3f(13, position.x, position.y, position.z);
}
