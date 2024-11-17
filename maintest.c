#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonction.h"
#include "fonctiontest.h"

int main(int argc, char *argv[]){  // on etant en argument la ligne joué puis la collone puis enfin la couleur de qui joue.
    if (argc != 3){
        printf ("erreur lors de la saisie des arguments\n");
        return 0;
    }
    int cp = ( argv[0] - '0' )*8 + (argv[1] -'0');
    if ((0 > cp) && (cp > 64)){
        printf("le coup jouer n'appar")
    }



}