#include "../include/Snake.h"
#include "../include/Game.h"
#include <iostream>

Snake::Snake()
{
	this->snakeSize_ = Grid::getGridSize();
	this->nmberOfSegments_ = 0;

	segments_.push_front(Segment(sf::Vector2f(snakeSize_, snakeSize_))); //Push head
	direction_ = NONE;
	reset();
}


Snake::~Snake()
{

}

void Snake::draw(sf::RenderTarget & target)
{
	for (int i = 0; i < segments_.size(); ++i)
		segments_[i].draw(target);
}

void Snake::update(float &dt)
{
 
	int gridPosX=segments_[HEAD].seg.getPosition().x / Grid::getGridSize();
	int gridPosY=segments_[HEAD].seg.getPosition().y / Grid::getGridSize(); //get grid position of snake

	if (direction_ == dir::UP)
	{
		prevDir_ = UP;
		segments_[HEAD].seg.setPosition(gridPosX * Grid::getGridSize(), gridPosY *
			Grid::getGridSize() - Grid::getGridSize());
	}
	else if (direction_ == dir::LEFT)
	{
		prevDir_ = LEFT;
		segments_[HEAD].seg.setPosition(gridPosX * Grid::getGridSize() - Grid::getGridSize(),
			gridPosY * Grid::getGridSize());
	}
	else if (direction_ == dir::DOWN)
	{
		prevDir_ = DOWN;
		segments_[HEAD].seg.setPosition(gridPosX * Grid::getGridSize(),
			gridPosY * Grid::getGridSize() + Grid::getGridSize());
	}
	else if (direction_ == dir::RIGHT)
	{
		prevDir_ = RIGHT;
		segments_[HEAD].seg.setPosition(gridPosX * Grid::getGridSize() + Grid::getGridSize(),
			gridPosY * Grid::getGridSize());
	}

	moveSegments();
}

void Snake::reset()
{
	segments_.erase(segments_.begin() + 1, segments_.end());
	nmberOfSegments_ = 0;

	int randPosX = Random::randomIntInRange(1, Grid::getWidth() - 1);
	int randPosY = Random::randomIntInRange(1, Grid::getHeight() - 1);
	segments_[HEAD].seg.setPosition(sf::Vector2f(randPosX * Grid::getGridSize(),
		randPosY * Grid::getGridSize()));  //place snake within the grid bounds
}

void Snake::setDir(dir direction)
{
	direction_ = direction;
}


void Snake::checkIfBadMove(int &score)
{
	if (nmberOfSegments_ > 0)
	{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				if (direction_ == DOWN)
				{
					score = 0;
					reset();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (direction_ == RIGHT)
				{
					score = 0;
					reset();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				if (direction_ == UP)
				{
					score = 0;
					reset();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (direction_ == LEFT)
				{
					score = 0;
					reset();
				}
			}
	}
}

void Snake::checkIfBitingItself(int &score)
{
	for (std::size_t i = 2; i < segments_.size(); i++) //start at 2 so we dont check the head and first seg
	{
		int segPosX = segments_[i].seg.getPosition().x / Grid::getGridSize();
		int segPosY = segments_[i].seg.getPosition().y / Grid::getGridSize();

		if (getGridPosOfSnake().x * Grid::getGridSize() == segPosX * Grid::getGridSize() &&
			getGridPosOfSnake().y * Grid::getGridSize() == segPosY * Grid::getGridSize()) //collided with ourself
		{
			score = 0;
			reset();
		}
	}
}

void Snake::eatFruit()
{
	auto position = getGridPosOfSnake();

	if (nmberOfSegments_ == 0)
	{
		//add tail
		for(int i=0; i<2; i++)
			segments_.push_back(Segment(sf::Vector2f(snakeSize_, snakeSize_),
			sf::Vector2f(position.x * Grid::getGridSize(), position.y * Grid::getGridSize())));
	}
	else
	{
		segments_.push_back(Segment(sf::Vector2f(snakeSize_, snakeSize_),
			sf::Vector2f(position.x * Grid::getGridSize(), position.y * Grid::getGridSize()))); //add new segment
	}

	nmberOfSegments_++;
}

void Snake::moveSegments()
{
	auto prevPos = getGridPosOfSnake();

	for (std::size_t i = 1; i < segments_.size(); i++)
	{
		int tempX = segments_[i].seg.getPosition().x / Grid::getGridSize();
		int tempY = segments_[i].seg.getPosition().y / Grid::getGridSize();

		segments_[i].seg.setPosition(sf::Vector2f(prevPos.x * Grid::getGridSize(),
				prevPos.y * Grid::getGridSize()));

		prevPos.x = tempX;
		prevPos.y = tempY;
	}
}

sf::Vector2i Snake::getGridPosOfSnake()
{
	int x = segments_[HEAD].seg.getPosition().x / Grid::getGridSize();    //multiply by grid size later to place segments in correct pos
	int y = segments_[HEAD].seg.getPosition().y / Grid::getGridSize();

	return sf::Vector2i(x, y);
}
