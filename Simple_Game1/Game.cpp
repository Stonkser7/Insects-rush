#include "Game.h"


Game::Game()
{
	window_.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
}

void Game::run()
{
	InputHandler inputHandler;
	Player player;

	sf::Clock frame_timer;
	float lag = 0.0;
	float elapsed = 0.0;
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

		inputHandler.handleInput(player);
		player.lookAt(sf::Mouse::getPosition(window_));

		while (lag >= MS_PER_UPDATE) {
			player.update();
			lag -= MS_PER_UPDATE;
		}


		window_.clear();

		window_.draw(player.sprite());

		window_.display();


		elapsed = frame_timer.getElapsedTime().asMilliseconds() - current;
		lag += elapsed;
	}
}
