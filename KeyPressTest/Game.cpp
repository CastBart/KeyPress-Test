#include "Game.h"

const sf::Int32 Game::s_MS_PER_UPDATE = 10;

Game::Game()
	: m_window()
{
}


Game::~Game()
{
}

void Game::init()
{
	sf::ContextSettings windowSettings = sf::ContextSettings();
	windowSettings.antialiasingLevel = 4u;
	m_window.create(sf::VideoMode(1600, 900), "Robo-Invasion", sf::Style::Default, windowSettings);
	m_window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;
	sf::Time dt = sf::Time::Zero;
	while (m_window.isOpen())
	{
		dt = clock.restart();
		lag += dt.asMilliseconds();
		processEvents();
		while (lag > s_MS_PER_UPDATE)
		{
			update(static_cast<double>(dt.asMilliseconds()));
			lag -= s_MS_PER_UPDATE;
		}
		update(static_cast<double>(dt.asMilliseconds()));
		render(static_cast<double>(dt.asMilliseconds()));
	}
}

void Game::processEvents()
{
	sf::Event event;
	int hi = 0;
	
	while (m_window.pollEvent(event));
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			std::cout << event.key.code << std::endl;
			break;
		case sf::Event::KeyReleased:
			//std::cout << event.key.code << std:: endl;
			break;
		case sf::Event::MouseButtonPressed:

			break;
		default:
			break;
		}
	}
}

void Game::update(double dt)
{
}

void Game::render(double ms)
{
	m_window.clear();

	m_window.display();
}
