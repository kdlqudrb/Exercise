#include <iostream>
using namespace std;
 
int answer;
int N, X;
int map[20][20];
int coloring[20][20];
 
void hSearch(){
    int chk, prev, prev_len;
    for (int i = 0; i < N; i++){
        chk = 0;
        for (int j = 0; j < N; j++){
            if (j == 0){
                prev = map[i][j];
                prev_len = 1;
            }
            else{
                if (prev == map[i][j]){
                    prev_len++;
                }
                else if (prev == map[i][j] - 1){
                    if (prev_len < X){
                        chk++;
                        break;
                    }
                    else{
                        int tmp = 0;
                        for (int k = X; k > 0; k--){
                            if (coloring[i][j - k] == 1){
                                tmp++;
                                break;
                            }
                        }
                        if (tmp == 0){
                            for (int k = X; k > 0; k--){
                                coloring[i][j - k] = 1;
                            }
                            prev = map[i][j];
                            prev_len = 1;
                        }
                        else{
                            chk++;
                            break;
                        }
                    }
                }
                else if (prev == map[i][j] + 1){
                    if (j + X > N){
                        chk++;
                        break;
                    }
                    int next = map[i][j];
                    for (int k = j + 1; k < j + X; k++){
                        if (map[i][k] != next){
                            chk++;
                            break;
                        }
                    }
                    if (chk) break;
                    else{
                        for (int k = X - 1; k >= 0; k--){
                            coloring[i][j + k] = 1;
                        }
                        prev = map[i][j];
                        prev_len = 1;
                        j += (X - 1);
                    }
                }
                else{
                    chk++;
                    break;
                }
            }
        }
        if (chk == 0) answer++;
    }
}
 
void vSearch(){
    int chk, prev, prev_len;
    for (int i = 0; i < N; i++){
        chk = 0;
        for (int j = 0; j < N; j++){
            if (j == 0){
                prev = map[j][i];
                prev_len = 1;
            }
            else{
                if (prev == map[j][i]){
                    prev_len++;
                }
                else if (prev == map[j][i] - 1){
                    if (prev_len < X){
                        chk++;
                        break;
                    }
                    else{
                        int tmp = 0;
                        for (int k = X; k > 0; k--){
                            if (coloring[j - k][i] == 1){
                                tmp++;
                                break;
                            }
                        }
                        if (tmp == 0){
                            for (int k = X; k > 0; k--){
                                coloring[j - k][i] = 1;
                            }
                            prev = map[j][i];
                            prev_len = 1;
                        }
                        else{
                            chk++;
                            break;
                        }
                    }
                }
                else if (prev == map[j][i] + 1){
                    if (j + X > N){
                        chk++;
                        break;
                    }
                    int next = map[j][i];
                    for (int k = j + 1; k < j + X; k++){
                        if (map[k][i] != next){
                            chk++;
                            break;
                        }
                    }
                    if (chk) break;
                    else{
                        for (int k = X - 1; k >= 0; k--){
                            coloring[j + k][i] = 1;
                        }
                        prev = map[j][i];
                        prev_len = 0;
                        j += (X - 1);
                    }
                }
                else{
                    chk++;
                    break;
                }
            }
        }
        if (chk == 0) answer++;
    }
}
 
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        answer = 0;
        scanf("%d %d", &N, &X);
        for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) scanf("%d", &map[j][k]);
        for (int j = 0; j < 20; j++) for (int k = 0; k < 20; k++) coloring[j][k] = 0;
        hSearch();
        for (int j = 0; j < 20; j++) for (int k = 0; k < 20; k++) coloring[j][k] = 0;
        vSearch();
        printf("#%d %d\n", i, answer);
    }
}