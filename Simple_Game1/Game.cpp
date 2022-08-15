#include "Game.h"

//FOR TESTS
#include <iostream>
#include <iomanip>
////////////


Game::Game()
{
	window_.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
}

void Game::run()
{
	Player player;

	Camera cam(2.5, window_.getDefaultView());

	Surface surface("Sprites\\test\\surface2.jpg", { 1920, 1080 });

	sf::Clock frame_timer;
	float lag = 0.0;
	while (window_.isOpen()) {
		float current = frame_timer.getElapsedTime().asMilliseconds();

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
		player.handleInput();
		sf::Vector2i cursor = static_cast<sf::Vector2i>((cam().getCenter() - window_.getDefaultView().getCenter())) + sf::Mouse::getPosition(window_);
		player.lookAt(cursor);


		//UPDATE
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while (lag >= MS_PER_UPDATE) {
			player.update();
			lag -= MS_PER_UPDATE;
		}

		cam.follow(player.sprite().getPosition());

		surface.update(cam());

		//RENDER
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		window_.setView(cam());

		window_.clear();


		surface.render(&window_);
		window_.draw(player.sprite());
		window_.display();

		//std::cout << player.sprite().getPosition().x << " " << player.sprite().getPosition().y << std::endl;
		//std::cout << std::setprecision(2) << std::fixed << " --- " << std::endl;



		lag += frame_timer.getElapsedTime().asMilliseconds() - current;
	}
}
