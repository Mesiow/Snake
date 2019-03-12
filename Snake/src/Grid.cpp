#include "../include/Grid.h"

int Grid::width_ = WIDTH;
int Grid::height_ = HEIGHT;
int Grid::gridSize_ = GRID_TILE_SIZE;
std::vector<sf::RectangleShape> Grid::grid_;

Grid::Grid()
{
	this->grid_.resize(WIDTH * HEIGHT);

	for (std::size_t x = 1; x < width_; x++)
	{
		for (std::size_t y = 1; y < height_; y++)
		{
			int index = getGridIndex(x, y);
			grid_[index] = sf::RectangleShape(sf::Vector2f(gridSize_, gridSize_));
			grid_[index].setPosition(sf::Vector2f(x * gridSize_, y * gridSize_));
			grid_[index].setFillColor(sf::Color::Transparent);
			grid_[index].setOutlineThickness(1.0f);
			grid_[index].setOutlineColor(sf::Color::Green);
		}
	}

	boundsOutline_.setSize(sf::Vector2f(WIDTH * GRID_TILE_SIZE, HEIGHT * GRID_TILE_SIZE));
	boundsOutline_.setPosition(sf::Vector2f(6, 12));
	boundsOutline_.setFillColor(sf::Color::Transparent);
	boundsOutline_.setOutlineThickness(1.0f);
	boundsOutline_.setOutlineColor(sf::Color::Green);
}

Grid::~Grid()
{

}

void Grid::draw(sf::RenderTarget & target)
{
	target.draw(boundsOutline_);
	/*for (std::size_t i = 0; i < grid_.size(); i++)
		target.draw(grid_[i]);*/
}

int Grid::getGridIndex(int x, int y)
{
	return (y * width_) + x;
}

sf::RectangleShape &Grid::gridAt(int index)
{
	return grid_[index];
}