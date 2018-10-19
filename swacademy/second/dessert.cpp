#include <bits/stdc++.h>
using namespace std;

int N, answer;
int dmap[20][20], coloring[20][20];
int dessert[101];

int isrange(int r, int c){
	if (r < 0 || c < 0) return 0;
	if (r >= N || c >= N) return 0;
	return 1;
}

void dfs(int r, int c, int curve){
	if (coloring[r][c] == 2 && curve == 3){
		int sum = 0;
		for (int i = 1; i < 101; i++) if (dessert[i]) sum++;
		if (answer < sum) answer = sum;
		return;
	}
	if (dessert[dmap[r][c]]) return;

	if (coloring[r][c] == 0) coloring[r][c] = 1;
	dessert[dmap[r][c]]++;

	if (curve == 0){
		if (isrange(r + 1, c - 1) && coloring[r + 1][c - 1] == 0){
			dfs(r + 1, c - 1, 0);
		}
		if (isrange(r + 1, c + 1) && coloring[r + 1][c + 1] == 0){
			dfs(r + 1, c + 1, 1);
		}
	}
	else if (curve == 1){
		if (isrange(r + 1, c + 1) && coloring[r + 1][c + 1] == 0){
			dfs(r + 1, c + 1, 1);
		}
		if (isrange(r - 1, c + 1) && coloring[r - 1][c + 1] == 0){
			dfs(r - 1, c + 1, 2);
		}
	}
	else if (curve == 2){
		if (isrange(r - 1, c + 1) && coloring[r - 1][c + 1] == 0){
			dfs(r - 1, c + 1, 2);
		}
		if (isrange(r - 1, c - 1) && (coloring[r - 1][c - 1] == 0 || coloring[r - 1][c - 1] == 2)){
			dfs(r - 1, c - 1, 3);
		}
	}
	else if (curve == 3){
		if (isrange(r - 1, c - 1) && (coloring[r - 1][c - 1] == 0 || coloring[r - 1][c - 1] == 2)){
			dfs(r - 1, c - 1, 3);
		}
	}

	coloring[r][c] = 0;
	dessert[dmap[r][c]]--;
}

void dsearch(){
	for (int i = 0; i < N - 1; i++){
		for (int j = 1; j < N - 1; j++){
			coloring[i][j] = 2;
			dfs(i, j, 0);
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		for (int j = 1; j < 101; j++) dessert[j] = 0;

		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++){
				scanf("%d", &dmap[j][k]);
				coloring[j][k] = 0;
			}

		dsearch();
		if (!answer) answer = -1;
		printf("#%d %d\n", i, answer);
	}
}