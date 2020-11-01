#pragma once
#include "State.h"
class Gamestate :
	public State
{
private:
	Entity player;

public:
	Gamestate(sf::RenderWindow* window);
	virtual ~Gamestate();

	// function //
	void endState();


	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

