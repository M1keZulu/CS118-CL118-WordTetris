#include<stdio.h>
#include<conio.h>


void main(){
	
	char ch;
	
	while(1!=0){
		if(kbhit()){
			ch = getch();
			if(ch == 13){
				printf("hello");
			}
		}
	}
	
	
}
