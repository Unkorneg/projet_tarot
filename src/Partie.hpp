#ifndef PARTIE_HPP
#define PARTIE_HPP

#include "FacadePartie"

using namespace std;

class Partie {

private:
	FacadePartie facade;
public:
	Partie();
	~Partie();
	void initialiserPartie();
	void ajouterJoueur(Joueur jo);
	void distribuerCartes();
	void donnerChien(); // donne le chien au preneur
	void constituerChien();
	void demanderMise(); // demande à chaque joueur quelle décision il prend
	void jouer(int num); // demande au joueur quelle carte jouer et joue la carte
	void ajouterADefense();
	void ajouterAPreneur();
	void compterPoints();


};

#endif
