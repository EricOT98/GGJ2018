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
	sf::Vector2f getNodePosition();
	float m_speed = 1;
	void spawn(sf::Vector2f pos, sf::Vector2f size, sf::Color col, float speed);

	bool getAlive();
	void setAlive(bool alive);
	bool withinBounds(sf::Vector2f pos, sf::Vector2f size);
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
protected:
	sf::Vector2f m_position;
	sf::RectangleShape m_rect;

	bool m_alive;
};

#endif //!NODE_H
