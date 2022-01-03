#include <stdio.h>
#include <stdlib.h>

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
	
	for(i=0;i<number;i++) {
		scanf("%d", &a[i]);
	}
	
	printf("%d\n", maxof(a, number));
	
	free(a);
	
	return 0;
}
