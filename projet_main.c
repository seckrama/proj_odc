#include <stdio.h>
#include <stdlib.h>
#include "projet1.c"

int main() {
  
  int choix_menu;
   while (1) {
        printf("\nMenu :\n");
        printf("1. Connexion\n");
        printf("2. Marquer presence\n");
        printf("3. liste des precences \n");
        printf("4. Deconnection\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix_menu);

        switch (choix_menu) {
            case 1:
                {
                    CONNEXION c = saisir_connexion();
                    if (verifier_connexion(c.email, c.mdp, "admin", "test.txt")) {
                        printf("Connexion réussie en tant qu'administrateur.\n");
                        
                    
                    
                    } else if (verifier_connexion(c.email, c.mdp, "utilisateur", "user.txt")) {
                        printf("Connexion réussie en tant qu'utilisateur.\n");
                    } else {
                        printf("Échec de la connexion. Veuillez saisir un login et un mot de passe valide.\n");
                    }
                }
                break;
            case 2:
                CONNEXION c = saisir_connexion();
                    if (verifier_connexion(c.email, c.mdp, "admin", "test.txt")) {
                        printf("Connexion réussie en tant qu'administrateur.\n");
                        // Récupération des classes
                         Classe classes[Max_taille];
                        int nb_classes = recuperer_classes(classes);

                        if (nb_classes > 0) {
                            printf("Liste des classes :\n");
                            for (int i = 0; i < nb_classes; i++) {
                            printf("%s\n", classes[i].nom);
                            }
                        } else {
                        printf("Aucune classe n'a été récupérée.\n");
                        }

                        //liste des etudiants
                    ETUDIANT etudiants[Max_taille];

                     int nb_etudiants = recuperer_liste_etudiants(etudiants, "test.txt");
                    if (nb_etudiants > 0) {
                        printf("Liste des étudiants :\n");
                        for (int i = 0; i < nb_etudiants; i++) {
                            printf("%s %s, %d ans\n", etudiants[i].prenom, etudiants[i].nom, etudiants[i].age);
                        }
                    
                        } 
                         int choix_etudiant;
                        printf("Sélectionnez un étudiant : ");
                        scanf("%d", &choix_etudiant);
                        if (choix_etudiant >= 1 && choix_etudiant <= nb_etudiants) {
                            printf("%s %s a été marqué(e) en présence.\n", etudiants[choix_etudiant - 1].prenom, etudiants[choix_etudiant - 1].nom);
                            etudiants[choix_etudiant - 1].present = 1; // Marquer l'étudiant comme présent                        } else {
                            printf("Choix invalide.\n");


                     }
                    }


                    else {
                        printf("Échec de la connexion. Veuillez saisir un login et un mot de passe valide.\n");
                    }
                   
                break;
                case 3:
                printf("liste des presences");
                
                break;
                case 4:
                printf("Deconnection");
                return 0;
                break;

            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 2.\n");
                break;
        }
   }
    return 0;
}