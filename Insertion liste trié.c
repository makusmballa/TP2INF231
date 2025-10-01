#include <stdio.h>
#include <stdlib.h>

// Définition de la cellule
typedef struct cellule {
    int donnee;
    struct cellule* suiv;
} cellule;

typedef cellule* liste;

// Affichage de la liste
void afficher_liste(liste T) {
    liste p = T;
    while (p != NULL) {
        printf("%d -> ", p->donnee);
        p = p->suiv;
    }
    printf("NULL\n");
}

// Insertion en ordre croissant
liste inserer_trie(liste T, int a) {
    liste nouv = (cellule*) malloc(sizeof(cellule));
    nouv->donnee = a;
    nouv->suiv = NULL;

    // Cas 1 : liste vide ou insertion en tête
    if (T == NULL || a <= T->donnee) {
        nouv->suiv = T;
        return nouv;
    }

    // Cas 2 : trouver la bonne place
    liste p = T;
    while (p->suiv != NULL && p->suiv->donnee < a) {
        p = p->suiv;
    }

    // Insertion du nouveau maillon
    nouv->suiv = p->suiv;
    p->suiv = nouv;

    return T;
}

int main() {
    liste T = NULL;
    int n, a, i;

    printf("Entrez le nombre d'elements initiaux : ");
    scanf("%d", &n);

    // Construction de la liste triée
    for (i = 0; i < n; i++) {
        printf("Entrez la donnee %d : ", i+1);
        scanf("%d", &a);
        T = inserer_trie(T, a);  // insertion automatique triée
    }

    printf("\nListe triee :\n");
    afficher_liste(T);

    // Exemple : insérer encore une nouvelle valeur
    printf("\nEntrez une nouvelle valeur a inserer : ");
    scanf("%d", &a);
    T = inserer_trie(T, a);

    printf("\nListe apres insertion :\n");
    afficher_liste(T);

    return 0;
}
