#include <stdio.h>
bool chk(char game[20][21], int height, int width){
	int a, b, g, s = 0;
	for (a = 0; a < height; a++){
		for (b = 0; b < width; b++){
			if (game[a][b] == '#') s++;
		}
	}
	g = height * width;
	if (s == g) return true;
	else return false;
}
void co1(char game[20][21], int x, int y){
	game[x][y] = '#';
	game[x][y + 1] = '#';
	game[x + 1][y] = '#';
}
void co2(char game[20][21], int x, int y){
	game[x][y] = '#';
	game[x + 1][y + 1] = '#';
	game[x + 1][y] = '#';
}
void co3(char game[20][21], int x, int y){
	game[x][y] = '#';
	game[x][y + 1] = '#';
	game[x + 1][y + 1] = '#';
}
void co4(char game[20][21], int x, int y){
	game[x][y] = '#';
	game[x + 1][y - 1] = '#';
	game[x + 1][y] = '#';
}
void co1_r(char game[20][21], int x, int y){
	game[x][y] = '.';
	game[x][y + 1] = '.';
	game[x + 1][y] = '.';
}
void co2_r(char game[20][21], int x, int y){
	game[x][y] = '.';
	game[x + 1][y + 1] = '.';
	game[x + 1][y] = '.';
}
void co3_r(char game[20][21], int x, int y){
	game[x][y] = '.';
	game[x][y + 1] = '.';
	game[x + 1][y + 1] = '.';
}
void co4_r(char game[20][21], int x, int y){
	game[x][y] = '.';
	game[x + 1][y - 1] = '.';
	game[x + 1][y] = '.';
}
void cover(char game[20][21], int height, int width, int x, int y, int &cnt){
	if (chk(game, height, width)){ cnt++; return; }
	if (x + 1 == height) return;
	if (game[x][y] == '#'){
		if (y + 1 == width) cover(game, height, width, x + 1, 0, cnt);
		else cover(game, height, width, x, y + 1, cnt);
		return;
	}
	if (y == 0){
		if (game[x][y + 1] == '#'){
			if (game[x + 1][y] != '#' && game[x + 1][y + 1] != '#'){
				co2(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co2_r(game, x, y);
			}
		}
		if (game[x][y + 1] != '#'){
			if (game[x + 1][y] != '#'){
				co1(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co1_r(game, x, y);
			}
			if (game[x + 1][y] != '#' && game[x + 1][y + 1] != '#'){
				co2(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co2_r(game, x, y);
			}
			if (game[x + 1][y + 1] != '#'){
				co3(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co3_r(game, x, y);
			}
		}
		
	}
	else if (y + 1 == width){ 
		if (game[x + 1][y - 1] == '.' && game[x + 1][y] == '.'){
			co4(game, x, y);
			cover(game, height, width, x + 1, 0, cnt);
			co4_r(game, x, y);
		}
	}
	else{
		if (game[x][y + 1] == '#'){
			if (game[x + 1][y] != '#' && game[x + 1][y + 1] != '#'){
				co2(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co2_r(game, x, y);
			}
			if (game[x + 1][y] != '#' && game[x + 1][y - 1] != '#'){
				co4(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co4_r(game, x, y);
			}
		}
		if (game[x][y + 1] != '#'){
			if (game[x + 1][y] != '#'){
				co1(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co1_r(game, x, y);
			}
			if (game[x + 1][y] != '#' && game[x + 1][y + 1] != '#'){
				co2(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co2_r(game, x, y);
			}
			if (game[x + 1][y + 1] != '#'){
				co3(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co3_r(game, x, y);
			}
			if (game[x + 1][y] != '#' && game[x + 1][y - 1] != '#'){
				co4(game, x, y);
				cover(game, height, width, x, y + 1, cnt);
				co4_r(game, x, y);
			}
		}
	}
}
int ready(char game[20][21], int height, int width){
	int cnt = 0;
	if (chk(game, height, width)) return 1;
	cover(game, height, width, 0, 0, cnt);
	return cnt;
}
int main(){
	int n, width, height, i, j;
	char game[20][21];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &height, &width);
		for (j = 0; j < height; j++) scanf("%s", game[j]);
		printf("%d\n", ready(game, height, width));
	}
}