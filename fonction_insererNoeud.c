//insertion
typedef struct Noeud{
    int valeur;
    struct Noeud *droit;
    struct Noeud *gauche;
}Noeud;

Noeud *createNoeud(int v){
  Noeud *new=malloc(sizeof(Noeud));
  if(new==NULL){
    exit(1);
  }
  new->valeur = v;
  new->droit = NULL;
  new->gauche =NULL;
  return new;
}

void insertNewNode(Noeud **a, int val){
  Noeud*new=createNoeud(val);
  if(*a==NULL){
  //arbre vide
    *a=new;
    return;
  }
  //arbre non vide
  Noeud *tmp;
  tmp=*a;
  while(1){
    //boucle infinie
    if(new->valeur > tmp->valeur){
      if(tmp->droit==NULL){
        tmp->droit=new;
        break;
      }
      else{
        tmp=tmp->droit;
      }
    }

    else{
      if(tmp->gauche==NULL){
        tmp->gauche=new;
        break;
      }
      else{
        tmp=tmp->gauche;
      }
    }
  }
}
