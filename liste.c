
#include "liste.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int choix_base(){
    int b;
    printf("Veuillez saisir une base comprise entre 2 et 16 :\n");
    scanf("%d", &b);
    while (b > 16 || b < 2){
        printf("La base selectionnee est incorret !\nVeuillez saisir une base comprise entre 2 et 16 :\n");
        fflush(stdin);
        scanf("%d", &b);
    }
    return b;
}

void choix_parametre(int *taille_nombre){
    do{
        printf("Veuillez indiquer combien souhaitez vous qu'il y ait de chiffre par nombre, choisisissez dans l'intervalle ]0;10] : \n");
        fflush(stdin);
        scanf("%d", &(*taille_nombre));
    }while(*taille_nombre > 10 || *taille_nombre <= 0);
}

int conversion_caractere_entier(char caractere){
    int temp = -1;

    if( caractere > 47 && caractere < 58) {
        temp = caractere - '0';
    } else if( caractere > 96 && caractere < 103){
        temp = caractere - 'a' + 10;
    } else if ( caractere > 64 && caractere < 71 ) {
        temp = caractere - 'A' + 10;
    } else {
        temp = -1;
    }
    return temp;
}

char conversion_chiffre(int b){
    int chiffre, verif;
    char result;
    do{
        printf("Veuillez saisir une valeure numerique comprise entre 0 et %d :\n", b);
        fflush(stdin);
        scanf("%d", &chiffre);
        if(chiffre >= b || chiffre < 0){
            printf("Veuillez saisir un chiffre appartenant a la base %d\n", b);
            verif = 1;
        }else if(chiffre < b && chiffre >= 0){
            if (chiffre >= 10) {
                result = 'A' + chiffre - 10;
            } else {
                result = '0' + chiffre;
            }
            verif = 0;
        }else{
            printf("Veuillez saisir un chiffre appartenant a la base %d\n", b);
            verif = 1;
        }
    }while (verif != 0);
    return  result;
}

seau* ajouter_fin(seau* nbr, char *val){
    seau *nouveau_nombre = malloc(sizeof(seau));
    strcpy(nouveau_nombre->valeur, val);
    nouveau_nombre->suivant = NULL;

    if(nbr == NULL){
        return nouveau_nombre;
    }else{
        seau *temp = nbr;
        while(temp->suivant != NULL){
            temp = temp->suivant;
        }
        temp->suivant = nouveau_nombre;
        return nbr;
    }
}
int valeur_position(char *tableau, int position){
    return conversion_caractere_entier(tableau[position]);
}

seau **creation_tableau(int base){
    int i;
    seau **tableau_seau = malloc(base * sizeof(seau));
    for (i = 0; i < base; ++i) {
        tableau_seau[i] = malloc(sizeof(seau));
        tableau_seau[i] = NULL;
    }
    return tableau_seau;
}

void afficher_tableau(int base, seau **tableau, int taille_nombre){
    int i, j;

    for (i = 0; i < base; i++){
        printf("%d : ", i);
        if(tableau[i] != NULL){
            seau *temp = tableau[i];
            while(temp != NULL){
                for(j = 0; j < taille_nombre; j++){
                    printf("%c", temp->valeur[j]);
                }
                printf(" ");
                temp = temp->suivant;
            }
        }
        printf("\n");
    }
}

seau **initialisation_tableau(int base,  seau **tableau_seau, int taille_nombre){
    char value = 'C', stockage_nombre[11];
    int i;

    while (value != 'Q'){

        for (i = 0; i <= taille_nombre - 1; i++){
            stockage_nombre[i] = conversion_chiffre(base);
        }

        tableau_seau[valeur_position(stockage_nombre, taille_nombre-1)] = ajouter_fin(tableau_seau[valeur_position(stockage_nombre, taille_nombre-1)], stockage_nombre);
	fflush(stdin);
        printf("Si vous souhaitez ajouter des nombres cliqué sur n'importe quelle touche sinon saisissez 'Q'\n");
        fflush(stdin);
        getchar();
        scanf("%c", &value);
       
    }
    return tableau_seau;
}

void attribution_ordre(seau **nbr, int base, int a, int taille_nombre){
    int i;
    for(i = 0; i < base; i++){
        seau *temp = nbr[i];
        while(temp != NULL){
            temp->ordre = valeur_position(temp->valeur, taille_nombre - 1 - a);
            temp = temp->suivant;
        }
    }
}

seau** changement_ordre(seau **tableau, int base){
    seau **nouveau_tableau;
    seau *temp;
    int i;
    nouveau_tableau = creation_tableau(base);

    for(i = 0; i < base; i++){
        temp = tableau[i];
        while(temp != NULL){
            nouveau_tableau[temp->ordre] = ajouter_fin(nouveau_tableau[temp->ordre], temp->valeur);
            temp = temp->suivant;
        }
    }
    free(tableau);
    return nouveau_tableau;
}

void affiche_liste_finale(int base, seau **tableau_seau, int taille_nombre){
    seau *temp;
    int i, j;

    printf("\n");
    printf("Caractere : ");
    for(i = 0; i < base; i++){
        temp = tableau_seau[i];
        while(temp != NULL){
            for(j = 0; j < taille_nombre; j++){
                printf("%c", temp->valeur[j]);
            }
            printf(" ");
            temp = temp->suivant;
        }
    }
    printf("\n");
    printf("Numerique : ");
    for(i = 0; i < base; i++){
        temp = tableau_seau[i];
        while(temp != NULL){
            for(j = 0; j < taille_nombre; j++){
                printf("%d", conversion_caractere_entier(temp->valeur[j]));
            }
            printf(" ");
            temp = temp->suivant;
        }
    }
}

