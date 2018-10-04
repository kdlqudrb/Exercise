#include <bits/stdc++.h>
using namespace std;
 
int N, W, H;
int blockmap[15][12];
int block_cnt;
 
int cal_block(){
    int cnt = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (blockmap[i][j] > 0) cnt++;
        }
    }
    return cnt;
}
 
void clean_block(){
    for (int i = H - 1; i >= 0; i--){
        for (int j = 0; j < W; j++){
            if (blockmap[i][j] == 0){
                for (int k = i - 1; k >= 0; k--){
                    if (blockmap[k][j] > 0){
                        blockmap[i][j] = blockmap[k][j];
                        blockmap[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}
 
void crash(int idx, int depth, int &ret){
    if (depth == N){
        return;
    }
 
    int cpy[15][12];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cpy[i][j] = blockmap[i][j];
 
    vector<pair<int, int>>queue;
    for (int i = 0; i < H; i++){
        if (blockmap[i][idx] > 0){
            queue.push_back(make_pair(i, idx));
            break;
        }
    }
 
    while (!queue.empty()){
        int r = queue[0].first;
        int c = queue[0].second;
        queue.erase(queue.begin());
        if (blockmap[r][c] == 0) continue;
        if (r < 0 || c < 0 || r >= H || c >= W) continue;
        int boomrange = blockmap[r][c] - 1;
        if (boomrange < 0) continue;
        blockmap[r][c] = 0;
 
        for (int i = 1; i <= boomrange; i++){
            if(r - i >= 0) queue.push_back(make_pair(r - i, c));
            if(r + i < H) queue.push_back(make_pair(r + i, c));
            if(c - i >= 0) queue.push_back(make_pair(r, c - i));
            if(c + i < W) queue.push_back(make_pair(r, c + i));
        }
    }
 
    clean_block();
    int tmp = cal_block();
    if (tmp < ret){
        ret = tmp;
    }
 
    for (int i = 0; i < W; i++){
        crash(i, depth + 1, ret);
    }
 
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            blockmap[i][j] = cpy[i][j];
}
 
int search(){
    int ret = block_cnt;
    for (int i = 0; i < W; i++){
        crash(i, 0, ret);
    }
    return ret;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        block_cnt = 0;
        scanf("%d %d %d", &N, &W, &H);
        for (int j = 0; j < H; j++){
            for (int k = 0; k < W; k++){
                scanf("%d", &blockmap[j][k]);
                if (blockmap[j][k] > 0) block_cnt++;
            }
        }
 
        printf("#%d %d\n", i, search());
    }
}