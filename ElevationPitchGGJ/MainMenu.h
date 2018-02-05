#ifndef MAINMENU
#define MAINMENU
#include <SFML\Graphics.hpp>
#include "XB0XCONTROLLER.h"
#include<SFML\Audio.hpp>

class Game;
class MainMenu
{
public:
	//default constructor
	MainMenu();
	//destructor
	~MainMenu();
	//initialise
	void init(sf::Font&);
	//render window
	void render(sf::RenderWindow&);
	//update window
	void update(sf::Window&);

	sf::SoundBuffer m_buffer;
	sf::Sound m_menuSound;
private:
	//font used
	sf::Font m_font;
	//count of amount of menu boxes in the menu
	static const int m_optionCount=3;
	//texts array for all menu boxes
	sf::Text m_buttonText[m_optionCount];
	sf::Text m_controlScheme;
	XboxController m_xbox;
	
};
#endif // !MAINMENU

