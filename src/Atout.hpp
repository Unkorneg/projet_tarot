#ifndef ATOUT_HPP
#define ATOUT_HPP

#include <string>
#include <iostream>

#include "Carte.hpp"

using namespace std;

class Atout : public Carte
{
public:
	Atout(string val, double pts, int rg); // Constructeur
	~Atout(); // Destructeur
	bool estBout();
	string getNom() override;

private:
	bool bout;
};

#endif