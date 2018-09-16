#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}
int main(){
	int m, n, i, sum;
	int str[1000];
	scanf("%d", &m);
	while (m--){
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &str[i]);
		sum = 0;
		qsort(str, n, sizeof(int), compare);
		for (i = 0; i < n - 1; i++){
				str[1] += str[0];
				sum += str[1];
				str[0] = 987654321;
				qsort(str, n, sizeof(int), compare);
		}
		printf("%d\n", sum);
		for (i = 0; i < n; i++) str[i] = 0;
	}
}