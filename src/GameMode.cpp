#include "GameMode.h"

GameMode::GameMode(sf::RenderWindow& window)
    :State(window, Type_t::bg_manu)//replace Background
{
	selection();

}

void GameMode::selection()
{
	//auto choosen = CharacterSelection(m_window, 2).choose();
	playerData test;

	test.m_commander = CommandType::ArrowUser;
	test.m_fighter = Fighter_f::dennis_f;
	test.playerNum = 0;
	test.team = Team::Team_A;
	playerData test2;
	test2.m_commander = CommandType::WASDUser;
	test2.m_fighter = Fighter_f::firzen_f;
	test2.playerNum = 1;
	test2.team = Team::Team_B;
	std::vector<playerData> chosen;
	chosen.push_back(test);
	chosen.push_back(test2);

	createPlayers(chosen);
	//m_characters.push_back(make_unique<PLayer>(CharactersSelection(m_window)));

	m_background = std::make_unique< SPBackground>();
}

void GameMode::createPlayers(std::vector < playerData > players)
{
	int i = 0;
	for(auto& player: players)
	{
		m_characters.emplace_back(std::make_shared <Fighter>(player, getStartPos(i)));
		
		i++;
	}
}
void GameMode::update()
{
	handleView();

	manageComputerAlgorithm();

	setAction();

	getDynamicAttacks();

	pollEvents();//get action from events

	auto delta = gameClock.restart();

	moveAndAnimation(delta);

	handleCollison();

	m_background->update(delta);

	std::erase_if(m_characters, [](const auto& plasyer) { return plasyer->isDead(); });
	std::erase_if(m_dynamicAttack, [](const auto& attack) { return attack->isDone(); });
}

void GameMode::getDynamicAttacks()
{
	for (auto& player : m_characters)
	{
		auto attack = player->getDynamicAttacks();
		if (attack)
			m_dynamicAttack.push_back(attack);
	}
}
void GameMode::moveAndAnimation(const sf::Time & delta)
{
	for (auto& player1 : m_characters)
	{
		player1->move(delta);
		player1->update(delta);
		
	}
	for (auto& dynamicAttack : m_dynamicAttack)
	{
		dynamicAttack->move(delta);
		dynamicAttack->update(delta);
	}
}

void GameMode::manageComputerAlgorithm()
{
	for (auto& player : m_characters)
	{
		if (player->getPlayerData().m_commander == CommandType::Computer)
		{
			auto target = minimumDistanceFighterTo(player);
			if (target)
				player->setTarget(target);
		}
	}
}

std::shared_ptr <Fighter> GameMode::minimumDistanceFighterTo(const std::shared_ptr <Fighter> fighter)
{
	sf::Vector2f closestPos;
	std::shared_ptr <Fighter> closestFighter;
	float closestDistance = WorldSize;

	for (auto& player : m_characters)
	{
		if (player->getPlayerData().team != fighter->getPlayerData().team && !player->isDelayed())
		{
			float distance = calcDistance(player->getPosition(), fighter->getPosition());
			if (distance < closestDistance)
			{
				closestDistance = distance;
				closestFighter = player;
			}

		}

	}
	return closestFighter;
}


void GameMode::handleCollison()
{
	//check and handle all pairs in characters
	for_each_pair(m_characters.begin(), m_characters.end(), [](auto& a, auto& b) { if (collide(*a, *b))	processCollision(*a, *b); });

	for (auto& attack : m_dynamicAttack)
		for (auto& character : m_characters)
			if (collide(*attack, *character))
				processCollision(*attack, *character);
	//for (auto& attack : m_dynamicAttack)
	//	for (auto& player : m_characters)
	//		processCollision(*attack, *player);
}

void GameMode::setAction()
{
	for (auto& character : m_characters)
		if(!character->isDelayed())
			character->setAction();
}

void GameMode::pollEvents()
{
    for (auto event = sf::Event(); m_window.pollEvent(event); )
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            m_window.close();
            break;
        }
        case sf::Event::MouseButtonReleased:
        {
            auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            handleClick(location);
            break;
        }
        case sf::Event::MouseMoved:
        {
            auto location = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
            handleMove(location);
            break;
        }
           
        case sf::Event::KeyReleased:
        {
            handleKeyReleased(event.key.code);
            break;
        }
        default:        break;
        }
		
    }
}

void GameMode::handleKeyReleased(sf::Keyboard::Key key)
{
	for (auto& player : m_characters)
	{
		if (player->getPlayerData().m_commander != CommandType::Computer)
			player->getActionFromKeyReleased(key);
	}
}


void GameMode::handleView()
{
	auto view = m_window.getView();
	sf::Vector2f pos = {0,0};
	auto Playerfocus = m_characters[0]->getPosition();//player position
	Playerfocus.y = WindowHeight / 2.f;

	/* left border scan */
	if (Playerfocus.x < WindowWidth / 4.f)
		view.setCenter(WindowWidth / 2, Playerfocus.y);
		

	/* right border scan */
	else if (WorldSize - Playerfocus.x < WindowWidth / 4.f)
		view.setCenter(WorldSize - WindowWidth / 2, Playerfocus.y);

	//else if (abs (Playerfocus.x - view.getCenter().x) > WindowWidth / 4)
	//	view.setCenter(Playerfocus.x + WindowWidth / 4, Playerfocus.y);


	//normalize player focus 
	else if (Playerfocus.x < view.getCenter().x - WindowWidth /4 )
		view.setCenter(Playerfocus.x + WindowWidth / 4, Playerfocus.y);

	else if (Playerfocus.x > view.getCenter().x + WindowWidth / 4)
		view.setCenter(Playerfocus.x - WindowWidth / 4, Playerfocus.y);


	m_window.setView(view);


	for (auto& player : m_characters)
		player->setInfoView(view.getCenter().x - WindowWidth / 2.f);
}

void GameMode::draw()
{
	/* draw here */
	m_background->draw(m_window);
	
	//local sort by Y, to print in 3D, no change private member order
	auto it = m_characters;
	std::sort(it.begin(), it.end(), [](const std::shared_ptr<Fighter>& first, const std::shared_ptr<Fighter>& second) { return first->y() < second->y(); });


	for (const auto& character: it)
	{
		character->draw(m_window);
	}

	for (const auto& dynamicAttack : m_dynamicAttack)
		dynamicAttack->draw(m_window);

}



sf::Vector2f GameMode::getStartPos(const int character) const
{
	return sf::Vector2f(firstPos.x + character*100, firstPos.y + character*40);
}

