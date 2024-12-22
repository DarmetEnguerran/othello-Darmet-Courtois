// COURTOIS Maxance
// DARMET Enguerran

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Plateau de Valeurs permettant de construire le vrai plateau de valeur
extern int Vtriangle[10]; 

//construit le vrai plateau de valeur
void completeVP(int valeurListe[64], int triangle[10]);

//calcul une estimation du plateau en fonction du plateau de valeur
int calculPresScore(int liste[64], int valeurListe[64],int couleur);

/*
Test tout les coup possible est associe a chaqu'un de la valeurs estimer par calculPresScoreprescore
du plateau si tout le monde joue au mieux, a une profondeurs choisi.
*/

int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur, int *mcp);