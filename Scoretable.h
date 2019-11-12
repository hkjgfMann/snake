#pragma once
#include <map>
#include <string>
#include <vector>
#include "Player.h"
class Scoretable
{
private:
	std::vector<Player> players;

public:
	Scoretable();
	void initFromFile(std::string filename);
	bool safeToFile(std::string filename);	//Schreibt die Liste in eine Datei
	void addPlayerSorted(Player player);	//Fügt den Spieler nach score sortiert der Liste hinzu
	void print();
};