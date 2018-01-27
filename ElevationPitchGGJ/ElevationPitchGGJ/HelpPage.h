#ifndef HELPPAGE
#define HELPPAGE
#include <SFML\Graphics.hpp>

class Game;
class HelpPage
{
public:
	//default constructor
	HelpPage();
	//destructor
	~HelpPage();
	//initialise message
	void init(sf::Font&);
	//render message
	void render(sf::RenderWindow&);
	//update
	void update(sf::Time&);
	//process player input
	void processInput(sf::Event&);
private:
	sf::Font m_font;
	sf::Text m_helpInstruction;
	//bool to 
	bool m_exitKeyPressed;
};
#endif // !HELPPAGE

