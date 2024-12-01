#include<stdio.h>
#include<stdlib.h>

typedef struct noeud {
    int valeur;
    struct noeud* gauche;
    struct noeud* droit;
} Noeud;

Noeud* createNoeud(int v) {
    Noeud* n = malloc(sizeof(Noeud));
    if (n == NULL) {
        exit(1);  // Erreur d'allocation mémoire
    }
    n->valeur = v;
    n->gauche = NULL;
    n->droit = NULL;
    return n;
}

void insertABR(Noeud** a, int e) {
    Noeud* new = createNoeud(e);
    if (new == NULL) {
        exit(2);  // Erreur d'allocation mémoire
    }
    if (*a == NULL) {
        *a = new;  // L'arbre est vide, on insère ici
        return;
    }

    // L'arbre n'est pas vide
    Noeud* tmp = *a;
    while (1) {
        if (new->valeur > tmp->valeur) {
            if (tmp->droit == NULL) {
                tmp->droit = new;
                break;
            } else {
                tmp = tmp->droit;
            }
        } else if (new->valeur < tmp->valeur) {
            if (tmp->gauche == NULL) {
                tmp->gauche = new;
                break;
            } else {
                tmp = tmp->gauche;
            }
        } else {
            // Si la valeur existe déjà, on ne l'insère pas
            break;
        }
    }
}

// Fonction pour afficher l'ABR avec les liens gauche/droit
void afficherABR(Noeud* a, int level) {
    if (a != NULL) {
        // Affichage du sous-arbre droit
        afficherABR(a->droit, level + 1);
        // Affichage de l'élément
        for (int i = 0; i < level; i++) {
            printf("   ");  // Espaces pour le niveau d'indentation
        }
        printf("%d\n", a->valeur);
        // Affichage du sous-arbre gauche
        afficherABR(a->gauche, level + 1);
    }
}

int main() {
    Noeud* arbre = NULL;  // Initialisation de l'ABR vide

    // Insertion des éléments dans l'ABR
    insertABR(&arbre, 10);
    insertABR(&arbre, 3);
    insertABR(&arbre, 5);
    insertABR(&arbre, 15);
    insertABR(&arbre, 20);
    insertABR(&arbre, 12);
    insertABR(&arbre, 7);
    insertABR(&arbre, 45);
    insertABR(&arbre, 9);

    printf("Affichage de l'ABR (avec liens gauche/droit) :\n");
    afficherABR(arbre, 0);
    printf("\n");

    return 0;
}
