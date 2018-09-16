#include <stdio.h>
#include <string.h>
int main(){
	int n, i, j, c;
	char yo[10];
	int month, day, save;
	int week[10000][7] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d %s", &month, &day, &yo); 
		if (strcmp(yo, "Sunday") == 0) c = 0;
		if (strcmp(yo, "Monday") == 0) c = 1;
		if (strcmp(yo, "Tuesday") == 0) c = 2;
		if (strcmp(yo, "Wednesday") == 0) c = 3;
		if (strcmp(yo, "Thursday") == 0) c = 4;
		if (strcmp(yo, "Friday") == 0) c = 5;
		if (strcmp(yo, "Saturday") == 0) c = 6;
		week[i][c] = save = day;
		while (c != 6){
			c++;
			day++;
			week[i][c] = day;}
		while (c != 0){
			c--;
			day--;
			week[i][c] = day;}
		for (j = 0; j < 7; j++){
			if (week[i][j] < 1){
				switch (month){
				case 1: week[i][j] = week[i][j] + 31; break;
				case 2: week[i][j] = week[i][j] + 31; break;
				case 3: week[i][j] = week[i][j] + 28; break;
				case 4: week[i][j] = week[i][j] + 31; break;
				case 5: week[i][j] = week[i][j] + 30; break;
				case 6: week[i][j] = week[i][j] + 31; break;
				case 7: week[i][j] = week[i][j] + 30; break;
				case 8: week[i][j] = week[i][j] + 31; break;
				case 9: week[i][j] = week[i][j] + 31; break;
				case 10: week[i][j] = week[i][j] + 30; break;
				case 11: week[i][j] = week[i][j] + 31; break;
				case 12: week[i][j] = week[i][j] + 30; break;}}
			else if (week[i][j] > 28){
				if (month == 2) week[i][j] = week[i][j] - 28;
				else if (week[i][j] > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) week[i][j] = week[i][j] - 30;
				else if (week[i][j] > 31) week[i][j] = week[i][j] - 31;}}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < 6; j++) printf("%d ", week[i][j]);
		printf("%d\n", week[i][6]);
	}
}
