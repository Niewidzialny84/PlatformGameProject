#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "TextureHolder.h" 
#include "Single.h"
#include "Multi.h"

#include "LevelManager.h"
#include "SoundManager.h"
#include "Hud.h"
#include "Menu.h"
#include "End.h"

#include "ParticleSystem.h"

using namespace sf;
class Engine
{
private:
	// The texture holder
	TextureHolder th;

	// create a particle system
	ParticleSystem m_PS;

	//Player
	Single m_Single;
	Multi m_Multi;

	int m_singlePoints;
	int m_multiPoints;
	const int MAX_POINTS = 50;

	// Is the game currently playing?
	bool m_Playing = false;
	bool m_Character1 = true;
	// Start in fullscreen mode
	bool m_SplitScreen = false;

	LevelManager m_LM;
	SoundManager m_SM;
	Hud m_Hud;

	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 30;
	
	View m_MenuView;
	Menu m_menu;
	bool m_inMenu;

	View m_EndScreen;
	End m_End;
	bool m_inEnd = false;
	int m_endDuration = 5000;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	// The force pushing the characters down
	const int GRAVITY = 300;
	// A regular RenderWindow
	RenderWindow m_Window;
	Image m_icon;
	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;
	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HudView;
	// Declare a sprite and a Texture
	// for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Declare a shader for the background
	Shader m_RippleShader;

	// How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;
	bool m_NewLevelRequired = true;

	VertexArray m_VALevel;
	int** m_ArrayLevel = NULL;
	Texture m_TextureTiles;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();
	bool detectCollisions(PlayableCharacter& character);
	void updateEnd(int number);
public:
	Engine();
	void run();
};
