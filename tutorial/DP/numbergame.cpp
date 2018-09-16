#include <stdio.h>
int game[50] = { 0, };
int save[50][50] = { 0, };
int chk[50][50] = { 0, };
int start_game(int *game, int left, int right){
	if (right < left) return 0;
	if (left == right) return game[left];
	if (right - left == 1){
		if (game[left] > game[right]) return game[left] - game[right];
		else return game[right] - game[left];
	}
	if (chk[left][right] != 0) return save[left][right];
	int c[4];
	int i, max;
	c[0] = game[left] - start_game(game, left + 1, right);
	c[1] = game[right] - start_game(game, left, right - 1);
	c[2] = 0 - start_game(game, left + 2, right);
	c[3] = 0 - start_game(game, left, right - 2);
	max = c[0];
	for (i = 1; i < 4; i++)	if (c[i] > max) max = c[i];
	save[left][right] = max;
	chk[left][right]++;
	return max;
}
int main(){
	int n, i, j, k, num;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &num);
		for (j = 0; j < 50; j++) game[j] = 0;
		for (j = 0; j < 50; j++){
			for (k = 0; k < 50; k++){
				save[j][k] = 0;
				chk[j][k] = 0;
			}
		}
		for (j = 0; j < num; j++) scanf("%d", &game[j]);
		j = 0;
		printf("%d\n", start_game(game, 0, num - 1));
	}
}