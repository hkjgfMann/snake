#pragma once
struct Coordinate
{
	int x;
	int y;
	Coordinate(int x, int y) { this->x = x; this->y = y; }
	Coordinate() { x = 0; y = 0; }
	bool equals(Coordinate coord);
};