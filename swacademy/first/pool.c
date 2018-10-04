#include <stdio.h>
#include <stdlib.h>
 
int cost[4], date[12];
int min;
 
void find(int index, int how, int much, int swh){
    if (much >= min) return;
    if (index == 12){
        if (much < min) min = much;
        return;
    }
    int tmp = much;
    switch (how){
    case 0:{
        tmp += (cost[how] * date[index]);
        find(index + 1, 0, tmp, 0);
        find(index + 1, 1, tmp, 0);
        find(index + 1, 2, tmp, 0);
        find(index + 1, 3, tmp, 0);
        break;
    }
    case 1:{
        tmp += cost[1];
        find(index + 1, 0, tmp, 0);
        find(index + 1, 1, tmp, 0);
        find(index + 1, 2, tmp, 0);
        find(index + 1, 3, tmp, 0);
        break;
    }
    case 2:{
        if (!swh){
            int sch = swh;
            sch++;
            tmp += cost[2];
            find(index + 1, 2, tmp, sch);
        }
        else{
            int sch = swh;
            sch++;
            if (sch == 3){
                sch = 0;
                find(index + 1, 0, tmp, sch);
                find(index + 1, 1, tmp, sch);
                find(index + 1, 2, tmp, sch);
                find(index + 1, 3, tmp, sch);
            }
            else find(index + 1, 2, tmp, sch);
        }
        break;
    }
    case 3:{
        tmp += cost[3];
        find(12, 0, tmp, 0);
        break;
    }
    }
}
 
int main(){
    int T, i, j;
    scanf("%d", &T);
    for (i = 1; i <= T; i++){
        for (j = 0; j < 4; j++) scanf("%d", &cost[j]);
        for (j = 0; j < 12; j++) scanf("%d", &date[j]);
        min = 5000;
        find(0, 0, 0, 0);
        find(0, 1, 0, 0);
        find(0, 2, 0, 0);
        find(0, 3, 0, 0);
        printf("#%d %d\n", i, min);
    }
}