#include <bits/stdc++.h>
using namespace std;

struct atom{
	int x;
	int y;
	int dir;
	int energy;
};

struct atom q[2000000];
int cpy[4001][4001];
int coloring[4001][4001];

int main(){
	int T, answer, N;
	int head, tail;
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	scanf("%d", &T);
	for (int i = 0; i < 4001; i++) 
		for (int j = 0; j < 4001; j++){
			cpy[i][j] = -1;
			coloring[i][j] = 0;
		}

	for (int x = 1; x <= T; x++){
		head = tail = answer = 0;
		scanf("%d", &N);
		int tmpx, tmpy, tmpd, tmpe;
		for (int i = 0; i < N; i++){
			scanf("%d %d %d %d", &tmpx, &tmpy, &tmpd, &tmpe);
			tmpx *= 2;
			tmpy *= 2;
			tmpx += 2000;
			tmpy += 2000;
			q[tail].x = tmpx;
			q[tail].y = tmpy;
			q[tail].dir = tmpd;
			q[tail].energy = tmpe;
			tail++;
		}

		while (head != tail){
			int oldhead = head;
			int oldtail = tail;
			for (int i = oldhead; i < oldtail; i++){
				if (coloring[q[i].x][q[i].y]){
					answer += cpy[q[i].x][q[i].y];
					coloring[q[i].x][q[i].y] = 0;
					cpy[q[i].x][q[i].y] = -1;
					continue;
				}
				else cpy[q[i].x][q[i].y] = -1;

				int nx = q[i].x;
				int ny = q[i].y;
				nx += dx[q[i].dir];
				ny += dy[q[i].dir];
				if (nx < 0 || ny < 0 || nx > 4000 || ny > 4000) continue;
				if (cpy[nx][ny] > 0){
					cpy[nx][ny] += q[i].energy;
					coloring[nx][ny] = 1;
				}
				else{
					cpy[nx][ny] = q[i].energy;
					q[tail].x = nx;
					q[tail].y = ny;
					q[tail].dir = q[i].dir;
					q[tail].energy = q[i].energy;
					tail++;
				}
			}
			head = oldtail;
		}

		printf("#%d %d\n", x, answer);
	}
}