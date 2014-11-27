#include "Tapis.hpp"

Tapis::Tapis() {

}

Tapis::~Tapis() {
	tas.clear();
}

Carte* Tapis::plusGrande(){
	return gagnante;
}

void Tapis::recevoirCarte(Carte* c) {
    if(tas.begin()==tas.end()) {
    	demande = c->getCouleur();
		gagnante = c;
		notifierObs();
    } 
    tas.push_back(c);
	if((c->getCouleur() == gagnante->getCouleur()) || (c->getCouleur == "Atout") ) && (c->getRang()>gagnante->getRang()) {
		gagnante = c;
	}
}
vector<Carte*> Tapis::getTas() {
	return tas;
}
vector<Carte*> Tapis::getChien() {
	return chien;
}
void Tapis::ajouterChien(Carte* c) {
	chien.push_back(c);
}
void Tapis::setDemande(string dem) {
	demande = dem;
}

vector<Carte*> Tapis::donnerChien() {
	vector<Carte*> rep = chien;
	chien.clear();
	return rep;
}

void Tapis::viderTas() {
	tas.clear();
}

string Tapis::getDemande() {
	return demande;
}

void Tapis::afficherChien() {
	int i=1;
	for(it=chien.begin();it!=chien.end();++it) {
		cout << i << (*it)->getNom() << endl;
		++i;
	}
}

void Tapis::afficherTas() {
    for(it=tas.begin();it!=tas.end();++it) {
        cout << (*it)->getNom() << endl;
    }
}

void Tapis::setObserver(Joueur* j) {
	observers.push_back(j);
}
void Tapis::notifierObs() {
	for(itj=observers.begin();itj!=observers.end();++itj) {
		(*itj)->actualiser(demande);
	}
}

/*
int main() {

	Carte* c1 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c2 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c3 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c4 = new Carte("Roi", "Coeur", 2.5, 7);

	Tapis* T=new Tapis();

	T->recevoirCarte(c1);
	T->recevoirCarte(c2);
	T->recevoirCarte(c3);
	T->recevoirCarte(c4);

	T->afficherTas();
}*/
