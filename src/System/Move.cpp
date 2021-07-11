#include "System/Move.hpp"

#include "Component/Velocity.hpp"
#include "Component/Position.hpp"

void MoveSystem::Move(entt::registry& reg, float dt)
{
	const auto view = reg.view<Velocity, Position>();

	for(auto& [entity, vel, pos] : view.each())
		pos.p += vel.velocity * dt;
}

void MoveSystem::Warp(entt::registry& reg, const sf::Vector2f& worldSize, const sf::Vector2f& spriteSize)
{
	const auto view = reg.view<Position>();

	for(auto& [entity, pos] : view.each())
	{
		if(pos.p.x > worldSize.x)
			pos.p.x = -spriteSize.x;
		else if(pos.p.x + spriteSize.x < 0.0f)
			pos.p.x = worldSize.x;
	}
}
