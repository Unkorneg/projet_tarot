#include "Tapis.hpp"

Tapis() {
	
}
~Tapis() {
	
}
void recevoirCarte(Carte& c) {
	tas.push_back(c)
}
vector<Carte> getTas();
void setDemande(string dem);
vector<Carte> distribuerChien(Joueur& joue);