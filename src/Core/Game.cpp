#include "Core/Game.hpp"

#include <SFML/Window/Event.hpp>

Game::Game()
{
	m_Window.create(sf::VideoMode(1920, 1080), "ECS - Collecting", sf::Style::Default);
	m_Window.setFramerateLimit(60);
	m_Window.setVerticalSyncEnabled(true);
}

void Game::Run()
{
	Init();

	sf::Clock timer;

	while(m_Window.isOpen())
	{
		const float dt = timer.getElapsedTime().asSeconds();
		timer.restart();

		HandleInput();
		Update(dt);
		Render();
	}

}

void Game::Init()
{
}

void Game::HandleInput()
{
	sf::Event event;

	while(m_Window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_Window.close();
			return;
		}

		if(event.type == sf::Event::KeyReleased)
		{
			switch(event.key.code)
			{
				case sf::Keyboard::Escape:
					m_Window.close();
					break;
				default:
					break;
			}
		}
	}
}

void Game::Update(const float dt)
{
}

void Game::Render()
{
	m_Window.clear(sf::Color(100, 100, 100));

	// Draw here

	m_Window.display();
}
