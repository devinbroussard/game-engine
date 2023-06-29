#pragma once
#include "GameGraphics/Camera.h"
#include "GameCore/InputComponent.h"

class FlyCamera :
    public GameGraphics::Camera
{
public:
    FlyCamera(float fov, float aspectRatio, float nearClipDistance = 0.01f, float farClipDistance = 1000.0f);
    ~FlyCamera();

    float getMovementSpeed() { return m_movementSpeed; }
    void setMovementSpeed(float speed) { m_movementSpeed = speed; }

    float getTurnSpeed() { return m_turnSpeed; }
    void setTurnSpeed(float speed) { m_turnSpeed = speed; }

    void onFixedUpdate(float fixedDeltaTime);

private:
    GameCore::InputComponent* m_input = nullptr;
    float m_movementSpeed = 1.0f;
    float m_turnSpeed = 1.0f;
};

