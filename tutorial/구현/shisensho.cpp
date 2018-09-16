#include <stdio.h>
void right(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search);
void left(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search);
void up(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search);
void down(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search);
bool isequal(char sss[52][52], char save, int x, int y){
	int i, j;
	for (i = 1; i < 52; i++) for (j = 1; j < 52; j++){
		if (sss[i][j] == save && i == x && j == y) continue;
		else if (sss[i][j] == save) return true;
	}
	return false;
}
bool isspace(char sss[52][52], int x, int y){
	if (sss[x][y + 1] == '.') return true;
	if (sss[x][y - 1] == '.') return true;
	if (sss[x + 1][y] == '.') return true;
	if (sss[x - 1][y] == '.') return true;
	return false;
}
void findr(char sss[52][52], char color[52][52], char save, int x, int y, int &search){
	if (sss[x][y + 1] == save){
		if (color[x][y + 1] == 'w'){
			search++;
			color[x][y + 1] = 'b';
			return;
		}
	}
	return;
}
void findl(char sss[52][52], char color[52][52], char save, int x, int y, int &search){
	if (sss[x][y - 1] == save){
		if (color[x][y - 1] == 'w'){
			search++;
			color[x][y - 1] = 'b';
			return;
		}
	}
	return;
}
void findu(char sss[52][52], char color[52][52], char save, int x, int y, int &search){
	if (sss[x - 1][y] == save){
		if (color[x - 1][y] == 'w'){
			search++;
			color[x - 1][y] = 'b';
			return;
		}
	}
	return;
}
void findd(char sss[52][52], char color[52][52], char save, int x, int y, int &search){
	if (sss[x + 1][y] == save){
		if (color[x + 1][y] == 'w'){
			search++;
			color[x + 1][y] = 'b';
			return;
		}
	}
	return;
}
void right(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search){
	int s = corner;
	if (corner > 2) return;
	findr(sss, color, save, x, y, search);
	if (corner < 2){
		findu(sss, color, save, x, y, search);
		findd(sss, color, save, x, y, search);
	}
	if (y <= w){
		if (sss[x][y + 1] == '.'){
			right(sss, color, save, x, y + 1, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (corner > 2) return;
	if (x <= h){
		if (sss[x + 1][y] == '.'){
			down(sss, color, save, x + 1, y, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (x > 0){
		if (sss[x - 1][y] == '.'){
			up(sss, color, save, x - 1, y, h, w, corner, search);
		}
	}
}
void left(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search){
	if (corner > 2) return;
	findl(sss, color, save, x, y, search);
	if (corner < 2){
		findu(sss, color, save, x, y, search);
		findd(sss, color, save, x, y, search);
	}
	int s = corner;
	if (y > 0){
		if (sss[x][y - 1] == '.'){
			left(sss, color, save, x, y - 1, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (corner > 2) return;
	if (x <= h){
		if (sss[x + 1][y] == '.'){
			down(sss, color, save, x + 1, y, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (x > 0){
		if (sss[x - 1][y] == '.'){	
			up(sss, color, save, x - 1, y, h, w, corner, search);
		}
	}
}
void up(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search){
	if (corner > 2) return;
	findu(sss, color, save, x, y, search);
	if (corner < 2){
		findr(sss, color, save, x, y, search);
		findl(sss, color, save, x, y, search);
	}
	int s = corner;
	if (x > 0){
		if (sss[x - 1][y] == '.'){
			up(sss, color, save, x - 1, y, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (corner > 2) return;
	if (y <= w){
		if (sss[x][y + 1] == '.'){
			right(sss, color, save, x, y + 1, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (y > 0){
		if (sss[x][y - 1] == '.'){
			left(sss, color, save, x, y - 1, h, w, corner, search);
		}
	}
}
void down(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w, int &corner, int &search){
	if (corner > 2) return;
	findd(sss, color, save, x, y, search);
	if (corner < 2){
		findr(sss, color, save, x, y, search);
		findl(sss, color, save, x, y, search);
	}
	int s = corner;
	if (x <= h){
		if (sss[x + 1][y] == '.'){
			down(sss, color, save, x + 1, y, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (corner > 2) return;
	if (y <= w){
		if (sss[x][y + 1] == '.'){
			right(sss, color, save, x, y + 1, h, w, corner, search);
		}
	}
	corner = s + 1;
	if (y > 0){
		if (sss[x][y - 1] == '.'){
			left(sss, color, save, x, y - 1, h, w, corner, search);
		}
	}
}
int findway(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w){
	int search = 0;
	int corner = 0;
	if (sss[x][y + 1] == save){
		color[x][y + 1] = 'b';
		search++;
	}
	if (sss[x][y - 1] == save){
		color[x][y - 1] = 'b';
		search++;
	}
	if (sss[x - 1][y] == save){
		color[x - 1][y] = 'b';
		search++;
	}
	if (sss[x + 1][y] == save){
		color[x + 1][y] = 'b';
		search++;
	}
	if (y <= w){
		if (sss[x][y + 1] == '.'){
			right(sss, color, save, x, y + 1, h, w, corner, search);
		}
	}
	corner = 0;
	if (y > 0){
		if (sss[x][y - 1] == '.'){
			left(sss, color, save, x, y - 1, h, w, corner, search);
		}
	}
	corner = 0;
	if (x <= h){
		if (sss[x + 1][y] == '.'){
			down(sss, color, save, x + 1, y, h, w, corner, search);
		}
	}
	corner = 0;
	if (x > 0){
		if (sss[x - 1][y] == '.'){
			up(sss, color, save, x - 1, y, h, w, corner, search);
		}
	}
	return search;
}
int start(char sss[52][52], char color[52][52], char save, int x, int y, int h, int w){
	int cnt = 0;
	color[x][y] = 'b';
	cnt += findway(sss, color, save, x, y, h, w);
	return cnt;
}
int main(){
	int n, i, x, y, h, w, a, b;
	int cnt = 0;
	int answer[10000];
	char sss[52][52];
	char color[52][52];
	char save;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (x = 0; x < 52; x++) for (y = 0; y < 52; y++) sss[x][y] = '.';
		scanf("%d %d", &h, &w);
		for (x = 1; x <= h; x++){
			scanf("%s", sss[x]);
		}
		for (x = 1; x <= h; x++){
			for (y = w; y >= 0; y--){
				sss[x][y] = sss[x][y - 1];
			}
		}
		for (x = 1; x <= h; x++){
			for (y = 1; y <= w; y++){
				if (sss[x][y] != '.'){
					for (a = 0; a <= h; a++) for (b = 0; b <= w; b++) color[a][b] = 'w';
					save = sss[x][y];
					cnt += start(sss, color, save, x, y, h, w);
				}
			}
		}
		answer[i] = cnt / 2;
	}
	for (i = 0; i < n; i++){
		printf("%d\n", answer[i]);
	}
}