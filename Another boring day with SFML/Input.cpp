#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				//m_Window.close();
				m_inMenu = true;
				m_Window.setMouseCursorVisible(true);
				m_Playing = false;
				m_Character1 = true;
				m_SplitScreen = false;
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				if (m_inMenu == false) {
					m_Playing = true;
				}

			}

			if (Keyboard::isKeyPressed(Keyboard::Down) && m_inMenu) {
				if (m_menu.getMenuCount() == 3) {
					m_menu.setMenuCount(1);
				}
				else {
					m_menu.setMenuCount(m_menu.getMenuCount() + 1);
				}
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Up) && m_inMenu) {
				if (m_menu.getMenuCount() == 1) {
					m_menu.setMenuCount(3);
				}
				else {
					m_menu.setMenuCount(m_menu.getMenuCount() - 1);
				}
			}
			
			if (m_inMenu) {
				if (m_menu.getMenuCount() == 1) {
					Mouse::setPosition(m_menu.getSingleCenter());
				}

				if (m_menu.getMenuCount() == 2) {
					Mouse::setPosition(m_menu.getMultiCenter());
				}

				if (m_menu.getMenuCount() == 3) {
					Mouse::setPosition(m_menu.getExitCenter());
				}
			}


		}
	}

	//Button handling for menu 
	if (m_inMenu) {
		Vector2i pixelPos = Mouse::getPosition();
		Vector2f worldPos = m_Window.mapPixelToCoords(pixelPos);

		if (Mouse::getPosition() == m_menu.getExitCenter() || Mouse::getPosition() == m_menu.getSingleCenter() || Mouse::getPosition() == m_menu.getMultiCenter()) {
			m_Window.setMouseCursorVisible(false);
		}
		else {
			m_Window.setMouseCursorVisible(true);
		}

		if (Mouse::isButtonPressed(sf::Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Return)) {
			if (m_menu.getSingle().getGlobalBounds().contains(worldPos) || m_menu.getMenuCount() == 1) {
				m_inMenu = false;
				m_Window.setMouseCursorVisible(false);
				m_SplitScreen = false;
				m_LM.setCurrentLevel(0);
				loadLevel();
				m_singlePoints = 0;
				m_Hud.setRoundEnd(" ");
			}

			if (m_menu.getMulti().getGlobalBounds().contains(worldPos) || m_menu.getMenuCount() == 2) {
				m_SplitScreen = true; //Multi goes here
				m_inMenu = false;
				m_Window.setMouseCursorVisible(false);
				m_LM.setCurrentLevel(0);
				loadLevel();
				m_singlePoints = 0;
				m_multiPoints = 0;
				m_Hud.setRoundEnd(" ");
			}

			if (m_menu.getExit().getGlobalBounds().contains(worldPos) || m_menu.getMenuCount() == 3)
				m_Window.close();//player quit
		}

		if (m_menu.getSingle().getGlobalBounds().contains(worldPos)) {
			m_menu.setMenuCount(1);
		}

		if (m_menu.getMulti().getGlobalBounds().contains(worldPos)) {
			m_menu.setMenuCount(2);
		}

		if (m_menu.getExit().getGlobalBounds().contains(worldPos)) {
			m_menu.setMenuCount(3);
		}
		m_menu.update();
	}


	// Handle input specific to single
	if (m_Single.handleInput()) {
		// Play a jump sound
		m_SM.playJump();
	}
	// Handle input specific to multi
	if (m_Multi.handleInput() && m_SplitScreen) {
		// Play a jump sound
		m_SM.playJump();
	}
}