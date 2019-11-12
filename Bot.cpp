#include "Bot.h"
#include <iostream>
#include "ConsoleInterface.h"

Bot::Bot()
{
	active = false;
	dir = Direction::NONE;
	prevDir = dir;
}

//Aktiviert oder deaktiviert den Bot
void Bot::toggle() {
	active = !active;
}

void Bot::searchPath()
{
	findFood();
	checkSnake();
	checkWall();
}

//Ändert die Richtung der Schlange in Abhängikeit der Essensposition auf dem Spielfeld
void Bot::findFood() {
	if (board.getFood().y > snake.head().y) {
		dir = Direction::DOWN;
		//std::cout << "Bot bewegt Schlange runter\n";
	}
	else if (board.getFood().y < snake.head().y) {
		dir = Direction::UP;
		//	std::cout << "Bot bewegt Schlange hoch\n";
	}
	else if (board.getFood().y == snake.head().y) {
		if (board.getFood().x > snake.head().x) {
			dir = Direction::RIGHT;
			//	std::cout << "Bot bewegt Schlange rechts\n";
		}
		else if (board.getFood().x < snake.head().x) {
			dir = Direction::LEFT, dir;
			//	std::cout << "Bot bewegt Schlange links\n";
		}
	}
}

//Ändert die Richtung, falls sich in der aktuellen Richtung ein Schlangenteil befindet
void Bot::checkSnake() {

	Coordinate next = nextInDirection(dir, snake.head());
	if (snake.isBody(next)) {
		Coordinate nextUP = nextInDirection(Direction::UP, snake.head());
		Coordinate nextDOWN = nextInDirection(Direction::DOWN, snake.head());
		Coordinate nextLEFT = nextInDirection(Direction::LEFT, snake.head());
		Coordinate nextRIGHT = nextInDirection(Direction::RIGHT, snake.head());

		if (!snake.isBody(nextUP)) {
			dir = Direction::UP;
			//recHead = nextUP;
		}
		else if (!snake.isBody(nextDOWN)) {
			dir = Direction::DOWN;
			//recHead = nextDOWN;
		}
		else if (!snake.isBody(nextLEFT)) {
			dir = Direction::LEFT;
			//recHead = nextLEFT;
		}
		else if (!snake.isBody(nextRIGHT)) {
			dir = Direction::RIGHT;
			//recHead = nextRIGHT;
		}
		/*
		switch (dir) {
		case Direction::UP:
			//if (!snake.isBody(nextDOWN) && prevDir != Direction::DOWN) {
			//	dir = Direction::DOWN;
			//}
			if (!snake.isBody(nextLEFT)) {
				dir = Direction::LEFT;
				recHead = nextLEFT;
			}
			else if (!snake.isBody(nextRIGHT)) {
				dir = Direction::RIGHT;
				recHead = nextRIGHT;
			}
			else if (!snake.isBody(nextDOWN)) {
				dir = Direction::DOWN;
				recHead = nextDOWN;
			}
			break;
		case Direction::DOWN:
			//if (!snake.isBody(nextUP) && prevDir != Direction::UP) {
			//	dir = Direction::UP;
			//}
			if (!snake.isBody(nextLEFT)) {
				dir = Direction::LEFT;
				recHead = nextLEFT;
			}
			else if (!snake.isBody(nextRIGHT)) {
				dir = Direction::RIGHT;
				recHead = nextRIGHT;
			}
			else if (!snake.isBody(nextUP)) {
				dir = Direction::UP;
				recHead = nextUP;
			}
			break;
		case Direction::LEFT:
			//if (!snake.isBody(nextRIGHT) && prevDir != Direction::RIGHT) {
			//	dir = Direction::RIGHT;
			//}
			if (!snake.isBody(nextUP)) {
				dir = Direction::UP;
				recHead = nextUP;
			}
			else if (!snake.isBody(nextDOWN)) {
				dir = Direction::DOWN;
				recHead = nextDOWN;
			}
			else if (!snake.isBody(nextRIGHT)) {
				dir = Direction::RIGHT;
				recHead = nextRIGHT;
			}
			break;
		case Direction::RIGHT:
			//if (!snake.isBody(nextLEFT) && prevDir != Direction::LEFT) {
			//	dir = Direction::LEFT;
			//}
			if (!snake.isBody(nextUP)) {
				dir = Direction::UP;
				recHead = nextUP;
			}
			else if (!snake.isBody(nextDOWN)) {
				dir = Direction::DOWN;
				recHead = nextDOWN;
			}
			else if (!snake.isBody(nextLEFT)) {
				dir = Direction::LEFT;
				recHead = nextLEFT;
			}
			break;
		}*/
		//checkSnake();
		//checkWall();
		//checkSnakeRecursive(recHead);
	}
}

//Ändert die Richtung, falls sich in der aktuellen Richtung eine Wand befindet
void Bot::checkWall() {
	Coordinate next = nextInDirection(dir, snake.head());
	if (board.isBorder(next.x, next.y)) {
		turnRight();
		checkWall();
		checkSnake();
	}
}

//Gibt die Koordinate zurück, die von der gegebenen Koordinate aus in die gegebene Richtung erreicht wird.
//Default: (0,0)
Coordinate Bot::nextInDirection(Direction direction, Coordinate coordinate) {

	switch (direction) {
	case Direction::DOWN:
		return Coordinate(coordinate.x, coordinate.y + 1);
	case Direction::UP:
		return Coordinate(coordinate.x, coordinate.y - 1);
	case Direction::RIGHT:
		return Coordinate(coordinate.x + 1, coordinate.y);
	case Direction::LEFT:
		return Coordinate(coordinate.x - 1, coordinate.y);
	default:
		return Coordinate(0, 0);
	}
}


//Nimmt den aktuellen Status des Spielfeldes entgegen um damit weiter zu arbeiten.
//Sucht anschließend auf dem Spielfeld nach einer geeigneten Richtung, in die sich die Schlange anschließend bewegen soll.
void Bot::tick(Board &board)
{
	this->board = board;
	snake = board.getSnake();

	searchPath();

	board.moveSnake(dir);

	prevDir = dir;
}

bool Bot::isActive() {
	return active;
}

////////////////////////////////////////////////////////////////

//Lässt die Schlange nach rechts abbiegen
void Bot::turnRight() {
	switch (dir) {
	case Direction::UP:
		dir = Direction::RIGHT;
		break;
	case Direction::DOWN:
		dir = Direction::LEFT;
		break;
	case Direction::LEFT:
		dir = Direction::UP;
		break;
	case Direction::RIGHT:
		dir = Direction::DOWN;
	}
}

//Lässt die Schlange nach links abbiegen
void Bot::turnLeft() {
	switch (dir) {
	case Direction::UP:
		dir = Direction::LEFT;
		break;
	case Direction::DOWN:
		dir = Direction::RIGHT;
		break;
	case Direction::LEFT:
		dir = Direction::DOWN;
		break;
	case Direction::RIGHT:
		dir = Direction::UP;
	}
}