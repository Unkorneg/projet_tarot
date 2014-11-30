#include <iostream>


#include "Carte.hpp"

Carte::Carte(string val, string coul, double pts, int rg) {
	valeur = val;
	couleur = coul;
	points = pts;
	rang = rg;
	if (( coul=="Atout") && ((val=="21") | (val=="1") | (val=="Excuse"))) {
		bout=true;
	}
	else {
		bout=false;
	}
	proprietaire = NULL;
}

Carte::~Carte() {
	//
}

string Carte::getValeur() {
	return valeur;
}

double Carte::getPoints() {
	return points;
}

int Carte::getRang() {
	return rang;
}

bool Carte::plusPetit(Carte& c) {
	return (rang < c.rang);
}

void Carte::setValeur(string val) {
	valeur = val;
}

void Carte::setPoints(double pts) {
	points = pts;
}

void Carte::setRang(int rg) {
	rang = rg;
}

string Carte::getNom() {
	return valeur + " de " + couleur;
}

bool Carte::estBout() {
	return (bout);
}

string Carte::getCouleur() {
	return couleur;
}

void Carte::setCouleur(string col) {
	couleur = col;
}

void Carte::setProprio(Joueur* jo) {
	proprietaire = jo;
}

Joueur* Carte::getProprio() {
	return proprietaire;
}

/*
int main() {
	Carte* cc = new Carte("Roi", "Coeur", 2.5, 7);

	cout << cc->getNom() << "\n"; // Roi
	cout << cc->getRang() << "\n";
	cout << cc->getPoints() << "\n";

	Carte* c1 = new Carte("Dame", "Pique", 1.5, 6);

	cout << c1->plusPetit(*cc) << '\n';

	return 0;
}*/
