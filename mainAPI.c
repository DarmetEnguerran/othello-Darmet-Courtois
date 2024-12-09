#include <stdlib.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "userNetwork.h"
#include "fonction.h" 

int main(int argc,char *argv[]) 
{
	game *g;
	int move; 

	if ((g=allocateGameOthello()) == NULL ) { return(EXIT_FAILURE); }

	if (argc > 3 ) { 
		g->userId=atoi(argv[3]); 
		g->address=argv[2]; 
	}
	else { fprintf(stderr,"usage : %s <userPasswd> <ip ad> <userId>\n",argv[0]); exit(-1); }

	g->port=8080; //par exemple

	if (registerGameOthello(g,argv[1]) < 0 ) { exit(-1); }	// test de l'authentification auprès du serveur 

	if (startGameOthello(g) < 0 ) { // cet appel est bloquant en attendant un adversaire 
		fprintf(stderr,"error Starting Game\n"); 
		return (EXIT_FAILURE); 
	}
	printf("I am player %s\n",(g->myColor==noir)?"Black":"White");
    afficherPlateau(plateau); 

	// debut de partie
	while (g->state == PLAYING && !feof(stdin)) {
	 	if (g->myColor != g->currentPlayer) { // attente du coup de l'adversaire 
			if ((move=waitMoveOthello(g)) == 0 ) {
				printf("Game status %d: \t",g->state); 
				if (g->state == PLAYING) { 
					printf("Received move from server %d (x=%d,y=%d)\n",g->move,g->move%8,g->move/8);
                    changement(plateau, g->move, g->currentPlayer);
                    afficherPlateau(plateau); 
				}
			}
		}
	 	else { 		
			g->move=65; // si scanf correct cette valeur est modifiée, sinon cela terminera la partie. 
            // recuperation du coup sur stdin 
            printf("Enter your move:\n");
			scanf("%d",&(g->move)); 
			printf("playing move %d (x=%d,y=%d)\n",g->move,g->move%8,g->move/8);
            changement(plateau, g->move, g->currentPlayer);
            afficherPlateau(plateau); 
			doMoveOthello(g);	// envoie du coup à l'adversaire 
	   	}
		g->currentPlayer=!g->currentPlayer; 
	} 
	// fin de partie 
	printf("Final game status = %d\n",g->state); 
	freeGameOthello(g);
	return 0; 
}



	
