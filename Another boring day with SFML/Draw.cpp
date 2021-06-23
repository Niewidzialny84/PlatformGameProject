#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>

void Engine::draw()
{
	m_Window.clear(Color::White);
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());
	if (!m_inEnd) {
		if (!m_inMenu) {
			if (!m_SplitScreen) {
				// Background
				m_Window.setView(m_BGMainView);
				m_Window.draw(m_BackgroundSprite, &m_RippleShader);

				//Main
				m_Window.setView(m_MainView);
				// Draw the Level
				m_Window.draw(m_VALevel, &m_TextureTiles);
				// Draw Single
				m_Window.draw(m_Single.getSprite());

				// Draw the particle system
				if (m_PS.running()) {
					m_Window.draw(m_PS);
				}

			}
			else {
				// Split screen
				//Player 1 side
				m_Window.setView(m_BGLeftView);
				m_Window.draw(m_BackgroundSprite, &m_RippleShader);
				m_Window.setView(m_LeftView);
				m_Window.draw(m_VALevel, &m_TextureTiles);

				m_Window.draw(m_Multi.getSprite());
				m_Window.draw(m_Single.getSprite());

				if (m_PS.running()) {
					m_Window.draw(m_PS);
				}

				//Player 2 side
				m_Window.setView(m_BGRightView);
				m_Window.draw(m_BackgroundSprite, &m_RippleShader);

				m_Window.setView(m_RightView);
				m_Window.draw(m_VALevel, &m_TextureTiles);

				m_Window.draw(m_Single.getSprite());
				m_Window.draw(m_Multi.getSprite());

				if (m_PS.running()) {
					m_Window.draw(m_PS);
				}

			}
			// Draw HUD
			m_Window.setView(m_HudView);
			m_Window.draw(m_Hud.getLevel());
			m_Window.draw(m_Hud.getTime());
			if (!m_SplitScreen) {
				m_Window.draw(m_Hud.getPoints());
			}
			else {
				m_Window.draw(m_Hud.getPoints());
				m_Window.draw(m_Hud.getPointsMulti());
			}

			if (!m_Playing)
			{
				m_Window.draw(m_Hud.getMessage());
				m_Window.draw(m_Hud.getRoundEnd());
			}
		}
		else {
			//Draw Menu
			m_Window.setView(m_MenuView);
			m_Window.draw(m_BackgroundSprite, &m_RippleShader);
			m_Window.draw(m_menu.getTitle());

			m_Window.draw(m_menu.getSingle());
			m_Window.draw(m_menu.getMulti());
			m_Window.draw(m_menu.getExit());

			m_Window.draw(m_menu.getButtonSingle());
			m_Window.draw(m_menu.getButtonMulti());
			m_Window.draw(m_menu.getButtonExit());
		}
	}
	else {
		//Draw End Screen
		m_Window.setView(m_EndScreen);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		m_Window.draw(m_End.getEndText());
		m_Window.draw(m_End.getEndPlayer());
		m_Window.draw(m_End.getEndPoints());
	}
	m_Window.display();
	
}