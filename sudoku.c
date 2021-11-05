#include<stdio.h>
int x[9][9];
int o[3][3][10];
int h[9][10];
int c[9][10];
int found;
int check(int v, int i, int j) {
    return !h[i][v] && !c[j][v] && !o[i/3][j/3][v];
}
void solution() {
    found = 1;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}
void Try(int i, int j) {
    if(found) return;
    for(int v = 1; v <= 9; v++) {
        if(check(v, i ,j)) {
            x[i][j] = v;
            h[i][v] = 1;
            c[j][v] = 1;
            o[i/3][j/3][v] = 1;
            if(i == 8 && j == 8) {
                solution();
            }
            else {
                if(j < 8) Try(i, j+1);
                else Try(i+1, 0);
            }
            h[i][v] = 0;
            c[j][v] = 0;
            o[i/3][j/3][v] = 0;
        }
    }
}
int main() {
    for(int v = 1; v <= 9; v++) {
        for(int i = 0; i <= 8; i++) {
            h[i][v] = 0;
            c[i][v] = 0;
        }
        for(int i = 0; i <= 2; i++) {
            for(int j = 0; j <= 2; j++) {
                o[i][j][v] = 0;
            }
        }
    }
    found = 0;
    Try(0, 0);
}