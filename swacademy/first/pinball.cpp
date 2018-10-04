#include <bits/stdc++.h>
using namespace std;
 
int N, answer;
int pmap[100][100];
int coloring[100][100][5];
int worm[5][2][2];
queue<pair<int, int> > q;
 
void dfs(int r, int c, int dir, int score){
    if (coloring[r][c][0] == -3 || pmap[r][c] == -1){
        if (answer < score) answer = score;
        return;
    }
 
    coloring[r][c][dir] = score;
 
    if (coloring[r][c][0] == 3){
        coloring[r][c][0] = 0;
        switch (dir){
        case 1:{
            if (r > 0) dfs(r - 1, c, 1, score);
            else dfs(r, c, 3, score + 1);
            break;
        }
        case 2:{
            if (c < N - 1) dfs(r, c + 1, 2, score);
            else dfs(r, c, 4, score + 1);
            break;
        }
        case 3:{
            if (r < N - 1) dfs(r + 1, c, 3, score);
            else dfs(r, c, 1, score + 1);
            break;
        }
        case 4:{
            if (c > 0) dfs(r, c - 1, 4, score);
            else dfs(r, c, 2, score + 1);
            break;
        }
        }
        return;
    }
 
    if (pmap[r][c] > 0){
        if (pmap[r][c] > 5){
            if (worm[pmap[r][c] - 6][0][0] == r && worm[pmap[r][c] - 6][0][1] == c){
                coloring[worm[pmap[r][c] - 6][1][0]][worm[pmap[r][c] - 6][1][1]][0] = 3;
                dfs(worm[pmap[r][c] - 6][1][0], worm[pmap[r][c] - 6][1][1], dir, score);
                coloring[worm[pmap[r][c] - 6][1][0]][worm[pmap[r][c] - 6][1][1]][0] = 0;
            }
            else{
                coloring[worm[pmap[r][c] - 6][0][0]][worm[pmap[r][c] - 6][0][1]][0] = 3;
                dfs(worm[pmap[r][c] - 6][0][0], worm[pmap[r][c] - 6][0][1], dir, score);
                coloring[worm[pmap[r][c] - 6][1][0]][worm[pmap[r][c] - 6][1][1]][0] = 0;
            }
        }
        else{
            switch (pmap[r][c]){
            case 1:{
                switch (dir){
                case 1:{
                    dfs(r + 1, c, 3, score + 1);
                    break;
                }
                case 2:{
                    dfs(r, c - 1, 4, score + 1);
                    break;
                }
                case 3:{
                    if(c < N - 1) dfs(r, c + 1, 2, score + 1);
                    else dfs(r, c, 4, score + 2);
                    break;
                }
                case 4:{
                    if(r > 0) dfs(r - 1, c, 1, score + 1);
                    else dfs(r, c, 3, score + 2);
                    break;
                }
                }
                break;
            }
            case 2:{
                switch (dir){
                case 1:{
                    if(c < N - 1) dfs(r, c + 1, 2, score + 1);
                    else dfs(r, c, 4, score + 2);
                    break;
                }
                case 2:{
                    dfs(r, c - 1, 4, score + 1);
                    break;
                }
                case 3:{
                    dfs(r - 1, c, 1, score + 1);
                    break;
                }
                case 4:{
                    if (r < N - 1) dfs(r + 1, c, 3, score + 1);
                    else dfs(r, c, 1, score + 2);
                    break;
                }
                }
                break;
            }
            case 3:{
                switch (dir){
                case 1:{
                    if(c > 0) dfs(r, c - 1, 4, score + 1);
                    else dfs(r, c, 2, score + 2);
                    break;
                }
                case 2:{
                    if(r < N - 1) dfs(r + 1, c, 3, score + 1);
                    else dfs(r, c, 1, score + 2);
                    break;
                }
                case 3:{
                    dfs(r - 1, c, 1, score + 1);
                    break;
                }
                case 4:{
                    dfs(r, c + 1, 2, score + 1);
                    break;
                }
                }
                break;
            }
            case 4:{
                switch (dir){
                case 1:{
                    dfs(r + 1, c, 3, score + 1);
                    break;
                }
                case 2:{
                    if(r > 0) dfs(r - 1, c, 1, score + 1);
                    else dfs(r, c, 3, score + 2);
                    break;
                }
                case 3:{
                    if (c > 0) dfs(r, c - 1, 4, score + 1);
                    else dfs(r, c, 2, score + 2);
                    break;
                }
                case 4:{
                    dfs(r, c + 1, 2, score + 1);
                    break;
                }
                }
                break;
            }
            case 5:{
                switch (dir){
                case 1:{
                    dfs(r + 1, c, 3, score + 1);
                    break;
                }
                case 2:{
                    dfs(r, c - 1, 4, score + 1);
                    break;
                }
                case 3:{
                    dfs(r - 1, c, 1, score + 1);
                    break;
                }
                case 4:{
                    dfs(r, c + 1, 2, score + 1);
                    break;
                }
                }
                break;
            }
            }
        }
    }
    else{
        switch (dir){
        case 1:{
            if (r > 0) dfs(r - 1, c, 1, score);
            else dfs(r, c, 3, score + 1);
            break;
        }
        case 2:{
            if (c < N - 1) dfs(r, c + 1, 2, score);
            else dfs(r, c, 4, score + 1);
            break;
        }
        case 3:{
            if (r < N - 1) dfs(r + 1, c, 3, score);
            else dfs(r, c, 1, score + 1);
            break;
        }
        case 4:{
            if (c > 0) dfs(r, c - 1, 4, score);
            else dfs(r, c, 2, score + 1);
            break;
        }
        }
    }
}
 
void search(int r, int c){
    coloring[r][c][0] = -3;
    if (r > 0) dfs(r - 1, c, 1, 0);
    else dfs(r, c, 3, 1);
    if (c < N - 1) dfs(r, c + 1, 2, 0);
    else dfs(r, c, 4, 1);
    if (r < N - 1) dfs(r + 1, c, 3, 0);
    else dfs(r, c, 1, 1);
    if (c > 0) dfs(r, c - 1, 4, 0);
    else dfs(r, c, 2, 1);
    coloring[r][c][0] = answer;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d", &N);
        for (int a = 0; a < 5; a++){
            for (int b = 0; b < 2; b++){
                for (int c = 0; c < 2; c++){
                    worm[a][b][c] = -1;
                }
            }
        }
 
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++){
                scanf("%d", &pmap[j][k]);
                if (!pmap[j][k]) q.push(make_pair(j, k));
                if (pmap[j][k] > 5){
                    if (worm[pmap[j][k] - 6][0][0] == -1){
                        worm[pmap[j][k] - 6][0][0] = j;
                        worm[pmap[j][k] - 6][0][1] = k;
                    }
                    else{
                        worm[pmap[j][k] - 6][1][0] = j;
                        worm[pmap[j][k] - 6][1][1] = k;
                    }
                }
            }
        answer = 0;
        for (int a = 0; a < N; a++){
            for (int b = 0; b < N; b++){
                for (int c = 0; c < 5; c++){
                    coloring[a][b][c] = 0;
                }
            }
        }
 
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            search(r, c);
        }
 
        printf("#%d %d\n", i, answer);
    }
}