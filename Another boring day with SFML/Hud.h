#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Hud
{
private:
	Font m_Font;
	Text m_StartText;
	Text m_TimeText;
	Text m_LevelText;
	Text m_Points;
	Text m_PointsMulti;
	Text m_RoundEnd;
public:
	Hud();
	Text getMessage();
	Text getLevel();
	Text getTime();
	Text getPoints();
	Text getPointsMulti();
	Text getRoundEnd();
	void setLevel(String text);
	void setTime(String text);
	void setPoints(String text);
	void setPointsMulti(String text);
	void setRoundEnd(String text);
};

