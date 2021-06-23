#include "pch.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

Menu::Menu()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Font.loadFromFile("fonts/Roboto-Light.ttf");
	m_Title.setFont(m_Font);
	m_Title.setCharacterSize(150);
	m_Title.setFillColor(Color::White);
	m_Title.setString("Crucibles");
	// Position the text
	FloatRect textRect = m_Title.getLocalBounds();
	m_Title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Title.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) - 200.0f);

	m_ButtonSingle.setFont(m_Font);
	m_ButtonSingle.setCharacterSize(75);
	m_ButtonSingle.setFillColor(Color::White);
	m_ButtonSingle.setString("Single");
	m_ButtonSingle.setLetterSpacing(4);
	textRect = m_ButtonSingle.getLocalBounds();
	m_ButtonSingle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_ButtonSingle.setPosition((resolution.x / 2.0f) , (resolution.y / 2.0f) + 50.0f);

	m_ButtonMulti.setFont(m_Font);
	m_ButtonMulti.setCharacterSize(75);
	m_ButtonMulti.setFillColor(Color::White);
	m_ButtonMulti.setString("Multi");
	m_ButtonMulti.setLetterSpacing(4);
	textRect = m_ButtonMulti.getLocalBounds();
	m_ButtonMulti.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_ButtonMulti.setPosition((resolution.x / 2.0f) , (resolution.y / 2.0f) + 150.0f);

	m_ButtonExit.setFont(m_Font);
	m_ButtonExit.setCharacterSize(75);
	m_ButtonExit.setFillColor(Color::White);
	m_ButtonExit.setString("Exit");
	m_ButtonExit.setLetterSpacing(4);
	textRect = m_ButtonExit.getLocalBounds();
	m_ButtonExit.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_ButtonExit.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) + 250.0f);
	
	Vector2f rect_size(350,95);
	m_Single.setSize(rect_size);
	m_Multi.setSize(rect_size);
	m_Exit.setSize(rect_size);

	Color rect_color(47, 84, 145, 50);
	m_Single.setFillColor(rect_color);
	m_Multi.setFillColor(rect_color);
	m_Exit.setFillColor(rect_color);

	textRect = m_Single.getLocalBounds();
	m_Single.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Single.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) + 50.0f);

	textRect = m_Multi.getLocalBounds();
	m_Multi.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Multi.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) + 150.0f);

	textRect = m_Exit.getLocalBounds();
	m_Exit.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_Exit.setPosition((resolution.x / 2.0f), (resolution.y / 2.0f) + 250.0f);
}

void Menu::update() {
	Color rect_color(47, 84, 145, 50);
	Color use_color(72, 244, 66, 56);
	switch (menuCount)
	{
	case 1:
		m_Single.setFillColor(use_color);
		m_Multi.setFillColor(rect_color);
		m_Exit.setFillColor(rect_color);
		break;
	case 2:
		m_Single.setFillColor(rect_color);
		m_Multi.setFillColor(use_color);
		m_Exit.setFillColor(rect_color);
		break;
	case 3:
		m_Single.setFillColor(rect_color);
		m_Multi.setFillColor(rect_color);
		m_Exit.setFillColor(use_color);
		break;
	default:
		break;
	}
}

Text Menu::getTitle() {
	return m_Title;
}

Text Menu::getButtonSingle() {
	return m_ButtonSingle;
}

Text Menu::getButtonMulti() {
	return m_ButtonMulti;
}

Text Menu::getButtonExit() {
	return m_ButtonExit;
}

RectangleShape Menu::getSingle() {
	return m_Single;
}

RectangleShape Menu::getMulti() {
	return m_Multi;
}

RectangleShape Menu::getExit() {
	return m_Exit;
}

Vector2i Menu::getSingleCenter() {
	return Vector2i((m_Single.getGlobalBounds().left+m_Single.getGlobalBounds().width/2), 
		(m_Single.getGlobalBounds().top + m_Single.getGlobalBounds().height/2));
}

Vector2i Menu::getMultiCenter() {
	return Vector2i((m_Multi.getGlobalBounds().left + m_Multi.getGlobalBounds().width/2),
		(m_Multi.getGlobalBounds().top + m_Multi.getGlobalBounds().height/2));
}

Vector2i Menu::getExitCenter() {
	return Vector2i((m_Exit.getGlobalBounds().left + m_Exit.getGlobalBounds().width/2) ,
		(m_Exit.getGlobalBounds().top + m_Exit.getGlobalBounds().height/2));
}

int Menu::getMenuCount() {
	return menuCount;
}

void Menu::setMenuCount(int count) {
	menuCount = count;
}
