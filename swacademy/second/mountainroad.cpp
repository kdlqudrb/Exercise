#include <bits/stdc++.h>
using namespace std;

int N, K, answer;
int mountain[8][8], coloring[8][8];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int> >q;

int isrange(int r, int c){
	if (r < 0 || c < 0) return 0;
	if (r >= N || c >= N) return 0;
	return 1;
}

void dfs(int r, int c, int gong, int depth){
	coloring[r][c] = 1;
	for (int i = 0; i < 4; i++){
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (coloring[nx][ny]) continue;
		if (isrange(nx, ny)){
			if (mountain[nx][ny] < mountain[r][c]){
				dfs(nx, ny, gong, depth + 1);
			}

			if (gong){
				for (int j = 1; j <= K; j++){
					if (mountain[nx][ny] - j < mountain[r][c]){
						mountain[nx][ny] -= j;
						dfs(nx, ny, 0, depth + 1);
						mountain[nx][ny] += j;
					}
				}
			}
		}
	}
	if (depth + 1 > answer) answer = depth + 1;
	coloring[r][c] = 0;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		scanf("%d %d", &N, &K);
		int m = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++){
				coloring[j][k] = 0;
				scanf("%d", &mountain[j][k]);
				if (m < mountain[j][k]) m = mountain[j][k];
			}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (m == mountain[j][k]) q.push(make_pair(j, k));

		while (!q.empty()){
			dfs(q.front().first, q.front().second, 1, 0);
			q.pop();
		}

		printf("#%d %d\n", i, answer);
	}
}