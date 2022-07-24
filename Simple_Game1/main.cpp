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

	sf::Event event;



	Player p("Sprites\\basePlayer.png");
	p.setPos({ window.getSize().x / 2, window.getSize().y / 2 });


	while (window.isOpen()) {

		while (window.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
				if (event.key.code == sf::Keyboard::Key::W) {
					/////////////////
				}

				break;
			}
		}



		window.clear();


		window.draw(p.drawable());


		window.display();

	}

}