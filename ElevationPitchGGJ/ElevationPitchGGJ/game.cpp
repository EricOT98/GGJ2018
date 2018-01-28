//Game:Elevation Pitch
#include "Game.h"
#include <iostream>


GameState Game::currentGameState = GameState::MainMenu;
float Game::screenWidth = 1280;
float Game::screenHeight = 720;


Game::Game() :
	m_window{ sf::VideoMode{ static_cast<unsigned>(Game::screenWidth), static_cast<unsigned>(Game::screenHeight), 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_gameOver{false},
	m_portal(sf::Vector2f(400,200), 100, "test"),
	m_player(250,100, 40,40)

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

	m_gameOverText.setFont(m_ArialBlackFont);
	m_gameOverText.setString("gameover");
	m_gameOverText.setPosition(500,500);
	m_gameOverText.setFillColor(sf::Color::Red);
	m_gameOverText.setCharacterSize(35);
	
	
	bar.setFillColor(sf::Color(100, 250, 50));
	bar.setPosition(m_bposition);
	bar.setSize(m_playerSize);

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
			if (!m_gameOver)
			{
				update(timePerFrame); //60 fps

			}
			m_timerChanger = m_hud.time(timePerFrame);
			//m_timer.setString(m_timerChanger);
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
	/*		if (sf::Keyboard::Space == event.key.code && m_gameOver == true)
			{
				m_gameOver = false;
				restartLevel();
			}*/
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


	if (event.key.code >= 0 && event.key.code < sf::Keyboard::Key::KeyCount)
	{
		if (event.type == event.KeyPressed)
		{
			if (!KeyboardHandler::GetInstance()->m_keysUp[event.key.code])
			{
				KeyboardHandler::GetInstance()->m_keysDown[event.key.code] = true;
			}
		}
		else if (event.type == event.KeyReleased)
		{
			KeyboardHandler::GetInstance()->m_keysDown[event.key.code] = false;
			KeyboardHandler::GetInstance()->m_keysUp[event.key.code] = false;
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
		m_hud.resetTimer();
		break;
	}
	case GameState::HelpPage:
	{
		m_helpPage.update(t_deltaTime);
		m_hud.resetTimer();
		break;
	}
	default:
		m_spawnTimer += t_deltaTime.asSeconds();
		m_player.Update(t_deltaTime.asSeconds());
		m_nodeHandler.setSpeed(m_player.m_nodeSpeed);

		//std::cout << "Timer: " << m_spawnTimer << std::endl;
		if (m_spawnTimer >= m_respawnTime)
		{
			m_spawnTimer = 0;
			m_nodeHandler.randomGeneration(sf::Vector2f(56, 100));
		}
		m_portal.update(t_deltaTime.asSeconds());
		m_nodeHandler.update();
		/*m_collided = m_nodeHandler.collision(m_player.getPlayerPosition(), m_player.getPlayerSize());
		if (m_collided)
		{
			std::cout << "collision" << std::endl;
		}
		else
		{
			std::cout << "not colliding" << std::endl;
		}*/
		for (auto & node : m_nodeHandler.m_nodes) {
			if (node.getAlive()) {
				if (m_nodeHandler.collision(m_player.getPlayerPosition(), m_player.m_player.getSize(), node)) {
					m_nodeHandler.m_pingSound.play();
					
					if (node.m_column == m_pathDisplay.getCurrentNode().m_column) {
						m_hud.increaseScore();
						std::cout << "Correct node" << std::endl;
						node.setAlive(false);
						m_pathDisplay.getCurrentNode().setColor(node.getColor());
						if (m_pathDisplay.m_currentNode >= m_pathDisplay.getNumNodes() - 1) {
							std::cout << "Complete" << std::endl;
							m_pathDisplay.m_nodeHandler.setAllAlive(false);
							m_pathDisplay.generatePath(4);
							std::cout << "Complete and your score is " << m_timerChanger << std::endl;
							m_hud.resetTimer();
							m_pathDisplay.m_currentNode = 0;
							for (int i = 0; i < 5; i++) {
								m_hud.increaseScore();
							}
							break;
						}

						m_pathDisplay.m_currentNode += 1;
					}
					else {
						std::cout << "Incorrect: Restarting" << std::endl;
						m_pathDisplay.m_currentNode = 0;
						m_player.loseLife();
						node.setAlive(false);
						m_player.m_lives -= 1;
						std::cout << "Lives: " <<  m_player.getLives()<<std::endl;
						for (auto & node : m_pathDisplay.m_nodeHandler.m_nodes) {
							node.setColor(sf::Color(128, 128, 128, 255));
						}
					}
				}
			}

		}
		break;
	}
	gameOverCheck();
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

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
		m_portal.render(m_window);
		m_player.Draw(m_window);
		m_hud.render(m_window);
		m_window.draw(bar);
		break;

	}
	if (m_gameOver==true)
	{
		m_window.draw(m_gameOverText);
	}
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
	m_timer.setPosition(Game::screenWidth - 500, 50);
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


		m_hud.init(m_ArialBlackFont);


}

void Game::gameOverCheck()
{
	if (m_player.getLives() == 0)
	{
		m_gameOver = true;
	}
}

bool Game::collision()
{
	sf::Vector2f p_pos = m_player.getPlayerPosition();
	sf::Vector2f p_size = m_player.m_player.getSize();
	sf::Vector2f n_pos = m_node.getNodePosition();
	sf::Vector2f n_size = m_nodeHandler.getNodeSize();
	return (p_pos.x + p_size.x < n_pos.x ||
		p_pos.x > n_pos.x + n_size.x ||
		p_pos.y + p_size.y < n_pos.y ||
		p_pos.y > n_pos.y + n_size.y);
}

void Game::restartLevel()
{
	m_player.setLives(3);
	m_hud.setScore(0);
}
