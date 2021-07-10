#include "Core/Factory.hpp"

#include "Component/Position.hpp"
#include "Component/Sprite.hpp"

#include "Prefabs/Player.hpp"
#include "Prefabs/Bush.hpp"

#include "Core/Constants.hpp"

entt::entity Factory::MakePlayer(entt::registry& reg, const sf::Vector2f& pos)
{
	const entt::entity entity = reg.create();
	reg.emplace<Player>(entity);

	reg.emplace<Sprite>(entity, Constants::Player::spriteId);
	reg.emplace<Position>(entity, pos);

	return entity;
}

entt::entity Factory::MakeBush(entt::registry& reg, const sf::Vector2f& pos)
{
	const entt::entity entity = reg.create();
	reg.emplace<Bush>(entity);

	reg.emplace<Sprite>(entity, Constants::Bush::spriteId);
	reg.emplace<Position>(entity, pos);

	return entity;
}
