#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <iostream>
#include <string>

#include "ComportementPoints.hpp"
#include "Carte.hpp"
#include "Observer.hpp"

using namespace std;

/*
struct cartecomp {
  bool operator() (const Carte& une, const Carte& deux) const {
	  return une.getRang() < deux.getRang();
  }
};*/
class Carte;
class ComportementPoints;
class Observer;
class Joueur : public Observer {

private:

	string nom;
	vector<Carte*> jeu; // vector de cartes, triées et numérotées. Les éléments sont des pointeurs vers les cartes contenues dans le paquet de Partie
	vector<Carte*> pli;
	vector<Carte*>::iterator it;
	int mise; // 0 passe, 1 prend, 2 garde, 3 garde_sans, 4 garde_contre
	double points; // points du joueur
	ComportementPoints* compPts;
	string demande; // couleur demandée par le tapis

public:

    Joueur();
	Joueur(string name);
	~Joueur();
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
};




#endif

