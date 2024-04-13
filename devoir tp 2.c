	#include <stdio.h>
#include <stdlib.h>

typedef struct Monome {
    int coefficient;
    int exposant;
    struct Monome *suivant;
} Monome;

typedef struct Polynome {
    Monome *debut;
} Polynome;

Monome *CreerMonome(int coeff, int expo) {
    Monome *nouveauMonome = (Monome *)malloc(sizeof(Monome));
    if (nouveauMonome != NULL) {
        nouveauMonome->coefficient = coeff;
        nouveauMonome->exposant = expo;
        nouveauMonome->suivant = NULL;
    }
    return nouveauMonome;
}

void AjouterDebut(Polynome *poly, Monome *monome) {
    monome->suivant = poly->debut;
    poly->debut = monome;
}

void AjouterFin(Polynome *poly, Monome *monome) {
    if (poly->debut == NULL) {
        poly->debut = monome;
    } else {
        Monome *ptr = poly->debut;
        while (ptr->suivant != NULL) {
            ptr = ptr->suivant;
        }
        ptr->suivant = monome;
    }
}

void AjouterPosition(Polynome *poly, Monome *monome, int position) {
    if (position == 0) {
        AjouterDebut(poly, monome);
    } else {
        Monome *ptr = poly->debut;
        int i = 0;
        while (ptr != NULL && i < position - 1) {
            ptr = ptr->suivant;
            i++;
        }
        if (ptr != NULL) {
            monome->suivant = ptr->suivant;
            ptr->suivant = monome;
        }
    }
}

void AfficherPolynome(Polynome *poly) {
    Monome *ptr = poly->debut;
    while (ptr != NULL) {
        printf("%dX^%d", ptr->coefficient, ptr->exposant);
        if (ptr->suivant != NULL) {
            printf(" + ");
        }
        ptr = ptr->suivant;
    }
    printf("\n");
}

int PolynomesEgaux(Polynome *poly1, Polynome *poly2) {
    Monome *ptr1 = poly1->debut;
    Monome *ptr2 = poly2->debut;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->coefficient != ptr2->coefficient || ptr1->exposant != ptr2->exposant) {
            return 0;
        }
        ptr1 = ptr1->suivant;
        ptr2 = ptr2->suivant;
    }
    if (ptr1 == NULL && ptr2 == NULL) {
        return 1;
    }
    return 0;
}

void SupprimerDebut(Polynome *poly) {
    if (poly->debut != NULL) {
        Monome *temp = poly->debut;
        poly->debut = poly->debut->suivant;
        free(temp);
    }
}

void SupprimerFin(Polynome *poly) {
    if (poly->debut != NULL) {
        if (poly->debut->suivant == NULL) {
            free(poly->debut);
            poly->debut = NULL;
        } else {
            Monome *ptr = poly->debut;
            while (ptr->suivant->suivant != NULL) {
                ptr = ptr->suivant;
            }
            free(ptr->suivant);
            ptr->suivant = NULL;
        }
    }
}

void SupprimerPosition(Polynome *poly, int position) {
    if (position == 0) {
        SupprimerDebut(poly);
    } else {
        Monome *ptr = poly->debut;
        int i = 0;
        while (ptr != NULL && i < position - 1) {
            ptr = ptr->suivant;
            i++;
        }
        if (ptr != NULL && ptr->suivant != NULL) {
            Monome *temp = ptr->suivant;
            ptr->suivant = ptr->suivant->suivant;
            free(temp);
        }
    }
}

int AppartenanceMonome(Polynome *poly, int coeff, int expo) {
    Monome *ptr = poly->debut;
    while (ptr != NULL) {
        if (ptr->coefficient == coeff && ptr->exposant == expo) {
            return 1;
        }
        ptr = ptr->suivant;
    }
    return 0;
}

int main() {
    Polynome *poly1 = (Polynome *)malloc(sizeof(Polynome));
    poly1->debut = NULL;

    Monome *monome1 = CreerMonome(3, 3);
    Monome *monome2 = CreerMonome(5, 2);
    Monome *monome3 = CreerMonome(1, 1);

    AjouterFin(poly1, monome1);
    AjouterFin(poly1, monome2);
    AjouterFin(poly1, monome3);

    AfficherPolynome(poly1);

    Polynome *poly2 = (Polynome *)malloc(sizeof(Polynome));
    poly2->debut = NULL;

    Monome *monome4 = CreerMonome(3, 3);
    Monome *monome5 = CreerMonome(5, 2);
    Monome *monome6 = CreerMonome(1, 1);

    AjouterFin(poly2, monome4);
    AjouterFin(poly2, monome5);
    AjouterFin(poly2, monome6);

    AfficherPolynome(poly2);

    printf("Les polynomes sont-ils egaux ? : %d\n", PolynomesEgaux(poly1, poly2));

    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

