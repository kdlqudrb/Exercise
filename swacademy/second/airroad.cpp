#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, X, answer;
	int gmap[20][20], coloring[20][20];

	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		scanf("%d %d", &N, &X);
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++){
				coloring[j][k] = 0;
				scanf("%d", &gmap[j][k]);
			}

		for (int j = 0; j < N; j++){
			int prev = gmap[j][0];
			int pre_len = 1;
			int achk = 0;
			for (int k = 1; k < N; k++){
				if (coloring[j][k]) continue;
				if (prev == gmap[j][k]) pre_len++;
				else if (abs(gmap[j][k] - prev) > 1){
					achk++;
					break;
				}
				else if(prev > gmap[j][k]){
					if (k + X > N){
						achk++;
						break;
					}
					if (gmap[j][k + X - 1] != prev - 1){
						achk++;
						break;
					}
					for (int x = k + 1; x < k + X; x++){
						if (gmap[j][k] != gmap[j][x]){
							achk++;
							break;
						}
						coloring[j][x] = 1;
					}
					if (achk) break;
					prev--;
					pre_len = 0;
				}
				else{
					if (k - X < 0){
						achk++;
						break;
					}
					if (pre_len < X){
						achk++;
						break;
					}
					prev = gmap[j][k];
					pre_len = 1;
				}
			}
			if (!achk) answer++;
		}

		for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) coloring[j][k] = 0;

		for (int j = 0; j < N; j++){
			int prev = gmap[0][j];
			int pre_len = 1;
			int achk = 0;
			for (int k = 1; k < N; k++){
				if (coloring[k][j]) continue;
				if (prev == gmap[k][j]) pre_len++;
				else if (abs(gmap[k][j] - prev) > 1){
					achk++;
					break;
				}
				else if (prev > gmap[k][j]){
					if (k + X > N){
						achk++;
						break;
					}
					if (gmap[k + X - 1][j] != prev - 1){
						achk++;
						break;
					}
					for (int x = k + 1; x < k + X; x++){
						if (gmap[k][j] != gmap[x][j]){
							achk++;
							break;
						}
						coloring[x][j] = 1;
					}
					if (achk) break;
					prev--;
					pre_len = 0;
				}
				else{
					if (k - X < 0){
						achk++;
						break;
					}
					if (pre_len < X){
						achk++;
						break;
					}
					prev = gmap[k][j];
					pre_len = 1;
				}
			}
			if (!achk) answer++;
		}
		
		printf("#%d %d\n", i, answer);
	}
}