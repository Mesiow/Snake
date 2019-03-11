#include "../include/Fruit.h"
#include "../include/Grid.h"

Fruit::Fruit(int x, int y)
{
	fruit_.setSize(sf::Vector2f(Grid::getGridSize(), Grid::getGridSize()));

	int randPosX = Random::randomIntInRange(0, x);
	int randPosY = Random::randomIntInRange(0, y);

	this->position_ = sf::Vector2f(randPosX * Grid::getGridSize(),
		randPosY * Grid::getGridSize());

	fruit_.setPosition(position_);  //place snake within the grid bounds
	fruit_.setFillColor(sf::Color::Red);
}

Fruit::~Fruit()
{

}

void Fruit::draw(sf::RenderTarget & target)
{
	target.draw(fruit_);
}
