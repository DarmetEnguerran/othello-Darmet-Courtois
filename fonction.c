#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"

extern int plateau[64]=
                {0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,2,1,0,0,0,
                0,0,0,1,2,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0};

void afficherPlateau(int liste[64])
{
 int i;
 int j;
 printf("      ");
 for (j =0; j<8; j++)
 {
     printf("-%d- ",(j+1));
 }
 printf("\n");
 for (i =0; i<63; i++)
{  
      if(i%8 == 0)
     {
         printf("-%d-  ",(i/8)+1);
     }
      if(liste[i]!=0){
          printf("| %d ", liste[i]);
      }
      else{
          printf("|   ");
      }
     if (i%8 == 7)
     {
         printf("| \n\n");
     }
 }
 printf("| %d |\n ", liste[63]);
 for (j =0; j<8; j++)
 {
     printf("--- ");
 }
 printf("\n");
}


//fonction changment retourne 1 si le coup est valide 0 sinon
int changement(int liste[64],int cp, int couleur){
   //definition des variables
  int i,j,v,d;
  bool ch=0;
  int ami=couleur;
  int ennemie;
  if (couleur== blanc )ennemie=noir;
      else  ennemie = blanc;
  if (liste[cp]!= vide){
      printf("le coup est invalide, case non vide");
      return 0;
  }

  // Calcul du nombre de pion à changer
  for (i=-1; i <= 1;i++){
      for (j=-1;j<= 1;j++){
          v = j+i*8;
          d=1;
          while ((liste[cp+d*v]==ennemie) && ((cp+d*v>=0) &&  (cp+d*v<=64)) && ( j*((cp+d*v)%8) <= j*((cp+(d+1)*v) % 8))) {
              d++;
          }
  //changment des pions
        
          if (( liste[cp+d*v]==ami) && (d>1)){
              ch=1;
              for (int n=0; n < d; n++){
                  liste[cp+n*v] =ami;
              }
          }
      }
  }
  if (ch == 0) printf("coup non valide, pas de pions adverse adj\n");
  return ch;
}


int Peutjouer(int liste[64], int couleur){
    int ami = couleur;
    int ennemie;
    if (couleur== blanc )ennemie=noir;
        else  ennemie = blanc;
    
    for (int cp=0;cp<64;cp++){
    
        if (liste[cp]== vide){
            for (int i =-1; i<= 1; i++ ){
                for (int j=-1; j<=1; j++){
                    int v= j+i*8;
                    int d=1;
                    while ((liste[cp+d*v]==ennemie) && ((cp+d*v>=0) &&  (cp+d*v<=64)) && ( j*((cp+d*v)%8) <= j*((cp+(d+1)*v) % 8))) {
                        d++;
                    }
                    if (( liste[cp+d*v]==ami) && (d>1)){
                        return 1;
                    }

                }
            }
        }
    }
    return 0;
}


