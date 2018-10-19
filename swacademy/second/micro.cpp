#include <bits/stdc++.h>
using namespace std;

struct misang{
	int r;
	int c;
	int dir;
	int cnt;
};

int main(){
	int T, answer;
	int N, K, M;
	int coloring[100][100][5];
	queue<struct misang>q;
	int dx[5] = { 0, -1, 1, 0, 0 };
	int dy[5] = { 0, 0, 0, -1, 1 };
	scanf("%d", &T);
	for (int x = 1; x <= T; x++){
		answer = 0;
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++){
			struct misang tmp;
			scanf("%d %d %d %d", &tmp.r, &tmp.c, &tmp.cnt, &tmp.dir);
			q.push(tmp);
		}

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for(int k = 0; k < 5; k++) coloring[i][j][k] = 0;

		int ti = 0;
		while (ti < M){
			int len = q.size();
			for (int i = 0; i < len; i++){
				struct misang tmp = q.front();
				q.pop();
				tmp.r += dx[tmp.dir];
				tmp.c += dy[tmp.dir];
				if (tmp.r == 0 || tmp.r == N - 1 || tmp.c == 0 || tmp.c == N - 1){
					tmp.cnt /= 2;
					switch (tmp.dir){
					case 1: tmp.dir = 2; break;
					case 2: tmp.dir = 1; break;
					case 3: tmp.dir = 4; break;
					case 4: tmp.dir = 3; break;
					}
				}

				if (!coloring[tmp.r][tmp.c][0]){
					coloring[tmp.r][tmp.c][0] = tmp.dir;
					coloring[tmp.r][tmp.c][1] = tmp.cnt;
				}
				else{
					int index = 1;
					int chk = 1;
					while (coloring[tmp.r][tmp.c][index]){
						if (tmp.cnt < coloring[tmp.r][tmp.c][index]) chk = 0;
						index++;
					}
					coloring[tmp.r][tmp.c][index] = tmp.cnt;
					if (chk) coloring[tmp.r][tmp.c][0] = tmp.dir;
				}
			}

			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++){
					if (coloring[i][j][1]){
						struct misang tmp;
						tmp.r = i;
						tmp.c = j;
						tmp.dir = coloring[i][j][0];
						tmp.cnt = coloring[i][j][1];
						if (coloring[i][j][2]) tmp.cnt += coloring[i][j][2];
						if (coloring[i][j][3]) tmp.cnt += coloring[i][j][3];
						if (coloring[i][j][4]) tmp.cnt += coloring[i][j][4];
						q.push(tmp);
						coloring[i][j][0] = coloring[i][j][1] = coloring[i][j][2] = coloring[i][j][3] = coloring[i][j][4] = 0;
					}
				}
			}

			ti++;
		}

		while (!q.empty()){
			struct misang tmp = q.front();
			answer += tmp.cnt;
			q.pop();
		}
		printf("#%d %d\n", x, answer);
	}
}