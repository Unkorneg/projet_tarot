#ifndef CPT1BOUT_HPP
#define CPT1BOUT_HPP


#include "ComportementPoints.hpp"

using namespace std;

class Cpt1bout : ComportementPoints {
	
	// Objectif de points = 51
	
public:
	double compterPoints(vector<Carte*> gain, int mise);

};

#endif