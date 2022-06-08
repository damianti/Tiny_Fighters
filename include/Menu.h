#pragma once
#include "State.h"
#include "ImageText.h"
#include "Background.h"
#include "Utilities.h"
#include "GameMode.h"

class Menu 
{
public:
	Menu();
	~Menu();

	void pollEvents(sf::RenderWindow& window, const sf::Event& event) ;
	void draw(sf::RenderWindow& window) ;
	void update() {}

private:
	using StateMap = std::vector<ButtonDetails<ImageText, State_t>>;

	const StateMap m_state;	
	std::shared_ptr <Background> m_background;
	std::vector <std::shared_ptr <State>> m_mode;


	//Menu functions
	Menu::StateMap createButton();
	void handleClick(const sf::Vector2f& location, sf::RenderWindow& window);
	void handleClick(State_t StateClicked, sf::RenderWindow& window);
	void handleMove(const sf::Vector2f& location);

};