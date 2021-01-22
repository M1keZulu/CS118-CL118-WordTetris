#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

#define ROW 17
#define COLUMN 25

char player1name[50];
char player2name[50];

char word[29] = {"hello"};

char wordlist[7000][29];

long long int score = 0;

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
	
	gotoxy(1,26);
	printf("Score - %lli", score);

	
}

int compare(char str1[], char str2[]){	
	int x;
	int y;
	x = 0;
	
	while(str1[x] != ' '){
		if(str1[x] != str2[x]){
			return 0;
		}
		x++;
	}
	
	return 1;

}
	
void print_game(){
	int x = 0, y=0;
	char cc[10]; 
	int z;
	
	int pos;
	pos = rand()%100;
	
	while(x<25){
		if (kbhit()){
            cc[y] = getch();
            y++;
            printf("%d", compare("hello      ", cc));
            if(compare("hello", cc) == 1)
                break;
        	}
		gotoxy(pos,x);
		printf("hello");
		gotoxy(pos,x);
		delay(100);
		printf("                             ");	
		x++;
	}
	
	if(x==25){
		score = score - 20;
	}
	else{
		score = score + 10;
	}
	
}

void main(){
	
	initialize_wordlist();
		
	while(score>=0){
		initialize_game();
		print_game();
	}
}





















