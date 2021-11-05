#include<stdio.h>
#define MAX_N 20
#define MAX_M 10
#define MAX_B 10
int N, M, b;
int sz[MAX_N+1];
int A[MAX_N+1][MAX_M+1];
int X[MAX_N+1][MAX_B+1];
int load[MAX_M+1];
int f_best;
void input() {
    scanf("%d%d%d", &N, &M, &b);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &sz[i]);
        for(int j = 1; j < sz[i]; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}
void solution() {
    int max_load = load[1];
    for(int i = 2; i <= M; i++) {
        if(max_load < load[i]) max_load = load[i];
    }
    if(max_load < f_best) f_best = max_load;
}
int check(int v, int k, int i) {
    if(load[k] >= f_best-1) return 0;
    return v > X[k][i-1];
}
void Try(int k, int i) {
    for(int j = 0; i < sz[k]; j++) {
        int v = A[k][j];
        if(check(v, k, i)) {
            X[k][i] = v;
            load[v]++;
            if(k == N) {
                if(i == b) solution();
                else Try(k, i+1);
            }
            else {
                if(i == b) Try(k+1, 1);
                else Try(k, i+1);
            }
            load[v]--;
        }
    }
}
void solve() {
    f_best = 1000000;
    for(int i = 1; i <= M; i++) {
        load[i] = 0;
        X[i][0] = 0;
    }
    Try(1, 1);
    printf("%d", f_best);
}
int main() {
    input();
    solve();
}