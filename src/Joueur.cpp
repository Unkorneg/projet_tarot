#include "Joueur.hpp"

Joueur::Joueur(string name){
	nom = name;
	main = new set<Cartes>(); // un set est trié
	decision = NULL;
	points = 0;
}

void Joueur::setDecision(int choix) {
	decision = choix;
}

int Joueur::getDecision(){
	return decision;
}

set<Carte> Joueur::getMain() {
	return main;
}

set<Carte>::iterator Joueur::getIterator() {
	return it;
}

int Joueur::getPoints() {
	return points;
}

void Joueur::ajouterCarte(Carte nvlCarte) {
	
	// insère la carte dans la main de façon à ce que le jeu soit trié
	jeu.insert(nvlCarte);
	
}

Carte Joueur::jouerCarte(int numero) {
	it = jeu.begin();
	for(int i=1; i<numero; ++i) {
		++it;
	}
	Carte rep = *it;
	jeu.erase(it);
	return rep;
}

Carte Joueur::getCarte(int numero) {
	it = jeu.begin();
	for(int i=1; i<numero; ++i) {
		++it;
	}
	Carte rep = *it;
	return rep;
}

void Joueur::ajouterPoints(int nbPts) {
	points += nbPts;
}

void Joueur::afficherMain() {
	int i = 1;
	for(it=jeu.begin();it=jeu.end();++it) {
		cout << i << ". " << c.getNom() << endl;
		++i;
	}
}

Equipe Joueur::getEquipe() {
	return equipe;
}

void Joueur::setEquipe(Equipe e) {
	equipe = e;
}
