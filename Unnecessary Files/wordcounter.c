#include<stdio.h>

void main(){
	
	char str[10000] = "My ";
	
	int x;
	int words = 0;
	while(str[x] != '\0'){
		if(str[x] == ' '){
			words++;
		}
	x++;
	}
	
	printf("%d", words + 1);
	
}

