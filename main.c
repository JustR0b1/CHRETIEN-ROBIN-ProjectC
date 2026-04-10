#include <stdio.h>                          // On inclut le module pour pouvoir utliser ses fonctions
#include "superheroes.h"  
#include <string.h>

int main() {
    Superhero heroes[MAX];                              // Définition du tableau en C pour accueillir les valeurs du fichier json
    int favoris[MAX] = {0};                             // Tableau de favoris initialisé une seule fois
    int n = loadHeroes("SuperHeros.json", heroes);

    if (n <= 0) {
        printf("Aucun hero charge. Fin du programme.\n");
        return 1;
    }

    // Début du menu et de l'interface utilisateur 

    int choix;
    do {                                            //permet de construire une boucle quittable à tout moment 
            // Interface utilisateur
        printf("\n===== MENU =====\n");             
        printf("1. Affichage des Super-Héros\n");
        printf("2. Détails sur le Super-Héros\n");
        printf("3. Recherche et Filtre\n");
        printf("4. Comparaison de Super-Héros\n");
        printf("5. Quiz Interactif\n");
        printf("6. Personnalisation de Profil\n");
        printf("7. Intégration de Contenu Textuel à la place de Vidéos\n"); 
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);                        


        if (choix == 1) {                // Question affichage de la liste des heros du fichier json
            displayHeroes(heroes, n);    // Appel de la fonction d'affichage 
        }





        else if (choix == 2) {                      // Affcihage des stats d'un hero
            int id;                                 // def variable local
            printf("ID: ");                         // Affichage utilisateur       
            scanf("%d", &id);                       // Garde l'ID entré par l'utilisateur
            if (id > 0 && id <= n) {                // vérifie si l'ID est bien attribué à un SuperHero
                displayHeroDetails(heroes[id - 1]); // Appel de la fonction sur les stats d'un hero (-1 car on commence à 0)
            }
            else {
                printf("ID invalide\n");            // Cas échéant du test de l'ID
            }
        }





        else if (choix == 3) {                      // QUESTION recherche par nom
            int choix4;
            printf("\n===== MENU RECHERCHE =====\n");
            printf("1. Rechercher par nom\n");
            printf("2. Rechercher par Filtre\n");
            printf("Choix: ");
            scanf("%d", &choix4);
            if (choix4 == 1) {
                char name[50];                          // Définition de la variable local
                printf("Nom: ");                        // Affichage utilisateur 
                scanf(" %49[^\n]", name);               // Garde en mémoire le nom saisi par l'utilisateur 
        
                int index = searchHeroByName(heroes, n, name);  // Appel de la fonction sur la rechercher par nom
                if (index != -1){                               // Test d'erreur 
                    displayHeroDetails(heroes[index]);          // Appel de la fonction sur les stats avec l'index definie pour que le nom correpond à l'ID
                }
                else {
                    printf("Hero non trouve\n");
                }
            }
            else if (choix4 == 2) {
                filterStrongHeroes(heroes, n);      // Appel de la fonction de filtrage des heros 
            }
            else {
                printf("Choix invalide\n");
            }
        }




        else if (choix == 4) {                                  // Question comparaison de heros
            int a, b;                                           // Définition des varaibles
            printf("ID 1: "); scanf("%d", &a);                  // Affichage utilisateur et sauvegarde du choix 
            printf("ID 2: "); scanf("%d", &b);

            if (a > 0 && a <= n && b > 0 && b <= n)             // Test de validité des ID entrés
                compareHeroes(heroes[a - 1], heroes[b - 1]);    // Appel de la fontion de comparaison des heros
            else
                printf("IDs invalides\n");
        }




        else if (choix == 5) {                  // Question filtrage heros
            printf("Bienvenue dans le quiz\n"); 
            printf("Le quiz comporte 16 questions\n");
            printf("Pour chacune d'elles, il vous sera donné les stats et une breuve description physique d'un hero\n");
            printf("Vous devrez alors indiquer d'ID du hero correspondant à la description\n"); 
            printf("Chaque bonne réponse vous rapportera un point\n");
            printf("Bonne chance!\n");
            int choixQuiz;
            int score = 0;
            displayHeroDetailsQuizz(heroes[4]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 4) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[4].name);
            }
            displayHeroDetailsQuizz(heroes[10]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 10) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[10].name);
            }
            displayHeroDetailsQuizz(heroes[15]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 15) {  
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[15].name);
            }
            displayHeroDetailsQuizz(heroes[1]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 1) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[1].name);
            }
            displayHeroDetailsQuizz(heroes[3]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 3) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[3].name);
            }
            displayHeroDetailsQuizz(heroes[12]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 12) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[12].name);
            }
            displayHeroDetailsQuizz(heroes[8]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 8) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[8].name);
            }
            displayHeroDetailsQuizz(heroes[7]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 7) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[7].name);
            }
            displayHeroDetailsQuizz(heroes[13]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz ==13 ) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[13].name);
            }
            displayHeroDetailsQuizz(heroes[6]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 6) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[6].name);
            }
            displayHeroDetailsQuizz(heroes[11]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 11) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[11].name);
            }
            displayHeroDetailsQuizz(heroes[16]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 16) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[16].name);
            }
            displayHeroDetailsQuizz(heroes[9]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 9) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[9].name);
            }
            displayHeroDetailsQuizz(heroes[14]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz == 14) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[14].name);
            }
            displayHeroDetailsQuizz(heroes[2]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz ==2 ) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[2].name);
            }
            displayHeroDetailsQuizz(heroes[5]);
            printf("ID du hero: ");
            scanf("%d", &choixQuiz);
            if (choixQuiz ==5 ) {
                printf("Bonne réponse!\n");
                score++;
            }
            else {
                printf("Mauvaise réponse! La bonne réponse était: %s\n", heroes[5].name);
            }
            printf("Votre score final est: %d/16\n", score);
        }    




        else if (choix == 6) {       
            int choix2;     
            printf("\n");
            printf("Que voulez vous faire?\n");
            printf("1: Voir vos favoris\n");
            printf("2: Ajouter un hero à vos favoris\n");
            printf("3: Supprimer un hero de vos favoris\n");
            printf("Choix: ");
            scanf("%d", &choix2);


            if (choix2 == 1) {
                if (favoris[0] == 0) {
                    printf("Aucun favori\n");
                }
                else {
                    printf("Vos favoris:\n");
                    for (int i = 0; i < MAX && favoris[i] != 0; i++) {
                        int id = favoris[i];
                        if (id > 0 && id <= n) {
                            printf("%d - %s\n", id, heroes[id-1].name);
                        }
                    }
                }
            } 
            else if (choix2 == 2) {
                int id;                                 // def variable local
                printf("ID du hero à ajouter aux favoris: ");                         // Affichage utilisateur
                scanf("%d", &id);                       // Garde l'ID entré par l'utilisateur
                if (id > 0 && id <= n) {                // vérifie si l'ID est bien attribué à un SuperHero
                    int exists = 0;
                    for (int i = 0; i < MAX; i++) {
                        if (favoris[i] == id) {
                            exists = 1;
                            break;
                        }
                    }
                    if (exists) {
                        printf("Hero deja en favoris\n");
                    } else {
                        for (int i = 0; i < MAX; i++) {
                            if (favoris[i] == 0) {          // Trouve la première place libre dans le tableau de favoris
                                favoris[i] = id;            // Ajoute l'ID du hero aux favoris
                                printf("Hero ajoute aux favoris\n");
                                break;
                            }
                        }
                    }
                }
                else {
                    printf("ID invalide\n");            // Cas échéant du test de l'ID
                }
            }
            else if (choix2 == 3) {
                int id;
                printf("ID du hero a supprimer des favoris: ");
                scanf("%d", &id);
                int removed = 0;
                for (int i = 0; i < MAX; i++) {
                    if (favoris[i] == id) {
                        removed = 1;
                        for (int j = i; j < MAX - 1; j++) {
                            favoris[j] = favoris[j + 1];
                        }
                        favoris[MAX - 1] = 0;
                        printf("Hero supprime des favoris\n");
                        break;
                    }
                }
                if (!removed) {
                    printf("Hero non trouve dans les favoris\n");
                }
            }
            else {
                printf("Choix invalide\n");
            }
        }    
        else if (choix == 7) {
            char bug[100] = "https://fr.wikipedia.org/wiki/Liste_de_super-h%C3%A9ros_au_cin%C3%A9ma";
            printf("Lien Wikipedia : %s\n", bug);
            printf("Lien Imdb : https://www.imdb.com/fr/superheroes/?ref_=nv_sr_srsg_0_tt_6_nm_1_in_0_q_super\n");
        }
        else if (choix != 0) {
            printf("Choix invalide\n");
        }



    } while (choix != 0);              // Condition de fin de boucle
    printf("Fin du programme\n");      // Indication de la fin de programme     
    return 0;
}
