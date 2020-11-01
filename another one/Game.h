#pragma once
#include "GameState.h"

class Game
{
private:
	// variable //
	sf::RenderWindow *window;
	sf::Event sfEvent;

	// deltatime //
	sf::Clock dtClock;
	float dt; 

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	// initialization //
	void initWindow();
	void initStates();
	void initKeys();




public:
	Game();
	virtual ~Game();

	// function //
	
	// Regular //
	void endApplication();

	// Update //
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render //
	void render();

	// Core //
	void run();
};

