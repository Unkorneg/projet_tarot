#include "Cpt2bouts.hpp"

double Cpt2bouts::compterPoints(vector<Carte*> gain, int mise) {
	double cpt=0;
	for(it=gain.begin();it!=gain.end();++it) {
		cpt += (*it)->getPoints();
	}
	double coef;
	switch(mise) {
		case 1:
			coef=1;
		case 2:
			coef=2;
		case 3:
			coef=4;
		case 4:
			coef=6;
	}

	double res = cpt - 41;
	if (res>=0) {
		// Le preneur a gagné
		return -(res+25);
	}
	else {
		// Le preneur a perdu
		return res+25;
	}
}
