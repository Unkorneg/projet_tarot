#ifndef COULEUR_HPP
#define COULEUR_HPP

#include <string>

using namespace std;

class Couleur : public Carte
{
public:
	Couleur(string val, double pts, int rg, string col);
	~Couleur();
	string getCouleur();
	void setCouleur();
	string getNom() override;
	
private:
	string couleur;
};

#endif