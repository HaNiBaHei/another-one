#pragma once
#include "Entity.h"

#include<vector>

class State
{
private:


protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;


public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	
	// function //
	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

