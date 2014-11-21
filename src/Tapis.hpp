#ifndef TAPIS_HPP
#define TAPIS_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Tapis {
	
private:
	
	string demande; // (Carreau, Trèfle, Coeur, Pique, Atout)
	vector<Carte> tas; // les 4 cartes jouées
	
public:
	
	Tapis();
	~Tapis();
	void recevoirCarte(Carte& c);
	vector<Carte> getTas();
	void setDemande(string dem);
	vector<Carte> distribuerChien(Joueur& joue);
};
	

#endif