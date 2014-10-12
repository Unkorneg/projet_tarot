#include <iostream>
#include <string>

using namespace std;
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
class Atout : public Carte
{
    public:
	int getHauteur();
	int getValeur();
	void setHauteur(int);
	void setValeur(int);
	void toString();

};
int Couleur::getValeur()
        {
            return this->valeur;
        }
int Couleur::getHauteur()
        {
            return this->hauteur;
        }
string Couleur::getCouleur(){
		return this->couleur;
		}
void Couleur::setValeur(int val)
        {
            this.valeur=val;
        }
void Couleur::setHauteur(int haut)
        {
            this.hauteur=haut;
        }
void Couleur::setCouleur(String coul){
		this.couleur=coul;
		}

int Atout::getValeur()
        {
            return this->valeur;
        }
int Atout::getHauteur()
        {
            return this->hauteur;
        }
void Atout::setValeur(int val)
        {
            this.valeur=val;
        }
void Atout::setHauteur(int haut)
        {
            this.hauteur=haut;
        }
void Atout::toString(){
cout << ” hauteur: ” << getHauteur() << “\n Valeur: ” << getValeur() << “\n \n”;
}
