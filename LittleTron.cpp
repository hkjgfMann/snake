#include "LittleTron.h"
#include "time.h"


int main()
{
	srand(time(NULL));

	scoretable.initFromFile(filename);
	bool stop = false;

	//Startbildschirm///////////////////////////////////////////////
	clearScreen();
	std::cout << "***************************\n";
	std::cout << "*Wilkommen bei littleTron!*\n";
	std::cout << "***************************\n\n";
	std::cout << "(Beliebige Taste druecken)";
	readKey();
	////////////////////////////////////////////////////////////////

	//Hauptschleife/////////////////////////////////////////////////
start:
	menupoints();
	while (!stop) {
		if (keyHit()) {
			switch (readKey()) {
			case 'q':
				stop = true;
				break;
			case '1':
				play();
				goto start;
				break;
			case '2':
				printHighscores();
				goto start;
				break;
			default:
				break;
			}
		}
	}

	//Programm beenden//////////////////////////////////////////////
	clearScreen();
	if (!scoretable.safeToFile(filename)) {
		std::cout << "Datei konnte nicht gespeichert werden\n";
	}
}

void play() {
	//Programm initialisieren////////////////////////////////////////
	std::string name;
	Direction direction = Direction::NONE;
	Board board(20, 30);
	Bot bot;

	//Spiel vorbereiten/////////////////////////////////////////////
	clearScreen();
	std::cout << "Spielernamen angeben (10 Buchstaben): ";
	std::cin >> name;
	player.setName(name);

	direction = Direction::NONE;
	float time = 50;	//Spielgeschwindigkeit, je niedrieger desto schneller
	int score = board.getScore();
	int prevScore = score;
	char c = ' ';

	//Hauptschleife Spiel///////////////////////////////////////////
	clearScreen();
	while (!board.snakeHitSnake() && !board.snakeHitBorder()) {

		board.printBoard();
		score = board.getScore();

		if (keyHit()) {
			c = readKey();
			if (c == 'b') {
				bot.toggle();
			}
			else {
				direction = changeDirection(c, direction);
			}
		}

		//Spielerkontrolle auf Bot umleiten, falls aktiv
		if (bot.isActive()) {
			bot.tick(board);
		}
		else {
			board.moveSnake(direction);
		}

		//Geschwindigkeit mit steigendem Punktestand ändern
		if (score != prevScore) {	
			time = (time == 0.5) ? 0.5 : time - 0.5;
			prevScore = score;
		}

		gotoxy(0, 0);// clearScreen();
		Sleep(time);
	}

	player.setScore(score);
	scoretable.addPlayerSorted(player);
	readKey();

	//Game Over Screen//////////////////////////////////////////////
	clearScreen();
	std::cout << "*Game Over!*\n";
	std::cout << "************\n";
	std::cout << "\nPunktestand: " << board.getScore() << "\n";
	////////////////////////////////////////////////////////////////

}

void printHighscores() {
	//Highscores////////////////////////////////////////////////////
	clearScreen();
	scoretable.print();
	std::cout << "\n(Beliebige Taste druecken)";
	readKey();
	////////////////////////////////////////////////////////////////
}

void menupoints() {
	clearScreen();
	std::cout << "Hauptmenue\n";
	std::cout << "*****************\n";
	std::cout << "[1] Neues Spiel\n";
	std::cout << "[2] Highscores\n";
	std::cout << "[q] Spiel beenden\n";
}