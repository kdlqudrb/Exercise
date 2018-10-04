#include <iostream>
using namespace std;
 
int answer, ti;
int N, M, K;
int map[100][100];
 
struct misang{
    int x;
    int y;
    int cnt;
    int dir;
    int life;
    int avail;
};
 
struct misang queue[1000000];
int head, tail;
 
void search(){
    ti = M;
    while (true){
        if (ti == 0) break;
 
        while (queue[head].life == ti){
            if (queue[head].avail == 0){
                head++;
                continue;
            }
            switch (queue[head].dir){
            case 1:{
                queue[tail].x = queue[head].x - 1;
                queue[tail].y = queue[head].y;
                queue[tail].cnt = queue[head].cnt;
                queue[tail].life = queue[head].life - 1;
                queue[tail].avail = queue[head].avail;
                queue[tail].dir = queue[head].dir;
                break;
            }
            case 2:{
                queue[tail].x = queue[head].x + 1;
                queue[tail].y = queue[head].y;
                queue[tail].cnt = queue[head].cnt;
                queue[tail].life = queue[head].life - 1;
                queue[tail].avail = queue[head].avail;
                queue[tail].dir = queue[head].dir;
                break;
            }
            case 3:{
                queue[tail].x = queue[head].x;
                queue[tail].y = queue[head].y - 1;
                queue[tail].cnt = queue[head].cnt;
                queue[tail].life = queue[head].life - 1;
                queue[tail].avail = queue[head].avail;
                queue[tail].dir = queue[head].dir;
                break;
            }
            case 4:{
                queue[tail].x = queue[head].x;
                queue[tail].y = queue[head].y + 1;
                queue[tail].cnt = queue[head].cnt;
                queue[tail].life = queue[head].life -  1;
                queue[tail].avail = queue[head].avail;
                queue[tail].dir = queue[head].dir;
                break;
            }
            }
 
            if (queue[tail].x == 0 || queue[tail].x == N - 1 || queue[tail].y == 0 || queue[tail].y == N - 1){
                switch (queue[tail].dir){
                case 1: queue[tail].dir = 2; break;
                case 2: queue[tail].dir = 1; break;
                case 3: queue[tail].dir = 4; break;
                case 4: queue[tail].dir = 3; break;
                }
                queue[tail].cnt /= 2;
            }
 
            head++;
            tail++;
        }
        for (int i = head; i < tail - 1; i++){
            if (queue[i].avail == 1){
                int tmp_x = queue[i].x;
                int tmp_y = queue[i].y;
                struct misang tmp[4];
                int tmp_head = 0;
                for (int j = i + 1; j < tail; j++){
                    if (tmp_x == queue[j].x && tmp_y == queue[j].y && queue[j].avail == 1){
                        tmp[tmp_head].cnt = queue[j].cnt;
                        queue[j].avail = 0;
                        tmp[tmp_head].avail = j;
                        tmp_head++;
                    }
                }
                if (tmp_head){
                    queue[i].avail = 0;
                    int max = queue[i].cnt;
                    int idx = i;
                    int sum = queue[i].cnt;
                    for (int j = 0; j < tmp_head; j++){
                        sum += tmp[j].cnt;
                        if (max < tmp[j].cnt){
                            max = tmp[j].cnt;
                            idx = tmp[j].avail;
                        }
                    }
                    queue[idx].cnt = sum;
                    queue[idx].avail = 1;
                }
            }
        }
        ti--;
    }
 
    for (int i = head; i < tail; i++){
        if (queue[i].avail){
            answer += queue[i].cnt;
        }
    }
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d %d", &N, &M, &K);
        head = tail = ti = answer = 0;
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if (j == 0 || k == 0 || j == N - 1 || k == N - 1) map[j][k] = -1;
                else map[j][k] = 0;
            }
        }
 
        for (int j = 0; j < K; j++){
            scanf("%d %d %d %d", &queue[tail].x, &queue[tail].y, &queue[tail].cnt, &queue[tail].dir);
            queue[tail].life = M;
            map[queue[tail].x][queue[tail].y] = queue[tail].cnt;
            queue[tail].avail = 1;
            tail++;
        }
 
        search();
 
        printf("#%d %d\n", i, answer);
    }
}