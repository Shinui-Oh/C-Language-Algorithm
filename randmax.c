#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for(i=1;i<n;i++) {
		if(a[i]>max) max = a[i];
	}
	
	return max;
}

int main(void) {
	int i, number;
	int *a;
	
	scanf("%d", &number);
	
	a = calloc(number, sizeof(int));
	
	srand(time(NULL));
	
	for(i=0;i<number;i++) {
		a[i] = 100 + rand() % 90;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	printf("%d\n", maxof(a, number));
	
	free(a);
	
	return 0;
}
