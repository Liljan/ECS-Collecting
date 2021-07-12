#include "Core/InputManager.hpp"

#include <iostream>

void InputManager::Update(const sf::Window& window)
{
}

bool InputManager::AddButton(uint id, sf::Keyboard::Key rawInput)
{
	if(HasButton(id))
	{
		std::cerr << "Trying to add key \"" << id << "\" which has already been added.\n";
		return false;
	}

	m_ButtonActions.emplace(std::make_pair(id, rawInput));
	return true;
}

bool InputManager::RemoveButton(uint id)
{
	if(!HasButton(id))
	{
		std::cerr << "Trying to remove key \"" << id << "\" which has not been added.\n";
		return false;
	}

	m_ButtonActions.erase(id);

	return true;
}

bool InputManager::HasButton(uint id) const
{
	if(m_ButtonActions.find(id) == m_ButtonActions.end())
		return true;

	return false;
}
