#include <stdio.h>
struct doosot{
	int minute;
	int eat;
};
void sort(doosot *a, int k){
	int i, j;
	doosot temp;
	for (i = 0; i < k; i++){
		for (j = i + 1; j < k; j++){
			if (a[i].eat < a[j].eat){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main(){
	int n, i, box, dtime, etime, now;
	doosot dos[10000];
	scanf("%d", &n);
	while (n--){
		scanf("%d", &box);
		dtime = 0;
		for (i = 0; i < box; i++) scanf("%d", &dos[i].minute);
		for (i = 0; i < box; i++) scanf("%d", &dos[i].eat);
		sort(dos, box);
		for (i = 0; i < box; i++) dtime += dos[i].minute;
		i = 1;
		now = dos[0].minute;
		etime = now + dos[0].eat;
		while (1){
			if (i == box) break;
			now += dos[i].minute;
			if (etime - now <= 0){
				etime = now + dos[i].eat;
			}
			if (now + dos[i].eat > etime) etime = now + dos[i].eat;
			i++;
		}
		printf("%d\n", etime);
	}
}