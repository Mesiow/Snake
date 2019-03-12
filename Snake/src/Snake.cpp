#include "../include/Snake.h"
#include "../include/Game.h"
#include <iostream>

Snake::Snake()
{
	this->snakeSize_ = Grid::getGridSize();
	this->nmberOfSegments_ = 0;
	head_.setFillColor(sf::Color::White);
	head_.setSize(sf::Vector2f(snakeSize_, snakeSize_));

	segments_.push_front(head_);
	direction_ = NONE;
	reset();
}


Snake::~Snake()
{

}

void Snake::draw(sf::RenderTarget & target)
{
	for (int i = 0; i < segments_.size(); ++i)
	{
		target.draw(segments_[i]);
	}
}

void Snake::update(float &dt)
{
 
	int gridPosX=segments_[HEAD].getPosition().x / Grid::getGridSize();
	int gridPosY=segments_[HEAD].getPosition().y / Grid::getGridSize(); //get grid position of snake

	if (direction_ == dir::UP)
		segments_[HEAD].setPosition(gridPosX * Grid::getGridSize(), gridPosY * 
			Grid::getGridSize() - Grid::getGridSize());
	else if (direction_ == dir::LEFT)
		segments_[HEAD].setPosition(gridPosX * Grid::getGridSize() - Grid::getGridSize(),
			gridPosY * Grid::getGridSize());
	else if (direction_ == dir::DOWN)
		segments_[HEAD].setPosition(gridPosX * Grid::getGridSize(),
			gridPosY * Grid::getGridSize() + Grid::getGridSize());
	else if (direction_ == dir::RIGHT)
		segments_[HEAD].setPosition(gridPosX * Grid::getGridSize() + Grid::getGridSize(),
			gridPosY * Grid::getGridSize());

	moveSegments();
}

void Snake::reset()
{
	int randPosX = Random::randomIntInRange(1, Grid::getWidth() - 1);
	int randPosY = Random::randomIntInRange(1, Grid::getHeight() - 1);
	segments_[HEAD].setPosition(sf::Vector2f(randPosX * Grid::getGridSize(),
		randPosY * Grid::getGridSize()));  //place snake within the grid bounds
}

void Snake::setDir(dir direction)
{
	direction_ = direction;
}

void Snake::eatFruit()
{
    int gridPosX = segments_[HEAD].getPosition().x / Grid::getGridSize();
	int gridPosY = segments_[HEAD].getPosition().y / Grid::getGridSize(); //get grid position of snake

	sf::RectangleShape newSeg(sf::Vector2f(snakeSize_, snakeSize_));
	newSeg.setFillColor(sf::Color::White);

	segments_.push_back(newSeg); //add new segment
}

void Snake::moveSegments()
{
	auto prevPos = getGridPosOfSnake();

	for (std::size_t i = 0; i < segments_.size(); i++)
	{
		auto tempX = segments_[i].getPosition().x / Grid::getGridSize();
		auto tempY = segments_[i].getPosition().y / Grid::getGridSize();

		segments_[i].setPosition(sf::Vector2f(prevPos.x * Grid::getGridSize(),
				prevPos.y * Grid::getGridSize()));

		prevPos.x = tempX;
		prevPos.y = tempY;
	}
}

sf::Vector2i Snake::getGridPosOfSnake()
{
	int x = segments_[HEAD].getPosition().x / Grid::getGridSize();
	int y = segments_[HEAD].getPosition().y / Grid::getGridSize();

	return sf::Vector2i(x, y);
}
