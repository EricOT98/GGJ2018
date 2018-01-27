#include "Player.h"
#include <iostream>
#include "KeyboardHandler.h"

Player::Player():
	m_lives{0}
{
}

Player::Player(float x, float y, float const SCALE, bool set)
{
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
	
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Left) || m_xbox.m_currentState.LeftThumbStick.x < -75)
	{

		m_position.x -= speed /2;
		
		//std::cout << "moving" << std::endl;
		//if (jump == true && m_body->GetPosition().x <= 3.9)
		//{
		//	m_body->SetLinearVelocity(b2Vec2(-15, 15));
		//}
	}

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Right) || m_xbox.m_currentState.LeftThumbStick.x > 75)
	{

		m_position.x += speed / 2;

		//std::cout << "moving" << std::endl;
		
	}

	
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Up) || m_xbox.m_currentState.LTtrigger > 75)
	{
		//m_player.setSize(m_player.);
		if(m_player.getSize().x < 150 )
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x + 1.0f, m_player.getSize().y - 0.5f));
			m_position.y -= speed / 14;
			/*m_nodes.m_speed -= 1;*/
		}
		
		
		
	
		std::cout << m_xbox.m_currentState.LTtrigger << std::endl;
	}
	/*else  if (m_player.getPosition().y < 400)
	{
		m_player.setSize(sf::Vector2f(m_player.getSize().x + 0.2f, m_player.getSize().y + 0.2f));
		m_position.y += speed / 25;
	}*/

	

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Down) ||m_xbox.m_currentState.RTtrigger < -75)
	{
		if (m_player.getSize().x > 50)
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f, m_player.getSize().y + 0.5f));
			m_position.y += speed / 14;
			/*m_nodes.m_speed += 1;*/
		}
		//m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f,m_player.getSize().y ));
		std::cout << m_xbox.m_currentState.RTtrigger << std::endl;
	}

	std::cout << "Speed: "  << std::endl;
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
