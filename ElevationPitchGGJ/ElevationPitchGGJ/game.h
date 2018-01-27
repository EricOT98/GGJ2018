#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "Portal.h"
#include "NodeHandler.h"

#include "MainMenu.h"
#include "HelpPage.h"

enum class GameState
{
	MainMenu,
	PlayGame,
	HelpPage,
	EndGame
};
#include "Player.h"
#include "XB0XCONTROLLER.h"
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	//whats the current state
	static GameState currentGameState;
	//width and height of screen
	static float screenWidth;
	static float screenHeight;

private:
	Hud m_hud;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFont();
	void setUpScreens();
	std::string m_timerChanger; // passes timer to function to convert to sf::Text
	sf::Text m_timer; // this is the timer in sf::Text
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackFont; // font used by message
	bool m_exitGame; // control exiting game
	Portal m_portal;
	NodeHandler m_nodeHandler;

	//TODO: (ERIC) Remove this to work with hud timer
	float m_spawnTimer = 0;
	float m_respawnTime;
	Player player;

	//object for main menu
	MainMenu m_mainMenu;
	//object for help page
	HelpPage m_helpPage;
};

#endif // !GAME
