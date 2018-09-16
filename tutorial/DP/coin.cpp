#include <stdio.h>
int coin[101];
int totalCase[1000001];
int cal(int money, int coin_num);
int main(){
	int n, i, j;
	int money, coin_num;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j <= 100; j++) coin[j] = 0;
		for (j = 0; j <= 1000000; j++) totalCase[j] = 0;
		scanf("%d %d", &money, &coin_num);
		for (j = 1; j <= coin_num; j++) scanf("%d", &coin[j]);
		printf("%d\n", cal(money, coin_num));
	}
}
int cal(int money, int coin_num){
	int i, j;
	totalCase[0] = 1;
	for (i = 1; i <= coin_num; i++){
		for (j = 1; j <= money; j++){
			if (coin[i] <= money && j - coin[i] >= 0){
				totalCase[j] += totalCase[j - coin[i]];
				if (totalCase[j] > 1000000007) totalCase[j] -= 1000000007;
			}
		}
	}
	return totalCase[money];
}