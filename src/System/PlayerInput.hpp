#pragma once

#include <EnTT/entt.hpp>

#include "Core/InputManager.hpp"

class PlayerInputSystem
{
public:

	static void SetupInput(entt::registry& reg, InputManager& inputManager);

	static void HandleInput(entt::registry& reg, InputManager& inputManager);
};
