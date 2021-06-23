#include "pch.h"
#include "PlayableCharacter.h"
#include <SFML/Graphics.hpp>

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	// Initialize the gravity
	m_Gravity = gravity;
	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

	m_Sprite.setTexture(m_AnimationTexture);
	animation = Animation(&m_AnimationTexture, Vector2u(4, 3), 0.3f);
	m_row = 0;
	faceRight = true;
	update(0);
}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_RightPressed) {
		m_Position.x += m_Speed * elapsedTime;
		faceRight = true;
	}

	if (m_LeftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
		faceRight = false;
	}

	if (!m_LeftPressed && !m_RightPressed && !m_IsJumping) {
		m_row = 0;
	}
	else {
		m_row = 1;
	}
	
	// Handle Jumping
	if (m_IsJumping) {
		m_row = 2;
		// Update how long the jump has been going
		m_TimeThisJump += elapsedTime;
		// Is the jump going upwards
		if (m_TimeThisJump < m_JumpDuration) {
			// Move up
			m_Position.y -= m_Gravity * 3 * elapsedTime;
		} else {
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}

	// Apply gravity
	if (m_IsFalling) {
		m_Position.y += m_Gravity * elapsedTime;
	}

	// Update the rect for all body parts
	FloatRect r = getPosition();
	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
	// Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * 0.15625) + 1;
	m_Head.width = r.width;
	m_Head.height = 1;
	// Right
	m_Right.left = r.left + r.width - 1;
	m_Right.top = r.top + (r.height * 0.15625);
	m_Right.width = 1;
	m_Right.height = r.height * 0.36;
	// Left
	m_Left.left = r.left + 1;
	m_Left.top = r.top + (r.height * 0.15625);
	m_Left.width = 1;
	m_Left.height = r.height * 0.36;
	// "Center" rect for collision
	m_Colide.left = r.left + 3;
	m_Colide.top = r.top + r.height - 7;
	m_Colide.width = r.width - 6;
	m_Colide.height = 1;
	// Move the sprite into position
	animation.Update(m_row, elapsedTime, faceRight);
	m_Sprite.setTextureRect(animation.uvRect);
	m_Sprite.setPosition(m_Position);

}

FloatRect PlayableCharacter::getPosition() {
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet() {
	return m_Feet;
}

FloatRect PlayableCharacter::getHead() {
	return m_Head;
}

FloatRect PlayableCharacter::getLeft() {
	return m_Left;
}

FloatRect PlayableCharacter::getRight() {
	return m_Right;
}

FloatRect PlayableCharacter::getColide() {
	return m_Colide;
}

Sprite PlayableCharacter::getSprite() {
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position) {
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharacter::stopRight(float position) {
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position) {
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump() {
	// Stop a jump early
	m_IsJumping = false;
	m_IsFalling = true;
}