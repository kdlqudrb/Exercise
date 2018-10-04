#include <bits/stdc++.h>
using namespace std;
 
int T, M, A, answer;
int moveA[100], moveB[100];
int smap[11][11];
 
struct AP{
    int r;
    int c;
    int ch;
    int p;
    int avail;
};
 
struct people{
    int r;
    int c;
};
 
struct AP arr[8];
struct people a, b;
 
int inchk(int ar, int ac, int br, int bc){
    int m = 0;
    int mi = 0;
    for (int i = 0; i < A; i++){
        if (abs(arr[i].r - ar) + abs(arr[i].c - ac) <= arr[i].ch && arr[i].avail){
            arr[i].avail = 0;
            int tmp = arr[i].p;
            for (int j = 0; j < A; j++){
                if (i == j) continue;
                if (abs(arr[j].r - br) + abs(arr[j].c - bc) <= arr[j].ch && arr[j].avail){
                    tmp += arr[j].p;
                    if (tmp > m) m = tmp;
                    tmp -= arr[j].p;
                }
            }
            if (tmp > m) m = tmp;
            arr[i].avail = 1;
        }
    }
 
    for (int i = 0; i < A; i++){
        if (abs(arr[i].r - br) + abs(arr[i].c - bc) <= arr[i].ch && arr[i].avail){
            arr[i].avail = 0;
            int tmp = arr[i].p;
            for (int j = 0; j < A; j++){
                if (i == j) continue;
                if (abs(arr[j].r - ar) + abs(arr[j].c - ac) <= arr[j].ch && arr[j].avail){
                    tmp += arr[j].p;
                    if (tmp > m) m = tmp;
                    tmp -= arr[j].p;
                }
            }
            if (tmp > m) m = tmp;
            arr[i].avail = 1;
        }
    }
    return m;
}
 
int main(){
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d", &M, &A);
        for (int j = 0; j < M; j++) scanf("%d", &moveA[j]);
        for (int j = 0; j < M; j++) scanf("%d", &moveB[j]);
        for (int j = 0; j < A; j++) scanf("%d %d %d %d", &arr[j].c, &arr[j].r, &arr[j].ch, &arr[j].p);
        a.r = a.c = 1;
        b.r = b.c = 10;
 
        answer = 0;
        int ti = 0;
        while (ti <= M){
            for (int j = 0; j < A; j++) arr[j].avail = 1;
 
            int tmp = inchk(a.r, a.c, b.r, b.c);
            if (tmp){
                answer += tmp;
            }
 
            if (ti != M){
                switch (moveA[ti]){
                case 1: a.r--; break;
                case 2: a.c++; break;
                case 3: a.r++; break;
                case 4: a.c--; break;
                }
                switch (moveB[ti]){
                case 1: b.r--; break;
                case 2: b.c++; break;
                case 3: b.r++; break;
                case 4: b.c--; break;
                }
            }
 
            ti++;
        }
 
        printf("#%d %d\n", i, answer);
    }
}