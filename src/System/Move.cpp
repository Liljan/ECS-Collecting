#include "System/Move.hpp"

#include "Component/Velocity.hpp"
#include "Component/Position.hpp"

void MoveSystem::Move(entt::registry& reg, float dt)
{
	const auto view = reg.view<Velocity, Position>();

	for(auto& [entity, vel, pos] : view.each())
		pos.p += vel.veocity * dt;
}
