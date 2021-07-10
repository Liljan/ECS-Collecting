#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public:
	Game();
	~Game() = default;

	void Run();

private:

	void Init();

	void HandleInput();
	void Update(const float dt);
	void Render();

private:

	// Systems
	sf::RenderWindow m_Window;
};
