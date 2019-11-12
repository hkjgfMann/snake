#pragma once
#include "Snake.h"
#include "Coordinate.h"

class Board
{
public:
	Board(int height, int width);
	Board();
	void printBoard();
	void moveSnake(Direction direction);
	int getScore();
	bool snakeHitBorder();
	bool snakeHitSnake();
	Coordinate getFood();
	Snake getSnake();

private:
	friend class Bot;

	int score;
	int height;
	int width;
	Coordinate food;
	Snake snake;

	void newFoodPosition();
	void growSnake();
	bool snakeAteFood();
	bool isSnakeBody(int x, int y);
	bool isSnakeHead(int x, int y);
	bool isBorder(int x, int y);
	bool isFood(int x, int y);
	bool fullBoard();
};

