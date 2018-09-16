#include <stdio.h>
#define MIN(X,Y) ((X)<(Y))?(X):(Y) 
int su[100] = { 0, };
int minus[101][101] = { 0, };
int chk[101][101] = { 0, };
void sort(int *ary, int length){
	int i, j, temp;
	for (i = 0; i < length; i++){
		for (j = i + 1; j < length; j++){
			if (ary[j] < ary[i]){
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}
int cal(int left, int right){
	int i, num, sum, bad;
	float avg = 0;
	num = right - left + 1;
	for (i = left; i <= right; i++){
		avg += su[i];
	}
	avg = (avg / num) + 0.5;
	bad = avg;
	sum = 0;
	for (i = left; i <= right; i++){
		sum += (bad - su[i]) * (bad - su[i]);
	}
	return sum;
}
int quan(int left, int right, int q){
	if (left > right) return 0;
	if (q == 0) return 987654321;
	if (chk[left][q] == 1) return minus[left][q];
	int sum, i;
	sum = 987654321;
	for (i = left; i <= right; i++){
		sum = MIN(sum, cal(left, i) + quan(i + 1, right, q - 1));
	}
	minus[left][q] = sum;
	chk[left][q] = 1;
	return sum;
}
int main(){
	int n, i, j, k, sl, q;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &sl, &q);
		for (j = 0; j < 101; j++){
			for (k = 0; k < 101; k++){
				minus[j][k] = 0;
				chk[j][k] = 0;
			}
		}
		for (j = 0; j < sl; j++) scanf("%d", &su[j]);
		sort(su, sl);
		printf("%d\n", quan(0, sl - 1, q));
	}
}