#ifndef COULEUR_HPP
#define COULEUR_HPP

class Couleur : public Carte
{
    public:
	int getHauteur();
	int getCouleur();
	string getValeur();
	void setHauteur(int haut);
	void setValeur(int val);
	void setCouleur(string coul);

	private:
	string couleur;
};

#endif