#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
int n;
int c[MAX][MAX];
int cmin;
int x[MAX];
int appear[MAX];
int f;
int f_best;
int x_best[MAX];
void input() {
    scanf("%d", &n);
    cmin = 1000000;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j && cmin > c[i][j]) {
                cmin = c[i][j];
            } 
        }
    }
}
int check(int v, int k) {
    if(appear[v] == 1) return 0;
    return 1;
}
void solution() {
    if(f + c[x[n]][0] < f_best) {
        f_best = f + c[x[n]][0];
        for(int i = 0; i <= n; i++) {
            x_best[i] = x[i];
        }
    }
}
void Try(int k) {
    for(int v = 1; v <= n; v++) {
        if(check(v, k)) {
            x[k] = v;
            f += c[x[k-1]][x[k]];
            appear[v] = 1;
            if(k == n) solution();
            else {
                if(f + (n-1-k)*cmin < f_best) {
                    Try(k+1);
                }
            }
            appear[v] = 0;
            f -= c[x[k-1]][x[k]];
        }
    }
}
void solve() {
    f = 0;
    f_best = 1000000;
    for(int i = 1; i <= n; i++) {
        appear[i] = 0;
    }
    x[0] = 0;
    Try(1);
    printf("%d", f_best);
}
int main() {
    input();
    solve();
}