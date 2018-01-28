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
	int numPositions = m_nodeHandler.getNumPositions();
	int nodeSizeY = m_size.y / numNodes;
	int nodeSizeX = m_size.x / numNodes;
	
	for (int i = 0; i < numNodes; ++i) {
		int colToSpawn = std::rand() % numPositions;
		sf::Color col(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255);
		m_nodeHandler.spawnNode(sf::Vector2f(m_nodeHandler.m_positions.at(colToSpawn),i * nodeSizeY),
			sf::Vector2f(nodeSizeX,nodeSizeY), col, colToSpawn);
	}
}

void PathDisplay::init(sf::Vector2f pos, sf::Vector2f size, int numNodes)
{
	m_nodeHandler.populate(numNodes);
	m_nodeHandler.init(pos, sf::Vector2f(size.x * 2.0f, size.y), 4);
	m_position = pos;
	m_size = size;
	m_active = true;
}

