#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define noir 2
#define blanc 1
#define vide 0

extern int TableauCouleur[2];
extern int couleur;
extern int cptest;

extern int plateauTest[64];

extern int plateauAttendu[64];

extern int cp_s_attendu;
extern int score_attendu[2];
extern int victoir_attendu;

verifier_egalite(int * T1, int * T2, int taille);

