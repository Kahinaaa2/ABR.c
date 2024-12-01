typedef struct noeud{
    int valeur;
    struct noeud* gauche;
    struct noeud* droit;
}Noeud;

Noeud *Min(Noeud *a){
    while(a->gauche != NULL){
        a=a->gauche;
    }
    return a;
}

Noeud *Max(Noeud *a){
    while(a->droit != NULL){
        a=a->droit;
    }
    return a;
}

//fonction de suppression
Noeud *supNoeud(Noeud *a, int e){
    if(a==NULL){
        //si l'arbre est vide rien a sup
        return a;
    }
    if(e<a->valeur){
        //l'element a supp est dans le sous arbre gauche
        a->gauche = supNoeud(a->gauche, e);
    }
    else if(e>a->valeur){
        //l'element a supp est dans le sous arbre droit
        a->droit = supNoeud(a->droit, e);
    }
    else{
        //cas ou on trouve le noeud a supp
        if(a->gauche == NULL && a->droit == NULL){
            //le noeud a sup est une feuille
            free(a);
            a=NULL;
            return a;
        }
        else if(a->gauche == NULL){
            //le noeud a sup a un seul fils droit
            Noeud *tmp = a;
            a=a->droit;
            free(a);
            return tmp;
        }
        else if(a->droit==NULL){
            //le neoud a sup a un seul fils gauche
            Noeud *tmp = a;
            a=a->gauche;
            free(a);
            return tmp;
        }
        else{
            //le neoud a deux enfants
            Noeud*min = Min(a->droit);//trouver le minimum du sous abre droit
            a->valeur = min->valeur;
            a->droit = supNoeud(a->droit, min->valeur);
        }
    }
    return a;
}
