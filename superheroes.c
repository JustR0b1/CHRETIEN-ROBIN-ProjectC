#include <stdio.h>
#include <string.h>
#include "superheroes.h"

int loadHeroes(const char *filename, Superhero heroes[]) {
    FILE *file = fopen(filename, "r");                                      // Définition de la structure file
                                                                            //La fonction fopen permet d'ouvrir un fichier
                                                                            // *file est un pointeur vers le fichier json pour recupérer les informations contenues
                                                                            // le r permet d'ouvrir le fichier en lecture seulement 

    if (!file) {
        printf("Erreur ouverture fichier\n");                               // Message d'erreur si le fichier a un problème
        return 0;
    }

    int i = -1;         // Definition des variables 
    char line[256];    // i compte le nombre de héros / line permet de stocker les lignes du fichier json           



        // Chaque if permet de detecter un champ différent dans le fichier json
        // Chaque ligne va agir de manière similaire
        // fgets permet de lire une ligne à la fois
        // line va contenir une ligne du fichier json à la fois, donc un hero à la fois
        // Permet de trouver une info dans le fichier json ex: id , name
        // %*[^:]:   perme d'ingnorer tout les caracteres jusqu'à :
        // Similairement %[^\"] permet d'ignorer tout les caractères jusqu'à " 
        // Ils récupèrent ensuite respectivement le int ou le char qui suit 
        // Ils mettent ensuite les valeurs du fichier json dans le tableau

    while (fgets(line, sizeof(line), file)) {                               
        if (strstr(line, "\"id\"")) {
            i++;
            sscanf(line, " %*[^:]: %d", &heroes[i].id);
        }
        else if (strstr(line, "\"name\"")) {
            sscanf(line, " %*[^:]: \"%[^\"]\"", heroes[i].name);
        }
        else if (strstr(line, "\"intelligence\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.intelligence);
        }
        else if (strstr(line, "\"strength\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.strength);
        }
        else if (strstr(line, "\"speed\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.speed);
        }
        else if (strstr(line, "\"durability\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.durability);
        }
        else if (strstr(line, "\"power\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.power);
        }
        else if (strstr(line, "\"combat\"")) {
            sscanf(line, " %*[^:]: %d", &heroes[i].stats.combat);  
        }
        

        
        else if (strstr(line, "\"gender\"")) {
            sscanf(line, "%*[^:]: \"%[^\"]\"", heroes[i].stats.gender);  
        }
        else if (strstr(line, "\"race\"")) {
            sscanf(line,"%*[^:]: \"%[^\"]\"", heroes[i].stats.race);  
        }
        else if (strstr(line, "\"height\"")) {
            sscanf(line,"%*[^:]: \"%[^\"]\"", heroes[i].stats.height);  
        }
        else if (strstr(line, "\"weight\"")) {
            sscanf(line,"%*[^:]: \"%[^\"]\"", heroes[i].stats.weight);  
        }
        else if (strstr(line, "\"eyeColor\"")) {
            sscanf(line, "%*[^:]: \"%[^\"]\"", heroes[i].stats.eyeColor);  
        }
        else if (strstr(line, "\"hairColor\"")) {
            sscanf(line, "%*[^:]: \"%[^\"]\"", heroes[i].stats.hairColor);  
        }
    }

    fclose(file);        //permet de refermer le fichier ouvert précédement
    return i;
}

void displayHeroes(Superhero heroes[], int n) {
    printf("\n=== LISTE DES HEROS ===\n");                          // Affichage de la question
    for (int i = 0; i < n+1; i++) {
        printf("%d - %s\n", heroes[i].id, heroes[i].name);
    }
}

void displayHeroDetails(Superhero hero) {
    printf("\n=== DETAILS ===\n");                                  // Affichage de la question
    printf("Nom: %s\n", hero.name);

    if (hero.stats.intelligence != 0) {
        printf("Intelligence: %d\n", hero.stats.intelligence);
    }
    else {
        printf("Intelligence: N/A\n");
    }
    if (hero.stats.strength != 0) {
        printf("Force: %d\n", hero.stats.strength);
    }
    else {
        printf("Force: N/A\n");
    }
    if (hero.stats.speed != 0) {
        printf("Vitesse: %d\n", hero.stats.speed);
    }
    else {
        printf("Vitesse: N/A\n");
    }
    if (hero.stats.durability != 0) {
        printf("Durabilite: %d\n", hero.stats.durability);
    }
    else {
        printf("Durabilite: N/A\n");
    }
    if (hero.stats.power != 0) {
        printf("Puissance: %d\n", hero.stats.power);
    }
    else {
        printf("Puissance: N/A\n");
    }
    if (hero.stats.combat != 0) {
        printf("Combat: %d\n", hero.stats.combat);
    }
    else {
        printf("Combat: N/A\n");
    }


    if (hero.stats.gender[0] == '\0') {
        printf("Gender: N/A\n");
    }
    else {
        printf("Gender: %s\n", hero.stats.gender);
    }
    if (hero.stats.race[0] == '\0') {
        printf("Race: N/A\n");
    }
    else {
        printf("Race: %s\n", hero.stats.race);
    }
    if (hero.stats.height[0] == '\0') {
        printf("Height: N/A\n");
    }
    else {
        printf("Height: %s\n", hero.stats.height);
    }
    if (hero.stats.weight[0] == '\0') {
        printf("Weight: N/A\n");
    }
    else {
        printf("Weight: %s\n", hero.stats.weight);
    }
    if (hero.stats.eyeColor[0] == '\0') {
        printf("Eye Color: N/A\n");
    }
    else {
        printf("Eye Color: %s\n", hero.stats.eyeColor);
    }
    if (hero.stats.hairColor[0] == '\0') {
        printf("Hair Color: N/A\n");
    }
    else {
        printf("Hair Color: %s\n", hero.stats.hairColor);
    }

}


void displayHeroDetailsQuizz(Superhero hero) {
    printf("\n=== DETAILS ===\n");                                  // Affichage de la question
    

    if (hero.stats.intelligence != 0) {
        printf("Intelligence: %d\n", hero.stats.intelligence);
    }
    else {
        printf("Intelligence: N/A\n");
    }
    if (hero.stats.strength != 0) {
        printf("Force: %d\n", hero.stats.strength);
    }
    else {
        printf("Force: N/A\n");
    }
    if (hero.stats.speed != 0) {
        printf("Vitesse: %d\n", hero.stats.speed);
    }
    else {
        printf("Vitesse: N/A\n");
    }
    if (hero.stats.durability != 0) {
        printf("Durabilite: %d\n", hero.stats.durability);
    }
    else {
        printf("Durabilite: N/A\n");
    }
    if (hero.stats.power != 0) {
        printf("Puissance: %d\n", hero.stats.power);
    }
    else {
        printf("Puissance: N/A\n");
    }
    if (hero.stats.combat != 0) {
        printf("Combat: %d\n", hero.stats.combat);
    }
    else {
        printf("Combat: N/A\n");
    }


    if (hero.stats.gender[0] == '\0') {
        printf("Gender: N/A\n");
    }
    else {
        printf("Gender: %s\n", hero.stats.gender);
    }
    if (hero.stats.race[0] == '\0') {
        printf("Race: N/A\n");
    }
    else {
        printf("Race: %s\n", hero.stats.race);
    }
    if (hero.stats.height[0] == '\0') {
        printf("Height: N/A\n");
    }
    else {
        printf("Height: %s\n", hero.stats.height);
    }
    if (hero.stats.weight[0] == '\0') {
        printf("Weight: N/A\n");
    }
    else {
        printf("Weight: %s\n", hero.stats.weight);
    }
    if (hero.stats.eyeColor[0] == '\0') {
        printf("Eye Color: N/A\n");
    }
    else {
        printf("Eye Color: %s\n", hero.stats.eyeColor);
    }
    if (hero.stats.hairColor[0] == '\0') {
        printf("Hair Color: N/A\n");
    }
    else {
        printf("Hair Color: %s\n", hero.stats.hairColor);
    }

}

int searchHeroByName(Superhero heroes[], int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(heroes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void compareHeroes(Superhero h1, Superhero h2) {
    printf("\n=== COMPARAISON ===\n");
    printf("%s vs %s\n", h1.name, h2.name);

    printf("Force: %d vs %d\n", h1.stats.strength, h2.stats.strength);
    printf("Intelligence: %d vs %d\n", h1.stats.intelligence, h2.stats.intelligence);
    printf("Vitesse: %d vs %d\n", h1.stats.speed, h2.stats.speed);
    printf("Combat: %d vs %d\n", h1.stats.combat, h2.stats.combat);
}
 
void filterStrongHeroes(Superhero heroes[], int n) {
    int choix;
    printf("\n===== MENU FILTRES =====\n");
    printf("1.Trier par intelligence\n");
    printf("2.Trier par force\n");
    printf("3.Trier par vitesse\n");
    printf("4.Trier par Durabilité\n");
    printf("5.Trier par puissance\n");
    printf("6.Trier par combat\n");
    printf("Choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("\n Valeur d'intelligence minimale: ");
        int min_intelligence;
        scanf("%d", &min_intelligence);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.intelligence > min_intelligence) {
                printf("%s (Intelligence: %d)\n", heroes[i].name, heroes[i].stats.intelligence);
            }
        }
    }
    else if (choix == 2) { 
        printf("\n Valeur de force minimale: ");
        int min_strength;
        scanf("%d", &min_strength);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.strength > min_strength) {
                printf("%s (Force: %d)\n", heroes[i].name, heroes[i].stats.strength);
            }
        }
    }
    else if (choix == 3) {
        printf("\n Valeur de vitesse minimale: ");
        int min_speed;
        scanf("%d", &min_speed);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.speed > min_speed) {
                printf("%s (Vitesse: %d)\n", heroes[i].name, heroes[i].stats.speed);
            }
        }
    }
    else if (choix == 4) {
        printf("\n Valeur de durabilité minimale: ");
        int min_durability;
        scanf("%d", &min_durability);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.durability > min_durability) {
                printf("%s (Durabilité: %d)\n", heroes[i].name, heroes[i].stats.durability);
            }
        }
    }
    else if (choix == 5) {
        printf("\n Valeur de puissance minimale: ");
        int min_power;
        scanf("%d", &min_power);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.power > min_power) {
                printf("%s (Puissance: %d)\n", heroes[i].name, heroes[i].stats.power);
            }
        }
    }
    else if (choix == 6) {
        printf("\n Valeur de combat minimale: ");
        int min_combat;
        scanf("%d", &min_combat);
        for (int i = 0; i < n; i++) {
            if (heroes[i].stats.combat > min_combat) {
                printf("%s (Combat: %d)\n", heroes[i].name, heroes[i].stats.combat);
            }
        }
    }
    else {
            printf("Choix invalide\n");
    }

    void displayHeroDetailsQuizz(Superhero hero) {
    printf("\n=== DETAILS ===\n");                                  // Affichage de la question
    

    if (hero.stats.intelligence != 0) {
        printf("Intelligence: %d\n", hero.stats.intelligence);
    }
    else {
        printf("Intelligence: N/A\n");
    }
    if (hero.stats.strength != 0) {
        printf("Force: %d\n", hero.stats.strength);
    }
    else {
        printf("Force: N/A\n");
    }
    if (hero.stats.speed != 0) {
        printf("Vitesse: %d\n", hero.stats.speed);
    }
    else {
        printf("Vitesse: N/A\n");
    }
    if (hero.stats.durability != 0) {
        printf("Durabilite: %d\n", hero.stats.durability);
    }
    else {
        printf("Durabilite: N/A\n");
    }
    if (hero.stats.power != 0) {
        printf("Puissance: %d\n", hero.stats.power);
    }
    else {
        printf("Puissance: N/A\n");
    }
    if (hero.stats.combat != 0) {
        printf("Combat: %d\n", hero.stats.combat);
    }
    else {
        printf("Combat: N/A\n");
    }


    if (hero.stats.gender[0] == '\0') {
        printf("Gender: N/A\n");
    }
    else {
        printf("Gender: %s\n", hero.stats.gender);
    }
    if (hero.stats.race[0] == '\0') {
        printf("Race: N/A\n");
    }
    else {
        printf("Race: %s\n", hero.stats.race);
    }
    if (hero.stats.height[0] == '\0') {
        printf("Height: N/A\n");
    }
    else {
        printf("Height: %s\n", hero.stats.height);
    }
    if (hero.stats.weight[0] == '\0') {
        printf("Weight: N/A\n");
    }
    else {
        printf("Weight: %s\n", hero.stats.weight);
    }
    if (hero.stats.eyeColor[0] == '\0') {
        printf("Eye Color: N/A\n");
    }
    else {
        printf("Eye Color: %s\n", hero.stats.eyeColor);
    }
    if (hero.stats.hairColor[0] == '\0') {
        printf("Hair Color: N/A\n");
    }
    else {
        printf("Hair Color: %s\n", hero.stats.hairColor);
    }

}
    

}
