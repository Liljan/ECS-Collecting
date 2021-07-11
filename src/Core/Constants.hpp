#pragma once

#include <SFML/System/Vector2.hpp>

#include "Util/DataTypes.hpp"

namespace Constants
{
	namespace Game
	{
		constexpr int Width = 1280;
		constexpr int Height = 720;

		constexpr uint SpriteBatchSize = 100;
	}

	namespace Player
	{
		constexpr int spriteId = 17;
		const sf::Vector2f startPos = {150.0f, 200.0f};
		constexpr float speed = -100.0f;
	}

	namespace Bush
	{
		constexpr int spriteId = 3;
	}

};
