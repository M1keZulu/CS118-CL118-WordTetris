#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

char wordlist[7000][29];
char bonus[105][29];
int score = 3;
int s;

struct score_handle{
	char name[100];
	int score;
	char mode[10];
};

struct score_handle instance;
struct score_handle h[10000];
int count=0;

void sorting(){
	int x;
	int y;
	char temp[100];
	int t;
	for(x=0;x<10000;x++){
		for(y=0;y<10000-1;y++){
			if(h[y].score<h[y+1].score){
				
				t = h[y].score;
				h[y].score = h[y+1].score;
				h[y+1].score=t;
				
				strcpy(temp, h[y].name);
				strcpy(h[y].name, h[y+1].name);
				strcpy(h[y+1].name, temp);
				
				strcpy(temp, h[y].mode);
				strcpy(h[y].mode, h[y+1].mode);
				strcpy(h[y+1].mode, temp);
								
			}
		}
	}
}

void read_file(){
	int y;
	FILE *ptr;
	ptr = fopen("test.txt", "r");
	while(1){
		if(fgetc(ptr) == EOF){
			break;
		}
		fscanf(ptr, "%[^\n]%d%s\n", h[count].name, &h[count].score, h[count].mode);
		printf("%s - %d - %s\n", h[count].name, h[count].score, h[count].mode);
		count++;
	}
	fclose(ptr);
}

void update_file(){
	FILE *ptr;
	ptr = fopen("test.txt", "w");
	int x;
	for(x=0;x<count;x++){
		fprintf(ptr, "?%s\n%d\n%s\n", h[x].name, h[x].score, h[x].mode);
	}
	fclose(ptr);
}

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

void yellow(){
	system("");
	printf("\033[0;33m");
}

void initialize_wordlist(){
	int x;
	FILE *fp;
	fp = fopen("wordlist.txt" , "r");
		for(x=1;x<7000;x++){
			fgets(wordlist[x], 50, fp);
		}
	fclose(fp);
	fp = fopen("bonus.txt", "r");
		for(x=1;x<105;x++){
			fgets(bonus[x], 50, fp);
		}
	fclose(fp);
}

void delay(int ms){
    long del;
    clock_t start, end;
	end = clock();
    while((start-end) < ms)
        start = clock();
}

void graph(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initialize_game(){	
	
	int z;
	
	for(z=0;z<=100;z++){
		graph(z,25);
		printf("-");
	}
	
	graph(80,26);
	green();
	printf("Player Name - %s", instance.name);
	white();
	graph(80,27);
	printf("Score - %d", s);
	
	graph(1,26);
	
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

int compare(char str1[], char str2[]){	
	int x;
	int y;
	x = 0;
	
	while(str1[x] != ' ' && str1[x] != '\0' && str1[x] != '\n'){	
		if(str1[x] != str2[x]){
			return 0;
		}	
		x++;
	}	
	return 1;

}

void print_game(float del, int mode){
	int yaxis = 0, y = 0;
	char local[29];
	char temp;
	char current[100];
	
	int z = 0;
	int pos;
	int flag=0;
	
	if(rand()%10==2){
		strcpy(current, bonus[rand()%105]);
		flag=1;
	}
	else{
		strcpy(current, wordlist[rand()%7000]);
	}
	
	pos = rand()%100;
	
	while(yaxis<26){
		if(yaxis==25){
			if(flag==0){
				score--;	
			}
			break;
		}
		
		if(kbhit()){
            local[y] = getch();
        	
        	if(local[y] == 27){
        		score = -2;
        		break;
			}
        	
            if(local[y] == 13){       
            	if(compare(current, local) == 1){
            		green();
            		graph(pos,yaxis);
            		printf("%s", current);
            		delay(30);
            		white();
            		graph(pos,yaxis);
            		printf("                             ");
            		if(flag==1){
            			s+=strlen(current);
					}
					else{
						s++;	
					}
					break;
				}
				else if(compare(current, local) == 0){
					red();
            		graph(pos,yaxis);
            		printf("%s", current);
            		if(flag==0){
            			score--;
            		}
            		delay(500);
            		white();
            		graph(pos,yaxis);
            		printf("                             ");
					break;
				}
			}
            
			y++;
        }
		
		if(flag==1){
			yellow();
			graph(pos,yaxis);
			printf("%s", current);
			graph(pos,yaxis);
			delay(mode-del);
			printf("                             ");	
			yaxis++;
			white();
		}
		else{
			graph(pos,yaxis);
			printf("%s", current);
			graph(pos,yaxis);
			delay(mode-del);
			printf("                             ");	
			yaxis++;
		}
	}
	
}

void easy(){
	score = 3; 
	s=0;
	printf(" Please Enter Player Name: ");
	fflush(stdin);
	gets(instance.name);
	strcpy(instance.mode, "Easy");
	system("CLS");
	int del = 0.5;
	
	initialize_wordlist();
		
	while(score>0){
		initialize_game();
		print_game(del, 200);
		del+=0.5;
	}
	
	graph(1,26);
	red();
	printf("Lives - No lives remaining ");
	white();
	printf("Game ended!\n");
	instance.score = s;
	printf("Press any key to continue...");
	getch();
}

void advanced(){
	score = 3;
	s=0;
	printf(" Please Enter Player Name: ");
	fflush(stdin);
	gets(instance.name);
	strcpy(instance.mode, "Advanced");
	system("CLS");
	int del = 0.5;
	
	initialize_wordlist();
		
	while(score>0){
		initialize_game();
		print_game(del, 130);
		del+=0.5;
	}
	
	graph(1,26);
	red();
	printf("Lives - No lives remaining ");
	white();
	printf("Game ended!\n");
	instance.score = s;
	printf("Press any key to continue...");
	getch();
}

void freee(){
	char escape;
	s=0;
	printf(" Please Enter Player Name: ");
	fflush(stdin);
	gets(instance.name);
	strcpy(instance.mode, "Free");
	system("CLS");
	int del = 0.5;
	
	initialize_wordlist();
		
	while(score!=-2){
		score = 3;
		initialize_game();
		print_game(del, 200);
		del+=0.5;
	}
	
	graph(1,26);
	red();
	printf("Lives - No lives remaining ");
	white();
	printf("Game ended!\n");
	instance.score = s;
	printf("Press any key to continue...");
	getch();
}

void display_highscore(){
	system("CLS");
	int x;
	printf("--------------------------------------------------\n\t\t   High Scores\n--------------------------------------------------\n");
	sorting();
	printf(" Player Name\t\tScore\t\tMode\n");
	printf(" -----------\t\t-----\t\t----\n");
	for(x=0;x<count;x++){
		printf(" %s\t\t%d\t\t%s\n", h[x].name, h[x].score, h[x].mode);
	}
	printf("\nPress any key to continue...");
	getch();
}

int mode_selection(){
	srand(time(0));
	system("CLS");
	int choice = -1;
	printf("\t\tWord Tetris\n--------------------------------------------------\n\n 1. Easy\n 2. Advanced\n 3. Free\n 4. View Highscores\n 5. Exit Game\n\n");
	printf(" Instructions\n ------------\n Please choose a mode to play.\n Easy Mode is recommended for players with slow typing speeds while free mode is for practice.\n To exit in any mode including Free press the ESCAPE key. There is no life in free mode.\n Please keep in mind that you only have one try for each word till you press enter so type with caution!\n The words colored Yellow are bonus words which do not cost any life but add points worth their length to the score.");
	printf("\n\n Select Mode: ");
	scanf(" %d", &choice);
	if(choice==1){
		easy();
	}
	else if(choice==2){
		advanced();
	}
	else if(choice==3){
		freee();
	}
	else if(choice==4){
		display_highscore();
		return 4;
	}
	else if(choice==5){
		exit(0);
	}
}

void main(){
	read_file();
	int x;
	int flag=1;
	while(1){
		if(mode_selection()==4){
			continue;
		}
		for(x=0;x<count;x++){
			if(strcmp(h[x].name, instance.name) == 0 && strcmp(h[x].mode, instance.mode) == 0 && instance.score>h[x].score){
				h[x].score = instance.score;
				flag = 0;
				break;
			}
			else if(strcmp(h[x].name, instance.name) == 0 && strcmp(h[x].mode, instance.mode) == 0 && instance.score<=h[x].score){
				flag=0;
			}
		}
		if(flag!=0){
			strcpy(h[count].name, instance.name);
			strcpy(h[count].mode, instance.mode);
			h[count].score = instance.score;
			count++;
			flag=1;
		}
		update_file();
	}
}

