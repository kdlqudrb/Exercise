#include <stdio.h>
 
int magnet[5][8], spin_stack[5];
 
void spin(int spin_num, int spin_dir){
    int tmp;
    if (spin_dir == 1){
        if (spin_num == 1){
            if (magnet[1][2] ^ magnet[2][6] && !spin_stack[2]){
                spin_stack[2] = 1;
                spin(2, -1);
            }
        }
        else if (spin_num == 2){
            if (magnet[1][2] ^ magnet[2][6] && !spin_stack[1]){
                spin_stack[1] = 1;
                spin(1, -1);
            }
            if (magnet[2][2] ^ magnet[3][6] && !spin_stack[3]){
                spin_stack[3] = 1;
                spin(3, -1);
            }
 
        }
        else if (spin_num == 3){
            if (magnet[4][6] ^ magnet[3][2] && !spin_stack[4]){
                spin_stack[4] = 1;
                spin(4, -1);
            }
            if (magnet[2][2] ^ magnet[3][6] && !spin_stack[2]){
                spin_stack[2] = 1;
                spin(2, -1);
            }
        }
        else{
            if (magnet[4][6] ^ magnet[3][2] && !spin_stack[3]){
                spin_stack[3] = 1;
                spin(3, -1);
            }
        }
 
        tmp = magnet[spin_num][7];
        for (int i = 7; i > 0; i--){
            magnet[spin_num][i] = magnet[spin_num][i - 1];
        }
        magnet[spin_num][0] = tmp;
    }
    else{
        if (spin_num == 1){
            if (magnet[1][2] ^ magnet[2][6] && !spin_stack[2]){
                spin_stack[2] = 1;
                spin(2, 1);
            }
        }
        else if (spin_num == 2){
            if (magnet[1][2] ^ magnet[2][6] && !spin_stack[1]){
                spin_stack[1] = 1;
                spin(1, 1);
            }
            if (magnet[2][2] ^ magnet[3][6] && !spin_stack[3]){
                spin_stack[3] = 1;
                spin(3, 1);
            }
 
        }
        else if (spin_num == 3){
            if (magnet[4][6] ^ magnet[3][2] && !spin_stack[4]){
                spin_stack[4] = 1;
                spin(4, 1);
            }
            if (magnet[2][2] ^ magnet[3][6] && !spin_stack[2]){
                spin_stack[2] = 1;
                spin(2, 1);
            }
        }
        else{
            if (magnet[4][6] ^ magnet[3][2] && !spin_stack[3]){
                spin_stack[3] = 1;
                spin(3, 1);
            }
        }
 
        tmp = magnet[spin_num][0];
        for (int i = 0; i < 8; i++){
            magnet[spin_num][i] = magnet[spin_num][i + 1];
        }
        magnet[spin_num][7] = tmp;
    }
}
 
int cal(){
    int sum, pow = 1;
    sum = 0;
    for (int i = 1; i < 5; i++){
        if (magnet[i][0]) sum += pow;
        pow *= 2;
    }
    return sum;
}
 
int main(){
    int T, K, spin_num, spin_dir;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d", &K);
        for (int j = 1; j < 5; j++){
            for (int k = 0; k < 8; k++)
                scanf("%d", &magnet[j][k]);
        }
        while (K--){
            for (int j = 1; j < 5; j++) spin_stack[j] = 0;
            scanf("%d %d", &spin_num, &spin_dir);
            spin_stack[spin_num] = 1;
            spin(spin_num, spin_dir);
        }
        printf("#%d %d\n", i, cal());
    }
}