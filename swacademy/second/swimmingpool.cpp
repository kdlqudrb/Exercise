#include <bits/stdc++.h>
using namespace std;

int answer;
int swim[3], calen[12], coloring[12];

void dfs(int howswim, int index, int sum){
	if (index == 12){
		if (sum < answer) answer = sum;
		return;
	}

    if(sum >= answer) return;
	if (coloring[index]){
		dfs(0, index + 1, sum);
		dfs(1, index + 1, sum);
		dfs(2, index + 1, sum);
	}

	int tmp;
	switch (howswim){
	case 0:{
		tmp = (sum + (swim[0] * calen[index]));
		coloring[index] = 1;
		dfs(0, index + 1, tmp);
		dfs(1, index + 1, tmp);
		dfs(2, index + 1, tmp);
		coloring[index] = 0;
		break;
	}
	case 1:{
		tmp = (sum + swim[1]);
		coloring[index] = 1;
		dfs(0, index + 1, tmp);
		dfs(1, index + 1, tmp);
		dfs(2, index + 1, tmp);
		coloring[index] = 0;
		break;
	}
	case 2:{
		tmp = (sum + swim[2]);
		coloring[index] = 1;
		if (index + 1 < 12) coloring[index + 1] = 1;
		if (index + 2 < 12) coloring[index + 2] = 1;
		dfs(0, index + 1, tmp);
		dfs(1, index + 1, tmp);
		dfs(2, index + 1, tmp);
		coloring[index] = 0;
		if (index + 1 < 12) coloring[index + 1] = 0;
		if (index + 2 < 12) coloring[index + 2] = 0;
		break;
	}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d %d", &swim[0], &swim[1], &swim[2], &answer);
		for (int j = 0; j < 12; j++){
			coloring[j] = 0;
			scanf("%d", &calen[j]);
		}

		dfs(0, 0, 0);
		dfs(1, 0, 0);
		dfs(2, 0, 0);

		printf("#%d %d\n", i, answer);
	}
}