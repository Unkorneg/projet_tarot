#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>

using namespace std;

class Carte
{
public:
	Carte(string val, double pts, int rg);
	~Carte();
	string getValeur();
	double getPoints();
	int getRang();
	bool estPlusPetitQue(Carte& c);
	void setValeur(string val);
	void setPoints(double pts);
	void setRang(int rg);
	//Joueur getProprio();
	//void setProprio(Joueur prop);
	virtual string getNom();
	
protected:
	string valeur; // valeur de la carte (1 à 21 pour les Atouts, 1 à 10 pour les Couleurs + Valet, Cavalier, Dame, Roi)
	double points; // points de la carte
	int rang; // rang pour le tri
	//Joueur proprietaire; // joueur proprietaire de la carte
	 
};


#endif