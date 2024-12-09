#include <stdio.h>
#include <stdbool.h>
#include <math.h>

extern int Vtriangle[10]; 
extern int valeurPlateau[64];

void completeVP(int valeurListe[64], int triangle[10]);

int calculPresScore(int liste[64], int valeurListe[64],int couleur);

int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur);