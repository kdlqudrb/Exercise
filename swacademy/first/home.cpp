#include <iostream>
using namespace std;
 
int answer, cnt;
int N, M;
int map[20][20];
int cost[22];
 
void cal(int r, int c, int size){
    int house = 0;
    int up, down, left, right;
    up = r - size + 1;
    down = r + size - 1;
    left = c - size + 1;
    right = c + size - 1;
    int hel = 1;
    int helhel = 0;
    int height = -1;
    int tmp_hel = size - 1;
    for (int i = up; i <= down; i++){
        if(helhel == 0) height++;
        else height--;
        if (i < 0 || i > N - 1){
            if (helhel == 0){
                hel++;
                tmp_hel--;
            }
            else{
                hel--;
                tmp_hel++;
            }
            continue;
        }
        int hlt = tmp_hel;
        int hlt2 = height;
        int chk = 0;
        for (int j = left; j <= right; j++){
            if (j < 0){
                hlt--;
                continue;
            }
            if (j > N - 1) continue;
 
            if (hlt > 0){
                hlt--;
                continue;
            }
 
            if (chk){
                if (hlt2){
                    if (map[i][j] == 1) house++;
                    hlt2--;
                    continue;
                }
                else{
                    continue;
                }
            }
 
            if (j == c) chk = 1;
            if (map[i][j] == 1) house++;
        }
        if (hel == size) helhel++;
        if (helhel == 0){
            hel++;
            tmp_hel--;
        }
        else{
            hel--;
            tmp_hel++;
        }
    }
 
    if (house * M >= cost[size]){
        if(answer < house) answer = house;
    }
}
 
void search(){
    int tmp = cnt * M;
    int tmp_n;
    if (N % 2 == 0) tmp_n = N + 1;
    else tmp_n = N;
    if (tmp > cost[N]){
        answer = cnt;
        return;
    }
    tmp_n = 21;
    while (tmp_n > 1){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cal(i, j, tmp_n);
            }
        }
        tmp_n--;
    }
}
 
int main(){
    int T, pow;
    scanf("%d", &T);
    pow = 4;
    cost[1] = 1;
    for (int i = 2; i < 22; i++){
        cost[i] = cost[i - 1] + pow;
        pow += 4;
    }
 
    for (int i = 1; i <= T; i++){
        scanf("%d %d", &N, &M);
        answer = cnt = 0;
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                scanf("%d", &map[j][k]);
                if (map[j][k]) cnt++;
            }
        }
        search();
        if(answer == 0) answer = 1;
        printf("#%d %d\n", i, answer);
    }
}