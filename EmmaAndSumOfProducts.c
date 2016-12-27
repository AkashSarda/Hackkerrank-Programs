#include<stdio.h>

int f(int *a, int size, int index, int sum, int max){
	if(index == size && max != 0){
		return 0; // means that the subset is still incomplete
	}else if(max == 0){
		// means the subset is complete
		return sum;
	}else{
	//	printf("max : %d, index : %d, %d\n", max, index, a[index]); 
		return f(a, size, index + 1, sum, max) + f(a, size, index + 1, sum * a[index], max - 1);
	}
}

int main(){
	int a[3], i;
	for(i = 0; i < 3; i++){
		a[i] = i + 1;
	}

	printf("%d", f(a, 3, 0, 1, 3)); // prototype is as follows : (array, size, index to start from, the product gathered till now, size of the subset
}



