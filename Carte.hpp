#ifndef CARTE_HPP
#define CARTE_HPP

class Carte
{
    public:
        virtual ~Carte() {}
        virtual int getValeur() = 0;
		virtual int getHauteur() = 0;
		virtual void setValeur() = 0;
		virtual void setHauteur() = 0;
	private:
	int valeur,hauteur;
};

#endif