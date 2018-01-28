#include "Game.h"
#include <iostream>


GameState Game::currentGameState = GameState::MainMenu;
float Game::screenWidth = 1280;
float Game::screenHeight = 720;


Game::Game() :
	m_window{ sf::VideoMode{ static_cast<unsigned>(Game::screenWidth), static_cast<unsigned>(Game::screenHeight), 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_portal(sf::Vector2f(400,200), 100, "test"),
	player(400,400, 40,40)
{
	int gap = 20;
	m_respawnTime = 1;
	m_nodeHandler.populate(30);
	m_nodeHandler.init(sf::Vector2f(0, 0), sf::Vector2f((m_window.getSize().x - gap), m_window.getSize().y), 4);
	m_pathDisplay.init(sf::Vector2f((m_window.getSize().x / 2) + (gap * 2), 0), sf::Vector2f((m_window.getSize().x / 2) - (gap * 2) , m_window.getSize().y), 4);
	m_pathDisplay.generatePath(4);
	//Game:Elevation Pitch

	setupFont(); // load font
	setUpScreens(); // load screens

}


Game::~Game()
{

}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
			m_timerChanger = m_hud.time(timePerFrame);
			m_timer.setString(m_timerChanger);
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			//go back to main menu-> change to controller
			if (sf::Keyboard::BackSpace == event.key.code)
			{
				Game::currentGameState = GameState::MainMenu;
			}
		}
		switch (currentGameState)
		{
		case GameState::MainMenu:
		{
			break;
		}

		case GameState::HelpPage:
		{
			m_helpPage.processInput(event);
			break;
		}
		default:
			break;
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{

	if (m_exitGame)
	{
		m_window.close();
	}

	switch (currentGameState)
	{
	case GameState::MainMenu:
	{
		m_mainMenu.update(m_window);
		break;
	}
	case GameState::HelpPage:
	{
		m_helpPage.update(t_deltaTime);
	}
	default:
	m_spawnTimer += t_deltaTime.asSeconds();
	player.Update(t_deltaTime.asSeconds());
	std::cout << "Timer: " << m_spawnTimer << std::endl;
	if (m_spawnTimer >= m_respawnTime)
	{
		m_spawnTimer = 0;
		m_nodeHandler.randomGeneration(sf::Vector2f(56, 100));
	}
	m_portal.update(t_deltaTime.asSeconds());
	m_nodeHandler.update();
	m_pathDisplay.update();
		break;
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);


	switch (currentGameState)
	{
	case GameState::MainMenu:
	{
		m_mainMenu.render(m_window);
		break;
	}
	case GameState::HelpPage:
	{
		m_helpPage.render(m_window);
		break;
	}
	default:
		m_nodeHandler.render(m_window);
		m_pathDisplay.render(m_window);
		m_window.draw(m_timer);
		//m_portal.render(m_window);
		player.Draw(m_window);
		break;
	}

//	m_window.draw(m_welcomeMessage);
//	m_window.draw(m_logoSprite);
	m_window.display();


}

/// <summary>
/// load the font
/// </summary>
void Game::setupFont()
{
	if (!m_ArialBlackFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_timer.setFont(m_ArialBlackFont);
	m_timer.setStyle(sf::Text::Bold);
	m_timer.setPosition(100.f, 100.f);
	m_timer.setCharacterSize(60);
	m_timer.setFillColor(sf::Color::Yellow);
	m_timer.setOutlineColor(sf::Color::Black);
	m_timer.setOutlineThickness(5.f);

}

/// <summary>
/// initialization of the screens
/// </summary>
void Game::setUpScreens()
{
	m_mainMenu.init(m_ArialBlackFont);
	m_helpPage.init(m_ArialBlackFont);
}
