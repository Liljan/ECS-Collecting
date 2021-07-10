#pragma once

// Switch to fwd declarations?
#include <EnTT/entt.hpp>

// fwd
namespace sf
{
	Vector2f;
};

class Factory
{
public:
	static entt::entity MakePlayer(entt::registry& reg, const sf::Vector2f& pos);
	static entt::entity MakeBush(entt::registry& reg, const sf::Vector2f& pos);
};
