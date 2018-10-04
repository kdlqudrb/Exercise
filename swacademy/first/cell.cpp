#include <bits/stdc++.h>
using namespace std;
 
struct cell{
    int stat;
    int hp;
    int hpmax;
};
 
int N, M, K;
struct cell jmap[352][352], cpy[352][352];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
int cal(){
    int sum = 0;
    for (int i = 0; i < 352; i++){
        for (int j = 0; j < 352; j++){
            if (jmap[i][j].stat == 1 || jmap[i][j].stat == 2) sum++;
        }
    }
 
    return sum;
}
 
int main(){
    int T, ti;
 
    scanf("%d", &T);
    for (int q = 1; q <= T; q++){
        scanf("%d %d %d", &N, &M, &K);
        int ran = K / 2;
        int upperbound, lowerbound = 150 - ran - 1;
        if (N > M) upperbound = 150 + N + ran + 1;
        else upperbound = 150 + M + ran + 1;
        if(lowerbound < 0) lowerbound = 0;
         
        for (int i = 0; i < 352; i++) for (int j = 0; j < 352; j++) jmap[i][j].stat = cpy[i][j].hpmax = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++){
                scanf("%d", &jmap[i + 150][j + 150].hpmax);
                if (jmap[i + 150][j + 150].hpmax){
                    jmap[i + 150][j + 150].hp = jmap[i + 150][j + 150].hpmax;
                    jmap[i + 150][j + 150].stat = 1;
                }
            }
 
        ti = 0;
        while (ti < K){
            int chk = 0;
            for (int i = lowerbound; i < upperbound; i++){
                for (int j = lowerbound; j < upperbound; j++){
                    if (jmap[i][j].stat == 1){
                        jmap[i][j].hp--;
                        if (jmap[i][j].hp == 0) jmap[i][j].stat = 2;
                    }
                    else if (jmap[i][j].stat == 2){
                        for (int x = 0; x < 4; x++){
                            if (jmap[i + dx[x]][j + dy[x]].stat == 0){
                                chk++;
                                if (cpy[i + dx[x]][j + dy[x]].hpmax < jmap[i][j].hpmax) cpy[i + dx[x]][j + dy[x]].hpmax = jmap[i][j].hpmax;
                            }
                        }
                        jmap[i][j].hp++;
                        if (jmap[i][j].hp == jmap[i][j].hpmax) jmap[i][j].stat = 3;
                    }
                }
            }
            for (int i = lowerbound; i < upperbound; i++){
                for (int j = lowerbound; j < upperbound; j++){
                    if (cpy[i][j].hpmax > 0){
                        jmap[i][j].hpmax = cpy[i][j].hpmax;
                        jmap[i][j].stat = 1;
                        jmap[i][j].hp = jmap[i][j].hpmax;
                        cpy[i][j].hpmax = 0;
                    }
                }
            }
 
            ti++;
        }
 
        printf("#%d %d\n", q, cal());
    }
}