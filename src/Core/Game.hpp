#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <EnTT/entt.hpp>

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
	entt::registry m_Entities;

	sf::Texture m_ObjectTexture;
};
