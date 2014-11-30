#ifndef TAPIS_HPP
#define TAPIS_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Carte.hpp"
//#include "Joueur.hpp"

using namespace std;
class Carte;
class Joueur;
class Tapis {

private:

	string demande; // (Carreau, Trèfle, Coeur, Pique, Atout)
	Carte* gagnante;
	vector<Carte*> tas; // les 4 cartes jouées
	vector<Carte*>::iterator it;
	vector<Carte*> chien;
	vector<Joueur*> observers;
	vector<Joueur*>::iterator itj;

public:

	Tapis();
	~Tapis();
	void recevoirCarte(Carte* c);
	vector<Carte*> getTas();
	void ajouterChien(Carte* c);
	void setObserver(Joueur* j);
	void notifierObs();
	vector<Carte*> getChien();
	void setDemande(string dem);
	vector<Carte*> donnerChien();
	Carte* getGagnante();
	void viderTas();
	string getDemande();
	void afficherChien();
	void afficherTas();

	Joueur* getGagnant();
};


#endif
