#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <set>
#include <iostream>
#include <string>

#include "Carte.hpp"

using namespace std;

class Joueur {
	
private:
	
	string nom;
	set<Carte> jeu; // Set de cartes, triées et numérotées
	set<Carte>::iterator it;
	int decision; // 0 passe, 1 prend, 2 garde, 3 garde_sans, 4 garde_contre
	//Equipe equipe;
	int points; // points du joueur
	
public:
	
	Joueur(string name);
	void setDecision(int choix);
	int getDecision();
	//Equipe getEquipe();
	//void setEquipe(Equipe team);
	set<Carte> getJeu();
	set<Carte>::iterator getIterator();
	int getPoints();
	void ajouterCarte(Carte& nvlCarte);
	Carte* jouerCarte(int numero); // supprime la carte du jeu
	Carte* getCarte(int numero); // laisse la carte dans le jeu
	void ajouterPoints(int pts);
	void afficherJeu();
};

#endif

