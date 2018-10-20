#include <bits/stdc++.h>
using namespace std;

int home[20][20];
int N;

int cnthome(int r, int c, int size){
	int sum = 0;
	int cpow = size - 1;
	int rpow = 0;
	for (int i = 0; i < size; i++){
		int ur = r - rpow;
		int dr = r + rpow;
		int rc = c + cpow;
		int lc = c - cpow;
		for (int j = lc; j <= rc; j++){
			if (j < 0 || j >= N) continue;
			if (ur >= 0 && home[ur][j]) sum++;
			if (ur == dr) continue;
			if (dr < N && home[dr][j]) sum++;
		}
		cpow--;
		rpow++;
	}

	return sum;
}

int main(){
	int T, answer;
	int M, ho;
	int cost[22];
	scanf("%d", &T);

	int pow = 4;
	cost[1] = 1;
	for (int i = 2; i < 22; i++){
		cost[i] = cost[i - 1] + pow;
		pow += 4;
	}

	for (int x = 1; x <= T; x++){
		answer = ho = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++){
				scanf("%d", &home[i][j]);
				if (home[i][j]) ho++;
			}

		int chk = 0;
		if (ho * M >= cost[21]){
			answer = ho;
			chk = 1;
		}

		for (int i = N + 1; i > 1; i--){
			if (chk) break;
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					int hcnt = cnthome(j, k, i);
					if (hcnt * M >= cost[i]){
						if(answer < hcnt) answer = hcnt;
						chk++;
					}
				}
			}
		}

		if (!chk) answer = 1;
		printf("#%d %d\n", x, answer);
	}
}