#include "pch.h"
#include "End.h"


End::End()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Font.loadFromFile("fonts/Roboto-Light.ttf");

	m_EndText.setFont(m_Font);
	m_EndText.setCharacterSize(150);
	m_EndText.setFillColor(Color::White);
	m_EndText.setString("Congratulations !!!");
	FloatRect textRect = m_EndText.getLocalBounds();
	m_EndText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_EndText.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) - 200.0f);

	m_EndPlayer.setFont(m_Font);
	m_EndPlayer.setCharacterSize(150);
	m_EndPlayer.setFillColor(Color::White);
	m_EndPlayer.setString("Player 1 Won");
	textRect = m_EndPlayer.getLocalBounds();
	m_EndPlayer.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_EndPlayer.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f));

	m_EndPoints.setFont(m_Font);
	m_EndPoints.setCharacterSize(125);
	m_EndPoints.setFillColor(Color::White);
	m_EndPoints.setString("having 10 Points");
	textRect = m_EndPoints.getLocalBounds();
	m_EndPoints.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_EndPoints.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) + 150);
}

Text End::getEndText() {
	return m_EndText;
}

Text End::getEndPlayer() {
	return m_EndPlayer;
}

Text End::getEndPoints() {
	return m_EndPoints;
}

void End::setEndText(String text) {
	m_EndText.setString(text);
}

void End::setEndPlayer(String text) {
	m_EndPlayer.setString(text);
}

void End::setEndPoints(String text) {
	m_EndPoints.setString(text);
}