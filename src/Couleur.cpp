#include "Couleur.hpp"

Couleur::Couleur(string val, double pts, int rg, string col):Carte(val, pts, rg) {
	couleur = col
}

~Couleur() {
	
}

string Couleur::getCouleur() {
	return couleur;
}
void Couleur::setCouleur(string col) {
	couleur = col;
}

string Couleur::getNom() {
	return valeur + "de" + couleur;
}