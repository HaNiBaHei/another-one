#include "Game.h"

// Initializer Fuctions //
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "game");
	this->window->setFramerateLimit(144);
	
}

void Game::initStates()
{
	this->states.push(new Gamestate(this->window));
}

void Game::initKeys()
{
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

	std::cout << this->supportedKeys.at("A") << "\n";
}

// Constructors //
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// function //
void Game::endApplication()
{
	std::cout << "Ending" << "\n";
}

void Game::updateDt()
{
	// Update and render in 1 frame //
	this->dt = this->dtClock.getElapsedTime().asSeconds();

	system("cls");
	std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
		while (this->window->pollEvent(sfEvent))
		{
			if (this->sfEvent.type == sf::Event::Closed)
				this->window->close();
		}

}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	// App End //
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();
	
	// render items //
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{


		this->updateDt();
		this->update();
		this->render();


	}
}
