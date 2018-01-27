#include "Game.h"
#include <iostream>


//ASPR of 16:9
Game::Game() :
	m_window{ sf::VideoMode{ 1280, 720, 32 }, "SFML Game" },
	m_exitGame{false},//when true game will exit
	m_portal(sf::Vector2f(400,200), 100, "test")
{
	m_respawnTime = 1;
	m_nodeHandler.populate(30);
	m_nodeHandler.init(sf::Vector2f(200, 0), sf::Vector2f(m_window.getSize()), 4);
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
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	m_spawnTimer += t_deltaTime.asSeconds();
	std::cout << "Timer: " << m_spawnTimer << std::endl;
	if (m_exitGame)
	{
		m_window.close();
	}
	if (m_spawnTimer >= m_respawnTime)
	{
		m_spawnTimer = 0;
		m_nodeHandler.randomGeneration(sf::Vector2f(56, 100));
	}
	m_portal.update(t_deltaTime.asSeconds());
	m_nodeHandler.update();
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_welcomeMessage);
	m_window.draw(m_logoSprite);
	m_window.draw(m_timer);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);
	m_timer.setFont(m_ArialBlackfont);
	m_timer.setStyle(sf::Text::Bold);
	m_timer.setPosition(100.f, 100.f);
	m_timer.setCharacterSize(60);
	m_timer.setFillColor(sf::Color::Yellow);
	m_timer.setOutlineColor(sf::Color::Black);
	m_timer.setOutlineThickness(5.f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}
	m_portal.render(m_window);
	m_nodeHandler.render(m_window);
	
	m_window.display();
}
