#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Carte.hpp"



using namespace std;

/*
struct cartecomp {
  bool operator() (const Carte& une, const Carte& deux) const {
	  return une.getRang() < deux.getRang();
  }
};*/
class Carte;
class Joueur {

private:

	string nom;
	vector<Carte> jeu; // vector de cartes, triées et numérotées
	vector<Carte>::iterator it;
	int decision; // 0 passe, 1 prend, 2 garde, 3 garde_sans, 4 garde_contre
	int points; // points du joueur
	//Etat etat; // defenseur ou preneur
	int nbBout;
	

public:

    Joueur();
	Joueur(string name);
	~Joueur();
	void setDecision(int choix);
	int getDecision();
	vector<Carte> getJeu();
	vector<Carte>::iterator getIterator();
	int getPoints();
	void ajouterCarte(Carte c);
	Carte jouerCarte(int numero); // supprime la carte du jeu
	Carte getCarte(int numero); // laisse la carte dans le jeu
	void ajouterPoints(int pts);
	void afficherJeu();

	void compterBouts();
	void afficherPossibilites(string demande);
};




#endif

