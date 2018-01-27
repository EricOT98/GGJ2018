#ifndef PORTAL_H
#define PORTAL_H

#include "SFML\Graphics.hpp"

class Portal
{
public:
	Portal();
	Portal(sf::Vector2f position, float radius, std::string filename);
	~Portal();

	void loadPortal();

	void update(float timeInSecs);
	void render(sf::RenderWindow & window);

	sf::Vector2f m_position;
	sf::RectangleShape m_rectShape;
	sf::Shader m_shader;
	bool m_active;
	float totalTime = 0;
	sf::RenderTexture m_renderTexture;
	sf::Texture & m_texture;
	sf::Sprite m_sprite;
protected:

};

#endif //!PORTAL
