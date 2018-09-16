#include <stdio.h>
void cal(double matrix[8][8], int ma[8], int size, int index, int x, int y, double &sum, double &min){
	if (index + 1 == size){
		if (sum < min) min = sum;
		return;
	}
	if (matrix[x][y] == 0) return;
	if (ma[y] == 1) return;
	ma[x] = 1;
	sum += matrix[x][y];
	int i;
	for (i = 0; i < size; i++){
		cal(matrix, ma, size, index + 1, y, i, sum, min);
	}
	ma[x] = 0;
	sum -= matrix[x][y];
}
double ready(double matrix[8][8], int ma[8], int size){
	int i, j;
	double sum = 0;
	double min = 0;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			min += matrix[i][j];
		}
	}
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			cal(matrix, ma, size, 0, i, j, sum, min);
		}
	}
	return min;
}
int main(){
	int n, i, size, a, b;
	double matrix[8][8];
	int ma[8] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &size);
		for (a = 0; a < size; a++){
			for (b = 0; b < size; b++){
				scanf("%lf", &matrix[a][b]);
			}
		}
		printf("%.10f\n", ready(matrix, ma, size));
	}
}