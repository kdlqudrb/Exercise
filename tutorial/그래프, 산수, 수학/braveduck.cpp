#include <stdio.h>
int jump, ret;
struct point{
	int x;
	int y;
	int color = 0;
};
point queue[200];
point nonvisit[200];
int qindexf, qindexl, nindexf, nindexl;
bool is_jump(point brave, point m){
	if ((brave.x - m.x)*(brave.x - m.x) + (brave.y - m.y)*(brave.y - m.y) <= jump * jump) return 1;
	else return 0;
}
void across(point last){
	int i, j, temp;
	if (nindexf == nindexl) return;
	if (qindexf == qindexl) return;
	if (ret == 1) return;
	temp = qindexl;
	for (i = qindexf; i < qindexl; i++){
		if (is_jump(queue[i], last)){
			ret = 1;
			return;
		}
	}
	for (i = qindexf; i < qindexl; i++){
		for (j = nindexf; j < nindexl; j++){
			if (is_jump(queue[i], nonvisit[j]) && nonvisit[j].color == 0){
				queue[qindexl] = nonvisit[j];
				nonvisit[j].color = 1;
				qindexl++;
			}
		}
	}
	qindexf = temp;
	across(last);
}
void quecl(point que[]){
	int i;
	for (i = 0; i < 200; i++){
		que[i].x = 0;
		que[i].y = 0;
		que[i].color = 0;
	}
}
int main(){
	int n, i, j, dol;
	point duck, start, last;
	point stone[100];
	scanf("%d", &n);
	quecl(queue);
	for (i = 0; i < n; i++){
		qindexf = qindexl = nindexf = nindexl = 0;
		scanf("%d", &jump);
		scanf("%d %d", &start.x, &start.y);
		scanf("%d %d", &last.x, &last.y);
		duck.x = start.x;
		duck.y = start.y;
		scanf("%d", &dol);
		for (j = 0; j < dol; j++){
			scanf("%d %d", &stone[j].x, &stone[j].y);
		}
		if (is_jump(duck, last)) printf("YES\n");
		else{
			for (j = 0; j < dol; j++){
				if (is_jump(duck, stone[j])){
					queue[qindexl].x = stone[j].x;
					queue[qindexl].y = stone[j].y;
					stone[j].color = 1;
					qindexl++;
				}
				else{
					nonvisit[nindexl].x = stone[j].x;
					nonvisit[nindexl].y = stone[j].y;
					nindexl++;
				}
			}
			across(last);
			if (ret == 1) printf("YES\n");
			else printf("NO\n");
			ret = 0;
			quecl(queue);
			quecl(nonvisit);
		}
	}
}