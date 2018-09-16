#include <stdio.h>
int grid(int k){
	if (k == 1) return 1;
	if (k == 2) return 5;
	if (k == 3) return 11;
	int i = k;
	int j = 0;
	int sum = 0;
	for (i; i > 1; i--){
		if (i == k){
			sum += grid(i - 1);
			j++;
		}
		else if (i + 1 == k){
			sum += 4 * grid(i - 1);
			j++;
		}
		else if (j % 2 == 0){
			sum += 2 * grid(i - 1);
			j++;
		}
		else {
			sum += 3 * grid(i - 1);
			j++;
		}
	}
	if (k % 2 == 1) sum += 2;
	else sum += 3;
	return sum;
}
int main(){
	int n, i;
	int ans[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &ans[i]);
		ans[i] = grid(ans[i]);
	}
	for (i = 0; i < n; i++)	printf("%d %d\n", i + 1, ans[i]);
}