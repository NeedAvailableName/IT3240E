#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
int cap;
int c[2*MAX+1][2*MAX+1];
int cmin;
int x[MAX];
int appear[MAX];
int load;
int f;
int f_best;
void input() {
    scanf("%d%d", &n, &cap);
    cmin = 1000000;
    for(int i = 0; i <= 2*n; i++) {
        for(int j = 0; j <= 2*n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j && cmin > c[i][j]) {
                cmin = c[i][j];
            }
        }
    }
}
int check(int v, int k) {
    if(appear[v] == 1) return 0;
    if(v > n) {
        if(!appear[v-n]) return 0;
    }
    else {
        if(load+1 > cap) return 0;
    }
    return 1;
}
void solution() {
    if(f + c[x[2*n]][0] < f_best) {
        f_best = f + c[x[2*n]][0];
    }
}
void Try(int k) {
    for(int v = 1; v <= 2*n; v++) {
        if(check(v, k)) {
            x[k] = v;
            f += c[x[k-1]][x[k]];
            if(v <= n) load += 1;
            else load -= 1;
            appear[v] = 1;
            if(k == 2*n) solution();
            else {
                if(f + (2*n+1-k)*cmin < f_best) Try(k+1);
            }
            if(v <= n) load -= 1;
            else load -= -1;
            appear[v] = 0;
            f -= c[x[k-1]][x[k]];
        }
    }
}
void solve() {
    load = 0;
    f = 0;
    f_best = 1000000;
    for(int i = 1; i <= 2*n; i++) appear[i] = 0;
    x[0] = 0;
    Try(1);
    printf("%d", f_best);
}
int main() {
    input();
    solve();
}