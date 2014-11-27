#include "Joueur.hpp"

Joueur::Joueur() {
	nom = "";
	mise = 0;
	points = 0;
}

Joueur::Joueur(string name){
	nom = name;
	mise = 0;
	points = 0;
}

Joueur::~Joueur() {
	jeu.clear();
}


void Joueur::setMise(int choix) {
	mise = choix;
}

int Joueur::getMise(){
	return mise;
}

vector<Carte*> Joueur::getJeu() {
	return jeu;
}

vector<Carte*>::iterator Joueur::getIterator() {
	return it;
}

int Joueur::getPoints() {
	return points;
}

void Joueur::ajouterCarte(Carte* c) {

	// insère la carte dans la main de façon à ce que le jeu soit trié

	if (jeu.end()==jeu.begin()) {
        jeu.push_back(c);
	}
	else {
        it = jeu.begin();
        while (((*it)->plusPetit(*c)) && (it != jeu.end())) {
            ++it;
        }
        jeu.emplace(it,c);
	}

}

Carte* Joueur::jouerCarte(int num) {

	Carte* rep = jeu[num];
	jeu.erase(jeu.begin()+num);
	return rep;
}

Carte* Joueur::getCarte(int num) {

	return jeu[num];
}

void Joueur::ajouterPoints(int nbPts) {
	points += nbPts;
}

void Joueur::afficherJeu() {
	int i = 1;
	for(it=jeu.begin();it!=jeu.end();++it) {
		cout << i << ". " << (*it)->getNom() << endl;
		++i;
	}
}

void Joueur::compterBouts() {
	int cpt=0;
	for(it=jeu.begin();it!=jeu.end();++it) {
		if ((*it)->estBout())
			++cpt;
	}
}

void Joueur::afficherPossibilites() {
    int i=1;
    bool joueCouleur = false;
    for(it=jeu.begin();it!=jeu.end();++it) {
        if ((*it)->getCouleur()==demande) {
            cout << i << ". " << (*it)->getNom() << endl;
            joueCouleur=true;
        }
        else if(joueCouleur==false && (*it)->getCouleur()=="Atout" ) {
            cout << i << ". " << (*it)->getNom() << endl;
        }
		//else afficherJeu();
        ++i;

	}

}

void Joueur::gagnerPli(vector<Carte*> gain) {
	pli = gain;
}

double Joueur::compterPoints() {
	points = -3*(compPts->compterPoints(pli, mise));
}

void Joueur::afficherMisePossible(int miseMax) {
	string tabMises {"Passe";"Prend";"Garde";"Garde Sans";"Garde Contre"};
	cout << "0. " << tabMise[0];
	for(int i=miseMax+1; i<5; i++) {
		cout << tabMise[i] << endl;
	}
}

/*
int main() {
	Joueur* j1 = new Joueur("David");
    cout << "Joueur initialisé\n";

	Carte* c2 = new Carte("Dame", "Pique", 1, 3);
	Carte* c4 = new Carte("As", "Carreau", 1, 4);
    Carte* c1 = new Carte("Valet", "Coeur", 1, 1);
    Carte* c5 = new Carte("21", "Atout", 1, 5);
    Carte* c3 = new Carte("Roi", "Coeur", 1, 2);
    cout << "Cartes initialisées\n";

    j1->ajouterCarte(c5);
    cout << "c5 inséré\n";
    j1->ajouterCarte(c1);
    cout << "c1 inséré\n";
    j1->ajouterCarte(c2);
    cout << "c2 inséré\n";
    j1->ajouterCarte(c3);
    cout << "c3 inséré\n";
    j1->ajouterCarte(c4);
    cout << "c4 inséré\n";


    cout << "Cartes ajoutées\n";

	//j1->afficherJeu();


	j1->afficherPossibilites("Trefle");

}*/
