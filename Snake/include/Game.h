#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Grid.h"
#include "Fruit.h"
#include <iostream>

#define WIDTH 490
#define HEIGHT 520

class Game
{
public:
	Game(const std::string &title);
	~Game();

	void run();

public:
	static sf::RenderWindow &getWindow() { return *window_; }
	
private:
	void update(float &dt);
	void pollEvents(sf::Event &e);
	void handleInput();
	void draw();
	void display();
	void clear();

	void initText();
	void updateText();

	void createGameObjects();
	void updateGameLogic();
	void spawnFruit();
	void checkBoundsCollision();
	void checkFruitCollision();

private:
	static sf::RenderWindow *window_;

	sf::Clock clock;
	float dt;


private:
	Snake *snake_;
	Grid *grid_;
	Fruit *fruit_;

	int score_;
	bool gameover_;

	sf::Text scoreText_;
	sf::Font scoreFont_;
};