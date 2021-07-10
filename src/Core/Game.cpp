#include "Core/Game.hpp"

#include "Core/Factory.hpp"

// Remove later...?
#include <Core/Constants.hpp>

#include "Component/Position.hpp"
#include "Component/Sprite.hpp"

#include "Prefabs/Player.hpp"
#include "Prefabs/Bush.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

// Temp
#include <cassert>

Game::Game()
{
	m_Window.create(sf::VideoMode(GameConstants::Game::Width, GameConstants::Game::Height), "ECS - Collecting", sf::Style::Default);
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

void Game::LoadAssets()
{
	const std::string path = "../../assets/img/";
	const std::string fileName = "Objects.png";

	bool didLoad = m_ObjectTexture.loadFromFile(path + fileName);
	assert(didLoad);
}

void Game::Init()
{
	LoadAssets();

	Factory::MakePlayer(m_Entities);

	for(int i = 0; i < 10; ++i)
		Factory::MakeBush(m_Entities);

	// Move this to a system

	auto view = m_Entities.view<Bush, Position>();
	for(const entt::entity entity : view)
	{
		auto& pos = view.get<Position>(entity).pos;

		pos.x = rand() % GameConstants::Game::Width;
		pos.y = rand() % GameConstants::Game::Height;
	}
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

	// Refactor into a system
	auto view = m_Entities.view<Position, Sprite>();

	for(const entt::entity entity : view)
	{
		const auto& pos = view.get<Position>(entity).pos;
		const auto id = view.get<Sprite>(entity).id;

		const int x = id % 15;
		const int y = id / 15;
		constexpr int w = 16;
		constexpr int h = 16;

		sf::Sprite sprite;
		sprite.setTexture(m_ObjectTexture);
		sprite.setTextureRect(sf::IntRect(x * w, y * h, w, h));
		sprite.setPosition(pos);

		m_Window.draw(sprite);
	}

	m_Window.display();
}
