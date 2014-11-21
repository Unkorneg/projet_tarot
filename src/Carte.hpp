#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>

using namespace std;

class Carte
{
public:
	Carte(string val, string coul, double pts, int rg);
	~Carte();
	string getValeur();
	double getPoints();
	int getRang() const ;
	bool estPlusPetitQue(Carte& c);
	void setValeur(string val);
	void setPoints(double pts);
	void setRang(int rg);
	//Joueur getProprio();
	//void setProprio(Joueur prop);
	string getNom() const ;
	
	bool estBout();
	string getCouleur();
	void setCouleur(string col);
	
private:
	string valeur; // valeur de la carte (1 à 21 pour les Atouts, 1 à 10 pour les Couleurs + Valet, Cavalier, Dame, Roi)
	string couleur; // Atout, Trèfle, Carreau, Coeur, Pique
	double points; // points de la carte
	int rang; // rang pour le tri
	bool bout; // true si la carte est un bout
	//Joueur proprietaire; // joueur proprietaire de la carte
	 
};
/*
bool operator<(Carte const &first, Carte const &second) {
	return (first.getRang() < second.getRang());
}

bool operator==(Carte const &first, Carte const &second) {
	return (first.getRang() == second.getRang());
}

bool operator>(Carte const &first, Carte const &second) {
	return (first.getRang() > second.getRang());
}*/

#endif