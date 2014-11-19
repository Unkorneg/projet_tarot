#include <iostream>


#include "Carte.hpp"

 
Carte::Carte(string val, double pts, int rg) {
	valeur = val;
	points = pts;
	rang = rg;
	//this->proprietaire = NULL;
}

Carte::~Carte() {
	
}

string Carte::getValeur() {
	return valeur;
}
double Carte::getPoints() {
	return points;
}
int Carte::getRang() {
	return rang;
}
bool Carte::estPlusPetitQue(Carte& c) {
	return (rang < c.rang);
}
void Carte::setValeur(string val) {
	valeur = val;
}
void Carte::setPoints(double pts) {
	points = pts;
}
void Carte::setRang(int rg) {
	rang = rg;
}
string Carte::getNom() {
	return "";
}

bool operator<(Carte &first, Carte &second) {
	return (first.getRang() < second.getRang());
}

int main() {
	Carte* cc = new Carte("Roi", 2.5, 7);
	
	cout << cc->getValeur() << "\n"; // Roi
	cout << cc->getRang() << "\n";
	cout << cc->getPoints() << "\n";
	
	Carte* c1 = new Carte("Dame", 1.5, 6);
	
	cout << c1->estPlusPetitQue(*cc) << '\n';
	
	if(*c1<*cc){
		cout <<"Ok"<<'\n';
	}
	
	
	return 0;
}