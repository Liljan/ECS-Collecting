#include "Core/InputManager.hpp"

#include <iostream>

void InputManager::Update()
{
	// Update buttons	
	for(const auto& action : m_ButtonActions)
	{
		const auto id = action.first;
		const auto rawInput = action.second;

		m_ButtonCurrentState[id] = sf::Keyboard::isKeyPressed(rawInput);
	}
}

bool InputManager::AddButton(uint id, sf::Keyboard::Key rawInput)
{
	if(HasButton(id))
	{
		std::cerr << "Trying to add key \"" << id << "\" which has already been added.\n";
		return false;
	}

	m_ButtonActions.emplace(id, rawInput);
	m_ButtonCurrentState.emplace(id, false);
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
	m_ButtonCurrentState.erase(id);

	return true;
}

bool InputManager::HasButton(uint id) const
{
	if(m_ButtonActions.find(id) != m_ButtonActions.end())
		return true;

	return false;
}
