#ifndef SUPERHEROS_H
#define SUPERHEROS_H

#define MAX 100



//Création de la structure Powerstats

typedef struct {
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
    char gender[50];
    char race[50] ;
    char height[50];
    char weight[50];
    char eyeColor[50];
    char hairColor[50];
} Powerstats;                 


// Création de la structure Superhero 

typedef struct {
    int id;
    char name[50];
    Powerstats stats;
} Superhero;

// Prototypes des fonctions utilisées dans le projet

int loadHeroes(const char *filename, Superhero heroes[]);
void displayHeroes(Superhero heroes[], int n);
void displayHeroDetails(Superhero hero);
void displayHeroDetailsQuizz(Superhero hero);
int searchHeroByName(Superhero heroes[], int n, char *name);
void compareHeroes(Superhero h1, Superhero h2);
void filterStrongHeroes(Superhero heroes[], int n);

#endif
