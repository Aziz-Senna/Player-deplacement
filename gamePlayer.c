#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct Player{
    int x;
    int y;
}Player;

Player player = {15,32};

void renderControls(){
	printf("\033[29;1H");										//Position du curseur
	printf ("\033[1;37;46m");									//Couleur du texte en cyan
	printf("Controls:\n");
	printf("Up : Z | Left : Q | Down : S | Right : D | Leave : X");
	printf("\033[?25l");										//Cacher le curseur
	printf("\033[0m");         									// <-- reset indispensable
    printf("\033[?25l");       									// cacher curseur	
}

void renderInfos(){	
	printf("\033[1;31m");
	printf("\033[1;75H");										//Se mettre à la position x = 75 et y = 1	
	printf(">>>> Information Debug <<<<\n");
	printf("\033[2;75H");										//Position du curseur
	printf("Player position : %2d; %2d", player.y, player.x);	//Dire les coordonnées du player
	printf("\033[0m"); 	
}

void renderPlayer(){
	if(_kbhit() == 1){
		char touch = getch();
		switch(touch){
			case 'z':
				if(player.x > 4) player.x --;
				break;
			case 'q':
				if(player.y > 2) player.y--;
				break;
			case 's':
				if(player.x < 24) player.x ++;
				break;
			case 'd':
				if(player.y < 64) player.y++;
				break;
			case 'x':
				system("cls");
				exit(0);
				break;
		}		
	}
	printf("\033[%d;%dH", player.x, player.y);
	printf("\033[1;35m");
	printf("@");
	Sleep(100);
	printf("\b");
	printf(" \b");
	Sleep(100);
}

int main(){
	int i;
	for(i = 0 ; i < 65 ; i++){
		printf("\033[3;%dH", i);
		printf("-");
		printf("\033[25;%dH", i);
		printf("-");
	}
	for(i = 3 ; i < 26 ; i++){
		printf("\033[%d;1H", i);
		printf("|");
		printf("\033[%d;65H", i);
		printf("|");
	}
	
	while(1){
		renderPlayer();				//Affiche le sprite à la bonne position		
		renderControls();			//Affichage des touches
		renderInfos();		 		//Affichage du debug du perso	
 					 		
	}
    return 0;
}

/*Je fais un Buffer de pixel mais il y a une façon bien plus simple.
    char tableau[24][64];
    int i, j; 
	while(1){
		for(i = 0 ; i < 24 ; i++){
	        for(j = 0 ; j < 64 ; j++){
	        	printf("\033[?25l");						//Cacher le curseur
	        	printf("\033[1;37m");						//Couleur blanche de base
	        	tableau[i][j] = 32;							//Code ascii de la touche espace
	        	if(i == 12 && j == 32){
	        		tableau[i][j] = 64;						//Code ascii de @.
					printf("\033[1;35m");					//Couleur mauve pour le caractere @	
				}
	            printf("%1c", tableau[i][j]);
	        }
        	printf("\n");
    	}
		system("cls");
		//Sleep(50);	
	}*/
