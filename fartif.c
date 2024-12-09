#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fartif.h"

extern int Vtriangle[10]= {10, 1, 7, 5, 
                              0, 3, 2,
                                 5, 4,
                                     1};

void completeVP(int ValeurListe[64], int triangle[10]){
    ValeurListe[64]= {  Vtriangle[0],Vtriangle[1],Vtriangle[2],Vtriangle[3],Vtriangle[3],Vtriangle[2],Vtriangle[1],Vtriangle[0],
                        Vtriangle[1],Vtriangle[4],Vtriangle[5],Vtriangle[6],Vtriangle[6],Vtriangle[5],Vtriangle[4],Vtriangle[1],
                        Vtriangle[2],Vtriangle[5],Vtriangle[7],Vtriangle[8],Vtriangle[8],Vtriangle[7],Vtriangle[5],Vtriangle[2],
                        Vtriangle[3],Vtriangle[6],Vtriangle[8],Vtriangle[9],Vtriangle[9],Vtriangle[8],Vtriangle[6],Vtriangle[3],
                        Vtriangle[3],Vtriangle[6],Vtriangle[8],Vtriangle[9],Vtriangle[9],Vtriangle[8],Vtriangle[6],Vtriangle[3],
                        Vtriangle[2],Vtriangle[5],Vtriangle[7],Vtriangle[8],Vtriangle[8],Vtriangle[7],Vtriangle[5],Vtriangle[2],
                        Vtriangle[1],Vtriangle[4],Vtriangle[5],Vtriangle[6],Vtriangle[6],Vtriangle[5],Vtriangle[4],Vtriangle[1],
                        Vtriangle[0],Vtriangle[1],Vtriangle[2],Vtriangle[3],Vtriangle[3],Vtriangle[2],Vtriangle[1],Vtriangle[0]};

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
    int vMcp=-1000;
    int concurant_vMcp;
    int **fplateau;  //tableau de taille 64
    if (!(profondeur)){
        return calculPresScore;
    }
    else{
        for (int i=0; i<64; i++){
            fplateau = maloc(sizeof(int)*64);
            if (changement(*fplateau, i, couleur)){
                concurant_vMcp=(-1)*MinMax(*fplateau, valeurListe, not(couleur),profondeur-1);
                if (vMcp < concurant_vMcp){
                    vMcp=concurant_vMcp;
                    mcp=i;
                }
            }
            free (fplateau);
        }
        return vMcp;    
    }
}