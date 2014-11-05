void echange(Carte& ct)//echanger deux carte 
{ 
Carte perm=*this;// creer une carte perm pour enregistrer la premier carte 
valeur=ct.valeur;// Echange de valeur
couleur=ct.couleur;// Echange de valeur
ct=perm;//en recopie la 2 carte dans la premier 
} 
Vector triMain(Vector<Atout> A,Vector<Couleur> C){
Vector<Carte> Main;
for(int i=0;i<C.size();i++){
    for(int j=i+1;j<A.size();j++) 
{ 
if(C[i].getValeur()>->C[j].getValeur()) 
{ 
// permuter les deux carte 
C[i].echange(C[j]); 
} 
}
}
Main.splice(0, C);
for(int i=0;i<A.size();i++){
    for(int j=i+1;j<A.size();j++) 
{ 
if(A[i].getvaleur()>->A[j].getvaleur()) 
{ 
// permuter les deux carte 
A[i].echange(A[j]); 
} 
}
}
Main.splice(A.size(), A);
return Main;
}