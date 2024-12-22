// COURTOIS Maxance
// DARMET Enguerran

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "fonction.h"
#include "IAfonction.h"

//Comme le plateau possede beacoup de symetrie, on peut definir avec ce triangle une valeur pour chaque cases.
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

/* 
Fonction qui renvoit un entier correspondant a une estimation du plateau donné.
A chaque case est associcie une valeur, si cette cases est a nous alors on gagne sa valeur,
si elle est a l'adversaire on perd sa valeur.
*/
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


/*
Renvoie un entier correspondant a la meilleur valeur du plateau possible au bout de "profondeur" coup si tout le monde joue au mieux.
Modifie l'entier mcp (meilleur coup possible) en fonction de ce qu'il trouve et le mieux.
*/
int MinMax(int liste[64], int valeurListe[64], int couleur, int profondeur, int *mcp){
    int vMcp=-10000;
    int concurant_vMcp;
    int useless;
    //Quand on arrive au bout de la branche.
    if (!(profondeur)){
        return calculPresScore(liste,valeurListe,couleur);
    }
    else{
        for (int i=0; i<64; i++){
            // creation d'un tableau identique au parents qui va etre modifier puis analyser
            int fplateau [64];  
            for (int l=0; l<64; l++){
                fplateau[l]=liste[l];
            }
            if (changement(fplateau, i, couleur)){
                // la valeur du coup joué est l'inverse de meilleurs valeurs de l'adversaire apres ce coup. 
                concurant_vMcp=(-1)*MinMax(fplateau, valeurListe, !(couleur),profondeur-1,&useless);
                
                if (vMcp < concurant_vMcp){
                    vMcp=concurant_vMcp;
                    *mcp=i;
                };
            }
        }
        // si aucun coup n'a pue etre joué
        if (vMcp==-10000){
            // si l'adversaire peut joué.
            if ((Peutjouer(liste, !couleur))){
                vMcp=-30;  //il passe (-30 est la valeurs associé a passé)
            }
            // calcul du gagant
            else{
                int useless1=0;
                int useless2=0;
                if(calculScore (liste, &useless1, &useless2) == couleur){
                    vMcp=1000; //Victoire
                }
                else if (calculScore (liste, &useless1, &useless2) != couleur){
                    vMcp=-1000; //defaite
                }
                else{
                    vMcp=0; //match null
                }
            }
        }
        return vMcp;    
        }
}