#include<stdio.h>

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



void main(){
	
	int x;
	int z = 7;
	
	char wordlist[7000][29];
	
	FILE *fp;
	fp = fopen("wordlist.txt" , "r");
		for(x=1;x<7000;x++){
			fgets(wordlist[x], 29, fp);
		}
	fclose(fp);
	
	char str[29] = "ablaze     "; 
			
	printf("%s", wordlist[z]);
	
	printf("%d", compare(wordlist[z], "ablazde                 "));
	
	
}
