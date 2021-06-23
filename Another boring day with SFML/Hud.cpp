#include "pch.h"
#include "Hud.h"

Hud::Hud()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	// Load the font
	m_Font.loadFromFile("fonts/Roboto-Light.ttf");
	// when Paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(100);
	m_StartText.setFillColor(Color::White);
	m_StartText.setString("Press Enter to start!");
	FloatRect textRect = m_StartText.getLocalBounds();
	m_StartText.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);
	// Time
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(65);
	m_TimeText.setFillColor(Color::Red);
	m_TimeText.setPosition((resolution.x / 2.0f)-37, 0);
	m_TimeText.setString("------");
	// Level
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(50);
	m_LevelText.setFillColor(Color::White);
	m_LevelText.setPosition(25, resolution.y - 60);
	m_LevelText.setString("1");

	//Single points
	m_Points.setFont(m_Font);
	m_Points.setCharacterSize(45);
	m_Points.setFillColor(Color::White);
	m_Points.setPosition(25, 0);
	m_Points.setString("0");

	//Multi points
	m_PointsMulti.setFont(m_Font);
	m_PointsMulti.setCharacterSize(45);
	m_PointsMulti.setFillColor(Color::White);
	m_PointsMulti.setPosition(resolution.x - 200, 0);
	m_PointsMulti.setString("0");

	m_RoundEnd.setFont(m_Font);
	m_RoundEnd.setCharacterSize(65);
	m_RoundEnd.setFillColor(Color::White);
	m_RoundEnd.setString("Player 1 earned 00");
	textRect = m_RoundEnd.getLocalBounds();
	m_RoundEnd.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_RoundEnd.setPosition(resolution.x / 2.0f , (resolution.y / 2.0f)+85);
	m_RoundEnd.setString(" ");
}

Text Hud::getMessage()
{
	return m_StartText;
}

Text Hud::getLevel()
{
	return m_LevelText;
}

Text Hud::getTime()
{
	return m_TimeText;
}

Text Hud::getPoints()
{
	return m_Points;
}

Text Hud::getPointsMulti()
{
	return m_PointsMulti;
}

Text Hud::getRoundEnd()
{
	return m_RoundEnd;
}

void Hud::setLevel(String text)
{
	m_LevelText.setString(text);
}

void Hud::setTime(String text)
{
	m_TimeText.setString(text);
}

void Hud::setPoints(String text)
{
	m_Points.setString(text);
}

void Hud::setPointsMulti(String text)
{
	m_PointsMulti.setString(text);
}

void Hud::setRoundEnd(String text) {
	m_RoundEnd.setString(text);
}