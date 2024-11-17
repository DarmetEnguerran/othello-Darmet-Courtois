#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define noir 2
#define blanc 1
#define vide 0

extern int plateauTest[64];

extern int plateauAttendu[64];


extern int plateau[64];


void afficherPlateau(int liste[64]);
int changement(int liste[64],int cp, int couleur);
int Peutjouer(int liste[64], int couleur);
