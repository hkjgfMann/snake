#include <iostream>
#include "Snake.h"

void Snake::grow()
{
	Coordinate newPart{ snakeparts[0].x, snakeparts[0].y };
	std::vector<Coordinate> grownSnake(snakeparts.size() + 1);
	grownSnake[0] = newPart;

	for (int i = 0; i < snakeparts.size(); i++) {
		grownSnake[i + 1] = snakeparts[i];
	}

	snakeparts = grownSnake;

}

void Snake::move(Direction direction)
{
	updateSnakeparts();
	switch (direction) {
	case Direction::UP:
		snakeparts[0].y--;
		break;
	case Direction::DOWN:
		snakeparts[0].y++;
		break;
	case Direction::LEFT:
		snakeparts[0].x--;
		break;
	case Direction::RIGHT:
		snakeparts[0].x++;
		break;
	default:
		break;
	}
}

//Alle Teile der Schlange um eine Position nach hinten verschieben
void Snake::updateSnakeparts() {
	for (int i = (snakeparts.size() - 1); i > 0; i--) {
		snakeparts[i] = snakeparts[i - 1];
	}
}

//Schlange löschen und den Schlangenkopf auf x, y setzen
void Snake::reset(int x, int y) {
	snakeparts.clear();
	snakeparts.push_back({ x, y });
}

Coordinate Snake::head() {
	return snakeparts[0];
}

//NICHT VERWENDET: Move und grow in einem
void Snake::move(Direction direction, bool ateFood)
{
	switch (direction) {
	case Direction::UP:
		snakeparts[0].y--;
		break;
	case Direction::DOWN:
		snakeparts[0].y++;
		break;
	case Direction::LEFT:
		snakeparts[0].x--;
		break;
	case Direction::RIGHT:
		snakeparts[0].x++;
		break;
	default:
		break;
	}

	Coordinate newPart{ snakeparts[0].x, snakeparts[0].y };
	std::vector<Coordinate> grownSnake(snakeparts.size() + 1);
	grownSnake[0] = newPart;

	for (int i = 0; i < snakeparts.size(); i++) {
		grownSnake[i + 1] = snakeparts[i];
	}

	if (ateFood) {
		grownSnake.pop_back();
	}

	snakeparts = grownSnake;
}

//Prüft, ob [x,y] ein Teil der Schlange ist (kein Kopf)
bool Snake::isBody(Coordinate part) {
	for (int i = 1; i < snakeparts.size(); i++) {
		if (snakeparts[i].x == part.x && snakeparts[i].y == part.y) {
			return true;
		}
	}
	return false;
}