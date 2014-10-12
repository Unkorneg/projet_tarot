#ifndef TAPIS_HPP
#define TAPIS_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Tapis {
	
private:
	
	vector<Carte> jeu;
	Carte* gagnante;
	
public:
	
	Tapis();
	void recevoirCarte(Carte recu);
	vector<Carte> distribuerGain(Equipe gagnant);
	vector<Carte> distribuerChien(Joueur joue);
};
	

#endif