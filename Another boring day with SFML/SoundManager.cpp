#include "pch.h"
#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;
SoundManager::SoundManager()
{
	// Load the sound in to the buffers
	m_FallInFireBuffer.loadFromFile("sound/lava.wav");
	m_FallInWaterBuffer.loadFromFile("sound/water.wav");
	m_JumpBuffer.loadFromFile("sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("sound/win.wav");
	// Associate the sounds with the buffers
	m_FallInFireSound.setBuffer(m_FallInFireBuffer);
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);
}

void SoundManager::playFallInFire()
{
	m_FallInFireSound.setRelativeToListener(true);
	m_FallInFireSound.play();
}

void SoundManager::playFallInWater()
{
	m_FallInWaterSound.setRelativeToListener(true);
	m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
	m_JumpSound.setRelativeToListener(true);
	m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
	m_ReachGoalSound.setRelativeToListener(true);
	m_ReachGoalSound.play();
}