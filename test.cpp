#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
char *TabValeur[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "valet", "dame", "roi"}; 
char *TabCouleur[] = {"trèfle", "carreau", "coeur", "pique"}; 
// Définir la structure des cartes 
// (on pourrait mettre des chaines directement, ou un autre système ...) 
typedef struct _CARTE_ { 
int valeur; // 0 à 12 pour As à Roi 
int couleur; // 0 à 3 (trefle, carreau coeur et pique) !! 
// On pourrait mettre un enum, mais ce n'est pas l'objet ici 
} CARTE; 
// Le jeu de cartes (en global pour simplifier) 
CARTE Jeu[52]; 
int gMax; // indice de carte maximal (52 au départ) 
  
// Initialisation du jeu 
// En sortie, Jeu[0] vaut As de trefle, Jeu[1] 2 de trefle, ... 
void InitJeu() 
{ 
int val, coul, i;; 

// on le fait très simple, OK ? 
i = 0; 
for (coul=0; coul<=3; coul++) 
{ 
	for (val=0; val<13; val++) 
	{ 
		carte = new Carte();
		paquet.push_back(carte)
		carte.valeur = TabValeur[i];
		carte.couleur = TabCouleur[i]; 
		i++; 
	} 
} 

/* 
avec typedef struct _CARTE_ { 
char carte[32]; 
} CARTE; 

on ferait 
for (i=0; i<52; i++) 
sprintf(Jeu[i].carte, "%s de %s", TabValeur[i%13], TabCouleur[i/13]); */
} 


// Distribuer Cartes 
// Renvoie une carte à la fois 
// En entrée, pCarte pointe sur une structure déjà allouée et en sortie on renvoie le même pointeur (si, si ! Ca peut être utile ...) 
// Pas besoin de mélanger le tableau au départ, ni de vérifier qu'une carte a déjà été distribuée, ... 
CARTE *Distribue(CARTE *pCarte) 
{ 
int indice; 

if (gMax) 
indice = rand()%(gMax); // gMax vaut 51 au départ, puis 50, 49, ... 
else 
indice = 0; 
// on renseigne la carte choisie, prise au hasard 
 *pCarte = Jeu[indice]; 

// On insère la dernière carte du paquet à la place !!! 
Jeu[indice] = Jeu[gMax]; 


// ou si votre compilo n'aime pas les copies de structures 
// pCarte->valeur = Jeu[indice].valeur; 
// pCarte->couleur = Jeu[indice].couleur; 
// 
// Jeu[indice].valeur = Jeu[gMax].valeur; 
// Jeu[indice].couleur = Jeu[gMax].couleur; 

// une carte de moins dans le paquet 
gMax--; 
return pCarte; 
} 
  
int main(int argc, char **argv) 
{ 
int i; 
CARTE Carte; 

srand(time(NULL)); // initialiser le générateur aléatoire 
gMax = 51; 
InitJeu(); 

for (i=0; i<52; i++) 
{ 
Distribue(&Carte); 
printf("%d -- %s de %s\n", i, TabValeur[Carte.valeur], TabCouleur[Carte.couleur]); 
} 
} 
// Le tableau au cours des distributions : 
// Au début on a 
// 
// Jeu[0] = "as de trèfle" 
// Jeu[1] = "2 de trèfle" 
// Jeu[2] = "3 de trèfle" 
// Jeu[3] = "4 de trèfle" 
// ... 
// Jeu[50] = "10 de pique" 
// Jeu[51] = "valet de pique" 
// Jeu[52] = "dame de pique" 
// Jeu[53] = "roi de pique" <<--- gMax 
// 
// supposons qu'on ait tiré le 3 de trèfle la première fois 
// on a 
// Jeu[0] = "as de trèfle" 
// Jeu[1] = "2 de trèfle" 
// Jeu[2] = "roi de pique" <--- remplacement -----------------------+ 
// Jeu[3] = "4 de trèfle" | 
// ... | 
// Jeu[50] = "10 de pique" | 
// Jeu[51] = "valet de pique" | 
// Jeu[52] = "dame de pique" <<--- gMax | 
// Jeu[53] = "roi de pique" <- cette entrée n'est plus accessible --+ 
// 
// si on tire le 10 de pique ensuite 
// on a 
// Jeu[0] = "as de trèfle" 
// Jeu[1] = "2 de trèfle" 
// Jeu[2] = "roi de pique" 
// Jeu[3] = "4 de trèfle" 
// ... 
// Jeu[50] = "dame de pique" <--- remplacement ----------------------+ 
// Jeu[51] = "valet de pique" <<--- gMax | 
// Jeu[52] = "dame de pique" <- cette entrée n'est plus accessible --+ 
// Jeu[53] = "roi de pique" <- cette entrée n'est plus accessible 
// 
/// ainsi de suite ...