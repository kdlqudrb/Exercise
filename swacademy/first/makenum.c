#include <stdio.h>
 
int N, result, max, min, oper[4], card[12];
 
void cal(int index, int op, int num){
    int tmp = card[index];
    if (index == N){
        if (num > max) max = num;
        if (num < min) min = num;
        return;
    }
    if (op == 0){
        if (oper[0]){
            oper[0]--;
            tmp += num;
        }
        else return;
    }
    else if (op == 1){
        if (oper[1]){
            oper[1]--;
            tmp = num - tmp;
        }
        else return;
    }
    else if (op == 2){
        if (oper[2]){
            oper[2]--;
            tmp *= num;
        }
        else return;
    }
    else{
        if (oper[3]){
            oper[3]--;
            tmp = num / tmp;
        }
        else return;
    }
 
    cal(index + 1, 0, tmp);
    cal(index + 1, 1, tmp);
    cal(index + 1, 2, tmp);
    cal(index + 1, 3, tmp);
     
    oper[op]++;
}
 
void find(){
    cal(1, 0, card[0]);
    cal(1, 1, card[0]);
    cal(1, 2, card[0]);
    cal(1, 3, card[0]);
 
    result = max - min;
}
 
void init(){
    max = -100000001;
    min = 100000001;
    result = 0;
    for (int i = 0; i < 12; i++) card[i] = 0;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        init();
        scanf("%d", &N);
        for (int j = 0; j < 4; j++) scanf("%d", &oper[j]);
        for (int j = 0; j < N; j++) scanf("%d", &card[j]);
        find();
        printf("#%d %d\n", i, result);
    }
}
