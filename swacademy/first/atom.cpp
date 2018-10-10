#include <bits/stdc++.h>
using namespace std;

struct atom{
	int x;
	int y;
	int dir;
	int energy;
	int avail;
};

int N, answer, head, tail;
int amap[4001][4001];
struct atom q[2000000];
struct atom cleanq[1000];

int main(){
	int T;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		answer = head = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			scanf("%d %d %d %d", &q[j].x, &q[j].y, &q[j].dir, &q[j].energy);
			q[j].x *= 2;
			q[j].x += 2000;
			q[j].y *= 2;
			q[j].y += 2000;
			q[j].avail = 1;
			amap[q[j].y][q[j].x] = 1;
		}
		
		tail = N;
		while (head != tail){
			int oldtail = tail;
			for (int j = head; j < oldtail; j++){
				if (!q[j].avail) continue;
				amap[q[j].y][q[j].x] = 0;
				switch (q[j].dir){
				case 0:{
					q[j].y++;
					break;
				}
				case 1:{
					q[j].y--;
					break;
				}
				case 2:{
					q[j].x--;
					break;
				}
				case 3:{
					q[j].x++;
					break;
				}
				}
				if (q[j].x < 0 || q[j].y < 0 || q[j].x > 4000 || q[j].y > 4000){
					continue;
				}
				else{
					q[tail].x = q[j].x;
					q[tail].y = q[j].y;
					q[tail].dir = q[j].dir;
					q[tail].energy = q[j].energy;
					q[tail].avail = 1;
					amap[q[j].y][q[j].x]++;
					tail++;
				}

				q[j].avail = 0;
			}

			int cnt = 0;
			for (int j = oldtail; j < tail; j++){
				if (amap[q[j].y][q[j].x] > 1){
					answer += q[j].energy;
					q[j].avail = 0;
					int chk = 0;
					for (int k = 0; k < cnt; k++){
						if (cleanq[k].x == q[j].x && cleanq[k].y == q[j].y) chk++;
					}
					if (!chk){
						cleanq[cnt].x = q[j].x;
						cleanq[cnt].y = q[j].y;
						cnt++;
					}
				}
			}

			for (int j = 0; j < cnt; j++) amap[cleanq[j].y][cleanq[j].x] = 0;
			cnt = 0;
			head = oldtail;
		}

		printf("#%d %d\n", i, answer);
	}
}