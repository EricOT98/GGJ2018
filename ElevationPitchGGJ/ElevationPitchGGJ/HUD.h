#ifndef HUD
#define HUD
#include <SFML/Graphics.hpp>
#include <iostream>
class Hud
{
public:
	Hud();
	~Hud();
	float time(sf::Time t_time); // checks time played and converts total time to seconds and minutes
private:
	float m_miliseconds = 0.f;	// holds time in miliseconds
	int m_seconds = 0.f;		// holds time in seconds 
	int m_minutes = 0.f;		// holds time in minutes
	std::string m_milisecondString = "";
	std::string m_secondString = "";
	std::string m_minuteString = "";

};

#endif // !HUD

