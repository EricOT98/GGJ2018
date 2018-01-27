#ifndef NODEHANDLER_H
#define NODEHANDLER_H

#include <SFML\Graphics.hpp>
#include "Node.h"

class NodeHandler
{
public:
	NodeHandler();
	~NodeHandler();

	void update();
	void render(sf::RenderWindow & window);

	void init(sf::Vector2f pos, sf::Vector2f & windowSize, int numColumns);

	void populate(int numNodes);
	bool spawnNode(sf::Vector2f pos, sf::Vector2f size, sf::Color col);
	void randomGeneration( sf::Vector2f size);
	int getNumPositions();
protected:
	sf::Vector2f m_position;
	std::vector<Node> m_nodes;
	std::vector<int> m_positions;
	float m_columnWidth = 0;
	std::vector<sf::VertexArray> m_lines;
	sf::Vector2f m_size;
};

#endif //!NODEHANDLER
