#include <iostream>
#include "Board.h"

//Initialisiere Board mit Höhe und Breite; setzt Schlangenkopf in die Mitte
Board::Board(int height, int width) {
	score = 0;
	this->height = height;
	this->width = width;
	snake.reset(height / 2, width / 2);
	newFoodPosition();
}

Board::Board()
{
	score = 0;
	height = 0;
	width = 0;
}

void Board::printBoard() {

	//Board output
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			if (isBorder(x, y)) {
				std::cout << "x";
			}
			else if (isSnakeHead(x, y)) {
				std::cout << "@";
			}
			else if (isSnakeBody(x, y)) {
				std::cout << "o";
			}
			else if (isFood(x, y)) {
				std::cout << "A";
			}
			else {
				std::cout << " ";
			}
			
			if (snakeAteFood()) {
				growSnake();
				newFoodPosition();
				score += 10;
			}

		}
		std::cout << "\n";
	}
	std::cout << "score: " << score;
}

void Board::growSnake() {
	snake.grow();
}

void Board::newFoodPosition() {

	if (fullBoard()) {	//Falls das Feld voll ist, mach "nichts"
		food.x = 0;
		food.y = 0;
		return;
	}
	food.x = 1 + (rand() % (width - 2));
	food.y = 1 + (rand() % (height - 2));

	if (isSnakeHead(food.x, food.y) || isSnakeBody(food.x, food.y)) {
		newFoodPosition();
	}
}

void Board::moveSnake(Direction direction) {
	snake.move(direction);

	
	//snake.move(direction, snakeAteFood());
}

////////////////////////////////////////////////////////////////

bool Board::isBorder(int x, int y) {
	return (x == 0 || x == width - 1 || y == 0 || y == height - 1);
}

bool Board::isSnakeHead(int x, int y) {
	return (x == snake.head().x && y == snake.head().y);
}

bool Board::isFood(int x, int y) {
	return (x == food.x && y == food.y);
}

bool Board::isSnakeBody(int x, int y) {
	return snake.isBody({ x, y });
}

//Prüft ob das Spielbrett ausschließlich aus Schlangenteilen besteht.
//Falls ein einziges Feld keinen Schlangenteil enthält ist das Brett nicht voll.
bool Board::fullBoard() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (!isSnakeBody(x, y) && !isSnakeHead(x, y)) {
				return false;
			}
		}
	}
	return true;
}

////////////////////////////////////////////////////////////////

bool Board::snakeHitBorder() {
	return (snake.head().x == 0 || snake.head().x == width - 1
		|| snake.head().y == 0 || snake.head().y == height - 1);
}

bool Board::snakeHitSnake() {
	return snake.isBody(snake.head());
}

bool Board::snakeAteFood() {
	return (snake.head().x == food.x && snake.head().y == food.y);
}

////////////////////////////////////////////////////////////////

int Board::getScore() {
	return score;
}

Coordinate Board::getFood()
{
	return food;
}

Snake Board::getSnake()
{
	return snake;
}
