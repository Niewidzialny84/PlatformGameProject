#include "pch.h"
#include "Single.h"
#include "TextureHolder.h"

Single::Single() {
	// Associate a texture with the sprite
	//m_Sprite = Sprite(TextureHolder::GetTexture("graphics/single.png"));
	m_AnimationTexture = TextureHolder::GetTexture("graphics/char12.png");
	//m_Sprite = Sprite(m_AnimationTexture);
	//Vector2f scale(0.7, 0.7);
	//m_Sprite.setScale(scale);

	m_JumpDuration = .3;
}

bool Single::handleInput()
{
	m_JustJumped = false;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
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

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		m_LeftPressed = true;
	} else {
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		m_RightPressed = true;
	} else {
		m_RightPressed = false;
	}

	return m_JustJumped;
}
