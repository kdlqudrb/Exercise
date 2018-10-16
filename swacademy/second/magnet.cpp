#include <bits/stdc++.h>
using namespace std;

deque<int> magnet[4];
int coloring[4];

void rot(int num, int dir){
	if (num < 0 || num > 3) return;
	if (coloring[num]) return;
	coloring[num] = 1;

	if (dir == 1){
		if (num < 3 && magnet[num][2] != magnet[num + 1][6]){
			rot(num + 1, -1);
		}
		if (num > 0 && magnet[num][6] != magnet[num - 1][2]){
			rot(num - 1, -1);
		}
		int tmp = magnet[num][7];
		magnet[num].pop_back();
		magnet[num].push_front(tmp);
		
	}
	else{
		if (num < 3 && magnet[num][2] != magnet[num + 1][6]){
			rot(num + 1, 1);
		}
		if (num > 0 && magnet[num][6] != magnet[num - 1][2]){
			rot(num - 1, 1);
		}
		int tmp = magnet[num][0];
		magnet[num].pop_front();
		magnet[num].push_back(tmp);
	}
}

int main(){
	int T, K, answer;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = 0;
		scanf("%d", &K);
		int tmp;
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 8; k++){
				scanf("%d", &tmp);
				magnet[j].push_back(tmp);
			}

		int num, dir;
		for (int j = 0; j < K; j++){
			scanf("%d %d", &num, &dir);
			coloring[0] = coloring[1] = coloring[2] = coloring[3] = 0;
			rot(num - 1, dir);
		}

		int pow = 1;
		for (int j = 0; j < 4; j++){
			answer += pow * magnet[j][0];
			pow *= 2;
		}
		printf("#%d %d\n", i, answer);

		for (int j = 0; j < 8; j++){
			magnet[0].pop_back();
			magnet[1].pop_back();
			magnet[2].pop_back();
			magnet[3].pop_back();
		}
	}
}