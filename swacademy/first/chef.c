#include <stdio.h>
 
int S[16][16], color[16], N, result;
 
int cal(){
    int food1, food2;
    food1 = food2 = 0;
    for (int i = 0; i < N; i++){
        if (color[i]){
            for (int j = 0; j < N; j++)
                if (color[j]) food1 += S[i][j];
        }
        else{
            for (int j = 0; j < N; j++)
                if (!color[j]) food2 += S[i][j];
        }
    }
    if (food1 > food2) return food1 - food2;
    else return food2 - food1;
}
 
void dfs(int num, int index, int eat){
    if (num == N) return;
    if (index == N / 2){
        int tmp = cal();
        if (result > tmp) result = tmp;
        return;
    }
    if (eat){
        color[num] = 1;
        dfs(num + 1, index + 1, 0);
        dfs(num + 1, index + 1, 1);
        color[num] = 0;
    }
    else{
        dfs(num + 1, index, 0);
        dfs(num + 1, index, 1);
    }
}
 
void find(){
    dfs(0, 0, 0);
    dfs(0, 0, 1);
}
 
void init(){
    result = 987654321;
    for (int i = 0; i < 16; i++) color[i] = 0;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        init();
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &S[j][k]);
        find();
        printf("#%d %d\n", i, result);
    }
}