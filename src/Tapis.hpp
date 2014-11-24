#ifndef TAPIS_HPP
#define TAPIS_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Carte.hpp"
#include "Joueur.hpp"

using namespace std;

class Tapis {

private:

	string demande; // (Carreau, Trèfle, Coeur, Pique, Atout)
	vector<Carte> tas; // les 4 cartes jouées
	vector<Carte>::iterator it;
	vector<Carte> chien;

public:

	Tapis();
	~Tapis();
	void recevoirCarte(Carte& c);
	vector<Carte> getTas();
	void ajouterChien(Carte c);
	vector<Carte> getChien();
	void setDemande(string dem);
	vector<Carte> donnerChien();
	Carte plusGrande();
	void viderTas();
	string getDemande();
	void afficherChien();
};


#endif
