#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class End
{
private:
	Font m_Font;
	Text m_EndText;
	Text m_EndPlayer;
	Text m_EndPoints;
public:
	End();
	Text getEndText();
	Text getEndPlayer();
	Text getEndPoints();
	void setEndText(String text);
	void setEndPlayer(String text);
	void setEndPoints(String text);
};

