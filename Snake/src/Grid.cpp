#include "../include/Grid.h"

int Grid::width_;
int Grid::height_;
int Grid::gridSize_;
std::vector<sf::RectangleShape> Grid::grid_;

Grid::Grid(int width, int height, int gridSize)
{
	this->width_ = width;
	this->height_ = height;
	this->gridSize_ = gridSize;
	this->grid_.resize(width * height);

	for (std::size_t x = 1; x < width; x++)
	{
		for (std::size_t y = 1; y < height; y++)
		{
			int index = getGridIndex(x, y);
			grid_[index] = sf::RectangleShape(sf::Vector2f(gridSize, gridSize));
			grid_[index].setPosition(sf::Vector2f(x * gridSize, y * gridSize));
			grid_[index].setFillColor(sf::Color::Transparent);
			grid_[index].setOutlineThickness(1.0f);
			grid_[index].setOutlineColor(sf::Color::Green);
		}
	}
}

Grid::~Grid()
{

}

void Grid::draw(sf::RenderTarget & target)
{
	for (std::size_t i = 0; i < grid_.size(); i++)
		target.draw(grid_[i]);
}

int Grid::getGridIndex(int x, int y)
{
	return (y * width_) + x;
}

sf::RectangleShape &Grid::gridAt(int index)
{
	return grid_[index];
}
