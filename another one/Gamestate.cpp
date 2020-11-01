#include "Gamestate.h"

Gamestate::Gamestate(sf::RenderWindow* window)
	:State(window)
{

}

Gamestate::~Gamestate()
{

}

void Gamestate::endState()
{
	std::cout << "Ending" << "\n";
}

void Gamestate::updateInput(const float& dt)
{
	this->checkForQuit();

	// update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player.move(dt, 0.f, 1.f);
}

void Gamestate::update(const float& dt)
{
	this->updateInput(dt);

	this->player.update(dt);
}

void Gamestate::render(sf::RenderTarget* target )
{
	if (!target)

		target = this->window;
	
	
	
		this->player.render(target);
	
}
