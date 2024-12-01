void supprimerArbre(Noeud *a){
  if(a==NULL){
    return;//arbre vide
  }
  supprimerArbre(a->gauche);//sup sous arbre gauche
  supprimerArbre(a->droit);//sup sous arbre droit
  free(a);//libere le noeud actuel
}

//copier un arbre
Noeud *copierArbre(Noeud *a){
  if(a==NULL){
    return NULL;
  }
  //cree un nouveau noeud avec la meme valeur
  Noeud* copie = createNoeud(a->valeur);
  //copier recursivement les sous arbres gauches et droits
  copie->gauche = copierArbre(a->gauche);
  copie->droit = copierArbre(a->droit);
  return copie;
}

//supprimer le min
Noeud *supMin(Noeud*a){
  if(a==NULL){
    return NULL;
  }
  if(a->gauche == NULL){
    //pas de sous arbre gauche
    Noeud*tmp =a->droit;//sauvegarde du sous arbre droit
    free(a);
    return tmp;
  }
  //continuer de chercher dans le sous arbre gauche
  a->gauche = supMin(a->gauche);
  return a;
}

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

void afficherInfixe(Noeud *a){
  if(a==NULL){
    return;//rien a afficher
  }
  afficherInfixe(a->gauche);
  printf("%d ",a->valeur);
  afficherInfixe(a->droit);
}
