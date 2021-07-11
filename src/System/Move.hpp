#pragma once

// Todo: Fwd
#include <EnTT/entt.hpp>

#include <SFML/System/Vector2.hpp>

class MoveSystem
{
public:

	static void Move(entt::registry& reg, float dt);
	static void Warp(entt::registry& reg, const sf::Vector2f& worldSize, const sf::Vector2f& spriteSize);
};