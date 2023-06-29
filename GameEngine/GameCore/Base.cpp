#include "pch.h"
#include "Base.h"
void GameCore::Base::added()
{
	onAdded();
}

void GameCore::Base::removed()
{
	onRemoved();
}

void GameCore::Base::start()
{
	onStart();

	m_shouldCallStart = false;
}

void GameCore::Base::update(float deltaTime)
{
	if (m_shouldCallStart)
	{
		start();
	}

	onUpdate(deltaTime);
}

void GameCore::Base::fixedUpdate(float fixedTimestep)
{

	onFixedUpdate(fixedTimestep);
}

void GameCore::Base::draw()
{
	onDraw();
}

void GameCore::Base::end()
{
	onEnd();
}
