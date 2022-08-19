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

	surface_.init("Sprites\\test\\surface2.jpg", { 1920, 1080 });

	commands_.push_back(new MoveUpCommand(sf::Keyboard::Key::W));
	commands_.push_back(new MoveDownCommand(sf::Keyboard::Key::S));
	commands_.push_back(new MoveLeftCommand(sf::Keyboard::Key::A));
	commands_.push_back(new MoveRightCommand(sf::Keyboard::Key::D));

	current = 0.0;
	lag = 0.0;
}

void Game::run()
{
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
		while (lag >= MS_PER_UPDATE) {
			update();
			lag -= MS_PER_UPDATE;
		}

		//RENDER
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		render();

		//std::cout << player.sprite().getPosition().x << " " << player.sprite().getPosition().y << std::endl;
		//std::cout << std::setprecision(2) << std::fixed << cam().getCenter().x - cam().getSize().x / 2 << " --- " << cam().getCenter().y - cam().getSize().y / 2 << std::endl;
	}

	for (auto x : commands_) {
		delete x;
	}
}



void Game::handleInput()
{
	for (auto x : commands_) {
		if (sf::Keyboard::isKeyPressed(x->getKey())) {
			x->execute(player_);
		}
	}

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

	lag += frame_timer.getElapsedTime().asMilliseconds() - current;
}