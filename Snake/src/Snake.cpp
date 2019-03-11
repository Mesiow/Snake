#include "../include/Snake.h"
#include "../include/Game.h"

Snake::Snake(Grid &grid)
{
	this->snakeSize_ = grid.getGridSize();
	head_.setFillColor(sf::Color::White);
	head_.setSize(sf::Vector2f(snakeSize_, snakeSize_));

	int randPosX = Random::randomIntInRange(0, grid.getWidth() - 1);
	int randPosY = Random::randomIntInRange(0, grid.getHeight() - 1);
	head_.setPosition(sf::Vector2f(randPosX * grid.getGridSize(),
		randPosY * grid.getGridSize()));  //place snake within the grid bounds

	/*dir_.x = 0;
	dir_.y = 0;*/

	speed_ = 40.0f;
	direction_ = NONE;
}


Snake::~Snake()
{

}

void Snake::draw(sf::RenderTarget & target)
{
	target.draw(head_);

	for (int i = 0; i < SEGMENTS_SIZE; ++i)
	{
		
	}

}

void Snake::update(float &dt)
{
    lastPosition_.x = head_.getPosition().x / Grid::getGridSize();
	lastPosition_.y = head_.getPosition().y / Grid::getGridSize();

	int gridPosX=head_.getPosition().x / Grid::getGridSize();
	int gridPosY=head_.getPosition().y / Grid::getGridSize(); //get grid position of snake

	////head_.setPosition(lastPosition_.x, lastPosition_.y)
	//if (direction_ == dir::UP)
	//	head_.move(0, -1);
	//else if (direction_ == dir::LEFT)
	//	head_.move(-1, 0);
	//else if (direction_ == dir::DOWN)
	//	head_.move(0, 1);
	//else if (direction_ == dir::RIGHT)
	//	head_.move(1, 0);

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


}

void Snake::setDir(dir direction)
{
	direction_ = direction;
}
