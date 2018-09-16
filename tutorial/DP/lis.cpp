#include <stdio.h>
void cho(int *ary){
	int i = 0;
	while (ary[i] != 0){
		ary[i] = 0;
		i++;
	}
}
int main(){
	int n, k, i, j, a, b, max, chk;
	int lis[500] = { 0, };
	int dy[500] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &k);
		for (j = 0; j < k; j++) scanf("%d", &lis[j]);
		max = 0;
		dy [0] = lis[0];
		for (a = 1; a < k; a++){
			b = 0;
			chk = 0;
			while (dy[b] != 0 && chk == 0){
				if (lis[a] < dy[b]){
					dy[b] = lis[a];
					chk++;
				}
				b++;
			}
			if (dy[b] == 0 && chk == 0) dy[b] = lis[a];
		}
		j = 0;
		while (dy[j] != 0){
			max++;
			j++;
		}
		cho(dy);
		cho(lis);
		printf("%d\n", max);
	}
}