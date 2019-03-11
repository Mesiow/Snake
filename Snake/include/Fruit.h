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
	void spawn();

public:
	sf::FloatRect getBounds()const { return fruit_.getGlobalBounds(); }

private:
	sf::RectangleShape fruit_;
};