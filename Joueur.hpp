#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Joueur {
	
private:
	
	string nom;
	vector<Carte> main; // Vecteur de cartes, triées et numérotées
	string decision; // 0 passe, 1 prend, 2 garde, 3 garde_contre, 4 garde_sans
	int points; // points du joueur
	
public:
	
	Joueur(string name);
	void setDecision(int choix);
	string getDecision();
	vector<Carte> getMain();
	int getPoints();
	void ajouterCarte(Carte nvlCarte);
	Carte lancerCarte(int numero);
	Carte getCarte(int numero)
	void ajouterPoints();
};

#endif

