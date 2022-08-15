#include "Surface.h"


//FOR TESTS////////

/// ////////////////

Surface::Surface(const std::string& texture_file, sf::Vector2f sectors_size)
{
	t_.loadFromFile(texture_file);

	sector_size_ = new sf::Vector2f(sectors_size);


	sf::RectangleShape* first_sector = new sf::RectangleShape;
	first_sector->setSize(*sector_size_);
	first_sector->setTexture(&t_);
	first_sector->setFillColor(sf::Color(70, 130, 180));
	sectors_.push_back(first_sector);

	///////////////////////////// ÁÎÐÄÅÐ ÁÎÊÑ, ÁÅÄÍßÃÀ, ÁÅÇ ÏÀÌßÒÈ ÆÈÂ¨Ò. ÏÐÎÑòî ÄÀÉ ÅÌÓ ÁÈÒÈÊÎÂ, èëè òåáå æàëêî???? -_-

	//15.08.22// òû ÷åãî íàäåëàë... åãî òåïåðü íåò ñ íàìè ;_; ...îí óø¸ë äàëåêî-äàëåêî, â èíîé ìèð. Íàäåþñü â ñòåêå åìó áóäåò êóäà ëó÷øå, ÷åì çäåñü.

}

Surface::~Surface()
{

	for (auto x : sectors_) {
		delete x;
	}

	delete sector_size_;

}

void Surface::update(const sf::View& view)
{

	sf::Vector2f top_left = { view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 };
	sf::Vector2f top_right = { view.getCenter().x + view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 };
	sf::Vector2f bottom_left = { view.getCenter().x - view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 };
	sf::Vector2f bottom_right = { view.getCenter().x + view.getSize().x / 2, view.getCenter().y + view.getSize().y / 2 };


	if (isEmptyHere(top_left)) {
		addSector(top_left);
	}
	

	if (isEmptyHere(top_right)) {
		addSector(top_right);
	}


	if (isEmptyHere(bottom_left)) {
		addSector(bottom_left);
	}


	if (isEmptyHere(bottom_right)) {
		addSector(bottom_right);
	}
}

void Surface::render(sf::RenderWindow* window)
{
	for (auto x : sectors_) {
		window->draw(*x);
	}

}

bool Surface::isEmptyHere(sf::Vector2f here)
{
	for (auto x : sectors_) {
		if (x->getGlobalBounds().contains(here)) {
			return false;
		}
	}
	return true;
}

void Surface::addSector(sf::Vector2f Where)
{
	int factor_x = Where.x / sector_size_->x;
	if (std::fmodf(Where.x, sector_size_->x) < 0) --factor_x;

	int factor_y = Where.y / sector_size_->y;
	if (std::fmodf(Where.y, sector_size_->y) < 0) --factor_y;

	sf::RectangleShape* new_sector = new sf::RectangleShape(*sector_size_);
	new_sector->setPosition(factor_x * sector_size_->x, factor_y * sector_size_->y);
	new_sector->setTexture(&t_);
	new_sector->setFillColor(sf::Color(70, 130, 180));
	sectors_.push_back(new_sector);
}