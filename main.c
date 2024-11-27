#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"


int main(){
   int n;
   int cp;
   int scoreB =0, scoreN =0;
   int TableauCouleur[2]={blanc,noir};
   int couleur=1;
   afficherPlateau(plateau);

   while(1) {
       scanf("%d",&n);
       cp=((n%10)-1)+((n/10)-1)*8;
       while( changement(plateau, cp, TableauCouleur[couleur]) != 1){
           printf("\nrejouez\n");
           scanf("%d",&n);
           cp=((n%10)-1)+((n/10)-1)*8;
       }
       afficherPlateau(plateau);
     
       if (Peutjouer(plateau,TableauCouleur[(couleur+1)%2])){
           couleur = (couleur+1)%2;
       }
       else if (Peutjouer(plateau,TableauCouleur[couleur])){
           printf("Aucun coup valide pour %d\n", TableauCouleur[(couleur+1)%2]);
       }
       else {
           printf("Partie terminée\n");
           calculScore(plateau, &scoreB, &scoreN);
          return 1;
       }
      
   }
}
