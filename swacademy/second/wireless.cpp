#include <bits/stdc++.h>
using namespace std;

struct AP{
	int x;
	int y;
	int C;
	int P;
	int avail;
};

int main(){
	int T, answer, M, A;
	int moveA[100], moveB[100];
	pair<int, int> peopleA, peopleB;
	struct AP ap[8];

	scanf("%d", &T);
	for (int x = 1; x <= T; x++){
		answer = 0;
		scanf("%d %d", &M, &A);
		for (int i = 0; i < M; i++) scanf("%d", &moveA[i]);
		for (int i = 0; i < M; i++) scanf("%d", &moveB[i]);
		for (int i = 0; i < A; i++) scanf("%d %d %d %d", &ap[i].x, &ap[i].y, &ap[i].C, &ap[i].P);

		peopleA.first = peopleA.second = 1;
		peopleB.first = peopleB.second = 10;

		int ti = 0;
		while (true){
			for (int i = 0; i < A; i++) ap[i].avail = 1;

			int P_tmp = 0;
			int tmp_prev = 0;
			for (int i = 0; i < A; i++){
				if (ap[i].avail && abs(peopleA.first - ap[i].x) + abs(peopleA.second - ap[i].y) <= ap[i].C){
					if (ap[i].P > P_tmp){
						ap[tmp_prev].avail = 1;
						ap[i].avail = 0;
						P_tmp = ap[i].P;
						tmp_prev = i;
					}
				}
			}

			int P_tmp2 = 0;
			tmp_prev = 0;
			for (int i = 0; i < A; i++){
				if (ap[i].avail && abs(peopleB.first - ap[i].x) + abs(peopleB.second - ap[i].y) <= ap[i].C){
					if (ap[i].P > P_tmp2){
						ap[tmp_prev].avail = 1;
						ap[i].avail = 0;
						P_tmp2 = ap[i].P;
						tmp_prev = i;
					}
				}
			}

			int sum = 0;
			if (P_tmp + P_tmp2 > sum) sum = P_tmp + P_tmp2;

			for (int i = 0; i < A; i++) ap[i].avail = 1;
			P_tmp2 = tmp_prev = 0;
			for (int i = 0; i < A; i++){
				if (ap[i].avail && abs(peopleB.first - ap[i].x) + abs(peopleB.second - ap[i].y) <= ap[i].C){
					if (ap[i].P > P_tmp2){
						ap[tmp_prev].avail = 1;
						ap[i].avail = 0;
						P_tmp2 = ap[i].P;
						tmp_prev = i;
					}
				}
			}

			P_tmp = tmp_prev = 0;
			for (int i = 0; i < A; i++){
				if (ap[i].avail && abs(peopleA.first - ap[i].x) + abs(peopleA.second - ap[i].y) <= ap[i].C){
					if (ap[i].P > P_tmp){
						ap[tmp_prev].avail = 1;
						ap[i].avail = 0;
						P_tmp = ap[i].P;
						tmp_prev = i;
					}
				}
			}
			if (P_tmp + P_tmp2 > sum) sum = P_tmp + P_tmp2;
			answer += sum;

			if (ti == M) break;

			switch (moveA[ti]){
			case 1: peopleA.second--; break;
			case 2: peopleA.first++; break;
			case 3: peopleA.second++; break;
			case 4: peopleA.first--; break;
			}

			switch (moveB[ti]){
			case 1: peopleB.second--; break;
			case 2:	peopleB.first++; break;
			case 3:	peopleB.second++; break;
			case 4:	peopleB.first--; break;
			}
			ti++;
		}

		printf("#%d %d\n", x, answer);
	}
}