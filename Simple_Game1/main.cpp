#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.h"


void error(std::string s1, std::string s2 = "")
{
	throw std::runtime_error(s1 + s2);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Untitled", sf::Style::Default);

	Game IR(&window);

	while (window.isOpen()) {
		switch (IR.getState()) {
		case GAMESTATE::MENU:
			IR.menu();
			break;

		case GAMESTATE::EXIT:
			window.close();
			break;
		}


	}



	//IR.run(/*level*/);




	


	//float delta_time = 0;

	////game loop
	//while (window.isOpen()) {
	//	sf::Clock clock;
	//	while (window.pollEvent(event)) {

	//		switch (event.type) {
	//		case sf::Event::Closed:
	//			window.close();
	//			break;
	//		case sf::Event::KeyPressed:
	//			if (event.key.code == sf::Keyboard::Key::Escape)
	//				window.close();
	//			break;
	//		}
	//	}

	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
	//		p.addMoveDir(Player::DIR::UP);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
	//		p.addMoveDir(Player::DIR::DOWN);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
	//		p.addMoveDir(Player::DIR::LEFT);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
	//		p.addMoveDir(Player::DIR::RIGHT);
	//	}





	//	p.updatePos(delta_time);
	//	p.rotateTo(sf::Mouse::getPosition(window));

	//	




	//	window.clear();

	//	window.draw(p.drawable());

	//	window.display();

	//	delta_time = clock.getElapsedTime().asSeconds();
	//}

}