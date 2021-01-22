#include<windows.h> 
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

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

void main(){
	
	int x = 0, y=0;
	char cc[10]; 
	int z;
	
	for(z=0;z<=100;z++){
		gotoxy(z,25);
		printf("-");
	}
	
	while(x<25){
		if (kbhit()){
            cc[y] = getch();
            printf("%c", cc);
            y++;
            if(strcmp(cc, "hello") == 0)
                break;
        }
		gotoxy(7,x);
		printf("hello");
		gotoxy(7,x);
		delay(100);
		printf("                             ");	
		x++;
	}

}
