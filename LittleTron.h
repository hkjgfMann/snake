#pragma once

#include <iostream>
#include "Board.h"
#include "ConsoleInterface.h"
#include "Direction.h"
#include "Scoretable.h"
#include "Bot.h"

#ifdef  _MSC_VER
#include <Windows.h>
COORD coord = { 0,0 }; // this is global variable
									/*center of axis is set to the top left cornor of the screen*/
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
void gotoxy(int x, int y)
gjfiodjiogjiofdjs
gdfisjgojfiosdjiogfds
gjfiod

#endif


//Hauptteil
std::string filename = "C:\\dev\\Visual Studio Projekte\\LittleTron\\highscores.txt";
Scoretable scoretable;
Player player;

void play();

void printHighscores();

void menupoints();

int main();