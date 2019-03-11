#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"
#include <deque>

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
	Snake();
	~Snake();

	void draw(sf::RenderTarget &target);
	void update(float &dt);

	void reset();
	void setDir(dir direction);

	void eatFruit();
	void moveSegments();

public:
	sf::FloatRect getBounds()const { return head_.getGlobalBounds(); }
	sf::Vector2i getGridPosOfSnake();


private:
	sf::RectangleShape head_;
	std::deque<sf::RectangleShape> segments_;

	sf::Vector2f lastPosition_;
	dir direction_;

	float speed_;
	int snakeSize_;
};