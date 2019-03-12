#include "../include/Game.h"

sf::RenderWindow *Game::window_ = nullptr;

Game::Game(const std::string &title)
{
	this->dt = 0.0f;
	window_ = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default);
	window_->setFramerateLimit(15);

	createGameObjects();
}

Game::~Game()
{
	delete this->grid_;
	delete this->snake_;
	delete this->window_;
}

void Game::run()
{
	sf::Event e;
	while (window_->isOpen())
	{
		dt = clock.restart().asSeconds();
		pollEvents(e);

		update(dt);
		handleInput();

		clear();

		draw();

		display();
	}
}

void Game::update(float &dt)
{
	snake_->update(dt);

	updateGameLogic();
}

void Game::pollEvents(sf::Event &e)
{
	while (window_->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window_->close();
		}
	}
}


void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		snake_->setDir(dir::UP);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		snake_->setDir(dir::LEFT);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		snake_->setDir(dir::DOWN);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		snake_->setDir(dir::RIGHT);
}

void Game::draw()
{
	grid_->draw(*window_);
	snake_->draw(*window_);
	fruit_->draw(*window_);
}

void Game::display()
{
	window_->display();
}

void Game::clear()
{
	window_->clear();
}

void Game::createGameObjects()
{
	grid_ = new Grid();
	snake_ = new Snake();
	fruit_ = new Fruit(grid_->getWidth(), grid_->getHeight());
}

void Game::updateGameLogic()
{
	snake_->checkIfBadMove();
	snake_->checkIfBitingItself();
	checkBoundsCollision();
	checkFruitCollision();
}

void Game::spawnFruit()
{
	fruit_->spawn();
}

void Game::checkBoundsCollision()
{
	if (snake_->getGridPosOfSnake().x > grid_->getWidth()) //right bounds
		snake_->reset();
	else if (snake_->getGridPosOfSnake().x < 0)
		snake_->reset();
	else if (snake_->getGridPosOfSnake().y > grid_->getHeight())
		snake_->reset();
	else if (snake_->getGridPosOfSnake().y < 0)
		snake_->reset();
}

void Game::checkFruitCollision()
{
	if (snake_->getBounds().intersects(fruit_->getBounds()))
	{
		snake_->eatFruit();
		spawnFruit();
	}
}
