#ifndef ATOUT_HPP
#define ATOUT_HPP

class Atout : public Carte
{
    public:
	int getHauteur();
	int getValeur();
	void setHauteur(int);
	void setValeur(int);
	void toString();

};

#endif