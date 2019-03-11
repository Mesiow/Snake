#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"

#define SEGMENTS_SIZE 100

class Grid;
class Snake
{
public:
	Snake(Grid &grid);
	~Snake();

	void draw(sf::RenderTarget &target);
	void update(float &dt);

	void setDir(int xDir, int yDir);

private:
	sf::RectangleShape head_;
	sf::RectangleShape tail_[SEGMENTS_SIZE];

	sf::Vector2f position_;
	sf::Vector2f dir_;

	float speed_;
	int snakeSize_;
};