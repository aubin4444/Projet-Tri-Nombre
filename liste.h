
#ifndef PROJET_LO21_LISTE_H
#define PROJET_LO21_LISTE_H

typedef struct elem{
    char valeur[11];
    struct elem* suivant;
    int ordre;
}seau;

/**
 * Fonction demandant à l'utilisateur de choisir la base qu'il souhaite [2;16]
 * @return base
 */
int choix_base();

/**
 * Demande à l'utilisateur combien de chiffre il y aura par nombre
 * @param taille_nombre la reponse de l'utilisateur
 */
void choix_parametre(int *taille_nombre);

/**
 * Convertit un caractère en sa valeur entière ( 1=1,2=2,3=3,...,A=10,B=11,...,F=15)
 * @param caractere le caractère à convertir
 * @return la valeur entière
 */
int conversion_caractere_entier(char caractere);

/**
 * Demande à l'utilisateur de saisir un chiffre de la base qu'il a choisit et le convertit en caractère
 * @param b la base choisit par l'utilisateur
 * @return le caractère correspondant à l'entier saisit
 */
char conversion_chiffre(int b);

/**
 * Ajoute un nombre en fin de liste
 * @param nbr la liste à laquelle l'element doit être ajouté
 * @param val sa valeur sous forme de liste de caractère
 * @return la nouvelle liste
 */
seau* ajouter_fin(seau* nbr, char *val);

/**
 * Retourne la valeure entière correspondant au caractère se trouvant en une position donnée dans une chaine de caractère
 * @param tableau la chaine de caractères
 * @param position la position demandée
 * @return la valeure entière correspondante
 */
int valeur_position(char *tableau, int position);

/**
 * Crée un tableau de liste en allouant une taille de tableau correspondant à la base et en allouant pour chaque case la place pour y mettre un seau
 * @param base la base correspondante
 * @return le tableau de liste alloué
 */
seau **creation_tableau(int base);

/**
 * Affiche le tableau en parcourant chacune de ses cases et pour chacune de celle-ci la liste qu'elle contient
 * @param base correspondant à la taille du tableau
 * @param tableau le tableau de liste
 * @param taille_nombre la taille de chauque nombre
 */
void afficher_tableau(int base, seau **tableau, int taille_nombre);

/**
 * Ajoute au tableau de liste les nombres saisis par l'utilisateur tant que celui ci veut en ajouter
 * @param base la taille du tableau
 * @param tableau_seau le tableau de liste
 * @param taille_nombre la taille de chaque nombre de la liste
 * @return le tableau de liste après ajout d'un nouveau nombre
 */
seau **initialisation_tableau(int base, seau **tableau_seau, int taille_nombre);

/**
 * Attribue un ordre à chaque nombre du tableau de liste correspondant à la valeur entière se trouvant à une certaine place de la chaine de caractère
 * @param nbr le tableau de liste de nombre
 * @param base la taille du tableau
 * @param a la place de la valeure que l'on souhaite attribuer
 * @param taille_nombre la taille de chaque nombre
 */
void attribution_ordre(seau **nbr, int base, int a, int taille_nombre);

/**
 * Attribue une nouvelle place à chaque nombre du tableau de liste d'après le nouvel ordre qui leur a été attribué
 * @param tableau correspondant au tableau de seau en fonction de l'ancien ordre de chaque nombre
 * @param base la taille du tableau de liste
 * @return le nouveau tableau de liste avec la bonne attribution des seaux en fonction de l'ordre de chaque nombre
 */
seau** changement_ordre(seau **tableau, int base);

/**
 * Affiche la liste sous forme de liste de caractère puis sous forme numérique lorsqu'elle est entièrement triée
 */
void affiche_liste_finale();

#endif 
