#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::Player(float x, float y, float const SCALE, bool set)
{
	m_player.setFillColor(sf::Color(100, 250, 50));
	m_player.setPosition(m_position);
	m_player.setSize(sf::Vector2f(100,100));


}

Player::~Player()
{
}


void Player::Update(float deltaTime)
{
	m_xbox.update();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || m_xbox.m_currentState.LeftThumbStick.x < -75)
	{

		m_position.x -= speed;
		
		std::cout << "moving" << std::endl;
		//if (jump == true && m_body->GetPosition().x <= 3.9)
		//{
		//	m_body->SetLinearVelocity(b2Vec2(-15, 15));
		//}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || m_xbox.m_currentState.LeftThumbStick.x > 75)
	{

		m_position.x += speed;

		std::cout << "moving" << std::endl;
		
	}


	if (m_xbox.m_currentState.LTtrigger > 75)
	{
		//m_player.setSize(m_player.);
		if(m_player.getSize().x < 150 )
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x + 1.0f, m_player.getSize().y - 0.5f));
		}
		//else
		//{
		//	if (m_player.setSize(sf::Vector2f(m_player.getSize().x, m_player.getSize().y) > m_player.setSize(sf::Vector2f(60, m_player.getSize().y))
		//	{
		//		m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f, m_player.getSize().y));
		//	}
		//}
	
		std::cout << m_xbox.m_currentState.LTtrigger << std::endl;
	}

	if (m_xbox.m_currentState.RTtrigger < -75)
	{
		if (m_player.getSize().x > 50)
		{
			m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f, m_player.getSize().y + 0.5f));
		}
		//m_player.setSize(sf::Vector2f(m_player.getSize().x - 1.0f,m_player.getSize().y ));
		std::cout << m_xbox.m_currentState.RTtrigger << std::endl;
	}


	m_player.setPosition(m_position);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(m_player);
//	std::cout << "Drawing" << std::endl;
	
}