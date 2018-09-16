#include <stdio.h>
#include <math.h>
int sort(int *ary, int *copy, int num){
	int i, j, temp, chk = 0;
	i = j = temp = 0;
	if (ary[i] < 0) chk = 1;
	while(1){
		if (i == num){
			copy[j] = temp;
			j++;
			break;
		}
		if (chk == 0){
			if (ary[i] >= 0) temp += ary[i];
			else{
				copy[j] = temp;
				temp = ary[i];
				j++;
				chk = 1;
			}
		}
		else{
			if (ary[i] <= 0) temp += ary[i];
			else{
				copy[j] = temp;
				temp = ary[i];
				j++;
				chk = 0;
			}
		}
		i++;
	}
	return j;
}
int main(){
	int n, i, j, k, num, sum, temp;
	int ary[100000];
	int copy[100000];
	scanf("%d", &n);
	while (n--){
		scanf("%d", &num);
		for(i = 0; i < num; i++) scanf("%d", &ary[i]);
		k = sort(ary, copy, num);
		sum = temp = 0;
		for (j = 0; j < k; j++){
			if (copy[j] >= 0) temp += copy[j];
			else{
				if (j == k - 1){
					if (temp > sum) sum = temp;
				}
				else if (j != 0){
					if (temp > sum) sum = temp;
					if (temp < -copy[j]) temp = 0;
					else temp += copy[j];
				}
			}
		}
		if (temp > sum) sum = temp;
		printf("%d\n", sum);
	}
}