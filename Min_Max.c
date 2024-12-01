Noeud *minimum(Noeud *a){
  Noeud *tmp;
  if(a==NULL){
    return NULL;
  }
  tmp=a;
  while(tmp->gauche!=NULL){
    tmp=tmp->gauche;
  }
  return tmp;
}

Noeud *maximum(Noeud *a){
  Noeud *tmp;
  if(a==NULL){
    return NULL;
  }
  tmp=a;
  while(tmp->droit!=NULL){
    tmp=tmp->droit;
  }
  return tmp;
}
