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
	int numPositions = m_nodeHandler.getNumPositions() - 1;
	int nodeSizeY = m_size.y / numNodes;
	int nodeSizeX = m_size.x / numNodes;
	
	for (int i = 0; i < numNodes; i++) {
		int colToSpawn = std::rand() % numPositions;
		sf::Color col(128,128,128, 255);
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

int PathDisplay::getNodesColumn(int node)
{
	return m_nodeHandler.m_nodes.at(node).m_column;
}

int PathDisplay::getNumNodes()
{
	return m_nodeHandler.m_nodes.size();
}

Node & PathDisplay::getCurrentNode()
{
	return m_nodeHandler.m_nodes.at(m_currentNode);
}

