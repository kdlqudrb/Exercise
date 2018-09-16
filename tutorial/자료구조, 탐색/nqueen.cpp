#include <stdio.h>
bool chk_h(int chess[13][13], int size, int x, int y){
	int i;
	for (i = 0; i < y; i++){
		if (chess[x][i] == 1) return true;
	}
	return false;
}
bool chk_d(int chess[13][13], int size, int x, int y){
	int a = x + 1;
	int b = y - 1;
	while (a < size && b > -1){
		if (chess[a][b] == 1) return true;
		a++;
		b--;
	}
	a = x - 1;
	b = y - 1;
	while (a > -1 && b > -1){
		if (chess[a][b] == 1) return true;
		a--;
		b--;
	}
	return false;
}
void queen(int chess[13][13], int size, int x, int y, int index, int &cnt){
	if (chk_h(chess, size, x, y)){ chess[x][y] = 0; return; }
	if (chk_d(chess, size, x, y)){ chess[x][y] = 0; return; }
	chess[x][y] = 1;
	int i;
	for(i = 0; i < size; i++) queen(chess, size, i, y + 1, index + 1, cnt);
	if (index + 1 == size) cnt++;
	chess[x][y] = 0;
}
int ready(int chess[13][13], int size){
	int cnt = 0;
	int i;
	for(i = 0; i < size; i++) queen(chess, size, i, 0, 0, cnt);
	return cnt;
}
int main(){
	int n, i, a, b;
	int q[10000];
	int answer[10000];
	int chess[13][13];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &q[i]);
		if (q[i] == 1) answer[i] = 1;
		else{
			for (a = 0; a < q[i]; a++) for (b = 0; b < q[i]; b++) chess[a][b] = 0;
			answer[i] = ready(chess, q[i]);
		}
		printf("%d\n", answer[i]);
	}
}