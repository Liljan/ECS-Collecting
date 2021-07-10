#include "Core/Factory.hpp"

#include "Component/Position.hpp"
#include "Component/Sprite.hpp"

#include "Prefabs/Player.hpp"
#include "Prefabs/Bush.hpp"

#include "Core/Constants.hpp"

entt::entity Factory::MakePlayer(entt::registry& reg)
{
	const entt::entity entity = reg.create();
	reg.emplace<Player>(entity);
	reg.emplace<Sprite>(entity, GameConstants::Player::spriteId);
	reg.emplace<Position>(entity, GameConstants::Player::startPos);

	return entity;
}

entt::entity Factory::MakeBush(entt::registry& reg)
{
	const entt::entity entity = reg.create();
	reg.emplace<Bush>(entity);
	reg.emplace<Sprite>(entity, GameConstants::Bush::spriteId);
	reg.emplace<Position>(entity);

	return entity;
}
