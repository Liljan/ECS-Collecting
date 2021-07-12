#pragma once

#include "Util/DataTypes.hpp"

#include "SFML/Window.hpp"

#include <unordered_map>

class InputManager
{
public:

	void Update(const sf::Window& window);

	bool AddButton(uint id, sf::Keyboard::Key rawInput);
	bool RemoveButton(uint id);

private:
	bool HasButton(uint id) const;

private:

	std::unordered_map<uint, sf::Keyboard::Key> m_ButtonActions;

};
