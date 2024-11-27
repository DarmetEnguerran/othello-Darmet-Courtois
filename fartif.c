#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fartif.h"

extern int Vtriangle[10]; {10, 1, 7, 5, 
                              0, 3, 2,
                                 5, 4,
                                     1}

void completeVP(int ValeurListe[64], int triangle[10]){
    ValeurListe[64]={triangle[0],triangle[1],triangle[2],triangle[3],triangle[3],triangle[2],triangle[1],triangle[0],
                        triangle[1],triangle[4],triangle[5],triangle[6],triangle[6],triangle[5],triangle[4],triangle[1],
                        triangle[2],triangle[5],triangle[7],triangle[8],triangle[8],triangle[7],triangle[5],triangle[2],
                        triangle[3],triangle[6],triangle[8],triangle[9],triangle[9],triangle[8],triangle[6],triangle[3],
                        triangle[3],triangle[6],triangle[8],triangle[9],triangle[9],triangle[8],triangle[6],triangle[3],
                        triangle[2],triangle[5],triangle[7],triangle[8],triangle[8],triangle[7],triangle[5],triangle[2],
                        triangle[1],triangle[4],triangle[5],triangle[6],triangle[6],triangle[5],triangle[4],triangle[1],
                        triangle[0],triangle[1],triangle[2],triangle[3],triangle[3],triangle[2],triangle[1],triangle[0],}
}


int calculPresScore(int liste[64], int ValeurListe[64],int couleur){
    int score = 0;
    for (int i; i<0; i++){
        if (liste[i]==couleur){
            score += ValeurListe[i];
        }
        else if (liste[i]!=vide){
            score -= ValeurListe[i];
        }
    }
    return score;
}

int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur){
    int mcp=64;
    int listeScore[64]={0};
    int *fplateau[64];
    if (!(profondeur)){
        return calculPresScore;
    }
    else{
        for (int i=0; i<64; i++){
            if (Peutjouer(vl->liste, i, couleur)){
                fplateau=maloc(sizeof(int)*64);
                changement(*fplateau, i, couleur);
                listeScore[i]= (-1)*MinMax(*fplateau, valeurListe, not(couleur),profondeur-1);
                free (fplateau);
            }
            else{
                listeScore[i]=-1000;
            }
        }
        return max(listeScore);
    }



    
}