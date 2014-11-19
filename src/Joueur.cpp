#include "Joueur.hpp"

Joueur::Joueur(string name){
	nom = name;
	decision = 0;
	points = 0;
}

void Joueur::setDecision(int choix) {
	decision = choix;
}

int Joueur::getDecision(){
	return decision;
}

set<Carte> Joueur::getJeu() {
	return jeu;
}

set<Carte>::iterator Joueur::getIterator() {
	return it;
}

int Joueur::getPoints() {
	return points;
}

void Joueur::ajouterCarte(Carte& nvlCarte) {
	
	// insère la carte dans la main de façon à ce que le jeu soit trié
	jeu.insert(nvlCarte);
	
}

Carte* Joueur::jouerCarte(int numero) {
	it = jeu.begin();
	for(int i=1; i<numero; ++i) {
		++it;
	}
	Carte rep = *it;
	jeu.erase(it);
	return &rep;
}

Carte* Joueur::getCarte(int numero) {
	it = jeu.begin();
	for(int i=1; i<numero; ++i) {
		++it;
	}
	Carte rep = *it;
	return &rep;
}

void Joueur::ajouterPoints(int nbPts) {
	points += nbPts;
}

void Joueur::afficherJeu() {
	int i = 1;
	for(it=jeu.begin();it!=jeu.end();++it) {
		cout << i << ". " << it->getNom() << endl;
		++i;
	}
}

/*Equipe Joueur::getEquipe() {
	return equipe;
}

void Joueur::setEquipe(Equipe e) {
	equipe = e;
}*/

int main() {
	Joueur* j1 = new Joueur("David");
	
	Carte* c1 = new Carte("Valet", 1, 1);
	Carte* c2 = new Carte("Dame", 1, 2);
	Carte* c3 = new Carte("Roi", 1, 3);
	Carte* c4 = new Carte("As", 1, 4);
	
	j1->afficherJeu();
	
}
