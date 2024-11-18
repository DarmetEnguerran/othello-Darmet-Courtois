#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fonctiontest.h"

int main(){  // on etant en argument la ligne joué puis la collone puis enfin la couleur de qui joue.
    int fonctionne = 1;
    int couleurs_reponse=couleur_test;
    int sB_reponse;
    int sN_reponse;
    int victoir_reponse;
    
    afficherPlateau(plateau_test);
    

    //simulation du main
    if (changement(plateau_test, cptest, TableauCouleur[couleur_test]) != 1){
        printf("coup_non_valide\n");
    }
    
    afficherPlateau(plateau_test);
    
    else {
        if (Peutjouer(plateau_test, TableauCouleur[(couleur_test+1)%2])){
           couleurs_reponse = (couleur_test+1)%2;
        }
        else if (Peutjouer(plateau_test, TableauCouleur[(couleur_test)])){
           printf("Aucun coup valide pour %d\n", TableauCouleur[(couleur_test+1)%2]);
        }
        else {
            printf("Partie terminer");
            victoir_reponse = calculScore(plateau_test,&sB_reponse, &sN_reponse);
       }
    }    
    // pour vefier la fonction meme quand la partie n'est pas fini.
    victoir_reponse = calculScore(plateau_test,&sB_reponse, &sN_reponse);

    //Verification des resultats.
    if (couleurs_reponse != couleur_s_attendu){
        printf("Mauvais joueur suivant\n");
        fonctionne = 0;
    }
    if (sB_reponse != sB_attendu){
        printf("Mauvais score Blanc\n");
        fonctionne = 0;
    }
    if (sN_reponse != sB_attendu){
        printf("Mauvais score Noir\n");
        fonctionne = 0;
    }
    if (victoir_reponse != victoir_attendu){
        printf("Mauvais gagnant\n");
        fonctionne = 0;
    }

    if (verifier_egalite(plateau_test,plateau_attendu,64)){
        printf("Mauvais tableau\n");
        fonctionne = 0;
    }

    if (fonctionne == 1){
        prinf("Tout va bien\n")
    }
    return fonctionne;




}