#include "Game.h"

//FOR TESTS
#include <iostream>
#include <iomanip>
////////////


Game::Game() :MS_PER_UPDATE_(16)
{
	window_.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);

	Assets::getAssets().init();

	cam_.init(window_.getDefaultView());

	player_.init();

	surface_.init({ 1920, 1080 });

	fossilsManager.randSpawn(player_.getPos(), 500);
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
		///////////////////////////////////////////
		handleInput();

		//UPDATE
		///////////////////////////////////////////
		while (lag >= MS_PER_UPDATE_) {
			update();
			lag -= MS_PER_UPDATE_;
		}

		//RENDER
		///////////////////////////////////////////
		render();

		lag += frame_timer.getElapsedTime().asMilliseconds() - current;

		//std::cout << player.sprite().getPosition().x << " " << player.sprite().getPosition().y << std::endl;
		//std::cout << std::setprecision(2) << std::fixed << cam().getCenter().x - cam().getSize().x / 2 << " --- " << cam().getCenter().y - cam().getSize().y / 2 << std::endl;
	}
}




void Game::handleInput()
{

	player_.handleInput();
	sf::Vector2i cursor = static_cast<sf::Vector2i>((cam_().getCenter() - window_.getDefaultView().getCenter())) + sf::Mouse::getPosition(window_);
	player_.lookAt(cursor);



	//TEST
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
		fossilsManager.randSpawn(player_.getPos(), 500);
	}*/
}


void Game::update()
{
	player_.update(MS_PER_UPDATE_);

	cam_.follow(player_.getPos());

	surface_.update(cam_());
}


void Game::render()
{
	window_.setView(cam_());

	window_.clear();

	surface_.render(window_);
	fossilsManager.renderFossils(window_);
	player_.render(window_);

	window_.display();
}