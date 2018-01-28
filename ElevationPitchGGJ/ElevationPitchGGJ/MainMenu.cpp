#include "MainMenu.h"
#include "Game.h"
MainMenu::MainMenu()
{
	init(m_font);
}

MainMenu::~MainMenu()
{
}
//initialise the texts
void MainMenu::init(sf::Font & font)
{
	
	sf::String m_menuTexts[] = { "Quit","Help Page","Play Game"};
	m_font = font;
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonText[i].setFont(m_font);
		m_buttonText[i].setString(m_menuTexts[i]);
		m_buttonText[i].setFillColor(sf::Color::Red);
		m_buttonText[i].setCharacterSize(34);
		m_buttonText[i].setPosition(Game::screenWidth /2,Game::screenHeight-(100*(i+1)));
	}
}
//draw the texts on screen
void MainMenu::render(sf::RenderWindow & window)
{
	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonText[i]);
	}
}

//go from 1 state to another-> change to controller
void MainMenu::update(sf::Window & window)
{

	m_xbox.update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || m_xbox.m_currentState.X)
	{
		Game::currentGameState = GameState::HelpPage;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) || m_xbox.m_currentState.A)
	{
		Game::currentGameState = GameState::PlayGame;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}
