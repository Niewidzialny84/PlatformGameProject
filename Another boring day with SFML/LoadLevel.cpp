#include "pch.h"
#include "Engine.h"
void Engine::loadLevel()
{
	m_Playing = false;
	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	// How long is this new time limit
	m_TimeRemaining = m_LM.getTimeLimit();
	m_Single.spawn(Vector2f(m_LM.getStartPosition().x + 20, m_LM.getStartPosition().y), GRAVITY);
	m_Multi.spawn(Vector2f(m_LM.getStartPosition().x - 20, m_LM.getStartPosition().y), GRAVITY);
	m_NewLevelRequired = false;
}
