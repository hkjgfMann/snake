#include "Player.h"

Player::Player() {
	name = "";
	score = 0;
}

Player::Player(std::string name) {
	this->name = name;
	score = 0;
}
Player::Player(std::string name, int score)
{
	this->name = name;
	this->score = score;
}
;

int Player::getScore() {
	return score;
}

std::string Player::getName()
{
	return name;
}

void Player::setScore(int score) {
	this->score = score;
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::toString() {
	return name + "=" + std::to_string(score);
}