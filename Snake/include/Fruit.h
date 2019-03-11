#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"

class Grid;
class Fruit
{
public:
	Fruit(int x, int y);
	~Fruit();

	void draw(sf::RenderTarget &target);

private:
	sf::RectangleShape fruit_;
	sf::Vector2f position_;
};