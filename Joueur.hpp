#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Joueur {
	
private:
	
	String nom;
	vector<Carte> main; // Vecteur de cartes, triées et numérotées
	String decision; // 0 passe, 1 prend, 2 garde, 3 garde_contre, 4 garde_sans
	int points; // points du joueur
	
public:
	
	Joueur(String name);
	void setDecision(int choix);
	String getDecision();
	vector<Carte> getMain();
	int getPoints();
	void ajouterCarte(Carte nvlCarte);
	Carte lancerCarte(int numero);
	Carte getCarte(int numero)
	void ajouterPoints();
};

#endif

