#include <bits/stdc++.h>
using namespace std;
 
int D, W, K, chk = 0;
int firm[13][20];
 
int firmchk(){
    int swh, cnt;
    for (int i = 0; i < W; i++){
        swh = firm[0][i];
        cnt = 1;
        int innerchk = 0;
        for (int j = 1; j < D; j++){
            if (swh == firm[j][i]) cnt++;
            else{
                swh = firm[j][i];
                cnt = 1;
            }
            if (cnt >= K){
                innerchk = 1;
                break;
            }
        }
        if (!innerchk) return 0;
    }
 
    return 1;
}
 
void dfs(int now, int bh, int cnt, int color){
    if (chk) return;
     
    if (cnt == 0){
        if (firmchk()){
            chk = 1;
            return;
        }
        else return;
    }
 
    if (bh){
        int cpy[20];
        for (int i = 0; i < W; i++) cpy[i] = firm[now][i];
        for (int i = 0; i < W; i++) firm[now][i] = color;
        if (now == D - 1){
            if (firmchk()) chk = 1;
            for (int i = 0; i < W; i++) firm[now][i] = cpy[i];
            return;
        }
        dfs(now + 1, 0, cnt - 1, 0);
        dfs(now + 1, 1, cnt - 1, 0);
        dfs(now + 1, 1, cnt - 1, 1);
        for (int i = 0; i < W; i++) firm[now][i] = cpy[i];
    }
    else{
        if (now == D - 1) return;
        dfs(now + 1, 0, cnt, 0);
        dfs(now + 1, 1, cnt, 0);
        dfs(now + 1, 1, cnt, 1);
    }
}
 
int search(){
    int answer = 100;
    int l = 0;
    int mid, r = K;
    if (firmchk()) return 0;
    else{
        while (l <= r){
            mid = (l + r) / 2;
            if (mid == K) return mid;
            dfs(0, 0, mid, 0);
            dfs(0, 1, mid, 0);
            dfs(0, 1, mid, 1);
            if (!chk) l = mid + 1;
            else{
                chk = 0;
                if(mid < answer) answer = mid;
                r = mid - 1;
            }
        }
        return answer;
    }
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        chk = 0;
        scanf("%d %d %d", &D, &W, &K);
        for (int j = 0; j < D; j++)
            for (int k = 0; k < W; k++)
                scanf("%d", &firm[j][k]);
 
        printf("#%d %d\n", i, search());
    }
}