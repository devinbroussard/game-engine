#include "GameCore/Engine.h"
#include "GameGraphics/CubeMeshComponent.h"
#include <GameGraphics/QuadMeshComponent.h>
#include "GameCore/Scene.h"
#include "GameCore/Entity.h"
#include <GameGraphics/Camera.h>
#include "FlyCamera.h"
#include "LightComponent.h"

int main(void)
{
    GameCore::Engine game = GameCore::Engine();

    GameCore::Scene scene;

    GameCore::Entity floor;
    GameGraphics::CubeMeshComponent floorMesh;
    floorMesh.setMaterial({
        { 0.5f, 0.5f, 0.5f},
        { 0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, 0.5f},
        });
    floor.addComponent(&floorMesh);
    floorMesh.setLocalPosition({ 0.0f, -1.0f, 0.0f });
    floorMesh.setLocalScale({ 10.0f, 1.0f, 10.0f });
    scene.addEntity(&floor);

    GameCore::Entity entity;
    GameGraphics::CubeMeshComponent mesh;
    mesh.setMaterial({ {0.2f, 0.2f, 0.2f}, {0.2f, 0.2f, 0.2f}, {0.2f, 0.2f, 0.2f} });

    GameCore::Entity entity2;
    GameGraphics::CubeMeshComponent mesh2;
    mesh2.setMaterial({
        { 0.0f, 20.0f, 0.0f},
        { 0.0f, 20.0f, 0.0f},
        {0.0f, 0.0f, 0.0f}
    });
    mesh2.setLocalPosition({ 3.0f, 0.0f, 0.0f });

    LightComponent mesh2Light = LightComponent({ {0.0f, 0.0f, 0.0f}, {0.0f, 0.5f, 0},
        {0.0f, 0.5f, 0} }, 0, {0.0f, 0.0f, 0.0f});
    mesh2Light.setLocalPosition({ 3.0f, 0.0f, 0.0f });

    entity2.addComponent(&mesh2Light);

    FlyCamera camera = FlyCamera(1.5708f, 4.0f / 3.0f);
    camera.setMovementSpeed(0.1f);
    camera.setTurnSpeed(0.1f);

    GameMath::Vector3 lightPosition = { 5.0f, 0.0f, 5.0f };
    GameGraphics::Material lightBulbMaterial =
    {
        { 20.0f, 0.0f, 0.0f },
        { 20.0f, 0.0f, 0.0f },
        { 20.0f, 0.0f, 0.0f }
    };

    GameGraphics::Material lightMaterial =
    {
        { 0.3f, 0.3f, 0.3f },
        { 0.5f, 0.5f, 0.5f },
        { 1.0f, 1.0f, 1.0f }
    };



    GameCore::Entity backWall;
    GameGraphics::CubeMeshComponent backWallMesh;
    backWallMesh.setLocalScale({ 5, 5, 1 });
    backWallMesh.setLocalPosition({ 0, 2.5, -3 });
    backWallMesh.setMaterial({
        {0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, 0.5f},
        {0.5f, 0.5f, 0.5f}
    });

    backWall.addComponent(&backWallMesh);
    scene.addEntity(&backWall);

    GameCore::Entity behindWall;
    GameGraphics::CubeMeshComponent behindWallMesh;
    behindWallMesh.setLocalScale({ 1, 10, 10 });
    behindWallMesh.setLocalPosition({ 7, 0, 8 });
    behindWallMesh.setMaterial({
        {.5, .5f, .5f},
        {.5, .5f, .5f},
        {0.8f, .8f, .8f}
        });

    behindWall.addComponent(&behindWallMesh);
    scene.addEntity(&behindWall);

    GameCore::Entity leftWall;
    GameGraphics::CubeMeshComponent leftWallMesh;
    leftWallMesh.setLocalScale({ 1, 5, 7 });
    leftWallMesh.setLocalPosition({ -3, 2.5, 2 });
    leftWallMesh.setMaterial({
        {0.0f, 0.5f, 0.5f},
        {0.0f, 0.5f, 0.5f},
        {0.0f, 0.5f, 0.5f}
        });
    leftWall.addComponent(&leftWallMesh);
    scene.addEntity(&leftWall);

    GameCore::Entity roof;
    GameGraphics::CubeMeshComponent roofMesh;
    roofMesh.setLocalScale({ 7, 1, 7 });
    roofMesh.setLocalPosition({ 2, 4, 2 });
    roofMesh.setMaterial({
        {.1f, .5f, .1f},
        {.1f, .5f, .1f},
        {0.8f, .8f, .8f}
        });
    roof.addComponent(&roofMesh);
    scene.addEntity(&roof);

    LightComponent lightBulb = LightComponent({
        {0, 0, 0},
        {0.8f, 0, 0},
        {0.8f, 0, 0}
        }, 1, { 0, 0, 0 });
    lightBulb.setLocalPosition(lightPosition);

    GameCore::Entity light = GameCore::Entity();
    GameGraphics::CubeMeshComponent lightMesh = GameGraphics::CubeMeshComponent();
    lightMesh.setLocalPosition(lightPosition);
    lightMesh.setLocalScale({ .5f, .5f, .5f });
    lightMesh.setMaterial(lightBulbMaterial);
    light.addComponent(&lightMesh);
    light.addComponent(&lightBulb);

    GameGraphics::CubeMeshComponent light2Mesh = GameGraphics::CubeMeshComponent();

    GameCore::Entity light2 = GameCore::Entity();
    light2Mesh.setLocalPosition({ -1, 0, 6});
    light2Mesh.setMaterial({ {0.0f, 0.0f, 20}, {0.0f, 0.0f, 20}, {0.0f, 0.0f, 20} });
    light2.addComponent(&light2Mesh);

    LightComponent light2Component = LightComponent({ {0.0f, 0.0f, 0}, {0, 0, 1}, {0, 0, 1} }, 2, {0, 0, 0});
    light2Component.setLocalPosition(light2Mesh.getLocalPosition());
    light2.addComponent(&light2Component);
    scene.addEntity(&light2);

    GameCore::Entity directionalLight = GameCore::Entity();
    LightComponent directionalLightComponent = LightComponent(lightMaterial,
        3, { 1, -1, 1 });
    directionalLight.addComponent(&directionalLightComponent);

    scene.addEntity(&directionalLight);

    scene.addEntity(&light);
    scene.addEntity(&camera);
    entity.addComponent(&mesh);
    entity2.addComponent(&mesh2);
    scene.addEntity(&entity);
    scene.addEntity(&entity2);
    game.setCurrentScene(&scene);
    game.run();
    return 0;
}