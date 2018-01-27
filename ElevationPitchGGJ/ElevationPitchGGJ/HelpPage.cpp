#include "HelpPage.h"
#include "Game.h"


HelpPage::HelpPage()
{
	init(m_font);
}

HelpPage::~HelpPage()
{
}

//initialise the message
void HelpPage::init(sf::Font & font)
{
	m_font = font;
	m_helpInstruction.setFont(font);
	m_helpInstruction.setString("help. go back using backspace");
	m_helpInstruction.setFillColor(sf::Color::Red);
	m_helpInstruction.setCharacterSize(35);
	m_helpInstruction.setPosition(Game::screenWidth / 2, Game::screenHeight / 2);
	m_exitKeyPressed = false;
}
//draw the message
void HelpPage::render(sf::RenderWindow &window)
{
	window.draw(m_helpInstruction);
}
//update the screen.
//check if escape key is pressed -> change to controller
void HelpPage::update(sf::Time &time)
{
	if (m_exitKeyPressed)
	{
		Game::currentGameState = GameState::MainMenu;
	}
	m_exitKeyPressed = false;
}
//if pressed go back to main menu-> change to controller
void HelpPage::processInput(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			m_exitKeyPressed = true;
		}
	}
}
