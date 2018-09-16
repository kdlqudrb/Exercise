#include <stdio.h>
#include <math.h>
struct point{
	double x;
	double y;
	int color = 0;
};
point call[100];
point nocall[100];
int cindexf, cindexl, nindexf, nindexl, sindexf, sindexl;
double guri(point m, point n){
	return sqrt((m.x - n.x) * (m.x - n.x) + (m.y - n.y) * (m.y - n.y));
}
void sort(double *ban, int cnt){
	int i, j;
	double temp;
	for (i = 0; i < cnt; i++){
		for (j = i + 1; j < cnt; j++){
			if (ban[j] < ban[i]){
				temp = ban[i];
				ban[i] = ban[j];
				ban[j] = temp;
			}
		}
	}
}
bool chk(double ban, int g){
	int i;
	while (cindexf != cindexl){
		for (i = nindexf; i < nindexl; i++){
			if (nocall[i].color == 1) continue;
			else{
				if (guri(call[cindexf], nocall[i]) <= ban){
					call[cindexl] = nocall[i];
					nocall[i].color = 1;
					cindexl++;
				}
			}
		}
		if (cindexl == g) break;
		cindexf++;
	}
	if (cindexl == g) return true;
	else {
		for (i = nindexf; i < nindexl; i++){
			nocall[i].color = 0;
		}
		cindexf = sindexf;
		cindexl = sindexl;
		return false;
	}
}
int main(){
	int n, i, j, k, g, cnt;
	double result;
	double ban[5000];
	point giji[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < 5000; j++) ban[j] = 0;
		cindexf = cindexl = nindexf = nindexl = sindexf = sindexl = 0;
		for (j = 0; j < 100; j++){
			giji[j].x = 0;
			giji[j].y = 0;
			giji[j].color = 0;
		}
		result = 0;
		scanf("%d", &g);
		cnt = 0;
		for (j = 0; j < g; j++) scanf("%lf %lf", &giji[j].x, &giji[j].y);
		for (j = 0; j < g - 1; j++){
			for (k = j + 1; k < g; k++){
				ban[cnt] = guri(giji[j], giji[k]);
				cnt++;
			}
		}
		call[0] = giji[0];
		giji[0].color = 1;
		cindexl = 1;
		for (j = 1; j < g; j++){
			nocall[nindexl] = giji[j];
			nindexl++;
		}
		sort(ban, cnt);
		sindexf = cindexf;
		sindexl = cindexl;
		j = 0;
		while (j < cnt){
			if (chk(ban[j], g)){
				result = ban[j];
				break;
			}
			j++;
		}
		printf("%.2f\n", result);
	}
}