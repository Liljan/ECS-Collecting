#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>

#include "Util/DataTypes.hpp"

// Forward decl.

namespace sf
{
	class Transform;
}

class SpriteBatch : public sf::Drawable
{
public:
	SpriteBatch() = default;

	void Reserve(uint QuadCapacity);
	void Clear();

	void Add(const sf::Transform& transform, const sf::IntRect& texCoords);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	std::vector<sf::Vertex> m_Vertices;
};
