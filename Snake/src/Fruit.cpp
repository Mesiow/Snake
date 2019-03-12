#include "../include/Fruit.h"
#include "../include/Grid.h"

Fruit::Fruit(int x, int y)
{
	fruit_.setSize(sf::Vector2f(Grid::getGridSize(), Grid::getGridSize()));
	fruit_.setFillColor(sf::Color::Red);
	spawn();
}

Fruit::~Fruit()
{

}

void Fruit::draw(sf::RenderTarget & target)
{
	target.draw(fruit_);
}

void Fruit::spawn()
{
	int posX = Random::randomIntInRange(1, Grid::getWidth() - 1);
	int posY = Random::randomIntInRange(1, Grid::getHeight() - 1);

	fruit_.setPosition(posX * Grid::getGridSize(), posY * Grid::getGridSize());
}
