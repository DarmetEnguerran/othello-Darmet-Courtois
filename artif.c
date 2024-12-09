#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "fonction.h"
#include "fartif.h"

int main(){
    int couleurCurrent= noir ;
    int couleurIA;
    int cp; 
    int profondeur =5;
    int valeurPlateau[64];
    printf("Qui commence ?'IA=1' 'joueur=0' :\n");
    scanf("%d",&couleurIA);
    completeVP(valeurPlateau,Vtriangle);
    while (1){
        afficherPlateau(plateau);
        if (couleurCurrent == couleurIA){
            int mcp=64;
            printf("valeur plateau: %d\n",MinMax(plateau, valeurPlateau, couleurCurrent, profondeur,&mcp));
            printf("\n\nValeur mcp = %d,%d\n", mcp/8+1,mcp%8+1);
            changement(plateau,mcp,couleurCurrent);
            couleurCurrent= !(couleurCurrent);
        }

        else {
            int n;
            scanf("%d",&n);
            cp=((n%10)-1)+((n/10)-1)*8;
            while( changement(plateau, cp, couleurCurrent) != 1){
                afficherPlateau(plateau);
                printf("\nrejouez\n");
                scanf("%d",&n);
                cp=((n%10)-1)+((n/10)-1)*8;
            }
            couleurCurrent= !(couleurCurrent);
        }
    }
    return 1;
}