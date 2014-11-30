#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <iostream>
#include <string>

//
//#include "Observer.hpp"
#include "Carte.hpp"
#include "ComportementPoints.hpp"

using namespace std;

//class Carte;
class ComportementPoints;
class Tapis;
//class Observer;
class Joueur {

private:

	string nom;
	vector<Carte*> jeu; // vector de cartes, triées et numérotées. Les éléments sont des pointeurs vers les cartes contenues dans le paquet de Partie
	vector<Carte*> pli;
	vector<Carte*>::iterator it;
	int mise; // 0 passe, 1 prend, 2 garde, 3 garde_sans, 4 garde_contre
	double points; // points du joueur
	ComportementPoints* compPts;

	Tapis* tapis;
    string demande;
    Carte* gagnante;


public:

    Joueur();
	Joueur(string name);
	~Joueur();
	string getNom();
	void setMise(int choix);
	void afficherMisePossible(int miseMax);
	int getMise();
	void setComportement(ComportementPoints comp);
	vector<Carte*> getJeu();
	vector<Carte*>::iterator getIterator();
	int getPoints();
	void ajouterCarte(Carte* c);
	Carte* jouerCarte(int numero); // supprime la carte du jeu
	Carte* getCarte(int numero); // laisse la carte dans le jeu
	void ajouterPoints(int pts);
	double compterPoints(); // Compte les points du joueur quand il est preneur et renvoie les points de l'équipe adverse

	void afficherJeu();

	void compterBouts();
	void afficherPossibilites();
	void gagnerPli(vector<Carte*> gain);

	void actualiser(string d, Carte* g);
    void setTapis(Tapis* t);
};




#endif

