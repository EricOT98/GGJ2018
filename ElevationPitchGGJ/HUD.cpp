#include "HUD.h"
#include "Game.h"
Hud::Hud():
	m_score{0}
{
}

Hud::~Hud()
{
}

void Hud::init(sf::Font &font)
{
	m_font = font;
	m_scoreText.setFont(font);
	m_scoreText.setStyle(sf::Text::Bold);
	m_scoreText.setString("Score");
	m_scoreText.setPosition(Game::screenWidth-1000, 50);
	m_scoreText.setFillColor(sf::Color::Yellow);
	m_scoreText.setCharacterSize(60);
	m_scoreText.setOutlineColor(sf::Color::Black);
	m_scoreText.setOutlineThickness(5.f);
}

int Hud::getScore()
{
	return m_score;
}

void Hud::setScore(int newScore)
{
	m_score = newScore;
}

void Hud::increaseScore()
{
	m_score = m_score + 1;
}

void Hud::render(sf::RenderWindow &window)
{
	m_scoreText.setString("Score : " + std::to_string(m_score));
	window.draw(m_scoreText);
}

std::string Hud::time(sf::Time t_deltaTime)
{
	m_miliseconds += t_deltaTime.asSeconds();	// gives time as seconds at rate of 1/60 of a second
	m_milisecondTruncate = m_miliseconds * m_multiplier;
	m_milisecondOutput = m_milisecondTruncate;
	m_milisecondString = std::to_string(m_milisecondOutput);
	
	
	if (m_miliseconds >= 1)		// checks if total miliseconds == 1 second
	{
		m_miliseconds = 0.f;	// resets miliseconds counter
		m_seconds++;			// adds 1 to second counter	
		if (m_seconds <= 9)
		{
			m_secondString = "0" + std::to_string(m_seconds);
		}
		else
		{
			m_secondString = std::to_string(m_seconds);
		}
	}
	if (m_seconds >= 59 && m_miliseconds > 0.97)		// 60 seconds in a minute occured, check for this
	{
		
		m_seconds = -1;			// resets second counter to minus -1 as there is 1 second gap in minute switch (messy but a fix still)
		m_minutes++;			// adds 1 to minute counter
		if (m_minutes <= 9)
		{
			m_minuteString = "0" + std::to_string(m_minutes);
		}
		else
		{
			m_minuteString = std::to_string(m_minutes);
		}
	}
	
	m_totalString = m_minuteString + " : " + m_secondString + " : " + m_milisecondString;
	
	return m_totalString; 
}

void Hud::resetTimer()
{
	m_miliseconds = 0.f;
	m_seconds = 0;
	m_minutes = 0;
	m_minuteString = "00";
	m_secondString = "00";
	m_milisecondString = "00";
	m_totalString = m_minuteString + " : " + m_secondString + " : " + m_milisecondString;
}

float Hud::returnMiliseconds()
{
	return m_miliseconds;
}

int Hud::returnSeconds()
{
	return m_seconds;
}

int Hud::returnMinutes()
{
	return m_minutes;
}
