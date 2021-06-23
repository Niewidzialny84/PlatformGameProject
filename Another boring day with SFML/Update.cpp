#include "pch.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired) {
		loadLevel();
	}

	
	if (m_endDuration > 0 && m_inEnd) {
		m_endDuration -= dtAsSeconds;
	}
	else {
		m_inEnd = false;
	}


	if (m_Playing)
	{
		stringstream ssRoundEnd;

		if (!m_SplitScreen) {
			// Update single
			m_Single.update(dtAsSeconds);
			if (detectCollisions(m_Single)) {
				// Points count
				m_singlePoints += static_cast<int>(m_TimeRemaining);

				// End screen
				if (m_singlePoints > MAX_POINTS && m_inEnd == false) {
					updateEnd(0);
				}

				m_NewLevelRequired = true;
				m_SM.playReachGoal();
				ssRoundEnd << "     You earned " << static_cast<int>(m_TimeRemaining);
				m_Hud.setRoundEnd(ssRoundEnd.str());
			}
		} else {
			m_Single.update(dtAsSeconds);
			// Update multi
			m_Multi.update(dtAsSeconds);

			if (detectCollisions(m_Single))
			{
				m_singlePoints += static_cast<int>(m_TimeRemaining);
				
				// End screen
				if (m_singlePoints > MAX_POINTS && m_inEnd == false) {
					updateEnd(1);
				}

				m_NewLevelRequired = true;
				m_SM.playReachGoal();
				ssRoundEnd << "Player 1 earned " << static_cast<int>(m_TimeRemaining);
				m_Hud.setRoundEnd(ssRoundEnd.str());
			}
			else if (detectCollisions(m_Multi)) {
				m_multiPoints += static_cast<int>(m_TimeRemaining);

				// End screen
				if (m_multiPoints > MAX_POINTS && m_inEnd == false) {
					updateEnd(2);
				}

				m_SM.playReachGoal();
				m_NewLevelRequired = true;
				ssRoundEnd << "Player 2 earned " << static_cast<int>(m_TimeRemaining);
				m_Hud.setRoundEnd(ssRoundEnd.str());
			}

			//Player colison 
			if (m_Multi.getFeet().intersects(m_Single.getHead())) {
				m_Multi.stopFalling(m_Single.getHead().top-1);
			}
			else if (m_Single.getFeet().intersects(m_Multi.getHead())) {
				m_Single.stopFalling(m_Multi.getHead().top-1);
			}

			/*
			if (m_Single.getRight().intersects(m_Multi.getLeft())) {
				m_Single.stopRight(m_Multi.getLeft().left - 1);
			}
			else if (m_Multi.getLeft().intersects(m_Single.getRight())) {
				m_Multi.stopLeft(m_Single.getLeft().left + 19);
			}

			if (m_Multi.getRight().intersects(m_Single.getLeft())) {
				m_Multi.stopRight(m_Single.getLeft().left - 1 );
			}
			else if (m_Single.getLeft().intersects(m_Multi.getRight())) {
				m_Single.stopLeft(m_Multi.getLeft().left + 19);
			}
			*/

		}

		m_TimeRemaining -= dtAsSeconds;
		if (m_TimeRemaining <= 0) {
			m_NewLevelRequired = true;
		}
	}

	// Set the appropriate view around the appropriate character
	if (m_SplitScreen) {
		m_LeftView.setCenter(m_Single.getCenter());
		m_RightView.setCenter(m_Multi.getCenter());
	} else {
		// Centre full screen around appropriate character
		if (m_Character1) {
			m_MainView.setCenter(m_Single.getCenter());
		} else {
			m_MainView.setCenter(m_Multi.getCenter());
		}
	}

	//HUD
	m_FramesSinceLastHUDUpdate++;
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate) {
		stringstream ssTime;
		stringstream ssLevel;
		stringstream ssPoints;
		stringstream ssPointsMulti;
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());
		ssLevel << "Level:" << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());
		ssPoints << "Points: " << m_singlePoints;
		m_Hud.setPoints(ssPoints.str());
		ssPointsMulti << "Points: " << m_multiPoints;
		m_Hud.setPointsMulti(ssPointsMulti.str());
		m_FramesSinceLastHUDUpdate = 0;
	}

	if (m_PS.running()) {
		m_PS.update(dtAsSeconds);
	}


}

void Engine::updateEnd(int number) {
	stringstream ssPlayer;
	stringstream ssPoints;

	switch (number)
	{
	case 0:
		ssPoints << "Having " << m_singlePoints << " Points";
		ssPlayer << "     You Won";
		break;
	case 1:
		ssPoints << "Having " << m_singlePoints << " Points";
		ssPlayer << "Player 1 Won";
		break;
	case 2:
		ssPoints << "Having " << m_multiPoints << " Points";
		ssPlayer << "Player 2 Won";
		break;
	default:
		break;
	}

	m_inEnd = true;
	m_inMenu = true;
	m_Playing = false;
	m_endDuration = 5000;

	m_End.setEndPlayer(ssPlayer.str());
	m_End.setEndPoints(ssPoints.str());
	m_Window.setMouseCursorVisible(true);
}