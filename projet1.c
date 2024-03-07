#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet_proto.h"
/*#define Max_taille 100 */
// return 0 Échec de la connexion 
// return 1 // Connexion réussie


// Fonction pour vérifier la connexion admin

int verifier_connexion(char *email, char *mot_de_passe, char *role, char *nomfichier) {
    FILE *fichier = fopen(nomfichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomfichier);
        return 0; // Échec de la connexion
    }

    CONNEXION c;
    while (fscanf(fichier, "%s %s %s", c.email, c.mdp, c.role) == 3) {
        if (strcmp(email, c.email) == 0 && strcmp(mot_de_passe, c.mdp) == 0) {
            if (strcmp(role, c.role) == 0) {
                fclose(fichier);
                return 1; // Connexion réussie
            }
        }
    }

    fclose(fichier);
    return 0; // Échec de la connexion
}

// Fonction pour saisir la connexion 
CONNEXION saisir_connexion(void) {
    CONNEXION c;
    printf("Entrer un email : ");
    scanf("%s", c.email);   
    printf("Entrer un mot de passe : ");
    fflush(stdout); 
    scanf("%s", c.mdp);   
    
    return c;
}  



// marquer presence

// liste de la classe 
int recuperer_classes(Classe *classes) {
    FILE *fichier = fopen("test.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    int nb_classes = 0;
    char ligne[Max_taille];

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char *token = strtok(ligne, " ");
        while (token != NULL) {
            strcpy(classes[nb_classes].nom, token);
            nb_classes++;
            token = strtok(NULL, " ");
        }
    }

    fclose(fichier);
    return nb_classes;
}

// liste etudiant

int recuperer_liste_etudiants(ETUDIANT *e, char *nomfichier) {
    FILE *fichier = fopen("test.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", "test.txt");
        return 0;
    }

    int nb_etudiants = 0;
    while (fscanf(fichier, "%s %s %d", e[nb_etudiants].nom, e[nb_etudiants].prenom, &e[nb_etudiants].age) == 3) {
        nb_etudiants++;
    }

    fclose(fichier);
    return nb_etudiants;
}




