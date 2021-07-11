#pragma once

// Todo: Fwd
#include <EnTT/entt.hpp>

class MoveSystem
{
public:

	static void Move(entt::registry& reg, float dt);
};