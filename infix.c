#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*returns the index of first occurence of character ch*/
int breakacc(char ch, char *str){
	int i, j, len;
	len = strlen(str);
	for(i = 0; i < len; i++){
		if(str[i] == ch){
			return i;
		}
	}

	return 0;
}	

/* checked and verified*/
void copyintome(char *dest, char *source, int bound){
	int i;
	for(i = 0; i < bound; i++){
		dest[i] = source[i];
	}
	return;
}
/*as the name sounds infix expression evaluation*/
int evalforinfix(char *str){
	int i, num1, num2;
	char *str2 = (char *)malloc(strlen(str) * sizeof(char));
	
	i = breakacc('+', str);
	if(i){
		copyintome(str2, str, i);
		num1 = evalforinfix(str2);
		num2 = evalforinfix(str + i + 1);
		return num1 + num2;
	}
	
	i = breakacc('-', str);
	if(i){
		copyintome(str2, str, i);
		num1 = evalforinfix(str2);
		num2 = evalforinfix(str + i + 1);
		return num1 - num2;
	}	
	
	i = breakacc('*', str);
	if(i){
		copyintome(str2, str, i);
		num1 = evalforinfix(str2);
		num2 = evalforinfix(str + i + 1);
		return num1 * num2;
	}	
	
	i = breakacc('/', str);
	if(i){
		copyintome(str2, str, i);
		num1 = evalforinfix(str2);
		num2 = evalforinfix(str + i + 1);
		return num1 / num2;
	}

	return atoi(str);		
}

int main(){
	char str[20];
	char *a, *b;
	int i;
		
	printf("Enter a string\n");
	scanf("%s", str);

	printf("%d\n", evalforinfix(str));
	return 0;
}
