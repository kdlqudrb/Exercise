#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int T, N, K, edge, idx, cnt, ncnt;
    vector<int>htod;
    char crypto[30];
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d", &N, &K);
        edge = N / 4;
        cnt = 0;
        scanf("%s", crypto);
        for (int j = 0; j < edge; j++){
            idx = j;
            ncnt = 0;
            char tmp[10];
            int x = 0;
            while (ncnt != N){
                tmp[x] = crypto[idx];
                x++;
                if (x % edge == 0){
                    int tmpd, pow;
                    tmpd = 0;
                    pow = 1;
                    for (int k = x - 1; k >= 0; k--){
                        if (tmp[k] - '0' >= 0 && tmp[k] - '0' <= 9) tmpd += (tmp[k] - '0') * pow;
                        else{
                            tmpd += (tmp[k] - 'A' + 10) * pow;
                        }
                        pow *= 16;
                    }
                    int chk = 0;
                    for (int k = 0; k < htod.size(); k++){
                        if (tmpd == htod[k]){
                            chk++;
                            break;
                        }
                    }
 
                    if (!chk){
                        htod.push_back(tmpd);
                        cnt++;
                    }
                    x = 0;
                }
                idx++;
                if (idx == N) idx = 0;
                ncnt++;
            }
        }
 
        sort(htod.begin(), htod.end());
 
        printf("#%d %d\n", i, htod[cnt - K]);
 
        htod.clear();
    }
}