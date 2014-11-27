#ifndef CPT0BOUT_HPP
#define CPT0BOUT_HPP


#include "ComportementPoints.hpp"

using namespace std;

class Cpt0bout : ComportementPoints {

	// Objectif de points = 56

public:
	double compterPoints(vector<Carte*> gain, int mise);

};

#endif
