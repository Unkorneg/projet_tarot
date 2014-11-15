#include "Carte.hpp"
 
Carte::Carte(string val, double pts, int rg) {
	valeur = val;
	points = pts;
	rang = rg;
	//proprietaire = NULL;
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
bool Carte::estPlusPetitQue(Carte c) {
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