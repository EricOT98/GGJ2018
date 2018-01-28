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
	sf::Vector2f getNodeSize();
	void populate(int numNodes);
	bool spawnNode(sf::Vector2f pos, sf::Vector2f size, sf::Color col, int column);
	void randomGeneration( sf::Vector2f size);
	bool collision(sf::Vector2f & p_pos, sf::Vector2f & p_size, Node & node);
	std::vector<Node> m_nodes;

	void setSpeed(float speed);
	int getNumPositions();
	std::vector<int> m_positions;
protected:
	sf::Vector2f m_position;
	std::vector<int> m_positions;
	std::vector<Node> m_nodes;
	
	float m_columnWidth = 0;
	std::vector<sf::VertexArray> m_lines;
	sf::Vector2f m_size;
};

#endif //!NODEHANDLER
