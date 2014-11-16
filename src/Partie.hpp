#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

using namespace std;

class Partie {
	
private:
	vector<Joueur> participants;// Ne change pas à chaque manche
	Tapis tapis;
	Equipe defense;
	Equipe preneur;
	int nbManches;
	vector<Carte> paquet;
	
public:
	Partie();
	void ajouterJoueur(Joueur nve);
	void setEquipe(Joueur seul);
	void distribuerCartes();
	void ramasserCartes();
	void creerEquipes(); // demande à chaque joueur sa décision, créé les équipes
	
};

#include "Partie.cpp"

#endif