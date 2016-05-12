#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* works correct*/
void exchange(char *str, int x, int y){
	char ch;
	if(str[x] != str[y]){
		ch = str[x];
		str[x] = str[y];
		str[y] = ch;
	}
	return;
}

void makeanagrams(char *str, int start){
	/* print the current string*/
//	printf("%s ::: %d \n ", str, start); 
	int i;	
	if(start == strlen(str) - 2){
		exchange(str, start, start + 1);
		printf("%s\n", str);
		return;
	}

	for(i = start + 1; i < strlen(str); i++){
		makeanagrams(str, start + 1);
		exchange(str, start, i);
		printf("%s ::: %d \n ", str, start);
	}
	
	
	return;
}

int main(){
	char *str;
	str = (char *)malloc(6*sizeof(char));
	scanf("%s", str);
	makeanagrams(str, 0);
}










