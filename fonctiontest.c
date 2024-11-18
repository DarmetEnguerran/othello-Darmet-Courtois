#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fonctiontest.h"

extern int TableauCouleur[2] = {blanc,noir};
extern int couleur_test= 1;
extern int cptest=4+2*8;


extern int plateau_test[64]=
                {0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,0,2,0,0,0,
                0,0,0,0,2,0,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,0,0,0,0,0};

extern int plateau_attendu[64]=
                {0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,0,2,0,0,0,
                0,0,0,0,2,0,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,0,0,0,0,0};


extern int couleur_s_attendu= 0 ;
extern int sB_attendu=1;
extern int sN_attendu=4;
extern int victoir_attendu=2;

int verifier_egalite(int * T1, int * T2, int taille)
{
    // On considère le tableau comme égale initialement
    int c = 0;
    // Au premier élément rencontré qui n'est pas bon, on marque le tableau comme différent
    for (int i = 0; i < taille; ++i)
    {
        if (T1[i] != T2[i]) {
           c = 1;
           break;
        }
    }
    return c;
}



