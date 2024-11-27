#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fartif.h"

int main(){
    int couleurCurrent= noir ;
    int couleurIA;
    int cp;
    int profondeur
    printf("Qui commence ?'IA=1' 'joueur=0' :\n"),
    scanf(%d,&couleurIA);
    completeVP(valeurPlateau);
    while (1){
        afficherPlateau(plateau);
        if (couleurCurrent == couleurAI){
            cp = MinMax(plateau, valeurPlateau, couleurCurrent, profondeur);
            changement(plateau,cp,couleurCurrent);
            couleurCurrent= not(couleurCurrent);
        }
        else {
            scanf("%d",&n);
            cp=((n%10)-1)+((n/10)-1)*8;
            while( changement(plateau, cp, TableauCouleur[couleur]) != 1){
                afficherPlateau(plateau);
                printf("\nrejouez\n");
                scanf("%d",&n);
                cp=((n%10)-1)+((n/10)-1)*8;
            }

        }
    }
    return 1;
}