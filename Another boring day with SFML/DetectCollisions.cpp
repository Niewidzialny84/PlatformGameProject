#include "pch.h"
#include "Engine.h"
/*
0 - empty
1 - simple grass
2 - lava head
3 - water head
4 - crucible
5 - drit block
6 - grass 2 
7 - grass 3
8 - water whole
9 - lava whole
*/
bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	FloatRect detectionZone = character.getPosition();
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;
	// Build a zone around
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	if (endX >= m_LM.getLevelSize().x) 
		endX = m_LM.getLevelSize().x;

	if (endY >= m_LM.getLevelSize().y) 
		endY = m_LM.getLevelSize().y;

	// Has the character fallen out of the map?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level)) {
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// Loop through all the local blocks
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;
			// Has character been burnt or drowned?
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3 || m_ArrayLevel[y][x] == 8 || m_ArrayLevel[y][x] == 9)
			{
				if (character.getColide().intersects(block))
				{
					// Which sound should be played? What color of particle should be displayed?
					if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 9) {
						m_SM.playFallInFire();
						m_PS.setColor(Color::Red);
					}
					else {
						m_SM.playFallInWater();
						m_PS.setColor(Color::Blue);
					}

					if (!m_PS.running()) {
						m_PS.emitParticles(character.getCenter());
					}

					character.spawn(m_LM.getStartPosition(), GRAVITY);
				}
			}

			// Is character colliding with a regular block
			if (m_ArrayLevel[y][x] == 1 || m_ArrayLevel[y][x] == 5 || m_ArrayLevel[y][x] == 6 || m_ArrayLevel[y][x] == 7)
			{
				if (character.getRight().intersects(block)) {
					character.stopRight(block.left);
				} else if (character.getLeft().intersects(block)) {
					character.stopLeft(block.left+18);
				}
				//Need to fix -1 and staggering effect
				if (character.getFeet().intersects(block)) {
					character.stopFalling(block.top-1);
				} else if (character.getHead().intersects(block)) {
					character.stopJump();
				}
			}

			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				reachedGoal = true;
			}
		}
	}
	return reachedGoal;
}
