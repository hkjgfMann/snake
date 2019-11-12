#pragma once
#include "Snake.h"
#include "Board.h"

class Bot
{
private:
	friend class Board;

	Direction dir;
	Direction prevDir;
	Snake snake;
	Board board;
	bool active;
	
	void turnRight();
	void turnLeft();
	void searchPath();	/////
	void checkSnake();
	void checkWall();
	void findFood();
	Coordinate nextInDirection(Direction direction, Coordinate coordinate);

public:

	Bot();	/////
	void toggle();
	void tick(Board &board);	/////
	bool isActive();
};