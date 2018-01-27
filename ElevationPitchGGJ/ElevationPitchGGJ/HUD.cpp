#include "HUD.h"

Hud::Hud()
{
}

Hud::~Hud()
{
}

float Hud::time(sf::Time t_deltaTime)
{
	m_miliseconds += t_deltaTime.asSeconds();	// gives time as seconds at rate of 1/60 of a second
	m_milisecondString = std::to_string(m_miliseconds);
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
	if (m_seconds >= 60)		// 60 seconds in a minute occured, check for this
	{
		
		m_seconds = 0;			// resets second counter
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
	
	std::cout << m_minuteString << " : " << m_secondString << " : " << m_milisecondString << std::endl;
	return m_seconds; 
}
