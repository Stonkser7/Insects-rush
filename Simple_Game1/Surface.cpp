#include "Surface.h"


//FOR TESTS////////

////////////////////

void Surface::init(sf::Vector2f sectors_size)
{
	t_.loadFromFile("Sprites\\test\\surface2.jpg");

	sector_size_ = new sf::Vector2f(sectors_size);


	sf::RectangleShape* first_sector = new sf::RectangleShape;
	first_sector->setSize(*sector_size_);
	first_sector->setTexture(&t_);
	first_sector->setFillColor(sf::Color(54, 98, 135));
	sectors_.push_back(first_sector);

	///////////////////////////// ������ ����, �������, ��� ������ ��¨�. ������ ��� ��� �������, ��� ���� �����???? -_-

	//15.08.22// �� ���� �������... ��� ������ ��� � ���� ;_; ...�� ���� ������-������, � ���� ���. ������� � ����� ��� ����� ���� �����, ��� �����.
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

void Surface::render(sf::RenderWindow& win)
{
	for (auto x : sectors_) {
		win.draw(*x);
	}

}

bool Surface::isEmptyHere(sf::Vector2f Where)
{
	for (auto x : sectors_) {
		if (x->getGlobalBounds().contains(Where)) {
			return false;
		}
	}
	return true;
}

void Surface::addSector(sf::Vector2f here)
{
	int factor_x = here.x / sector_size_->x;
	if (std::fmodf(here.x, sector_size_->x) < 0) --factor_x;

	int factor_y = here.y / sector_size_->y;
	if (std::fmodf(here.y, sector_size_->y) < 0) --factor_y;

	sf::RectangleShape* new_sector = new sf::RectangleShape(*sector_size_);
	new_sector->setPosition(factor_x * sector_size_->x, factor_y * sector_size_->y);
	new_sector->setTexture(&t_);
	new_sector->setFillColor(sf::Color(54, 98, 135));
	sectors_.push_back(new_sector);
}