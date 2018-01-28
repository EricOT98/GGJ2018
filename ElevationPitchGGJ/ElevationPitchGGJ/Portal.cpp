#include "Portal.h"
#include <iostream>

Portal::Portal()
	: m_texture(sf::Texture())
{
}

Portal::Portal(sf::Vector2f position, float radius, std::string filename)
	:m_position(position),
	m_texture(sf::Texture())
{
	if (!m_shader.loadFromFile("ASSETS/SHADERS/Portal.frag", sf::Shader::Fragment)) {
		std::cout << "ERROR: Failed to load portal shader" << std::endl;
	}
	
	if (!m_renderTexture.create(200, 200))
	{
		std::cout << "error" << std::endl;
	}
	m_rectShape.setPosition(sf::Vector2f(0, 0 ));
	m_rectShape.setSize(sf::Vector2f(200, 600));

	m_shader.setUniform("time", 1.f);
	//m_shader.setUniform("mouse",sf::Glsl::Vec2(m_position));
	m_shader.setUniform("resolution", sf::Vector2f(200, 200));
	
	m_sprite.setTexture(m_renderTexture.getTexture());
	m_sprite.setPosition(m_position);
	m_sprite.setScale(2, 1);
	std::cout << m_sprite.getGlobalBounds().width << std::endl;
}

Portal::~Portal()
{
}

void Portal::loadPortal()
{
}

void Portal::update(float timeInSecs)
{
	totalTime += timeInSecs;
	m_shader.setUniform("time", totalTime);
	//m_shader.setUniform("mouse", sf::Glsl::Vec2(m_position));
	if (m_animateIn) {
		animateIn();
	}
}

void Portal::render(sf::RenderWindow & window)
{
	m_renderTexture.clear(sf::Color::Black);
	m_renderTexture.draw(m_rectShape, &m_shader);
	//m_renderTexture.display();
//	window.draw(m_sprite);
}

void Portal::startAnimation()
{
	m_animateIn = true;
}

void Portal::animateIn()
{
	m_sprite.move(sf::Vector2f(0, -1));
}
