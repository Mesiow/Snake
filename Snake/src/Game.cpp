#include "../include/Game.h"

sf::RenderWindow *Game::window_ = nullptr;

Game::Game(const std::string &title)
{
	this->dt = 0.0f;
	window_ = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default);
	window_->setFramerateLimit(60);

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
		snake_->setDir(0, -1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		snake_->setDir(-1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		snake_->setDir(0, 1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		snake_->setDir(1, 0);
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
	grid_ = new Grid(40, 30, 16);
	snake_ = new Snake(*grid_);
	fruit_ = new Fruit(grid_->getWidth(), grid_->getHeight());
}

void Game::spawnFruit()
{

}
