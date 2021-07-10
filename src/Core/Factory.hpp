#pragma once

// Switch to fwd declarations?
#include <EnTT/entt.hpp>

class Factory
{
public:
	static entt::entity MakePlayer(entt::registry& reg);
	static entt::entity MakeBush(entt::registry& reg);
};
