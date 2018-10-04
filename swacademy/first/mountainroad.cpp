#include <iostream>
using namespace std;
 
int answer, N, K;
int map[8][8];
int coloring[8][8];
 
struct point{
    int r;
    int c;
};
 
struct point top[64];
int head, tail;
 
void dfs(int r, int c, int len, int chance){
    if (coloring[r][c]) return;
    if (len > answer) answer = len;
    coloring[r][c] = 1;
    if (r == 0){
        if (c == 0){
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
        }
        else if (c == N - 1){
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
        else{
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
    }
    else if (r == N - 1){
        if (c == 0){
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
        }
        else if (c == N - 1){
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
        else{
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
    }
    else{
        if (c == 0){
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
        }
        else if (c == N - 1){
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
        else{
            if (map[r + 1][c] < map[r][c]) dfs(r + 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r + 1][c] - i < map[r][c] && chance){
                    map[r + 1][c] -= i;
                    dfs(r + 1, c, len + 1, 0);
                    map[r + 1][c] += i;
                }
            }
            if (map[r - 1][c] < map[r][c]) dfs(r - 1, c, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r - 1][c] - i < map[r][c] && chance){
                    map[r - 1][c] -= i;
                    dfs(r - 1, c, len + 1, 0);
                    map[r - 1][c] += i;
                }
            }
            if (map[r][c + 1] < map[r][c]) dfs(r, c + 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c + 1] - i < map[r][c] && chance){
                    map[r][c + 1] -= i;
                    dfs(r, c + 1, len + 1, 0);
                    map[r][c + 1] += i;
                }
            }
            if (map[r][c - 1] < map[r][c]) dfs(r, c - 1, len + 1, chance);
            for (int i = 1; i <= K; i++){
                if (map[r][c - 1] - i < map[r][c] && chance){
                    map[r][c - 1] -= i;
                    dfs(r, c - 1, len + 1, 0);
                    map[r][c - 1] += i;
                }
            }
        }
    }
    coloring[r][c] = 0;
}
 
void search(){
    int x = top[head].r;
    int y = top[head].c;
    dfs(x, y, 1, 1);
    head++;
}
 
int main(){
    int T, tmp;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        answer = head = tail = tmp = 0;
        scanf("%d %d", &N, &K);
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                scanf("%d", &map[j][k]);
                coloring[j][k] = 0;
            }
        }
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if (tmp < map[j][k]) tmp = map[j][k];
            }
        }
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if (tmp == map[j][k]){
                    top[tail].r = j;
                    top[tail].c = k;
                    tail++;
                }
            }
        }
        while (head != tail){
            search();
        }
        printf("#%d %d\n", i, answer);
    }
}