#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include <unistd.h>

#define ROW 17
#define COLUMN 25

char playername[50];

char wordlist[7000][29];

int score = 3;

void red(){
	system("");
	printf("\033[31m");
}

void green(){
	system("");
	printf("\033[32m");
}

void white(){
	system("");
	printf("\033[0m");
}

void initialize_wordlist(){
	int x;
	FILE *fp;
	fp = fopen("wordlist.txt" , "r");
		for(x=1;x<7000;x++){
			fgets(wordlist[x], 50, fp);
		}
	fclose(fp);
}

void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initialize_game(){	
	
	int z;
	
	for(z=0;z<=100;z++){
		gotoxy(z,25);
		printf("-");
	}
	
	gotoxy(80,26);
	green();
	printf("Player Name - %s", playername);
	white();
	
	
	gotoxy(1,26);
	
	red();
	if(score == 3){
		printf("Lives - \x03 \x03 \x03");
	}
	else if(score == 2){
		printf("Lives - \x03 \x03     ");
	}
	else if(score == 1){
		printf("Lives - \x03          ");
	}
	else{
		printf("Lives -               ");
	}
	white();

	
}

int compare(char str1[], char str2[], int count){	
	int x;
	int y;
	int check = 2;
	x = 0;
		
		if(str1[count] == str2[count] && str1[count+1] == '\n'){
			return 2;
		}
		if(str1[count] == str2[count]){
			return 1;
		}
		else{
			return 0;
		}
		
}

void print_game(float del){
	int x = 0, y = 0;
	char cc[29];
	 
	int z = 0;
	
	int pos;
	pos = rand()%100;
	
	z = rand()%7000;
	
	while(x<26){
		if(x==25){
			score--;
			break;
		}
		if(kbhit()){
            cc[y] = getch();
            if(compare(wordlist[z], cc, y) == 2){
            	green();
            	gotoxy(pos,x);
            	printf("%s", wordlist[z]);
            	white();
            	gotoxy(pos,x);
				delay(30);
				printf("                             ");
				break;
			}
			else if(compare(wordlist[z], cc, y) == 0){
				red();
            	gotoxy(pos,x);
            	printf("%s", wordlist[z]);
            	delay(500);
            	white();
            	gotoxy(pos,x);
				printf("                             ");
				score--;
				break;
			}
            y++;
        }
		gotoxy(pos,x);
		printf("%s", wordlist[z]);
		gotoxy(pos,x);
		delay(100-del);
		printf("                             ");	
		x++;
	}
	
}

void main(){
	
	printf("Please Enter Player Name: ");
	gets(playername);
	system("CLS");
	int check;
	int del = 0.5;
	
	initialize_wordlist();
		
	while(score>0){
		initialize_game();
		print_game(del);
		del+=0.5;
	}
	
	gotoxy(1,26);
	red();
	printf("Lives - No lives remaining ");
	white();
	printf("Game ended!");
	
	scanf("%d");
	
	
}



