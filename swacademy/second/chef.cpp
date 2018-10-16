#include <bits/stdc++.h>
using namespace std;

int component[16][16];
int coloring[16];
int N, answer, bound;

void cal(){
	int cook1, cook2;
	cook1 = cook2 = 0;
	for (int i = 0; i < N; i++){
		if (coloring[i]){
			for (int j = 0; j < N; j++){
				if (i == j) continue;
				if (coloring[j]){
					cook1 += component[i][j];
				}
			}
		}
		else{
			for (int j = 0; j < N; j++){
				if (i == j) continue;
				if (!coloring[j]){
					cook2 += component[i][j];
				}
			}
		}
	}
	
	int tmp = abs(cook1 - cook2);
	if (tmp < answer) answer = tmp;
}

void dfs(int yori, int idx, int jori){
	if (idx >= N) return;
	if (yori){
		coloring[idx] = 1;
		if (jori + 1 == bound){
			cal();
			coloring[idx] = 0;
			return;
		}

		dfs(0, idx + 1, jori + 1);
		dfs(1, idx + 1, jori + 1);
		coloring[idx] = 0;
	}
	else{
		dfs(0, idx + 1, jori);
		dfs(1, idx + 1, jori);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 987654321;
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			coloring[j] = 0;
			for (int k = 0; k < N; k++)
				scanf("%d", &component[j][k]);
		}

		bound = N / 2;

		dfs(0, 0, 0);
		dfs(1, 0, 0);

		printf("#%d %d\n", i, answer);
	}
}