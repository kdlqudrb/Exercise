#include <stdio.h>
int main(){
	int n, i, y;
	double h, s, tsr;
	int isr, mp;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%lf %lf", &h, &s);
		y = 0;
		isr = (s * 100) / h;
		mp = isr + 1;
		if (mp >= 100){
			y = -1;
			printf("%d\n", y);
		}
		else{
			tsr = ((mp * h) - (100 * s)) / (99 - isr);
			y = tsr;
			if (tsr - y > 0) printf("%d\n", y + 1);
			else printf("%d\n", y);
		}
	}
}