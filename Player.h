#pragma once
#include <string>
class Player
{
private:
	std::string name;
	int score;

public:
	Player(std::string name);
	Player(std::string name, int score);
	Player();
	int getScore();
	std::string getName();
	void setScore(int score);
	void setName(std::string name);
	std::string toString();
};