#pragma once
#include <SFML/Audio.hpp>

using namespace sf;
class SoundManager
{
private:
	// The buffers
	SoundBuffer m_FallInFireBuffer;
	SoundBuffer m_FallInWaterBuffer;
	SoundBuffer m_JumpBuffer;
	SoundBuffer m_ReachGoalBuffer;
	// The Sounds
	Sound m_FallInFireSound;
	Sound m_FallInWaterSound;
	Sound m_JumpSound;
	Sound m_ReachGoalSound;
public:
	SoundManager();
	void playFallInFire();
	void playFallInWater();
	void playJump();
	void playReachGoal();
};