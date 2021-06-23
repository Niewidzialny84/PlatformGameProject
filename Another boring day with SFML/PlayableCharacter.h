#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{
private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;

public:
	IntRect uvRect;
	void Update(int row, float deltaTime, bool faceRight);
	Animation(Texture *m_AnimationTexture, Vector2u imageCount, float switchTime);
	Animation() {};
	~Animation();

};

class PlayableCharacter
{
protected:
	Sprite m_Sprite;
	// Jump
	float m_JumpDuration;
	bool m_IsJumping;
	bool m_IsFalling;
	// Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;
	// How long has this jump lasted so far
	float m_TimeThisJump;
	// Has the player just initialted a jump
	bool m_JustJumped = false;
	Texture m_AnimationTexture;
	Animation animation;
	int m_row;
	bool faceRight;
private:
	float m_Gravity;
	// How fast is the character
	float m_Speed = 400;
	// Where is the player
	Vector2f m_Position;
	// Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	FloatRect m_Colide;
	// And a texture
	Texture m_Texture;
public:
	void spawn(Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;
	FloatRect getPosition();
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();
	FloatRect getColide();
	Sprite getSprite();
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	Vector2f getCenter();
	void update(float elapsedTime);
};