#ifndef NODE_H
#define NODE_H

#include <SFML\Graphics.hpp>

class Node
{
public:
	Node();
	~Node();

	void update();
	void render(sf::RenderWindow & window);

	void spawn(sf::Vector2f pos, sf::Vector2f size, sf::Color col, float speed, int column);

	bool getAlive();
	void setAlive(bool alive);
	bool withinBounds(sf::Vector2f pos, sf::Vector2f size);
	int m_column;
protected:
	sf::Vector2f m_position;
	sf::RectangleShape m_rect;
	float m_speed = 1;
	bool m_alive;
};

#endif //!NODE_H
