#ifndef DECORATOR_HPP
#define DECORATOR_HPP

class Decorator : Resultat {

protected:
	Resultat* _result;
	double _prime;
public:
	Decorator(Resultat result, double prime);
	virtual double compterPoints() override ;
	
};

#endif