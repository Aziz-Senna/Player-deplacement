#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct Player{
    int x;
    int y;
}Player;

Player p1 = {15,32};
Player p2 = {15,33};

void renderControls(){
	printf("\033[27;1H");										//Position du curseur
	printf ("\033[1;37;46m");									//Couleur du texte en cyan
	printf("Controls:\n");
	printf("Player 1 -> Up : Z | Left : Q | Down : S | Right : D | Leave : X\n");
	printf("Player 2 -> Up : I | Left : J | Down : K | Right : L | Leave : X");
	printf("\033[?25l");										//Cacher le curseur
	printf("\033[0m");         									// <-- reset indispensable
    printf("\033[?25l");       									// cacher curseur	
}

void renderInfos(){	
	printf("\033[1;31m");
	printf("\033[1;75H");										//Se mettre à la position x = 75 et y = 1	
	printf(">>>> Information Debug <<<<\n");
	printf("\033[2;75H");										//Position du curseur
	printf("Player 1 position : %2d; %2d", p1.y, p1.x);			//Dire les coordonnées du p1
	printf("\033[3;75H");
	printf("Player 2 position : %2d; %2d", p2.y, p2.x);
	printf("\033[0m"); 	
}

void renderPlayer(){
	if(_kbhit() == 1){
		char touch = getch();
		switch(touch){
			//Player 1
			case 'z':
				if(p1.x > 4) p1.x --;
				break;
			case 'q':
				if(p1.y > 2) p1.y--;
				break;
			case 's':
				if(p1.x < 24) p1.x ++;
				break;
			case 'd':
				if(p1.y < 64) p1.y++;
				break;
				
			//Player 2
			case 'i':
				if(p2.x > 4) p2.x --;
				break;
			case 'j':
				if(p2.y > 2) p2.y--;
				break;
			case 'k':
				if(p2.x < 24) p2.x ++;
				break;
			case 'l':
				if(p2.y < 64) p2.y++;
				break;
				
			case 'x':
				system("cls");
				exit(0);
				break;
		}		
	}
	printf("\033[%d;%dH", p1.x, p1.y);
	printf("\033[1;35m");
	printf("@");
	Sleep(75);
	printf("\b");
	printf(" \b");
	Sleep(75);
	
	printf("\033[%d;%dH", p2.x, p2.y);
	printf("\033[1;35m");
	printf("$");
	Sleep(75);
	printf("\b");
	printf(" \b");
	Sleep(75);
	
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
