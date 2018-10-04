#include <iostream>
using namespace std;
 
int answer;
int N, M;
int map[50][50];
int coloring[50][50];
 
struct point{
    int x;
    int y;
    int t;
};
 
struct point queue[5000];
int head, tail;
 
void search(){
    while (true){
        if (head == tail) break;
 
        int x = queue[head].x;
        int y = queue[head].y;
        int t = queue[head].t;
 
        if (t == 0){
            head++;
            continue;
        }
 
        if (coloring[x][y] > t){
            head++;
            continue;
        }
 
        if (coloring[x][y] == 0){
            answer++;
            coloring[x][y] = t;
        }
 
        switch (map[x][y]){
        case 1:{
            if (x > 0 && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) {
                queue[tail].x = x - 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y > 0 && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) {
                queue[tail].x = x;
                queue[tail].y = y - 1;
                queue[tail].t = t - 1;
                tail++;
            }
            if (x < N - 1 && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) {
                queue[tail].x = x + 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y < M - 1 && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) {
                queue[tail].x = x;
                queue[tail].y = y + 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 2:{
            if (x > 0 && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) {
                queue[tail].x = x - 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (x < N - 1 && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) {
                queue[tail].x = x + 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 3:{
            if (y > 0 && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) {
                queue[tail].x = x;
                queue[tail].y = y - 1;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y < M - 1 && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) {
                queue[tail].x = x;
                queue[tail].y = y + 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 4:{
            if (x > 0 && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) {
                queue[tail].x = x - 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y < M - 1 && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) {
                queue[tail].x = x;
                queue[tail].y = y + 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 5:{
            if (x < N - 1 && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) {
                queue[tail].x = x + 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y < M - 1 && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) {
                queue[tail].x = x;
                queue[tail].y = y + 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 6:{
            if (x < N - 1 && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) {
                queue[tail].x = x + 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y > 0 && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) {
                queue[tail].x = x;
                queue[tail].y = y - 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        case 7:{
            if (x > 0 && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) {
                queue[tail].x = x - 1;
                queue[tail].y = y;
                queue[tail].t = t - 1;
                tail++;
            }
            if (y > 0 && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) {
                queue[tail].x = x;
                queue[tail].y = y - 1;
                queue[tail].t = t - 1;
                tail++;
            }
            break;
        }
        }
        head++;
    }
}
 
int main(){
    int T;
    int R, C, L;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        answer = head = tail = 0;
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        for (int j = 0; j < 50; j++) for (int k = 0; k < 50; k++) coloring[j][k] = 0;
        for (int j = 0; j < N; j++) for (int k = 0; k < M; k++) scanf("%d", &map[j][k]);
        queue[tail].x = R;
        queue[tail].y = C;
        queue[tail].t = L;
        tail++;
        search();
        printf("#%d %d\n", i, answer);
    }
}