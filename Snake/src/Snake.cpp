#include "../include/Snake.h"
#include "../include/Game.h"

Snake::Snake(Grid &grid)
{
	this->snakeSize_ = grid.getGridSize();
	head_.setFillColor(sf::Color::White);
	head_.setSize(sf::Vector2f(snakeSize_, snakeSize_));

	int randPosX = Random::randomIntInRange(0, grid.getWidth());
	int randPosY = Random::randomIntInRange(0, grid.getHeight());
	head_.setPosition(sf::Vector2f(randPosX * grid.getGridSize(),
		randPosY * grid.getGridSize()));  //place snake within the grid bounds

	dir_.x = 0;
	dir_.y = 0;

	speed_ = 100.0f;
}


Snake::~Snake()
{

}

void Snake::draw(sf::RenderTarget & target)
{
	target.draw(head_);

	for (int i = 0; i < SEGMENTS_SIZE; ++i)
	{
		target.draw(tail_[i]);
	}

}

void Snake::update(float &dt)
{
	head_.move(dir_.x, dir_.y);
}

void Snake::setDir(int xDir, int yDir)
{
	dir_.x = xDir;
	dir_.y = yDir;
}
