#include <iostream>
using namespace std;
 
int answer, N;
int map[10][10];
 
struct stair{
    int fill;
    int len;
    int r;
    int c;
};
 
struct people{
    int r;
    int c;
    int avail;
    int last;
    int dis1;
    int dis2;
};
 
struct people que[10];
struct people queue[2][10];
struct stair st[2];
int cnt, fir, snd;
struct people cpyque[2][10];
 
int cal(){
    int arrP = 0;
    int time = 0;
    int min = 987654321;
    while (true){
        if (arrP == cnt) break;
        for (int i = 0; i < fir; i++){
            if(cpyque[0][i].dis1 > 0) cpyque[0][i].dis1--;
            if (cpyque[0][i].dis1 == 0){
                if (cpyque[0][i].avail == 1){
                    if (st[0].fill < 3){
                        cpyque[0][i].last = st[0].len;
                        cpyque[0][i].avail = 0;
                        st[0].fill++;
                    }
                }
                else{
                    if (cpyque[0][i].last > 0) cpyque[0][i].last--;
                    if (cpyque[0][i].last == 0){
                        st[0].fill--;
                        arrP++;
                        cpyque[0][i].last = -1;
                        for (int k = 0; k < fir; k++){
                            if (cpyque[0][k].dis1 == 0 && cpyque[0][k].avail == 1){
                                cpyque[0][k].avail = 0;
                                cpyque[0][k].last = st[0].len;
                                if (k > i) cpyque[0][k].last++;
                                st[0].fill++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < snd; i++){
            if (cpyque[1][i].dis2 > 0) cpyque[1][i].dis2--;
            if (cpyque[1][i].dis2 == 0){
                if (cpyque[1][i].avail == 1){
                    if (st[1].fill < 3){
                        cpyque[1][i].last = st[1].len;
                        cpyque[1][i].avail = 0;
                        st[1].fill++;
                    }
                }
                else{
                    if (cpyque[1][i].last > 0) cpyque[1][i].last--;
                    if (cpyque[1][i].last == 0){
                        arrP++;
                        st[1].fill--;
                        cpyque[1][i].last = -1;
                        for (int k = 0; k < snd; k++){
                            if (cpyque[1][k].dis2 == 0 && cpyque[1][k].avail == 1){
                                cpyque[1][k].avail = 0;
                                cpyque[1][k].last = st[1].len;
                                if (k > i) cpyque[1][k].last++;
                                st[1].fill++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        time++;
    }
 
    return time;
}
 
void cpy(){
    int x = 0;
    int y = 0;
    for (int i = 0; i < fir; i++){
        cpyque[0][x].r = queue[0][i].r;
        cpyque[0][x].c = queue[0][i].c;
        cpyque[0][x].avail = queue[0][i].avail;
        cpyque[0][x].dis1 = queue[0][i].dis1;
        x++;
    }
    for (int i = 0; i < snd; i++){
        cpyque[1][y].r = queue[1][i].r;
        cpyque[1][y].c = queue[1][i].c;
        cpyque[1][y].avail = queue[1][i].avail;
        cpyque[1][y].dis2 = queue[1][i].dis2;
        y++;
    }
}
 
void assign(int i, int stair){
    if (i == cnt){
        cpy();
        int tmp = cal();
        if (tmp < answer) answer = tmp;
        return;
    }
    if (stair){
        queue[stair][snd].r = que[i].r;
        queue[stair][snd].c = que[i].c;
        queue[stair][snd].dis2 = que[i].dis2;
        queue[stair][snd].avail = 1;
        snd++;
        assign(i + 1, 0);
        assign(i + 1, 1);
        snd--;
    }
    else{
        queue[stair][fir].r = que[i].r;
        queue[stair][fir].c = que[i].c;
        queue[stair][fir].dis1 = que[i].dis1;
        queue[stair][fir].avail = 1;
        fir++;
        assign(i + 1, 0);
        assign(i + 1, 1);
        fir--;
    }
}
 
void search(){
    fir = snd = 0;
    assign(0, 0);
    assign(0, 1);
}
 
int main(){
    int T, tmp;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        cnt = tmp = 0;
        answer = 987654321;
        scanf("%d", &N);
 
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                scanf("%d", &map[j][k]);
                if (map[j][k] == 1){
                    que[cnt].r = j;
                    que[cnt].c = k;
                    cnt++;
                }
                if (map[j][k] > 1){
                    st[tmp].fill = 0;
                    st[tmp].len = map[j][k];
                    st[tmp].r = j;
                    st[tmp].c = k;
                    tmp++;
                }
            }
        }
 
        for (int j = 0; j < cnt; j++){
            que[j].dis1 = abs(que[j].r - st[0].r) + abs(que[j].c - st[0].c) + 1;
            que[j].dis2 = abs(que[j].r - st[1].r) + abs(que[j].c - st[1].c) + 1;
        }
 
        search();
 
        printf("#%d %d\n", i, answer);
    }
}