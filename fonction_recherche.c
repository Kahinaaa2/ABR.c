Noeud *Recherche(Noeud *a, int v){
  if(a==NULL){
    return NULL;//la valeur n'exite pas
  }
  if(v==a->valeur){
    return a;
  }
  else if(v>a->valeur){
    return Recherche(a->droit, v);
  }
  else{
    return Recherche(a->gauche, v);
  } 
}
