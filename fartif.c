#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "fonction.h"
#include "fartif.h"

extern int Vtriangle[10]= {20, 1, 7, 5, 
                              0, 3, 2,
                                 5, 4,
                                     1};
 
void completeVP(int ValeurListe[64], int triangle[10]){
    int cpValeurListe[64]= {  triangle[0],triangle[1],triangle[2],triangle[3],triangle[3],triangle[2],triangle[1],triangle[0],
                        triangle[1],triangle[4],triangle[5],triangle[6],triangle[6],triangle[5],triangle[4],triangle[1],
                        triangle[2],triangle[5],triangle[7],triangle[8],triangle[8],triangle[7],triangle[5],triangle[2],
                        triangle[3],triangle[6],triangle[8],triangle[9],triangle[9],triangle[8],triangle[6],triangle[3],
                        triangle[3],triangle[6],triangle[8],triangle[9],triangle[9],triangle[8],triangle[6],triangle[3],
                        triangle[2],triangle[5],triangle[7],triangle[8],triangle[8],triangle[7],triangle[5],triangle[2],
                        triangle[1],triangle[4],triangle[5],triangle[6],triangle[6],triangle[5],triangle[4],triangle[1],
                        triangle[0],triangle[1],triangle[2],triangle[3],triangle[3],triangle[2],triangle[1],triangle[0]};
    for (int i=0;i<64;i++)
    {
        ValeurListe[i] = cpValeurListe[i];
    }
}


int calculPresScore(int liste[64], int ValeurListe[64],int couleur){
    int score = 0;
    for (int i=0; i<64; i++){
        if (liste[i]==couleur){
            score += ValeurListe[i];
        }
        else if (liste[i]!=vide){
            score -= ValeurListe[i];
        }
    }
    return score;
}

int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur, int *mcp){
    int vMcp=-10000;
    int concurant_vMcp;
    int *fplateau;  //tableau de taille 64
    int useless;
    if (!(profondeur)){
        return calculPresScore(liste,valeurListe,couleur);
    }
    else{
        for (int i=0; i<64; i++){
            fplateau = malloc(sizeof(int)*64);
            for (int l=0; l<64; l++){
                fplateau[l]=liste[l];
            }
            if (changement(fplateau, i, couleur)){
                //afficherPlateau(liste);
                
                concurant_vMcp=(-1)*MinMax(fplateau, valeurListe, !(couleur),profondeur-1,&useless);
                //printf("\n\n nouveau plateau appelé\n au degré %d \ncoup testé %d,%d \nvaleur du plateau %d\n\n", profondeur-1, i/8,i%8 ,concurant_vMcp);
                //afficherPlateau(fplateau);

                //printf("\n\n ------------------------------------------------------------------------------------------\n\n");
                if (vMcp < concurant_vMcp){
                    vMcp=concurant_vMcp;
                    *mcp=i;
                }
            }
            free (fplateau);
        }
        if (vMcp==-10000){
            int useless1=0;
            int useless2=0;
            if(calculScore (liste, &useless1, &useless2) == couleur){
                vMcp=1000;
            }
            else if (calculScore (liste, &useless1, &useless2) != couleur){
                vMcp=-1000;
            }
            else{
                vMcp=0;
            }
        }
        return vMcp;    
    }
}