#ifndef PATHDISPLAY_H
#define PATHDISPLAY_H

#include <SFML\Graphics.hpp>
#include "NodeHandler.h"

class PathDisplay
{
public:
	PathDisplay();
	~PathDisplay();

	void update();
	void render(sf::RenderWindow & window);
	void generatePath(int numNodes);
	void init(sf::Vector2f pos, sf::Vector2f size, int numNodes);

protected:
	NodeHandler m_nodeHandler;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	bool m_active;
};

#endif //!PATHDISPLAY