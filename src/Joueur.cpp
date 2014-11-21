#include "Joueur.hpp"

Joueur::Joueur(string name){
	nom = name;
	decision = 0;
	points = 0;
}

Joueur::~Joueur() {
	jeu.clear();
}

void Joueur::setDecision(int choix) {
	decision = choix;
}

int Joueur::getDecision(){
	return decision;
}

vector<Carte> Joueur::getJeu() {
	return jeu;
}

vector<Carte>::iterator Joueur::getIterator() {
	return it;
}

int Joueur::getPoints() {
	return points;
}

void Joueur::ajouterCarte(Carte& c) {
	
	// insère la carte dans la main de façon à ce que le jeu soit trié
	it = jeu.end();
	while (c.plusPetit(*it) && it != jeu.begin()) {
		--it;
	}
	jeu.insert(it,c);
	
}

Carte Joueur::jouerCarte(int num) {
	
	Carte rep = jeu[num];
	jeu.erase(jeu.begin()+num);
	return rep;
}

Carte Joueur::getCarte(int num) {
	
	return jeu[num];
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

void Joueur::compterBouts() {
	
}
void Joueur::afficherPossibilites(string demande) {
	
}


int main() {
	Joueur* j1 = new Joueur("David");
	
	Carte* c1 = new Carte("Valet", "Coeur", 1, 1);
	Carte* c2 = new Carte("Dame", "Coeur", 1, 2);
	Carte* c3 = new Carte("Roi", "Coeur", 1, 3);
	Carte* c4 = new Carte("As", "Coeur", 1, 4);
	
	j1->afficherJeu();
	
}
