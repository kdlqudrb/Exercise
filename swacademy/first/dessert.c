#include <stdio.h>
 
int N, cafe[20][20], visit[20][20], ate[101], result, start;
 
void init(){
    result = 0;
    for (int i = 1; i < 101; i++) ate[i] = 0;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            cafe[i][j] = visit[i][j] = 0;
}
 
void road(int i, int j, int dir){
    if (i >= N || j >= N || i < 0 || j < 0) return;
    if (visit[i][j]){
        if (dir == 3){
            if (visit[i][j] == -1){
                int sum = 0;
                for (int a = 1; a < 101; a++) if (ate[a]) sum++;
                if (result < sum) result = sum;
            }
        }
        else if (start) start = 0;
        else return;
    }
    if (ate[cafe[i][j]]) return;
 
    if (!dir){
        ate[cafe[i][j]]++;
        visit[i][j]++;
        road(i + 1, j - 1, 0);
        road(i + 1, j + 1, 1);
    }
    else if (dir == 1){
        ate[cafe[i][j]]++;
        visit[i][j]++;
        road(i + 1, j + 1, 1);
        road(i - 1, j + 1, 2);
    }
    else if (dir == 2){
        ate[cafe[i][j]]++;
        visit[i][j]++;
        road(i - 1, j + 1, 2);
        road(i - 1, j - 1, 3);
    }
    else if (dir == 3){
        ate[cafe[i][j]]++;
        visit[i][j]++;
        road(i - 1, j - 1, 3);
    }
    visit[i][j]--;
    ate[cafe[i][j]]--;
}
 
void find(){
    for (int i = 0; i < N - 1; i++){
        for (int j = 1; j < N - 1; j++){
            visit[i][j] = -2;
            start = 1;
            road(i, j, 0);
        }
    }
    if (!result) result = -1;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        init();
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &cafe[j][k]);
        find();
        printf("#%d %d\n", i, result);
    }
}