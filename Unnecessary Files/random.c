#include<stdio.h>

int random(int array[]){
	
	int x;
	int z;
	
	z = rand()%10;
	printf("%d\n", z);
	
	for(x=0;x<10;x++){
		if(x == array[x]){
			random(array);
		}
	}
	
	return z;	
	
}

void main(){
	srand(time(0));
	
	int x;
	int arr[10];
	int sort[10];
	int z;
	
	for(x=0;x<10;x++){
		sort[x] = 0;
	}
	
	for(x=0;x<10;x++){
		z = random(sort);
		sort[x] = z;
		arr[x] = z;
	}
	
	for(x=0;x<10;x++){
		printf("%d\n", arr[x]);
	}
	
}
