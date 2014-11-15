#ifndef ATOUT_HPP
#define ATOUT_HPP

#include <string>

using namespace std;

class Atout : public Carte
{
public:
	Atout(string val, double pts, int rg); // Constructeur
	~Atout(); // Destructeur
	bool estBout();

private:
	bool bout;
};

#endif