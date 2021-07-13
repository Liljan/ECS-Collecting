#include "Core/Game.hpp"

#include "Core/Factory.hpp"

// Remove later...?
#include <Core/Constants.hpp>

// Components
#include "Component/PlayerInputConfig.hpp"

// Prefabs
#include "Prefabs/Player.hpp"
#include "Prefabs/Bush.hpp"

// Systems
#include "System/Move.hpp"
#include "System/Render.hpp"
#include "System/PlayerInput.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

// Temp
#include <cassert>

Game::Game()
{
	m_Window.create(sf::VideoMode(Constants::Game::Width, Constants::Game::Height), "ECS - Collecting", sf::Style::Default);
	m_Window.setFramerateLimit(60);
	m_Window.setVerticalSyncEnabled(true);

	m_SpriteBatch.Reserve(Constants::Game::SpriteBatchSize);
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

	Factory::MakePlayer(m_Entities, Constants::Player::startPos, Constants::Player::speed);

	for(int i = 0; i < 10; ++i)
		Factory::MakeBush(m_Entities, 
			sf::Vector2f(rand() % Constants::Game::Width, rand() % Constants::Game::Height));

	// Temp player input definitions
	{
		const auto view = m_Entities.view<PlayerInputConfig>();

		for(auto& [entity, input] : view.each())
		{
			input.left = sf::Keyboard::A;
			input.right = sf::Keyboard::D;
			input.up = sf::Keyboard::W;
			input.down = sf::Keyboard::S;
			input.action = sf::Keyboard::Space;
		}			
	}

	PlayerInputSystem::SetupInput(m_Entities, m_Input);
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

	m_Input.Update();

	PlayerInputSystem::HandleInput(m_Entities, m_Input);
}

void Game::Update(const float dt)
{
	MoveSystem::Move(m_Entities, dt);
	MoveSystem::Warp(m_Entities, sf::Vector2f(Constants::Game::Width, Constants::Game::Height), sf::Vector2f(16.0f, 16.0f));
}

void Game::Render()
{
	m_Window.clear(sf::Color(100, 100, 100));

	RenderSystem::RenderBushes(m_Entities, m_SpriteBatch);
	RenderSystem::RenderPlayers(m_Entities, m_SpriteBatch);

	sf::RenderStates state(&m_ObjectTexture);
	m_SpriteBatch.draw(m_Window, state);

	m_Window.display();

	// Post-frame clean-up
	m_SpriteBatch.Clear();
}
