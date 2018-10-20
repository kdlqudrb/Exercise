#include <bits/stdc++.h>
using namespace std;

struct cell{
	int state;
	int life;
	int val;
};

struct cell arr[352][352];
int cpy[352][352];

int main(){
	int T, answer;
	int N, M, K;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	scanf("%d", &T);

	for (int x = 1; x <= T; x++){
		answer = 0;
		scanf("%d %d %d", &N, &M, &K);
		int rbound = 150 + M + (K / 2);
		int lbound = 150 - (K / 2);
		int ubound = 150 - (K / 2);
		int dbound = 150 + N + (K / 2);
		for (int i = ubound; i <= dbound; i++) for (int j = lbound; j <= rbound; j++) cpy[i][j] = arr[i][j].life = arr[i][j].state = arr[i][j].val = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++){
				scanf("%d", &arr[i + 150][j + 150].val);
				if (arr[i + 150][j + 150].val){
					arr[i + 150][j + 150].state = 1;
					arr[i + 150][j + 150].life = arr[i + 150][j + 150].val;
				}
			}

		int ti = 0;
		while (ti < K){
			for (int i = ubound; i <= dbound; i++){
				for (int j = lbound; j <= rbound; j++){
					if (arr[i][j].state == 1){
						arr[i][j].life--;
						if (arr[i][j].life == 0){
							arr[i][j].life = arr[i][j].val;
							arr[i][j].state = 2;
						}
					}
					else if (arr[i][j].state == 2){
						if (arr[i][j].val == arr[i][j].life){
							for (int k = 0; k < 4; k++){
								int nx = i + dx[k];
								int ny = j + dy[k];
								if (arr[nx][ny].state == 0){
									if (cpy[nx][ny]){
										if (cpy[nx][ny] < arr[i][j].val)
											cpy[nx][ny] = arr[i][j].val;
									}
									else cpy[nx][ny] = arr[i][j].val;
								}
							}
						}
						arr[i][j].life--;
						if (arr[i][j].life == 0) arr[i][j].state = 3;
					}
				}
			}

			for (int i = ubound; i <= dbound; i++){
				for (int j = lbound; j <= rbound; j++){
					if (cpy[i][j]){
						arr[i][j].state = 1;
						arr[i][j].life = arr[i][j].val = cpy[i][j];
						cpy[i][j] = 0;
					}
				}
			}

			ti++;
		}

		for (int i = ubound; i <= dbound; i++){
			for (int j = lbound; j <= rbound; j++){
				if (arr[i][j].state == 1 || arr[i][j].state == 2) answer++;
			}
		}
		printf("#%d %d\n", x, answer);
	}
}