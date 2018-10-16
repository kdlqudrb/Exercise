#include <bits/stdc++.h>
using namespace std;

int giho[4], num[12];
int N, maxval, minval;

void dfs(int gindex, int depth, int sum){
	int tmp;
	switch (gindex){
	case 0:{
		tmp = sum + num[depth];
		break;
	}
	case 1:{
		tmp = sum - num[depth];
		break;
	}
	case 2:{
		tmp = sum * num[depth];
		break;
	}
	case 3:{
		tmp = sum / num[depth];
		break;
	}
	}

	giho[gindex]--;
	if (giho[0]) dfs(0, depth + 1, tmp);
	if (giho[1]) dfs(1, depth + 1, tmp);
	if (giho[2]) dfs(2, depth + 1, tmp);
	if (giho[3]) dfs(3, depth + 1, tmp);
	giho[gindex]++;

	if (depth == N - 1){
		if (maxval < tmp) maxval = tmp;
		if (minval > tmp) minval = tmp;
		return;
	}
}

int main(){
	int T, answer;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		scanf("%d", &N);
		scanf("%d %d %d %d", &giho[0], &giho[1], &giho[2], &giho[3]);
		for (int j = 0; j < N; j++) scanf("%d", &num[j]);
		maxval = -987654321;
		minval = 987654321;

		if (giho[0]) dfs(0, 1, num[0]);
		if (giho[1]) dfs(1, 1, num[0]);
		if (giho[2]) dfs(2, 1, num[0]);
		if (giho[3]) dfs(3, 1, num[0]);

		answer = maxval - minval;
		printf("#%d %d\n", i, answer);
	}
}