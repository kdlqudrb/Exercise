#include <stdio.h>
int diamond[200][100] = { { 0, 0 }, };
int square[100][100] = { { 0, 0 }, };
int max(int x, int y){
	int i, j, max = 0;
	for (i = 1; i <= x; i++){
		square[0][i] += square[0][i - 1];
		square[i][0] += square[i - 1][0];
	}
	for (i = 1; i <= x; i++){
		for (j = 1; j <= y; j++){
			if (square[i - 1][j] > square[i][j - 1]){
				square[i][j] += square[i - 1][j];
			}
			else{
				square[i][j] += square[i][j - 1];
			}
			if (square[i][j] > max) max = square[i][j];
		}
	}
	return max;
}
int main(){
	int a, b, n, i, j, k, sub, save_w, save_h, width, height, side;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < 200; j++){
			for (k = 0; k < 100; k++){
				diamond[j][k] = 0;
			}
		}
		for (j = 0; j < 100; j++){
			for (k = 0; k < 100; k++){
				square[j][k] = 0;
			}
		}
		scanf("%d", &width);
		height = width * 2 - 1;
		j = sub = 0;
		side = height / 2;
		while (j < height){
			if (j <= side){
				for (k = 0; k <= j; k++){
					scanf("%d", &diamond[j][k]);
				}
				j++;
			}
			else {
				sub += 2;
				for (k = 0; k <= j - sub; k++){
					scanf("%d", &diamond[j][k]);
				}
				j++;
			}
		}
		a = b = j = k = sub = save_h = save_w = 0;
		while (j < height){
			if (j <= side){
				for (k = 0; k <= j; k++){
					square[a][b] = diamond[j][k];
					if (a == 0){
						a = save_h + 1;
						b = 0;
						save_h++;
					}
					else{
						a--;
						b++;
					}
					if (a > side){
						a--;
						save_h--;
						b = 1;
						save_w++;
					}
				}
				j++;
			}
			else {
				sub += 2;
				for (k = 0; k <= j - sub; k++){
					square[a][b] = diamond[j][k];
					if (b == side){
						a = save_h;
						b = save_w + 1;
						save_w++;
					}
					else{
						a--;
						b++;
					}
				}
				j++;
			}
		}
		printf("%d\n", max(side, side));
	}
}