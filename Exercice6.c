#include <stdio.h>
#include <stdlib.h>

#define TAILLE 15

typedef struct noeud {
    int valeur;
    struct noeud* gauche;
    struct noeud* droit;
} Noeud;

Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = valeur;
    nouveau->gauche = NULL;
    nouveau->droit = NULL;
    return nouveau;
}

void insererABR(Noeud** racine, int valeur) {
    if (*racine == NULL) {
        *racine = creerNoeud(valeur);
    } else if (valeur < (*racine)->valeur) {
        insererABR(&(*racine)->gauche, valeur);
    } else if (valeur > (*racine)->valeur) {
        insererABR(&(*racine)->droit, valeur);
    }
}

Noeud* construireABR(int tableau[], int taille) {
    Noeud* arbre = NULL;
    for (int i = 0; i < taille; i++) {
        insererABR(&arbre, tableau[i]);
    }
    return arbre;
}

void afficherABR(Noeud* racine, int tableau[], int* index) {
    if (racine != NULL) {
        afficherABR(racine->gauche, tableau, index);
        tableau[*index] = racine->valeur;
        (*index)++;
        afficherABR(racine->droit, tableau, index);
    }
}

void trierTableau(int tableau[], int taille) {
    Noeud* arbre = construireABR(tableau, taille);

    int index = 0;
    afficherABR(arbre, tableau, &index);  // Remplir le tableau avec les valeurs triées

    printf("Tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main() {
    int tableau[TAILLE];

    printf("Veuillez entrer 15 valeurs différentes :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("Entrez la valeur %d: ", i + 1);
        scanf("%d", &tableau[i]);
    }

    trierTableau(tableau, TAILLE);

    return 0;
}

