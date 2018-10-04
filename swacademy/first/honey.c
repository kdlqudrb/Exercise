#include <stdio.h>
#include <stdlib.h>
 
int N, M, C, max;
int honey[10][10], coloring[10][10];
 
void takeHoney(int i, int j, int take, int index, int tong, int sum, int &total){
    if (index >= M) return;
    int tongTmp = tong;
    int sumTmp = sum;
    if (take){
        tongTmp += honey[i][j];
        if (tongTmp > C) return;
        sumTmp += (honey[i][j] * honey[i][j]);
        if (sumTmp > total) total = sumTmp;
    }
    takeHoney(i, j + 1, 0, index + 1, tongTmp, sumTmp, total);
    takeHoney(i, j + 1, 1, index + 1, tongTmp, sumTmp, total);
}
 
int cal(int i, int j){
    int sum = 0;
    takeHoney(i, j, 0, 0, 0, 0, sum);
    takeHoney(i, j, 1, 0, 0, 0, sum);
    return sum;
}
 
void secondBee(int i, int j, int lastSum){
    int a;
    for (a = j; a < j + M; a++){
        if (coloring[i][a]) return;
    }
    int sum = cal(i, j);
    sum += lastSum;
    if (max < sum) max = sum;
}
 
void firstBee(int i, int j){
    int sum = cal(i, j);
    int a, b;
    for (a = j; a < j + M; a++){
        coloring[i][a] = 1;
    }
    for (a = 0; a < N; a++){
        for (b = 0; b <= N - M; b++){
            secondBee(a, b, sum);
        }
    }
    for (a = j; a < j + M; a++){
        coloring[i][a] = 0;
    }
}
 
void find(){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j <= N - M; j++){
            firstBee(i, j);
        }
    }
}
 
int main(){
    int T, i, j, k;
    scanf("%d", &T);
    for (i = 1; i <= T; i++){
        scanf("%d %d %d", &N, &M, &C);
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++){
                scanf("%d", &honey[j][k]);
                coloring[j][k] = 0;
            }
        max = 0;
        find();
        printf("#%d %d\n", i, max);
    }
}