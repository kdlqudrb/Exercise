#include <iostream>
using namespace std;
void del(char str[][81], int i, int j, int l){
	int k, chk = 0;
	switch (str[i][j + 2]){
	case '0': str[i][j] = ' '; break;
	case '1': str[i][j] = '!'; break;
	case '2': chk++; break;
	case '3': chk++; break;
	case '4': str[i][j] = '$'; break;
	case '5': break;
	case '6': chk++; break;
	case '7':	chk++; break;
	case '8': str[i][j] = '('; break;
	case '9': str[i][j] = ')'; break;
	default: chk++; break;
	}
	if (chk == 0) for (k = j + 1; k < l; k++) str[i][k] = str[i][k + 2];
}
int main(){
	int n, i, j;
	char Uri[101][81];
	int stl[101];
	cin >> n;
	for (i = 0; i < n; i++) cin >> Uri[i];
	for (i = 0; i < n; i++){
		j = 0;
		while (Uri[i][j] != '\0') j++;
		stl[i] = j;}
	for (i = 0; i < n; i++){
		j = 0;
		while (Uri[i][j] != '\0'){
			if (Uri[i][j] == '%' && Uri[i][j + 1] == '2'){
					if (Uri[i][j + 2] == 'a'){
						Uri[i][j] = '*';
						for (int k = j + 1; k < stl[i]; k++) Uri[i][k] = Uri[i][k + 2];
					}
					else del(Uri, i, j, stl[i]);
				}
			j++;
		}
	}
	for (i = 0; i < n; i++) printf("%s\n", Uri[i]);
}