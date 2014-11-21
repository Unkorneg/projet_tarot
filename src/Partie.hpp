#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

using namespace std;

class Partie {
	
private:
	vector<Joueur> participants;// Ne change pas à chaque manche
	Joueur preneur;
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
	void jouer(int num, string demande); // demande au joueur quelle carte jouer et joue la carte
	string demandeTapis(); // renvoie la couleur demandée par le tapis
	void ajouterADefense(vector<Carte> gain);
	void ajouterAPreneur(vector<Carte> gain);
	
	
};

#include "Partie.cpp"

#endif