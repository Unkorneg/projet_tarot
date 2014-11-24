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

void Partie::donnerChien() {
	cout << "Le chien contient : " << endl;
	tapis.afficherChien();
	vector<Carte> chien = tapis.donnerChien();
	vector<Carte>::iterator it;
	for(it=chien.begin();it!=chien.end();++it) {
        preneur->ajouterCarte(*it);
	}
	string tmp;
	cin >> tmp;
	system("cls");
}

void Partie::constituerChien() {
	int num;
	for(int i=0;i<6;++i) {
		preneur->afficherJeu();
		cout << "Quelle carte souhaitez-vous mettre dans le chien ? (Reste "<< 6-i << " cartes." << endl;
		cin >> num;
		tapis.ajouterChien(preneur->jouerCarte(num));
		system("cls");
	}
}

void Partie::jouer(int num) {
	string demande = tapis.getDemande();
	Carte* c;
	participants[num].afficherPossibilites(demande);
	int choix;
	cout << "Quelle carte voulez-vous jouer ? (Indiquez son numéro) : ";
	cin >> choix;
	cout << endl;
	c = &(participants[num].jouerCarte(choix));
	tapis.recoisCarte(*c);
	system("cls");
	cout << "Vous avez joué " << c->getNom() << endl;
	string tmp;
	cin >> tmp;
	delete c;
	system("cls");
}

void ajouterADefense() {
	cout << "La défense gagne le pli" << endl;
	potDefense.insert(potDefense.begin(), tapis.getTas().begin(), tapis.getTas().end());
	tapis.viderTas();
	string tmp;
	cin >> tmp;
	delete tmp;
}
void ajouterAPreneur(vector<Carte> gain) {
	cout << "Le preneur gagne le pli" << endl;
	potPreneur.insert(potPreneur.begin(), tapis.getTas().begin(), tapis.getTas().end());
	tapis.viderTas();
	string tmp;
	cin >> tmp;
}
void compterPointsDefense() {

}
void compterPointsPreneur() {

}

