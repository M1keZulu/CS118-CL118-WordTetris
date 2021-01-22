#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void red(){
	printf("\033[0;31m%s"); 
}

void green(){
	printf("\033[0;32m");
}

void white(){
	printf("\033[0m %s", "Zain");
}


void main(){
	
	system("");	
	printf("\033[32;1mTest");
	printf("\033[0;31m");
	printf("\033[1m");
	printf("Hello");
	
}


