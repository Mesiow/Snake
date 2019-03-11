#include "../include/Snake.h"
#include "../include/Game.h"
#include <iostream>

Snake::Snake()
{
	this->snakeSize_ = Grid::getGridSize();
	head_.setFillColor(sf::Color::White);
	head_.setSize(sf::Vector2f(snakeSize_, snakeSize_));

	reset();
	direction_ = NONE;
}


Snake::~Snake()
{

}

void Snake::draw(sf::RenderTarget & target)
{
	target.draw(head_);

	for (int i = 0; i < segments_.size(); ++i)
	{
		target.draw(segments_[i]);
	}

}

void Snake::update(float &dt)
{
    lastPosition_.x = head_.getPosition().x / Grid::getGridSize();
	lastPosition_.y = head_.getPosition().y / Grid::getGridSize();

	int gridPosX=head_.getPosition().x / Grid::getGridSize();
	int gridPosY=head_.getPosition().y / Grid::getGridSize(); //get grid position of snake

	if (direction_ == dir::UP)
		head_.setPosition(gridPosX * Grid::getGridSize(), gridPosY * 
			Grid::getGridSize() - Grid::getGridSize());
	else if (direction_ == dir::LEFT)
		head_.setPosition(gridPosX * Grid::getGridSize() - Grid::getGridSize(),
			gridPosY * Grid::getGridSize());
	else if (direction_ == dir::DOWN)
		head_.setPosition(gridPosX * Grid::getGridSize(),
			gridPosY * Grid::getGridSize() + Grid::getGridSize());
	else if (direction_ == dir::RIGHT)
		head_.setPosition(gridPosX * Grid::getGridSize() + Grid::getGridSize(),
			gridPosY * Grid::getGridSize());

	moveSegments();
}

void Snake::reset()
{
	int randPosX = Random::randomIntInRange(1, Grid::getWidth() - 1);
	int randPosY = Random::randomIntInRange(1, Grid::getHeight() - 1);
	head_.setPosition(sf::Vector2f(randPosX * Grid::getGridSize(),
		randPosY * Grid::getGridSize()));  //place snake within the grid bounds
}

void Snake::setDir(dir direction)
{
	direction_ = direction;
}

void Snake::eatFruit()
{
	sf::RectangleShape newSeg(sf::Vector2f(snakeSize_, snakeSize_));
	newSeg.setFillColor(sf::Color::White);
	segments_.push_back(newSeg);
}

void Snake::moveSegments()
{
	for (std::size_t i = 1; i < segments_.size() + 1; i++)
	{
		segments_[i].setPosition(sf::Vector2f(lastPosition_.x * Grid::getGridSize(),
			lastPosition_.y * Grid::getGridSize()));

		sf::Vector2f lastSegPos = segments_[i].getPosition();
		int segPosX = lastSegPos.x / Grid::getGridSize() * Grid::getGridSize();
		int segPosY = lastSegPos.y / Grid::getGridSize() * Grid::getGridSize();
		segments_[i - 1].setPosition(segPosX, segPosY);
	}
}

sf::Vector2i Snake::getGridPosOfSnake()
{
	int x = head_.getPosition().x / Grid::getGridSize();
	int y = head_.getPosition().y / Grid::getGridSize();

	return sf::Vector2i(x, y);
}
