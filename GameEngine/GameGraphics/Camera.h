#pragma once
#include <GameCore/Entity.h>
#include <Matrix4.h>
#include <Vector3.h>
#include <numbers>

namespace GameCore 
{
    class TransformComponent;
}

namespace GameGraphics
{
    /// <summary>
    /// Used for 3D rendering.
    /// </summary>
    class Camera :
        public GameCore::Entity
    {
    public:
        Camera(float fieldOfView, float aspectRatio, float nearClipDistance = 0.1f, float farClipDistance = 1000.0f);
        ~Camera() {};

        /// <summary>
        /// Gets and sets the camera field of view.
        /// </summary>
        float getFieldOfViewDegrees();
        /// <summary>
        /// Gets and sets the camera field of view.
        /// </summary>
        float getFieldOfViewRadians() { return m_fieldOfView; }
        /// <summary>
        /// Gets and sets the camera field of view.
        /// </summary>
        void setFieldOfViewDegrees(float degrees);
        /// <summary>
        /// Gets and sets the camera field of view.
        /// </summary>
        void setFieldOfViewRadians(float radians) { m_fieldOfView = radians; }

        /// <summary>
        /// Gets and sets the aspect ratio.
        /// </summary>
        float getAspectRatio() { return m_aspectRatio; }
        /// <summary>
        /// Gets and sets the aspect ratio.
        /// </summary>
        void setAspectRatio(float aspectRatio) { m_aspectRatio = aspectRatio; }

        /// <summary>
        /// Gets and sets the near clip distance.
        /// </summary>
        float getNearClipDistance() { return m_nearClipDistance; }
        /// <summary>
        /// Gets and sets the near clip distance.
        /// </summary>
        void setNearClipDistance(float distance) { m_nearClipDistance = distance; }

        /// <summary>
        /// Gets and sets the far clip distance.
        /// </summary>
        float getFarClipDistance() { return m_farClipDistance; }
        /// <summary>
        /// Gets and sets the far clilp distance.
        /// </summary>
        void setFarClipDistance(float distance) { m_farClipDistance = distance; }

        /// <summary>
        /// Gets the view matrix.
        /// </summary>
        GameMath::Matrix4 getViewMatrix();

        /// <summary>
        /// Gets the projection matrix.
        /// </summary>
        GameMath::Matrix4 getProjectionMatrix();

        /// <summary>
        /// Gets the transform.
        /// </summary>
        GameCore::TransformComponent* getTransform();

        /// <summary>
        /// Called in the scene's draw method.
        /// </summary>
        void onDraw() override;

        /// <summary>
        /// Called in the scene's start method.
        /// </summary>
        void onStart() override;

    private:
        /// <summary>
        /// Camera options.
        /// </summary>
        float m_fieldOfView, m_aspectRatio, m_farClipDistance, m_nearClipDistance;
        GameCore::TransformComponent* m_transform;
    };
}
