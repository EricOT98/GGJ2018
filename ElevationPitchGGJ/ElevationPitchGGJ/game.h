// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "Portal.h"
#include "NodeHandler.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	Hud m_hud;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	std::string m_timerChanger; // passes timer to function to convert to sf::Text
	sf::Text m_timer; // this is the timer in sf::Text
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	Portal m_portal;
	NodeHandler m_nodeHandler;
	
	//TODO: (ERIC) Remove this to work with hud timer
	float m_spawnTimer = 0;
	float m_respawnTime;
};

#endif // !GAME

