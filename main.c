/* =========================
   PROJET SUPER-HEROS (C)
   VERSION SANS JANSSON (100% COMPATIBLE)
   ========================= */

/* ===== superheroes.h ===== */
#ifndef SUPERHEROS_H
#define SUPERHEROS_H

#define MAX 100

typedef struct {
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
} Powerstats;

typedef struct {
    int id;
    char name[50];
    Powerstats stats;
} Superhero;

int loadHeroes(const char *filename, Superhero heroes[]);
void displayHeroes(Superhero heroes[], int n);
void displayHeroDetails(Superhero hero);
int searchHeroByName(Superhero heroes[], int n, char *name);
void compareHeroes(Superhero h1, Superhero h2);
void filterStrongHeroes(Superhero heroes[], int n);

#endif


/* ===== superheroes.c ===== */
#include <stdio.h>
#include <string.h>
#include "superheroes.h"

int loadHeroes(const char *filename, Superhero heroes[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erreur ouverture fichier\n");
        return 0;
    }

    int i = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\"id\"")) {
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
            i++; // fin d'un héros
        }
    }

    fclose(file);
    return i;
}

void displayHeroes(Superhero heroes[], int n) {
    printf("\n=== LISTE DES HEROS ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", heroes[i].id, heroes[i].name);
    }
}

void displayHeroDetails(Superhero hero) {
    printf("\n=== DETAILS ===\n");
    printf("Nom: %s\n", hero.name);
    printf("Intelligence: %d\n", hero.stats.intelligence);
    printf("Force: %d\n", hero.stats.strength);
    printf("Vitesse: %d\n", hero.stats.speed);
    printf("Durabilite: %d\n", hero.stats.durability);
    printf("Puissance: %d\n", hero.stats.power);
    printf("Combat: %d\n", hero.stats.combat);
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
    printf("\n=== HEROS FORTS (force > 90) ===\n");
    for (int i = 0; i < n; i++) {
        if (heroes[i].stats.strength > 90) {
            printf("%s (Force: %d)\n", heroes[i].name, heroes[i].stats.strength);
        }
    }
}


/* ===== main.c ===== */
#include <stdio.h>
#include "superheroes.h"

int main() {
    Superhero heroes[MAX];
    int n = loadHeroes("SuperHeros.json", heroes);

    int choix;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Liste des heros\n");
        printf("2. Details d'un hero\n");
        printf("3. Recherche par nom\n");
        printf("4. Comparer deux heros\n");
        printf("5. Filtrer (force > 90)\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        if (choix == 1) {
            displayHeroes(heroes, n);
        }
        else if (choix == 2) {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            if (id > 0 && id <= n)
                displayHeroDetails(heroes[id - 1]);
            else
                printf("ID invalide\n");
        }
        else if (choix == 3) {
            char name[50];
            printf("Nom: ");
            scanf("%s", name);

            int index = searchHeroByName(heroes, n, name);
            if (index != -1)
                displayHeroDetails(heroes[index]);
            else
                printf("Hero non trouve\n");
        }
        else if (choix == 4) {
            int a, b;
            printf("ID 1: "); scanf("%d", &a);
            printf("ID 2: "); scanf("%d", &b);

            if (a > 0 && a <= n && b > 0 && b <= n)
                compareHeroes(heroes[a - 1], heroes[b - 1]);
            else
                printf("IDs invalides\n");
        }
        else if (choix == 5) {
            filterStrongHeroes(heroes, n);
        }

    } while (choix != 0);

    printf("Au revoir !\n");
    return 0;
}


/* ===== COMPILATION =====
   gcc main.c superheroes.c -o app
   ./app
*/
