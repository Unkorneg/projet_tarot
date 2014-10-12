#include "Joueur.hpp"

Joueur(string name){
	nom = name;
	main = new vector<Cartes>();
	decision = NULL;
	points = 0;
}

void setDecision(int choix) {
	
	switch(choix) {
		case 0:
		decision = "passe";
		break;
			
		case 1:
		decision = "prend";
		break;
			
		case 2:
		decision = "garde";
		break;
			
		case 3:
		decision = "garde_sans";
		break;
			
		case 4:
		decision = "garde_contre";
		break;
	} 
	
}

string getDecision(){
	return decision;
}

vector<Carte> getMain() {
	return main;
}

int getPoints() {
	return points;
}

void ajouterCarte(Carte nvlCarte) {
	int i=0;
	while  ((main[i] < nvlCarte) && (i<main.size()) { // Tant que la carte i est plus petite que la carte à insérer
		i++;
	}
	if (i == main.size-1){
		main.push_back(nvlCarte); // insère la carte à la fin du vecteur
	}
	else {
		main.insert(i, nvlCarte); // insère un élément avant l'emplacement i
	}
}

Carte lancerCarte(int numero) {
	main.erase(numero);
}

Carte getCarte(int numero) {
	return main[i-1];
}

void ajouterPoints(int nbPts) {
	points += nbPts;
}