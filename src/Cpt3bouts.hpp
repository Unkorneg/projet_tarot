#ifndef CPT3BOUTS_HPP
#define CPT3BOUTS_HPP


#include "ComportementPoints.hpp"

using namespace std;

class Cpt3bouts : ComportementPoints {

	// Objectif de points = 36

public:
	double compterPoints(vector<Carte*> gain, int mise);

};

#endif
