#include <stdio.h>
void pop(char stk[], int &cnt){
	stk[cnt] = stk[cnt - 1] = '\0';
	cnt = cnt - 2;
}
void check(char stk[], int &cnt, int &chk){
	if (stk[cnt] == ')'){
		if (stk[cnt - 1] == '('){
			pop(stk, cnt);
			return;
		}
		else chk = 1; return;
	}
	if (stk[cnt] == '}'){
		if (stk[cnt - 1] == '{'){
			pop(stk, cnt);
			return;
		}
		else chk = 1; return;
	}
	if (stk[cnt] == ']'){
		if (stk[cnt - 1] == '['){
			pop(stk, cnt);
			return;
		}
		else chk = 1; return;
	}
}
int main(){
	int n, i, j, cnt_b, cnt_s, chk = 0;
	char bracket[100][10001];
	char stk[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", bracket[i]);
		cnt_b = cnt_s = chk = 0;
		while (bracket[i][cnt_b] != '\0') cnt_b++;
		for (j = 0; j < cnt_b; j++){
			stk[cnt_s] = bracket[i][j];
			check(stk, cnt_s, chk);
			cnt_s++;
			if (chk == 1) break;
		}
		if (chk == 1) printf("NO\n");
		else if (stk[0] == '\0') printf("YES\n");
		else printf("NO\n");
	}
}