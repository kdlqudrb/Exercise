#include <iostream>
using namespace std;
 
int answer;
int N, M, K, A, B;
int a[10], b[10];
 
struct customer{
    int arrivedTime;
    int num;
    int Ach;
};
 
struct chang{
    int fill;
    int lastTime;
    int customer;
    int Ach;
};
 
struct customer queueA[1001];
struct customer queueB[1001];
 
struct chang JS[10];
struct chang JB[10];
 
int AHead, ATail, BHead, BTail;
 
void init(){
    answer = 0;
    for (int i = 0; i < 10; i++) 
        a[i] = b[i] = JS[i].fill = JB[i].fill = 0;
    AHead = ATail = BHead = BTail = 1;
}
 
int emptyQueue(){
    if (AHead == ATail && BHead == BTail){
        int chk = 0;
        for (int i = 1; i <= N; i++){
            if (chk) break;
            if (JS[i].fill) chk++;
        }
        for (int i = 1; i <= M; i++){
            if (chk) break;
            if (JB[i].fill) chk++;
        }
        if (chk) return 0;
        else return 1;
    }
    else return 0;
}
 
int main(){
    int T, tmp;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        init();
        scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
        for (int j = 1; j <= N; j++) scanf("%d", &a[j]);
        for (int j = 1; j <= M; j++) scanf("%d", &b[j]);
        for (int j = 1; j <= K; j++){
            scanf("%d", &tmp);
            queueA[ATail].arrivedTime = tmp;
            queueA[ATail].num = j;
            ATail++;
        }
        int time = 0;
        while (1){
            for (int j = 1; j <= N; j++){
                if (JS[j].fill){
                    JS[j].lastTime--;
                    if (JS[j].lastTime == 0){
                        JS[j].fill = 0;
                        queueB[BTail].arrivedTime = time;
                        queueB[BTail].num = JS[j].customer;
                        queueB[BTail].Ach = j;
                        BTail++;
                    }
                }
            }
 
            for (int j = 1; j <= M; j++){
                if (JB[j].fill){
                    JB[j].lastTime--;
                    if (JB[j].lastTime == 0){
                        JB[j].fill = 0;
                        if(JB[j].Ach == A && j == B) answer += JB[j].customer;
                    }
                }
            }
 
            for (int j = AHead; j < ATail; j++){
                if (queueA[j].arrivedTime <= time){
                    for (int k = 1; k <= N; k++){
                        if (JS[k].fill == 0){
                            JS[k].fill = 1;
                            queueA[j].Ach = k;
                            JS[k].customer = queueA[j].num;
                            JS[k].lastTime = a[k];
                            AHead++;
                            break;
                        }
                    }
                }
            }
 
            for (int j = BHead; j < BTail; j++){
                if (queueB[j].arrivedTime <= time){
                    for (int k = 1; k <= M; k++){
                        if (JB[k].fill == 0){
                            JB[k].fill = 1;
                            JB[k].customer = queueB[j].num;
                            JB[k].lastTime = b[k];
                            JB[k].Ach = queueB[j].Ach;
                            BHead++;
                            break;
                        }
                    }
                }
            }
 
            if (emptyQueue()) break;
            time++;
        }
 
        if (!answer) answer = -1;
        printf("#%d %d\n", i, answer);
    }
}