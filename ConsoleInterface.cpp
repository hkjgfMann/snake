#include <conio.h>
#include <iostream>
#include "ConsoleInterface.h"

bool keyHit()
{
	return _kbhit();
}

char readKey()
{
	return _getch();
}

char readKeyWithEcho()
{
	return _getche();
}

void clearScreen()
{
	std::system("cls");
}

Direction changeDirection(char c, Direction currentDir) {
	switch (c) {
	case 'a':
	case NUMPAD_LEFT:
		if (currentDir != Direction::RIGHT) {
			return Direction::LEFT;
		}
		else return currentDir;
		break;
	case 'd':
	case NUMPAD_RIGHT:
		if (currentDir != Direction::LEFT) {
			return Direction::RIGHT;
		}
		else return currentDir;
		break;
	case 'w':
	case NUMPAD_UP:
		if (currentDir != Direction::DOWN) {
			return Direction::UP;
		}
		else return currentDir;
		break;
	case 's':
	case NUMPAD_DOWN:
		if (currentDir != Direction::UP) {
			return Direction::DOWN;
		}
		else return currentDir;
		break;
	default:
		break;
	}
}

Direction changeDirection(Direction newDir, Direction currentDir) {
	if (newDir == Direction::LEFT && currentDir != Direction::RIGHT) {
		return newDir;
	}
	if (newDir == Direction::RIGHT && currentDir != Direction::LEFT) {
		return newDir;
	}
	if (newDir == Direction::UP && currentDir != Direction::DOWN) {
		return newDir;
	}
	if (newDir == Direction::DOWN && currentDir != Direction::UP) {
		return newDir;
	}
	return currentDir;
}