#include "Player.h"
#include <iostream>
#include "KeyboardHandler.h"

Player::Player()

{
}

Player::Player(float x, float y, float const SCALE, bool set):
	m_lives(3)
{
	m_position = sf::Vector2f(x, y);
	m_player.setFillColor(sf::Color(100, 250, 50));
	m_player.setPosition(m_position);
	m_player.setSize(m_playerSize);


}

Player::~Player()
{
}

sf::Vector2f Player::getPlayerPosition()
{
	return sf::Vector2f(m_position);
}

sf::Vector2f Player::getPlayerSize()
{
	return sf::Vector2f(m_playerSize);
}


void Player::Update(float deltaTime)
{
	m_xbox.update();
	//m_nodeSpeed = 5;

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Left) || m_xbox.m_currentState.LeftThumbStick.x < -75)
	{
		if (m_position.x >= 5)
		{
			m_position.x -= speed / 2;
		}

	}

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Right) || m_xbox.m_currentState.LeftThumbStick.x > 75)
	{
		if (m_position.x  + m_player.getSize().x <= 640 - 20 )
		{
			m_position.x += speed / 2;
		}
	}


	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Up) || m_xbox.m_currentState.LTtrigger > 75)
	{
		//m_player.setSize(m_player.);
		if(m_player.getSize().x < 150 )
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x + 1.0f, m_player.getSize().y - 0.5f));
			if (m_nodeSpeed >= 8)
			{
				m_nodeSpeed -= 0.5;
			}

		}




		//std::cout << m_xbox.m_currentState.LTtrigger << std::endl;
	}

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Down) ||m_xbox.m_currentState.RTtrigger < -75)
	{
		if (m_player.getSize().x > 50)
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f, m_player.getSize().y + 0.5f));
			m_nodeSpeed += 0.2 ;
		}
		//m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f,m_player.getSize().y ));
		//std::cout << m_xbox.m_currentState.RTtrigger << std::endl;
	}

	//std::cout << "Speed: "  << std::endl;
	m_player.setPosition(m_position);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(m_player);
//	std::cout << "Drawing" << std::endl;

}

int Player::getLives()
{
	return m_lives;
}

void Player::setLives(int newLives)
{
	m_lives = newLives;
}

void Player::loseLife()
{
	m_lives--;
}
