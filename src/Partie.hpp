#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

#include "Joueur.hpp"
#include "Carte.hpp"
#include "Tapis.hpp"

using namespace std;

class Partie {

private:
	/*Joueur nord;
	Joueur est;
	Joueur sud;
	Joueur ouest;*/
	vector<Joueur> participants;// Ne change pas à chaque manche
	Joueur* preneur;
	Tapis tapis;
	int nbManches;
	vector<Carte> paquet;
	vector<Carte> potDefense;
	vector<Carte> potPreneur;

public:
	Partie();
	~Partie();
	void ajouterJoueur(Joueur& jo);
	void distribuerCartes();
	void donnerChien(); // donne le chien au preneur
	void constituerChien();
	void demanderMise(); // demande à chaque joueur quelle décision il prend
	void jouer(int num); // demande au joueur quelle carte jouer et joue la carte
	void ajouterADefense(vector<Carte> gain);
	void ajouterAPreneur(vector<Carte> gain);
	void compterPointsDefense();
	void compterPointsPreneur();


};

#endif
