#pragma once
#include <SFML/Graphics.hpp>

class Grid : public sf::NonCopyable
{
public:
	Grid(int width, int height, int gridSize);
	~Grid();

	void draw(sf::RenderTarget &target);

	static int getGridSize(){ return gridSize_; }
	static int getWidth() { return width_; }
	static int getHeight() { return height_; }
    static int getGridIndex(int x, int y);

	static sf::RectangleShape &gridAt(int index);

private:
	static std::vector<sf::RectangleShape> grid_;

	static int width_;
	static int height_;
	static int gridSize_;
};