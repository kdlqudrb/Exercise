#include <bits/stdc++.h>
using namespace std;

int N, M, C, answer;
int honey[10][10], coloring[10][10];

void indfs(int r, int c, int chk, int now, int sum, int depth, int &ss){
	if (depth == M) return;
	if (chk){
		int tmp = now + honey[r][c];
		if (tmp > C) return;
		int tmp2 = sum + (honey[r][c] * honey[r][c]);
		if (tmp2 > ss) ss = tmp2;
		indfs(r, c + 1, 0, tmp, tmp2, depth + 1, ss);
		indfs(r, c + 1, 1, tmp, tmp2, depth + 1, ss);
	}
	else{
		indfs(r, c + 1, 0, now, sum, depth + 1, ss);
		indfs(r, c + 1, 1, now, sum, depth + 1, ss);
	}
}

void dfs2(int r, int c, int sum){
	int tmp = 0;
	for (int i = c; i < c + M; i++) if (coloring[r][i]) return;

	indfs(r, c, 0, 0, 0, 0, tmp);
	indfs(r, c, 1, 0, 0, 0, tmp);

	if (sum + tmp > answer) answer = sum + tmp;
}

void dfs1(int r, int c){
	int tmp = 0;
	indfs(r, c, 0, 0, 0, 0, tmp);
	indfs(r, c, 1, 0, 0, 0, tmp);

	for (int i = c; i < c + M; i++) coloring[r][i] = 1;
	for (int i = r; i < N; i++){
		for (int j = 0; j <= N - M; j++){
			dfs2(i, j, tmp);
		}
	}
	for (int i = c; i < c + M; i++) coloring[r][i] = 0;
}

void search(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= N - M; j++){
			dfs1(i, j);
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		scanf("%d %d %d", &N, &M, &C);
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++){
				scanf("%d", &honey[j][k]);
				coloring[j][k] = 0;
			}

		search();
		printf("#%d %d\n", i, answer);
	}
}