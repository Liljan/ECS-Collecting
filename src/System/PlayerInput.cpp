#include "System/PlayerInput.hpp"

#include "Input/InputTypes.hpp"

#include "Prefabs/Player.hpp"

#include "Component/PlayerInputConfig.hpp"
#include "Component/Velocity.hpp"

void PlayerInputSystem::SetupInput(entt::registry& reg, InputManager& inputManager)
{
	const auto view = reg.view<PlayerInputConfig>();

	for(auto& [entity, config] : view.each())
	{
		inputManager.AddButton(static_cast<uint>(PlayerInputActions::left), config.left);
		inputManager.AddButton(static_cast<uint>(PlayerInputActions::right), config.right);
		inputManager.AddButton(static_cast<uint>(PlayerInputActions::up), config.up);
		inputManager.AddButton(static_cast<uint>(PlayerInputActions::down), config.down);
		inputManager.AddButton(static_cast<uint>(PlayerInputActions::action), config.action);
	}
}

void PlayerInputSystem::HandleInput(entt::registry& reg, InputManager& inputManager)
{
	const auto view = reg.view<Player, Velocity>();

	for(const entt::entity e : view)
	{
		auto& vel = view.get<Velocity>(e);

		// Handle directions
		if (inputManager.IsButtonDown(static_cast<uint>(PlayerInputActions::left)))
			vel.velocity.x = -vel.speed;
		else if (inputManager.IsButtonDown(static_cast<uint>(PlayerInputActions::right)))
			vel.velocity.x = vel.speed;
		else
			vel.velocity.x = 0.0f;
	}
}
