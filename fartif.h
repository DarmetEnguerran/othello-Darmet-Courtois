#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


extern int Vtriangle[10]; 

void completeVP(int valeurListe[64], int triangle[10]);

int calculPresScore(int liste[64], int valeurListe[64],int couleur);
 
int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur, int *mcp);