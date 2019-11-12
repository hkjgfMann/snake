#include "Scoretable.h"
#include <fstream>
#include <iostream>

using namespace std;

Scoretable::Scoretable() {
	for (int i = 0; i < 10; i++) {
		Player p("LEER");
		players.push_back(p);
	}
}

void Scoretable::initFromFile(std::string filename)
{
	string line;	//Zwischenspeicher für Zeile
	ifstream scoretableFile(filename);	//Datei öffnen

	while (getline(scoretableFile, line)) {

		//Spieler erstellen
		int pos = line.find('=');
		string name = line.substr(0, pos);
		int score = stoi(line.substr(pos + 1));
		Player p(name, score);

		//Spieler hinzufügen
		addPlayerSorted(p);
	}
	scoretableFile.close();	//Datei schileßen
}

//return false falls Datei nicht gefunden wurde, andernfalls true
bool Scoretable::safeToFile(std::string filename)
{
	ofstream scoretableFile(filename);	//Datei öffnen

	if (!scoretableFile.is_open()) return false;

	for (Player p : players) {
		scoretableFile << p.toString() << "\n";	//Spieler hinzufügen
	}
	scoretableFile.close();	//Datei schließen

	return true;

}

void Scoretable::addPlayerSorted(Player player)
{

	//Füge Spieler bei leerer Liste hinzu
	if (players.empty()) {
		players.push_back(player);
		return;
	}

	//Sortiertes Einfügen
	std::vector<Player>::iterator it;
	for (it = players.begin(); it < players.end(); it++) {
		Player p = *it;
		if (player.getScore() > p.getScore()) {
			
			players.insert(it, player);
			break;
		}
	}

	//Nicht mehr als 10 Spieler in der Liste
	if (players.size() > 10) {
		players.erase(players.begin() + 10, players.end());
	}
}

void Scoretable::print()
{
	ios state(nullptr);
	state.copyfmt(cout);	//Aktuelle Formatierung von cout zwischenspeichern

	//Formatierte Ausgabe
	for (int i = 0; i < players.size(); i++) {
		cout.fill('-');
		cout.width(10);
		cout << left << players[i].getName() << "\t";

		cout.fill('0');
		cout.width(4);
		cout << right << players[i].getScore() << "\n";
	}

	cout.copyfmt(state);	//Ursprüngliche Formatierung von cout wieder herstellen
}