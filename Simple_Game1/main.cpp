#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Player.h"


void error(std::string s1, std::string s2 = "")
{
	throw std::runtime_error(s1 + s2);
}


int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Untitled game", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	sf::Event event;

	sf::View game_view(window.getDefaultView());
	window.setView(game_view);

	Player p("Sprites\\basePlayer.png");
	p.setPos(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	float delta_time = 0;

	while (window.isOpen()) {
		sf::Clock clock;
		while (window.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
				break;
			case sf::Event::KeyReleased:

				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			p.addMoveDir(Player::DIR::UP);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			p.addMoveDir(Player::DIR::DOWN);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			p.addMoveDir(Player::DIR::LEFT);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			p.addMoveDir(Player::DIR::RIGHT);
		}




		std::cout << p.getSpeed() << " || " << p.getMoveDir().x << ", " << p.getMoveDir().y << " --> ";
		p.updatePos(delta_time);
		std::cout << p.displacement.x << ", " << p.displacement.y << std::endl;
		p.rotateTo(sf::Mouse::getPosition(window));

		


		game_view.setCenter(p.getPos());
		//window.setView(game_view);



		window.clear();


		window.draw(p.drawable());


		window.display();

		delta_time = clock.getElapsedTime().asSeconds();
	}

}