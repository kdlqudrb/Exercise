#include <stdio.h>
void bag(int div[], int weight, int wlimit, int limit, int index, int &max){
	int w = weight;
	int k, sum = 0;
	for (k = 0; k <= index; k++) sum += div[k];
	if (max == 1) return;
	if (index < limit) return;
	if (w > wlimit) return;
	if (sum + w < wlimit) return;
	w += div[index];
	if (w == wlimit) max = 1;
	bag(div, w - div[index], wlimit, limit, index - 1, max);
	bag(div, w, wlimit, limit, index - 1, max);
}
int main(){
	int n, i, j, cnt, sum;
	int W[201];
	int chk;
	int div[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &W[i]);
	for (i = 0; i < n; i++){
		chk = 0;
		if (W[i] % 2 == 1){
			printf("not weird\n");
		}
		else{
			sum = 0;
			cnt = 0;
			for (j = 1; j <= W[i] / 2; j++){
				if (W[i] % j == 0){
					div[cnt] = j;
					cnt++;
				}
			}
			for (j = 0; j < cnt; j++) sum += div[j];
			if (sum < W[i])	printf("not weird\n");
			else{
				bag(div, 0, W[i], 0, cnt - 1, chk);
				if (chk == 1) printf("not weird\n");
				else printf("weird\n", W[i]);
			}
		}
	}
}