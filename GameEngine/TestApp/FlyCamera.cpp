#include "FlyCamera.h"
#include "GameCore/TransformComponent.h"
#include "GameCore/InputComponent.h"

FlyCamera::FlyCamera(float fov, float aspectRatio, float nearClipDistance, float farClipDistance)
	: GameGraphics::Camera(fov, aspectRatio, nearClipDistance, farClipDistance)
{
	m_input = new GameCore::InputComponent();
	addComponent(m_input);
}

FlyCamera::~FlyCamera()
{
	delete m_input;
}

void FlyCamera::onFixedUpdate(float fixedDeltaTime)
{
	Entity::onFixedUpdate(fixedDeltaTime);
	if (m_input->getKeyDown('W')) {
		GameMath::Vector3 position = getTransform()->getLocalPosition();
		position.z += m_movementSpeed;
		getTransform()->setLocalPosition(position);
	}

	if (m_input->getKeyDown('A'))
	{
		GameMath::Vector3 position = getTransform()->getLocalPosition();
		position.x -= m_movementSpeed;
		getTransform()->setLocalPosition(position);
	}

	if (m_input->getKeyDown('S'))
	{
		GameMath::Vector3 position = getTransform()->getLocalPosition();
		position.z -= m_movementSpeed;
		getTransform()->setLocalPosition(position);
	}

	if (m_input->getKeyDown('D'))
	{
		GameMath::Vector3 position = getTransform()->getLocalPosition();
		position.x += m_movementSpeed;
		getTransform()->setLocalPosition(position);
	}

	if (m_input->getKeyDown('Q'))
	{
		GameMath::Vector3 rotation = getTransform()->getLocalRotation();
		rotation.y -= m_turnSpeed;

		getTransform()->setLocalRotation(rotation);
	}
	if (m_input->getKeyDown('R'))
	{
		GameMath::Vector3 rotation = getTransform()->getLocalRotation();
		rotation.y += m_turnSpeed;

		getTransform()->setLocalRotation(rotation);
	}

}
