#include "Partie.hpp"
#include <ctime>
#include <cstdlib>

Partie::Partie() {

	string TabValeur[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Cavalier", "Dame", "Roi"};
	double TabPoints[] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.5, 2.5, 3.5, 4.5};
	string TabCouleur[] = {"Trèfle", "Carreau", "Coeur", "Pique"};
	string TabAtout[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "Excuse"};
	double TabPtsAtouts[] = {4.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 4.5, 4.5};

	int i = 0;
    int rg=1;
	// Création des cartes couleurs
	for (int coul=0; coul<=3; coul++)
	{
		for (int val=0; val<13; val++)
		{
			Carte* carte = new Carte(TabValeur[i], TabCouleur[i], TabPoints[i], rg);
			++i;
			++rg;
			paquet.push_back(*carte);
		}
	}

	i = 0;
	// Création des cartes d'atout
	for(int att = 0; att<= 21; ++att) {

		Carte* carte = new Carte(TabAtout[i], "Atout", TabPtsAtouts[i], rg);
		++i;
		++rg;
		paquet.push_back(*carte);
	}
}

void Partie::distribuerCartes() {
	int gMax = 72;
	for(int j=0; j<4; ++j) {
		for (int i=0; i<18; ++i){
			int ind = rand()%gMax;
			participants[j].ajouterCarte(paquet[ind]);
			paquet.erase(paquet.begin()+ind);
			gMax -= 1;
		}
	}
	for(int k =0; k<6; ++k) {
		tapis.recevoirCarte(paquet[k]);
		paquet.erase(paquet.begin()+k);
	}
}

void Partie::ajouterJoueur(Joueur& j) {
	participants.push_back(j);
}

/*
void Partie::creerEquipes() {
	Joueur preneur = participants[0];
	for(Joueur j : participants) {
		int dec;
		cout << "Décision de " + j.getNom() + " ?" << "\n";
		cout << "0. Je passe\n" << "1. Je prend\n" << "2. Je garde\n" << "3. Je garde sans\n" << "4. Je garde contre\n";
		cin >> dec;
		j.setDecision(dec);
		if (dec>preneur.getDecision())
			preneur = j;
	}
	if (preneur.getDecision == 0)
		finDeManche();
	else {
		cout << preneur.getNom() << " joue contre les autres.\n";
	}

	defense.ajouterJoueur();
}*/

