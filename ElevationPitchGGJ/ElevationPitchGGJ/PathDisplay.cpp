#include "PathDisplay.h"

PathDisplay::PathDisplay()
{
	m_active = false;
}

PathDisplay::~PathDisplay()
{
}

void PathDisplay::update()
{
}

void PathDisplay::render(sf::RenderWindow & window)
{
	if (m_active) {
		m_nodeHandler.render(window);
	}
}

void PathDisplay::generatePath(int numNodes)
{
	//int numPositions = m_nodeHandler
	for (int i = 0; i < numNodes; ++i) {
		//m_nodeHandler.spawnNode(m_size);
	}
}

void PathDisplay::init(sf::Vector2f pos, sf::Vector2f size, int numNodes)
{
	m_nodeHandler.populate(numNodes);
	m_nodeHandler.init(pos, size * 2.0f, numNodes);
	m_position = pos;
	m_size = size;
	m_active = true;
}

