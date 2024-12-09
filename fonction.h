#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


#define noir 1
#define blanc 0
#define vide 2


extern int plateau[64];


void afficherPlateau(int liste[64]);
int changement(int liste[64],int cp, int couleur);
int Peutjouer(int liste[64], int couleur);
int calculScore (int liste[64], int *sB, int *sN);
