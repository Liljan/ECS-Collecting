#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <EnTT/entt.hpp>

#include "Core/InputManager.hpp"
#include "Graphics/SpriteBatch.hpp"

class Game
{
public:
	Game();
	~Game() = default;

	void Run();

private:

	void LoadAssets();
	void Init();

	void HandleInput();
	void Update(const float dt);
	void Render();

private:

	// Systems
	sf::RenderWindow m_Window;
	InputManager m_Input;
	entt::registry m_Entities;

	SpriteBatch m_SpriteBatch;
	sf::Texture m_ObjectTexture;
};
