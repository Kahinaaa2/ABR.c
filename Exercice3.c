#include <stdio.h>
#include <stdlib.h>

//test des fonctions de recherches
typedef struct noeud{
  int valeur;
  struct noeud*gauche;
  struct noeud*droit;
}Noeud;

Noeud*creerNoeud(int v){
  Noeud *n = malloc(sizeof(Noeud));
  if(n==NULL){
    exit(1);
  }
  n->valeur=v;
  n->gauche=NULL;
  n->droit=NULL;
  return n;
}

//fonction pour inserer un element dans un abr
void insertABR(Noeud **a, int e){
  if(*a==NULL){
    *a=creerNoeud(e);
    return;
  }
  if(e < (*a)->valeur){
    insertABR(&(*a)->gauche, e);
  }
  else if(e>(*a)->valeur){
    insertABR(&(*a)->droit,e);
  }
}

//fonction de recherche modifiée pour compter les noeuds parcourus

int rechercheABR(Noeud*a, int e, int*noeudParcourus){
  *noeudParcourus=0;//initialisation du compteur
  Noeud *courant = a; // depart au sommet de l'arbre
  while(courant!=NULL){
    (*noeudParcourus)++;//implementer le compteur a chaque noeud visité
    if(e == courant->valeur){
      return 1;
    }
    else if(e<courant->valeur){
      courant=courant->gauche;//aller a gauche
    }
    else{
      courant=courant->droit;//aller a droite
    }
  }
  //si l'element n'est pas trouvé
  return 0;
}
int parcoursPrefixeRecherche(Noeud* a, int e, int* noeudsParcourus) {
    if (a == NULL) {
        return 0; // L'arbre est vide
    }
    (*noeudsParcourus)++; // Incrémenter le compteur de nœuds parcourus
    if (a->valeur == e) {
        printf("Élément %d trouvé au bout de %d nœuds (parcours préfixe).\n", e, *noeudsParcourus);
        return 1;
    }
    // Rechercher dans le sous-arbre gauche
    if (parcoursPrefixeRecherche(a->gauche, e, noeudsParcourus)) {
        return 1; // Trouvé dans le sous-arbre gauche
    }
    // Rechercher dans le sous-arbre droit
    if (parcoursPrefixeRecherche(a->droit, e, noeudsParcourus)) {
        return 1; // Trouvé dans le sous-arbre droit
    }
    return 0; // L'élément n'est pas dans l'arbre
}
int main() {
    // Construction de l'ABR de l'exercice précédent
    Noeud* a = NULL;
    insertABR(&a, 5);
    insertABR(&a, 3);
    insertABR(&a, 7);
    insertABR(&a, 12);
    insertABR(&a, 4);
    insertABR(&a, 20);

    int noeudsParcourus;

    // Test avec recherche classique modifiée
    printf("=== Recherche avec méthode classique ===\n");
  rechercheABR(a, 10, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

  rechercheABR(a, 20, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

  rechercheABR(a, 22, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

    // Test avec parcours préfixe modifié
    printf("\n=== Recherche avec parcours préfixe ===\n");
    parcoursPrefixeRecherche(a, 10, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

    parcoursPrefixeRecherche(a, 20, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

    parcoursPrefixeRecherche(a, 22, &noeudsParcourus);
    printf("Nombre de nœuds parcourus : %d\n", noeudsParcourus);

    return 0;
}

//fonction de recherche avec parcours préfixe
int recherchePrefixe(Noeud*a, int e, int *noeudParcourus){
  if(a==NULL) {
    return 0;//arbre vide ou fin du parcours
  }
  *noeudParcourus=*noeudParcourus+1;//compter ce neoud comme visité
  if(a->valeur==e){
    return 1;//element trouvé
  }
  if(recherchePrefixe(a->gauche, e, noeudParcourus)){
    return 1;
  }
  if(recherchePrefixe(a->droit, e, noeudParcourus)){
    return 1;
  }
  return 0;
}
