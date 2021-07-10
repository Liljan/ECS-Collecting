#pragma once

// Todo: Fwd
#include <EnTT/entt.hpp>
#include "Graphics/SpriteBatch.hpp"

class RenderSystem
{
public:

	static void RenderPlayers(entt::registry& reg, SpriteBatch& batch);
	static void RenderBushes(entt::registry& reg, SpriteBatch& batch);
};
