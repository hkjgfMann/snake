#pragma once
#include <vector>
#include "Coordinate.h"
#include "Direction.h"

class Snake
{
private:
	std::vector<Coordinate> snakeparts;

public:
	void reset(int x, int y);
	void grow();
	void move(Direction direction);
	void updateSnakeparts();
	bool isBody(Coordinate part);
	Coordinate head();
	//Direction direction;

	//NICHT VERWENDET: Move und grow in einem
	void move(Direction direction, bool ateFood);
};