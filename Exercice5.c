#include <stdio.h>
#include <stdlib.h>

// récuperation de elements de l'arbre binaire
// nous allons utilisé le parcours infixe(gauche, racine,droite) pour collecter
// les valeurs dans un tableau
typedef struct noeud {
  int valeur;
  struct noeud *gauche;
  struct noeud *droit;
} Noeud;

void recupererElements(Noeud *a, int *tab, int *i) {
  if (a == NULL) {
    return;
  }
  // parcours infixe pour recuperer les elements
  recupererElements(a->gauche, tab, i);
  tab[*i] = a->valeur; // ajouter la valeur dans le tableau
  i++;
  recupererElements(a->droit, tab, i);
}
Noeud *creerNoeud(int v) {
  Noeud *n = malloc(sizeof(Noeud));
  if (n == NULL) {
    exit(1);
  }
  n->valeur = v;
  n->gauche = NULL;
  n->droit = NULL;
  return n;
}
// inserer les elements dans un ABR
void insertABR(Noeud **a, int e) {
  if (*a == NULL) {
    *a = creerNoeud(e);
    return;
  }
  if (e < (*a)->valeur) {
    insertABR(&(*a)->gauche, e);
  } else if (e > (*a)->valeur) {
    insertABR(&(*a)->droit, e);
  }
}

Noeud *construireABR(int *tab, int taille) {
  Noeud *abr = NULL; // abr initialement vide
  for (int i = 0; i < taille; i++) {
    insertABR(&abr, tab[i]); // inserer chaque element dans l'ABR
  }
  return abr;
}
Noeud *transformerEnABR(Noeud *arbreBinaire) {
  if (arbreBinaire == NULL) {
    return NULL;
  }
  // etape1: Recuperer les elements de l'arbre binaire
  int tableau[100];
  int index = 0;
  recupererElements(arbreBinaire, tableau, &index);
  return construireABR(tableau, index);
}

// Fonction pour afficher un ABR avec un parcours infixe
void afficherABR(Noeud *arbre) {
  if (arbre == NULL) {
    return; // Si l'arbre est vide, il n'y a rien à afficher
  }

  // Parcourir d'abord le sous-arbre gauche
  afficherABR(arbre->gauche);

  // Afficher la valeur du noeud actuel
  printf("%d ", arbre->valeur);

  // Parcourir ensuite le sous-arbre droit
  afficherABR(arbre->droit);
}

int main() {
  // Création d'un arbre binaire simple
  Noeud *arbreBinaire = NULL;
  arbreBinaire = creerNoeud(5);
  arbreBinaire->gauche = creerNoeud(10);
  arbreBinaire->droit = creerNoeud(3);
  arbreBinaire->gauche->gauche = creerNoeud(4);
  arbreBinaire->gauche->droit = creerNoeud(8);
  arbreBinaire->droit->droit = creerNoeud(2);

  // Affichage de l'arbre binaire
  printf("Arbre Binaire (parcours infixe) :\n");
  afficherABR(arbreBinaire);
  printf("\n");

  // Transformation de l'arbre binaire en ABR
  Noeud *abr = transformerEnABR(arbreBinaire);

  // Affichage de l'ABR
  printf("ABR (parcours infixe) :\n");
  afficherABR(abr);
  printf("\n");

  return 0;
}
