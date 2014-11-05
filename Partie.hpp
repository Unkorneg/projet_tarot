#ifndef PARTIE_HPP
#define PARTIE_HPP



class Partie {
	
private:
	vector<Joueur> participants;// Ne change pas à chaque manche
	Tapis tapis;
	vector<Equipe> equipes; //Change à chaque manche
	int nbManches;
	vector<Carte> paquet;
	
public:
	Partie();
	void ajouterJoueur(Joueur nve);
	void setEquipe(Joueur seul);
	void distribuerCartes();
	void ramasserCartes();
	void lancerPartie();
};

#endif