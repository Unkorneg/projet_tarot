#ifndef COMPORTEMENTPOINTS_HPP
#define COMPORTEMENTPOINTS_HPP

using namespace std;

#include <vector>
//#include "Carte.hpp"


class Carte;
class ComportementPoints {

protected:
	vector<Carte*>::iterator it;

public:
	ComportementPoints();
	virtual double compterPoints(vector<Carte*> gain, int mise);

};

#endif
