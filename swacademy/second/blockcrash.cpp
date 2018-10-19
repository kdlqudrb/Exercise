#include <bits/stdc++.h>
using namespace std;

int N, W, H, answer;
int block[15][12];
queue<pair<int, int> > q;

int cal(){
	int sum = 0;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (block[i][j]) sum++;
		}
	}
	return sum;
}

void blocksort(){
	for (int i = 0; i < W; i++){
		for (int j = H - 1; j >= 0; j--){
			if (!block[j][i]){
				for (int k = j - 1; k >= 0; k--){
					if (block[k][i]){
						block[j][i] = block[k][i];
						block[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void dfs(int index, int ball){
	int cpy[15][12];
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cpy[i][j] = block[i][j];

	for (int i = 0; i < H; i++){
		if (block[i][index]){
			q.push(make_pair(i, index));
			block[i][index] *= -1;
			break;
		}
	}

	if (q.empty()){
		int tmp = cal();
		if (tmp < answer) answer = tmp;
	}
	
	while (!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		int boomrange = block[r][c] * -1;
		block[r][c] = 0;
		for (int i = 1; i < boomrange; i++){
			if (r - i >= 0 && block[r - i][c] > 0){
				q.push(make_pair(r - i, c));
				block[r - i][c] *= -1;
			}
			if (r + i < H && block[r + i][c] > 0){
				q.push(make_pair(r + i, c));
				block[r + i][c] *= -1;
			}
			if (c - i >= 0 && block[r][c - i] > 0){
				q.push(make_pair(r, c - i));
				block[r][c - i] *= -1;
			}
			if (c + i < W && block[r][c + i] > 0){
				q.push(make_pair(r, c + i));
				block[r][c + i] *= -1;
			}
		}
	}

	if (ball == 1){
		int tmp = cal();
		if (tmp < answer) answer = tmp;
		for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) block[i][j] = cpy[i][j];
		return;
	}
	blocksort();

	for (int i = 0; i < W; i++) dfs(i, ball - 1);

	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) block[i][j] = cpy[i][j];
}

int main(){
	int T;

	scanf("%d", &T);
	for (int x = 1; x <= T; x++){
		answer = 987654321;
		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				scanf("%d", &block[i][j]);

		for(int i = 0; i < W; i++) dfs(i, N);
		printf("#%d %d\n", x, answer);
	}
}