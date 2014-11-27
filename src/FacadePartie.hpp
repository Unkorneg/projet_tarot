#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

#include "Joueur.hpp"
#include "Carte.hpp"
#include "Tapis.hpp"

using namespace std;

class FacadePartie {

private:
	vector<Joueur*> participants;// Ne change pas à chaque manche
	Joueur* preneur;
	Tapis* tapis;
	int nbManches;
	vector<Carte*> paquet; // Le paquet qui contient toutes les cartes du jeu
	vector<Carte*> potDefense; // le pot contient des pointeurs vers les cartes gagnées par la défense
	vector<Carte*>::iterator it;
	bool excuseJouee = false;
	int compteur;

public:
	FacadePartie();
	~FacadePartie();
	void ajouterJoueur(string nom);
	void distribuerCartes();
	void donnerChien(); // donne le chien au preneur
	void constituerChien();
	void demanderMise(); // demande à chaque joueur quelle décision il prend
	void jouer(int num); // demande au joueur quelle carte jouer et joue la carte
	void finDeManche();
	void compterPoints();


};

#endif
