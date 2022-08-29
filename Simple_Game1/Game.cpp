#include "Game.h"

//FOR TESTS
#include <iostream>
#include <iomanip>
////////////


Game::Game()
{
	window_.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);

	cam_.init(window_.getDefaultView());

	player_.init();

	surface_.init({ 1920, 1080 });
}

void Game::run()
{
	sf::Clock frame_timer;
	float current = 0.0;
	float lag = 0.0;
	frame_timer.restart();
	while (window_.isOpen()) {
		current = frame_timer.getElapsedTime().asMilliseconds();

		sf::Event event;
		while (window_.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::Closed:
				window_.close();
				break;
			}
		}

		//INPUT HANDLING
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		handleInput();

		//UPDATE
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while (lag >= MS_PER_UPDATE_) {
			update();
			lag -= MS_PER_UPDATE_;
		}

		//RENDER
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		render();

		lag += frame_timer.getElapsedTime().asMilliseconds() - current;

		//std::cout << player.sprite().getPosition().x << " " << player.sprite().getPosition().y << std::endl;
		//std::cout << std::setprecision(2) << std::fixed << cam().getCenter().x - cam().getSize().x / 2 << " --- " << cam().getCenter().y - cam().getSize().y / 2 << std::endl;
	}
}

const float& Game::MS_PER_UPDATE()
{
	return MS_PER_UPDATE_;
}



void Game::handleInput()
{

	player_.handleInput();
	sf::Vector2i cursor = static_cast<sf::Vector2i>((cam_().getCenter() - window_.getDefaultView().getCenter())) + sf::Mouse::getPosition(window_);
	player_.lookAt(cursor);
}


void Game::update()
{
	player_.update();

	cam_.follow(player_.sprite().getPosition());

	surface_.update(cam_());
}


void Game::render()
{
	window_.setView(cam_());

	window_.clear();

	surface_.render(window_);
	player_.render(window_);

	window_.display();
}