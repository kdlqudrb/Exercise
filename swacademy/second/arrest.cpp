#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, answer;
	int N, M, R, C, L;
	int tunnel[50][50];
	int coloring[50][50];
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	queue<pair<int, int> >q;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				scanf("%d", &tunnel[j][k]);
				coloring[j][k] = 0;
			}
		}

		queue<pair<int, int> > sw;
		swap(q, sw);
		answer = 1;
		coloring[R][C] = 1;
		q.push(make_pair(R, C));
		int ti = 1;
		while (ti < L && !q.empty()){
			int len = q.size();
			for (int k = 0; k < len; k++){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				int swh[4] = { 0, 0, 0, 0 };
				switch (tunnel[x][y]){
				case 1:{
					swh[0] = swh[1] = swh[2] = swh[3] = 1;
					break;
				}
				case 2:{
					swh[0] = swh[2] = 1;
					break;
				}
				case 3:{
					swh[1] = swh[3] = 1;
					break;
				}
				case 4:{
					swh[0] = swh[1] = 1;
					break;
				}
				case 5:{
					swh[1] = swh[2] = 1;
					break;
				}
				case 6:{
					swh[2] = swh[3] = 1;
					break;
				}
				case 7:{
					swh[0] = swh[3] = 1;
					break;
				}
				}

				for (int j = 0; j < 4; j++){
					if (!swh[j]) continue;
					int nx = x + dx[j];
					int ny = y + dy[j];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (coloring[nx][ny]) continue;
					
					int inner_swh = 0;
					switch (j){
					case 0:{
						if (tunnel[nx][ny] == 1 || tunnel[nx][ny] == 2 || tunnel[nx][ny] == 5 || tunnel[nx][ny] == 6) inner_swh++;
						break;
					}
					case 1:{
						if (tunnel[nx][ny] == 1 || tunnel[nx][ny] == 3 || tunnel[nx][ny] == 6 || tunnel[nx][ny] == 7) inner_swh++;
						break;
					}
					case 2:{
						if (tunnel[nx][ny] == 1 || tunnel[nx][ny] == 2 || tunnel[nx][ny] == 4 || tunnel[nx][ny] == 7) inner_swh++;
						break;
					}
					case 3:{
						if (tunnel[nx][ny] == 1 || tunnel[nx][ny] == 3 || tunnel[nx][ny] == 4 || tunnel[nx][ny] == 5) inner_swh++;
						break;
					}
					}
					if (inner_swh){
						coloring[nx][ny] = 1;
						answer++;
						q.push(make_pair(nx, ny));
					}
				}
			}
			ti++;
		}

		printf("#%d %d\n", i, answer);
	}
}