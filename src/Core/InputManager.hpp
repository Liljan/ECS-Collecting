#pragma once

#include "Util/DataTypes.hpp"

#include "SFML/Window/Keyboard.hpp"

#include <unordered_map>

class InputManager
{
public:

	void Update();

	bool AddButton(uint id, sf::Keyboard::Key rawInput);
	bool RemoveButton(uint id);

private:
	bool HasButton(uint id) const;

private:

	std::unordered_map<uint, sf::Keyboard::Key> m_ButtonActions;
	std::unordered_map<uint, bool> m_ButtonCurrentState;
	//std::unordered_map<uint, bool> m_ButtonPreviousState;
};
