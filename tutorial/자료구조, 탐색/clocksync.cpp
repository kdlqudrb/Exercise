#include <stdio.h>
// 너무 느림... 속도 향상 방법???
bool chk(int *clk){
	int q, p = 0;
	int sum[16] = { 0, };
	for (q = 0; q < 16; q++){
		if ((clk[q] % 12) == 0) sum[q]++;
	}
	for (q = 0; q < 16; q++) if (sum[q] == 1) p += sum[q];
	if (p == 16) return true;
	else return false;
}
void swh(int *clk, int num, int h, int &cnt){
	int i;
	for (i = 0; i < h; i++){
		switch (num){
		case 0: clk[0] += 3; clk[1] += 3; clk[2] += 3; cnt++; break;
		case 1: clk[3] += 3; clk[7] += 3; clk[9] += 3; clk[11] += 3; cnt++; break;
		case 2: clk[4] += 3; clk[10] += 3; clk[14] += 3; clk[15] += 3; cnt++; break;
		case 3: clk[0] += 3; clk[4] += 3; clk[5] += 3; clk[6] += 3; clk[7] += 3; cnt++; break;
		case 4: clk[6] += 3; clk[7] += 3; clk[8] += 3; clk[10] += 3; clk[12] += 3; cnt++; break;
		case 5: clk[0] += 3; clk[2] += 3; clk[14] += 3; clk[15] += 3; cnt++; break;
		case 6: clk[3] += 3; clk[14] += 3; clk[15] += 3; cnt++; break;
		case 7: clk[4] += 3; clk[5] += 3; clk[7] += 3; clk[14] += 3; clk[15] += 3; cnt++; break;
		case 8: clk[1] += 3; clk[2] += 3; clk[3] += 3; clk[4] += 3; clk[5] += 3; cnt++; break;
		case 9: clk[3] += 3; clk[4] += 3; clk[5] += 3; clk[9] += 3; clk[13] += 3; cnt++; break;
		}
	}
}
void hws(int *clk, int num, int h, int &cnt){
	int i;
	for (i = 0; i < h; i++){
		switch (num){
		case 0: clk[0] -= 3; clk[1] -= 3; clk[2] -= 3; cnt--; break;
		case 1: clk[3] -= 3; clk[7] -= 3; clk[9] -= 3; clk[11] -= 3; cnt--; break;
		case 2: clk[4] -= 3; clk[10] -= 3; clk[14] -= 3; clk[15] -= 3; cnt--; break;
		case 3: clk[0] -= 3; clk[4] -= 3; clk[5] -= 3; clk[6] -= 3; clk[7] -= 3; cnt--; break;
		case 4: clk[6] -= 3; clk[7] -= 3; clk[8] -= 3; clk[10] -= 3; clk[12] -= 3; cnt--; break;
		case 5: clk[0] -= 3; clk[2] -= 3; clk[14] -= 3; clk[15] -= 3; cnt--; break;
		case 6: clk[3] -= 3; clk[14] -= 3; clk[15] -= 3; cnt--; break;
		case 7: clk[4] -= 3; clk[5] -= 3; clk[7] -= 3; clk[14] -= 3; clk[15] -= 3; cnt--; break;
		case 8: clk[1] -= 3; clk[2] -= 3; clk[3] -= 3; clk[4] -= 3; clk[5] -= 3; cnt--; break;
		case 9: clk[3] -= 3; clk[4] -= 3; clk[5] -= 3; clk[9] -= 3; clk[13] -= 3; cnt--; break;
		}
	}
}
void sync(int *clk, int index, int h, int &cnt){
	if (chk(clk)) return;
	if (index > 9) return;
	int i;
	swh(clk, index, h, cnt);
	for (i = 0; i < 4; i++){ sync(clk, index + 1, i, cnt); }
	if (chk(clk)) return;
	hws(clk, index, h, cnt);
}
int ready(int *clk){
	int i, cnt = 0;
	if (chk(clk)) return 0;
	for(i = 0; i < 4; i++) sync(clk, 0, i, cnt);
	if(cnt > 0) return cnt;
	else return -1;
}
int main(){
	int n, i;
	int clk[16] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &clk[0], &clk[1], &clk[2], &clk[3], &clk[4], &clk[5], &clk[6], &clk[7], &clk[8], &clk[9], &clk[10], &clk[11], &clk[12], &clk[13], &clk[14], &clk[15]);
		printf("%d\n", ready(clk));
	}
}