#include <stdio.h>
#include "liste.h"

int main() {
    int base, a;
    int taille_nombre;
    seau **tableau_seau = NULL;

    base = choix_base();

    tableau_seau = creation_tableau(base);

    choix_parametre(&taille_nombre);

    tableau_seau = initialisation_tableau(base, tableau_seau, taille_nombre);

    for(a = 0; a < taille_nombre;a++){
        attribution_ordre(tableau_seau, base, a, taille_nombre);
        tableau_seau = changement_ordre(tableau_seau, base);
        printf("\nEtape %d :\n", a + 1);
        afficher_tableau(base, tableau_seau, taille_nombre);
    }

    affiche_liste_finale(base, tableau_seau, taille_nombre);

    return 0;

}