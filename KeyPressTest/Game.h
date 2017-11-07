#pragma once
#include "include\SFML\Graphics.hpp"
#include "include\SFML\Window.hpp"
#include <iostream>
class Game
{

public:
	Game();
	~Game();
	void init();
	void run();

private:
	void processEvents();
	void update(double dt);
	void render(double ms);
	
	static const sf::Int32 s_MS_PER_UPDATE;
	sf::RenderWindow m_window;
};
