#include "Tapis.hpp"

Tapis::Tapis() {

}

Tapis::~Tapis() {

}

void Tapis::recevoirCarte(Carte& c) {

	tas.push_back(c);
}

vector<Carte> Tapis::getTas() {
	return tas;
}

void Tapis::setDemande(string dem) {
	demande = dem;
}
vector<Carte> Tapis::distribuerChien(Joueur& joue) {
}
