#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node *head = NULL, *temp, *courant;
    int n, valeur, elem;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    // Construction de la liste
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeur);
        Node* nouveau = (Node*)malloc(sizeof(Node));
        nouveau->data = valeur;
        nouveau->next = NULL;

        if (head == NULL) {
            head = nouveau;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = nouveau;
        }
    }

    // Affichage initial
    printf("\nListe initiale : ");
    temp = head;
    if (temp == NULL) printf("Liste vide");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Suppression
    printf("\nEntrez l'element a supprimer : ");
    scanf("%d", &elem);

    // Cas suppression en tête
    while (head != NULL && head->data == elem) {
        temp = head;
        head = head->next;
        free(temp);
    }

    // Cas général
    courant = head;
    while (courant != NULL && courant->next != NULL) {
        if (courant->next->data == elem) {
            temp = courant->next;
            courant->next = courant->next->next;
            free(temp);
        } else {
            courant = courant->next;
        }
    }

    // Affichage après suppression
    printf("\nListe apres suppression : ");
    temp = head;
    if (temp == NULL) printf("Liste vide");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
