#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}
int main() {
	int n, i, su, sum;
	int nam[10000];
	int yu[10000];
	scanf("%d", &n);
	while (n--) {
		sum = 0;
		scanf("%d", &su);
		for (i = 0; i < su; i++) scanf("%d", &nam[i]);
		for (i = 0; i < su; i++) scanf("%d", &yu[i]);
		qsort(nam, su, sizeof(int), compare);
		qsort(yu, su, sizeof(int), compare);
		for (i = 0; i < su; i++) {
			sum += abs(nam[i] - yu[i]);
		}
		printf("%d\n", sum);
	}
}