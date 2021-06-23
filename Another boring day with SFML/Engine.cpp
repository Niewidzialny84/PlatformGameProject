#include "pch.h"
#include "Engine.h"
Engine::Engine()
{
	// Get the screen resolution
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(resolution.x, resolution.y), "Crucibles", Style::Fullscreen);

	// Initialize menu and end screen view
	m_MenuView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	m_EndScreen.reset(FloatRect(0, 0, resolution.x, resolution.y));
	// Initialize fullscreen view
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	// Inititialize split screen views
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	// Shader broken
	if (!sf::Shader::isAvailable()) {
		m_Window.close();
	} else {
		// Load two shaders (1 vertex, 1 fragment)
		m_RippleShader.loadFromFile("shaders/vertShader.vert","shaders/rippleShader.frag");
	}

	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load the texture for blocks
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");

	//icons
	m_icon.loadFromFile("graphics/icon.png");

	// Initialize the particle system
	m_PS.init(1000);
	//m_Window.setFramerateLimit(60);
	//m_Window.setVerticalSyncEnabled(true);
}

void Engine::run()
{
	// Timing
	Clock clock;

	//Lost variables
	m_inMenu = true;
	m_menu.setMenuCount(1);
	m_singlePoints = 0;
	m_multiPoints = 0;

	m_Window.setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();
		input();
		update(dtAsSeconds);
		draw();
	}
}
