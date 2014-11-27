#include "FacadePartie.hpp"
#include <ctime>
#include <cstdlib>

FacadePartie::FacadePartie() {


	tapis = new Tapis();

    paquet.reserve(78*sizeof(Carte));

	string TabValeur[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Cavalier", "Dame", "Roi"};
	double TabPoints[] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.5, 2.5, 3.5, 4.5};
	string TabCouleur[] = {"Trèfle", "Carreau", "Coeur", "Pique"};
	string TabAtout[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "Excuse"};
	double TabPtsAtouts[] = {4.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 4.5, 4.5};

    cout << "Tableaux OK\n";

    Carte* carte;

	int i = 0;
    int rg=1;
	
	// Création des cartes couleurs
	for (int coul=0; coul<4; coul++)
	{
        cout << "Couleur " << TabCouleur[coul] << endl;
		for (int val=0; val<14; val++)
		{
		    cout << "Carte " << rg << endl;
			carte = new Carte(TabValeur[val], TabCouleur[coul], TabPoints[val], rg);
			++i;
			++rg;
			paquet.push_back(carte);
		}
	}

	i = 0;
	
	// Création des cartes d'atout
	for(int att = 0; att< 22; ++att) {
		cout << "Carte " << rg << endl;
		carte = new Carte(TabAtout[att], "Atout", TabPtsAtouts[att], rg);
		++i;
		++rg;
		paquet.push_back(carte);
	}
	
	Joueur* jo;
	
	// Création des 4 joueur
	for(int n=0; n<4; ++n) {
		jo = new Joueur();
		jo->setTapis(tapis)
		participants.push_back(jo);
	}
}

void FacadePartie::distribuerCartes() {
	int gMax = 72;
	for(int j=0; j<4; ++j) {
		for (int i=0; i<18; ++i){
			int ind = rand()%gMax;
			participants[j].ajouterCarte(paquet[ind]);
			gMax -= 1;
		}
	}
	for(int k =0; k<6; ++k) {
		tapis->recevoirCarte(paquet[k]);
		paquet.erase(paquet.begin()+k);
	}
}

void annoncerMise() {
	for(Joueur* j : participants) {
		cout << j->getNom() << ", que voulez-vous faire ?" << endl;
		j->afficherMisePossible(miseMax);
		cin >> mise;
		miseMax = mise;
		system("cls");
	}
}

void FacadePartie::ajouterJoueur(string nom) {
	//
}

void FacadePartie::donnerChien() {
	
	cout << "Le chien contient : " << endl;
	tapis->afficherChien();
	vector<Carte*> chien = tapis->donnerChien();
	if(miseMax<5) {
		for(it=chien.begin();it!=chien.end();++it) {
   			preneur->ajouterCarte(*it);
		}
	}
	else {
		for(it=chien.begin();it!=chien.end();++it) {
			potDefense.push_back(*it);
		}
	}
	string tmp;
	cin >> tmp;
	system("cls");
}

void FacadePartie::constituerChien() {
	int num;
	for(int i=0;i<6;++i) {
		preneur->afficherJeu();
		cout << "Quelle carte souhaitez-vous mettre dans le chien ? (Reste "<< 6-i << " cartes." << endl;
		cin >> num;
		tapis->ajouterChien(preneur->jouerCarte(num));
		system("cls");
	}
}

void FacadePartie::jouer(int num) {
	Carte* c;
	participants[num].afficherPossibilites();
	int choix;
	cout << "Quelle carte voulez-vous jouer ? (Indiquez son numéro) : ";
	cin >> choix;
	cout << endl;
	c = (participants[num].jouerCarte(choix));
	if (c->getValeur()=="Excuse") {
		excuseJouee = true;
	}
	tapis->recevoirCarte(c);
	system("cls");
	cout << "Vous avez joué " << c->getNom() << endl;
	string tmp;
	cin >> tmp;
	delete c;
	system("cls");
}

void FacadePartie::finDeManche() {
	if ((tapis->getGagnant())==preneur) {
		cout << "Le preneur gagne le pli" << endl;
		preneur->gagnerPli(tapis->getTas());
	}
	else {
		cout << "La défense gagne le pli" << endl;
		potDefense.insert(potDefense.begin(), tapis->getTas().begin(), tapis->getTas().end());
	}
	tapis->viderTas();
	string tmp;
	cin >> tmp;
}


void FacadePartie::compterPoints() {
	preneur->compterPoints();


}

/*
int main() {

    cout << "INITIALISATION DE LA PARTIE\n";

    FacadePartie* p = new FacadePartie();

    Carte* c1 = new Carte("2", "Coeur", 1, 1);
    Carte* c2 = new Carte("4", "Coeur", 1, 4);
    Carte* c3 = new Carte("19", "Coeur", 1, 13);
    Carte* c4 = new Carte("Roi", "Coeur", 1, 18);


    Tapis tapis;

    tapis.recevoirCarte(c1);
    cout << tapis.getDemande() << endl;
    tapis.recevoirCarte(c3);
    tapis.recevoirCarte(c4);
    tapis.recevoirCarte(c2);
    cout << tapis.getDemande() << endl;

    tapis.afficherTas();

    cout << tapis.plusGrande()->getNom() << endl;

    tapis.ajouterChien(c1);
    tapis.ajouterChien(c3);
    tapis.ajouterChien(c4);
    tapis.ajouterChien(c2);


}*/

