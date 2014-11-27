#ifndef CPT2BOUTS_HPP
#define CPT2BOUTS_HPP


#include "ComportementPoints.hpp"

using namespace std;

class Cpt2bouts : ComportementPoints {

	// Objectif de points = 41

public:
	double compterPoints(vector<Carte*> gain, int mise);

};

#endif
