#include "Tapis.hpp"

Tapis::Tapis() {

}

Tapis::~Tapis() {
	tas.clear();
}

Carte Tapis::plusGrande(){
	Carte C=tas[0];
	for(int i=1;i<4;i++){
		if(tas[i].getValeur()>C.getValeur()) C=tas.get(i);
	}
	return C;
}

void Tapis::recevoirCarte(Carte& c) {
    if(tas.begin()==tas.end()) demande=c->getCouleur();
    tas.push_back(c);
}
vector<Carte> Tapis::getTas() {
	return tas;
}
vector<Carte> Tapis::getChien() {
	return chien;
}
void Tapis::setChien(Carte& c) {
	chien.push_back(c);
}
void Tapis::setDemande(string dem) {
	demande = dem;
}

vector<Carte> Tapis::donnerChien() {
	rep = chien;
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
	for(it=tas.begin();it!=tas.end();++it) {
		cout << i << (*it)->getNom() << endl;
		++i;
	}
}

void ajouterChien(Carte c) {
	chien.push_back(c);
}

int main() {

	Carte* c1 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c2 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c3 = new Carte("Roi", "Coeur", 2.5, 7);
	Carte* c4 = new Carte("Roi", "Coeur", 2.5, 7);
	
	Tapis T=new Tapis();

	T.setTas(c1);
	T.setTas(c2);
	T.setTas(c3):
	T.setTas(c4);

	cout <<T->getTas();
}
