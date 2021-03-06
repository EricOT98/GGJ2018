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
	if (!m_buffer.loadFromFile("ASSETS\\AUDIO\\menu.wav"))
	{
	}
	m_menuSound.setBuffer(m_buffer);
	m_controlScheme.setFont(font);
	m_controlScheme.setString("Press RT to speed up \n LT to slow Down, \n Leftstick moves player,\n A to start \n backspace to go back ");
	m_controlScheme.setPosition(0, 0);
	m_controlScheme.setFillColor(sf::Color::Red);
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
	window.draw(m_controlScheme);
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
		m_menuSound.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}
