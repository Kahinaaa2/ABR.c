int estABR(Noeud*a, int min, int max){
  if(a==NULL){
    return 1; // un arbre vide est un arbre ABR
  }
  if(a->valeur<min||a->valeur>max){
    return 0; //pas un abr
  }
  //verifier recurssivement pour les sous arbres gauche et droit
  return estABR(a->gauche, min, a->valeur-1)&&estABR(a->droit, a->valeur+1, max);
}
