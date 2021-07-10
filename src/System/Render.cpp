#include "System/Render.hpp"

#include "Prefabs/Player.hpp"
#include "Prefabs/Bush.hpp"

#include "Component/Position.hpp"
#include "Component/Sprite.hpp"

void RenderSystem::RenderPlayers(entt::registry& reg, SpriteBatch& batch)
{
	const auto view = reg.view<Player, Position, Sprite>();

	for(const entt::entity entity : view)
	{
		const auto& pos = view.get<Position>(entity).pos;
		const auto id = view.get<Sprite>(entity).id;

		const int x = id % 15;
		const int y = id / 15;
		constexpr int w = 16;
		constexpr int h = 16;

		sf::Transform t;
		t.translate(pos);

		batch.Add(t, sf::IntRect(x * w, y * h, w, h));
	}
}

void RenderSystem::RenderBushes(entt::registry& reg, SpriteBatch& batch)
{
	const auto view = reg.view<Bush, Position, Sprite>();

	for (const entt::entity entity : view)
	{
		const auto& pos = view.get<Position>(entity).pos;
		const auto id = view.get<Sprite>(entity).id;

		const int x = id % 15;
		const int y = id / 15;
		constexpr int w = 16;
		constexpr int h = 16;

		sf::Transform t;
		t.translate(pos);

		batch.Add(t, sf::IntRect(x * w, y * h, w, h));
	}
}
