#include <stdio.h>
void LtoR(char &a){
	if (a == '(') a = ')';
	if (a == '[') a = ']';
	if (a == '{') a = '}';
	if (a == '<') a = '>';
}
void RtoL(char &a){
	if (a == ')') a = '(';
	if (a == ']') a = '[';
	if (a == '}') a = '{';
	if (a == '>') a = '<';
}
void pop(char *stk, int *index, int &cnt){
	stk[cnt] = stk[cnt - 1] = '\0';
	index[cnt] = index[cnt - 1] = 0;
	cnt--;
}
void fixparen(char *str, char *priority, int *strpri){
	char stk[101] = { '\0', };
	int index[101];
	int rightp = 0;
	int k = 0;
	int cnt = 0;
	while (str[k] != '\0'){
		if (str[k] == '(' || str[k] == '<' || str[k] == '[' || str[k] == '{'){
			stk[cnt] = str[k];
			index[cnt] = k;
			cnt++;
		}
		if (str[k] == ')' || str[k] == '>' || str[k] == ']' || str[k] == '}'){
			stk[cnt] = str[k];
			index[cnt] = k;
			cnt++;
			rightp++;
		}
		if (rightp == 1){ 
			cnt--;
			if (strpri[index[cnt]] > strpri[index[cnt - 1]]){
				str[index[cnt - 1]] = str[index[cnt]];
				RtoL(str[index[cnt - 1]]);
				pop(stk, index, cnt);
			}
			else if (strpri[index[cnt]] == strpri[index[cnt - 1]]) pop(stk, index, cnt);
			else{
				str[index[cnt]] = str[index[cnt - 1]];
				LtoR(str[index[cnt]]);
				pop(stk, index, cnt);
			}
			rightp--;
		}
		k++;
	}
}
int main(){
	int n, i, j;
	char str[101] = { '\0', };
	int strpri[101] = { 0, };
	char priority[9];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s %s", str, priority);
		for (j = 0; j < 4; j++){
			switch (priority[j]){
			case '{': priority[j + 4] = '}'; break;
			case '[': priority[j + 4] = ']'; break;
			case '(': priority[j + 4] = ')'; break;
			case '<': priority[j + 4] = '>'; break;
			}
		}
		j = 0;
		while (str[j] != '\0'){
			if (str[j] == priority[0] || str[j] == priority[4]) strpri[j] = 4;
			if (str[j] == priority[1] || str[j] == priority[5]) strpri[j] = 3;
			if (str[j] == priority[2] || str[j] == priority[6]) strpri[j] = 2;
			if (str[j] == priority[3] || str[j] == priority[7]) strpri[j] = 1;
			j++;
		}
		fixparen(str, priority, strpri);
		j = 0;
		while (str[j] != '\0'){
			printf("%c", str[j]);
			j++;
		}
		printf("\n");
	}
}