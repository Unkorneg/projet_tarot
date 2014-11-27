#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Tapis.hpp"

class Observer {
	protected:
		Tapis* tapis;
		string demande;
		Carte* gagnante;
	public:
		virtual void actualiser(string d);
		virtual void setTapis(Tapis* t);
};

#endif
