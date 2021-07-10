#pragma once

#include "Graphics/SpriteBatch.hpp"

void SpriteBatch::Reserve(uint quadCapacity)
{
	m_Vertices.reserve(4 * quadCapacity);
}

void SpriteBatch::Clear()
{
	m_Vertices.clear();
}

void SpriteBatch::Add(const sf::Transform& transform, const sf::IntRect& texCoords)
{
	sf::Vertex v0, v1, v2, v3;

	const float wHalf = 0.5f * texCoords.width;
	const float hHalf = 0.5f * texCoords.height;

	v0.position = transform * sf::Vector2f(-wHalf, -hHalf);
	v1.position = transform * sf::Vector2f(-wHalf, hHalf);
	v2.position = transform * sf::Vector2f(wHalf, hHalf);
	v3.position = transform * sf::Vector2f(wHalf, -hHalf);

	v0.texCoords = sf::Vector2f(texCoords.left, texCoords.top);
	v1.texCoords = sf::Vector2f(texCoords.left, texCoords.top + texCoords.height);
	v2.texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top + texCoords.height);
	v3.texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top);

	m_Vertices.push_back(v0);
	m_Vertices.push_back(v1);
	m_Vertices.push_back(v2);
	m_Vertices.push_back(v3);
}

void SpriteBatch::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Vertices.data(), m_Vertices.size(), sf::PrimitiveType::Quads, states);
}
