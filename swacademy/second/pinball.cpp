#include <bits/stdc++.h>
using namespace std;

struct pin{
	int r;
	int c;
	int dir;
	int cnt;
	pin(int a, int b, int d, int k){ r = a; c = b; dir = d; cnt = k; }
};

int pinball[102][102];
int coloring[102][102];
vector<pair<int, int> >wormhole[2];
int N, answer;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue <struct pin> q;

void pingame(int i, int j){
	struct pin tmp(0, 0, 0, 0);
	tmp.r = i;
	tmp.c = j;
	tmp.cnt = 0;
	for (int i = 0; i < 4; i++){
		tmp.dir = i;
		q.push(tmp);
	}

	while (!q.empty()){
		tmp = q.front();
		q.pop();
		
		if (coloring[tmp.r][tmp.c] == 5){
			if (tmp.cnt > answer) answer = tmp.cnt;
			continue;
		}
		else if (coloring[tmp.r][tmp.c]) coloring[tmp.r][tmp.c]++;

		if (pinball[tmp.r][tmp.c] == -1){
			if (tmp.cnt > answer) answer = tmp.cnt;
			continue;
		}
		else if (pinball[tmp.r][tmp.c] == 0){
			int nx = tmp.r + dx[tmp.dir];
			int ny = tmp.c + dy[tmp.dir];
			q.push(pin(nx, ny, tmp.dir, tmp.cnt));
		}
		else if (pinball[tmp.r][tmp.c] == -2){
			switch (tmp.dir){
			case 0: q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
			case 1:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
			case 2:	q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
			case 3: q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
			}
		}
		else if (pinball[tmp.r][tmp.c] >= 6){
			int len = wormhole[0].size();
			int nx, ny;
			for (int i = 0; i < len; i++){
				if (pinball[tmp.r][tmp.c] == pinball[wormhole[0][i].first][wormhole[0][i].second] && !(tmp.r == wormhole[0][i].first && tmp.c == wormhole[0][i].second)){
					nx = wormhole[0][i].first + dx[tmp.dir];
					ny = wormhole[0][i].second + dy[tmp.dir];
					q.push(pin(nx, ny, tmp.dir, tmp.cnt));
					break;
				}
				if (pinball[tmp.r][tmp.c] == pinball[wormhole[1][i].first][wormhole[1][i].second] && !(tmp.r == wormhole[1][i].first && tmp.c == wormhole[1][i].second)){
					nx = wormhole[1][i].first + dx[tmp.dir];
					ny = wormhole[1][i].second + dy[tmp.dir];
					q.push(pin(nx, ny, tmp.dir, tmp.cnt));
					break;
				}
			}
		}
		else{
			switch (pinball[tmp.r][tmp.c]){
			case 1:{
				switch (tmp.dir){
				case 0:	q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
				case 1:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
				case 2:	q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
				case 3: q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
				}
				break;
			}
			case 2:{
				switch (tmp.dir){
				case 0:	q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
				case 1:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
				case 2:	q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
				case 3: q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
				}
				break;
			}
			case 3:{
				switch (tmp.dir){
				case 0:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
				case 1:	q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
				case 2:	q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
				case 3: q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
				}
				break;
			}
			case 4:{
				switch (tmp.dir){
				case 0:	q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
				case 1:	q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
				case 2:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
				case 3: q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
				}
				break;
			}
			case 5:{
				switch (tmp.dir){
				case 0:	q.push(pin(tmp.r + 1, tmp.c, 2, tmp.cnt + 1)); break;
				case 1:	q.push(pin(tmp.r, tmp.c - 1, 3, tmp.cnt + 1)); break;
				case 2:	q.push(pin(tmp.r - 1, tmp.c, 0, tmp.cnt + 1)); break;
				case 3: q.push(pin(tmp.r, tmp.c + 1, 1, tmp.cnt + 1)); break;
				}
				break;
			}
			}
		}
	}
}

int main(){
	int T, w;
	scanf("%d", &T);
	for (int i = 0; i < 102; i++) pinball[0][i] = -2;
	for (int i = 0; i < 102; i++) pinball[i][0] = -2;

	for (int x = 1; x <= T; x++){
		answer = w = 0;
		scanf("%d", &N);
		wormhole[0].clear();
		wormhole[1].clear();
		for (int i = 0; i <= N + 1; i++) for (int j = 0; j <= N + 1; j++) coloring[i][j] = 0;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				scanf("%d", &pinball[i][j]);
				if (pinball[i][j] > 5){
					if (w & 1 << (pinball[i][j] - 6)) wormhole[1].push_back(make_pair(i, j));
					else{
						wormhole[0].push_back(make_pair(i, j));
						w |= 1 << (pinball[i][j] - 6);
					}
				}
			}
		}

		for (int i = 1; i <= N + 1; i++) pinball[N + 1][i] = -2;
		for (int i = 1; i <= N + 1; i++) pinball[i][N + 1] = -2;

		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (!pinball[i][j]){
					coloring[i][j] = 1;
					pingame(i, j);
					coloring[i][j] = 0;
				}
			}
		}

		printf("#%d %d\n", x, answer);
	}
}