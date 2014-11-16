#ifndef TAPIS_HPP
#define TAPIS_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Tapis {
	
private:
	
	String demande; // (Carreau, Trèfle, Coeur, Pique, Atout)
	;
	
public:
	
	Tapis();
	void recevoirCarte(Carte recu);
	vector<Carte> distribuerGain(Equipe gagnant);
	vector<Carte> distribuerChien(Joueur joue);
};
	

#endif