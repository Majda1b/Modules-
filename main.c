#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fournisseur {
    int code;
    char nom[50];
    char adresse[100];
    char nationalite[50];
};

struct Medicament {
    char nom[50];
    char code[20];
    char categorie[20];
    float prix;
    int quantite;
    struct Fournisseur fournisseur;
    struct Medicament* next;
};

void afficherDetailsStock(struct Medicament* stock);
void afficherMoinsMedicaments(struct Medicament* stock);
void afficherMedicamentsFournisseur(struct Medicament* stock, char nomFournisseur[]);

int main() {
    int choix;
    struct Medicament* stock = NULL;

    do {
        printf("MENU GESTION DES LIVRES:\n");
        printf("1. Afficher le détail du stock de la pharmacie\n");
        printf("2. Afficher les médicaments de la catégorie ayant le moins de médicaments de la pharmacie\n");
        printf("3. Afficher médicaments d'un fournisseur donné\n")
        printf("6. Quitter le programme\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherDetailsStock(stock);
                break;
            case 2:
                afficherMoinsMedicaments(stock);
                break;
            case 3:
                char nomFournisseur[50];
                printf("Entrez le nom du fournisseur : ");
                scanf("%s", nomFournisseur);
                afficherMedicamentsFournisseur(stock, nomFournisseur);
                break;
 
            case 6:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);
    struct Medicament* current = stock;
    struct Medicament* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
