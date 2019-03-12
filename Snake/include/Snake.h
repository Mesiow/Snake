#pragma once
#include <SFML/Graphics.hpp>
#include "Random.h"
#include <deque>

#define SEGMENTS_SIZE 100

class Grid;

enum dir
{
	NONE=-1,
	UP=0,
	DOWN,
	LEFT,
	RIGHT
};

enum part
{
	HEAD=0,
	TAIL,
};

class Snake
{
public:
	struct Segment
	{
		Segment(sf::Vector2f size,sf::Vector2f position=sf::Vector2f(0,0))
			:position(position), size(size)
		{
			seg.setSize(size);
			seg.setPosition(position);
			seg.setFillColor(sf::Color::Green);
		}

		void draw(sf::RenderTarget &target)
		{
			target.draw(seg);
		}

		sf::RectangleShape seg;
		sf::Vector2f position;
		sf::Vector2f size;

	};
	Snake();
	~Snake();

	void draw(sf::RenderTarget &target);
	void update(float &dt);

	void reset();
	void setDir(dir direction);

	void checkIfBitingItself();
	void eatFruit();
	void moveSegments();

public:
	sf::FloatRect getBounds()const { return segments_[HEAD].seg.getGlobalBounds(); }
	sf::Vector2i getGridPosOfSnake();


private:
	std::deque<Segment> segments_;

	sf::Vector2f lastPosition_;
	dir direction_;

	float speed_;
	int snakeSize_;
	int nmberOfSegments_;
};