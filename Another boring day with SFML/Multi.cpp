#include "pch.h"
#include "Multi.h"
#include "TextureHolder.h"

Multi::Multi() {
	// Associate a texture with the sprite
	//m_Sprite = Sprite(TextureHolder::GetTexture("graphics/multi.png"));
	m_AnimationTexture = TextureHolder::GetTexture("graphics/char2.png");
	//m_Sprite = Sprite(m_AnimationTexture);
	//Vector2f scale(0.7, 0.7);
	//m_Sprite.setScale(scale);

	m_JumpDuration = .3;
}

bool Multi::handleInput()
{
	m_JustJumped = false;
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		// Start a jump if not already jumping
		if (!m_IsJumping && !m_IsFalling) {
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	} else {
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		m_LeftPressed = true;
	} else {
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		m_RightPressed = true;;
	} else {
		m_RightPressed = false;
	}

	return m_JustJumped;
}