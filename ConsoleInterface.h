#pragma once
#include "Direction.h"

#define NUMPAD_UP 56
#define NUMPAD_DOWN 53
#define NUMPAD_LEFT 52
#define NUMPAD_RIGHT 54

bool keyHit();
char readKey();
char readKeyWithEcho();
void clearScreen();
Direction changeDirection(char c, Direction currentDir);
Direction changeDirection(Direction newDir, Direction currentDir);