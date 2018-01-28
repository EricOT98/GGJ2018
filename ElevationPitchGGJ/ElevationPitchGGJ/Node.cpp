#include "Node.h"

Node::Node()
{
	m_alive = false;
}

Node::~Node()
{
}

void Node::update()
{
	m_position.y -= m_speed;
	m_rect.setPosition(m_position);
}

void Node::render(sf::RenderWindow & window)
{
	window.draw(m_rect);
}

sf::Vector2f Node::getNodePosition()
{
	return sf::Vector2f(m_position);
}

/// <summary>
/// 
/// </summary>
/// <param name="pos">Spawn position of node</param>
/// <param name="size">Size of the node</param>
/// <param name="col">Fil color of the node</param>
/// <param name="speed"> speed of the node</param>
void Node::spawn(sf::Vector2f pos, sf::Vector2f size, sf::Color col, float speed, int column)
{
	m_position = pos;
	m_rect.setSize(size);
	m_rect.setFillColor(col);
	m_rect.setPosition(pos);
	m_alive = true;
	m_speed = speed;
	m_column = column;
}

bool Node::getAlive()
{
	return m_alive;
}

void Node::setAlive(bool alive)
{
	m_alive = alive;
}

bool Node::withinBounds(sf::Vector2f pos, sf::Vector2f size)
{
	return (m_position.y + m_rect.getSize().y < pos.y);
}

sf::Vector2f Node::getSize()
{
	return m_rect.getSize();
}

sf::Vector2f Node::getPosition()
{
	return m_position;
}
