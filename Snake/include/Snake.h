#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"

#define SEGMENTS_SIZE 100

class Grid;

enum dir
{
	NONE=-1,
	UP=0,
	DOWN,
	LEFT,
	RIGHT
};

class Snake
{
public:
	Snake(Grid &grid);
	~Snake();

	void draw(sf::RenderTarget &target);
	void update(float &dt);

	void setDir(dir direction);

public:
	sf::FloatRect getBounds()const { return head_.getGlobalBounds(); }

private:
	sf::RectangleShape head_;
	std::vector<sf::RectangleShape> segments_;

	sf::Vector2f lastPosition_;
	dir direction_;

	float speed_;
	int snakeSize_;


};