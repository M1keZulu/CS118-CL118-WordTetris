#include<stdio.h>
#include<string.h>

struct score_handle{
	char name[100];
	int score;
	char mode[10];
};

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

void update_file(){
	FILE *ptr;
	ptr = fopen("test.txt", "w");
	int x;
	for(x=0;x<count;x++){
		fprintf(ptr, "?%s\n%d\n%s\n", h[x].name, h[x].score, h[x].mode);
	}
	fclose(ptr);
}

void main(){
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
	sorting();
	update_file();
	printf("%s - %d - %s\n", h[0].name, h[0].score, h[0].mode);
	printf("%s - %d - %s\n", h[1].name, h[1].score, h[1].mode);
	printf("%s - %d - %s\n", h[2].name, h[2].score, h[2].mode);
}
