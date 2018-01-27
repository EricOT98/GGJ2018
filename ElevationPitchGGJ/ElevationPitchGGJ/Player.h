#ifndef PLAYER
#define PLAYER


#include "XB0XCONTROLLER.h"
#include "Node.h"

class Player
{
public:
	Player();
	Player(float x, float y, float const SCALE, bool set);
	~Player();
	sf::Vector2f getPlayerPosition();
	sf::Vector2f getPlayerSize();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
//	float colour =
	int getLives();
private:

	sf::RectangleShape m_player;
	sf::Vector2f m_playerSize = { 100,100 };
	XboxController m_xbox;

	float speed = 50;
	float increase = 10;
	sf::Vector2f m_position = sf::Vector2f(200,400);
	int m_lives;

};

#endif
