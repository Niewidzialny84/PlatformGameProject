#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
private:
	Font m_Font;
	Text m_Title;
	Text m_ButtonSingle;
	Text m_ButtonMulti;
	Text m_ButtonExit;
	RectangleShape m_Single;
	RectangleShape m_Multi;
	RectangleShape m_Exit;
	int menuCount;
public:
	Menu();
	void update();
	Text getTitle();
	Text getButtonSingle();
	Text getButtonMulti();
	Text getButtonExit();
	RectangleShape getSingle();
	RectangleShape getMulti();
	RectangleShape getExit();
	void setMenuCount(int count);
	Vector2i getSingleCenter();
	Vector2i getMultiCenter();
	Vector2i getExitCenter();
	int getMenuCount();
};


