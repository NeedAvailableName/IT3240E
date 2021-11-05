#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_N 50
#define MAX_M 10
int N, M;
int sz[MAX_N];
int t[MAX_N][MAX_M];
int h[MAX_N];
int A[MAX_N][MAX_N];
int X[MAX_N];
int f[MAX_M];
int f_best;
void input() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &h[i]);
    }
    for(int i = 1; i <= N; i++) {
        scanf("%d", &sz[i]);
        for(int j = 0; j < sz[i]; j++) {
            scanf("%d", &t[i][j]);
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}
int check(int v, int k) {
    for(int i = 1; i <= k-1; i++) {
        if(A[i][k] && v == X[i]) return 0;
    }
    return 1;
}
void solution() {
    int max = 0;
    for(int i = 1; i <= M; i++) {
        if(max < f[i]) max = f[i];
    }
    if(max < f_best) f_best = max;    
}
void Try(int k) {
    for(int i = 0; i < sz[k]; i++) {
        int v = t[k][i];
        if(check(v, k)) {
            X[k] = v;
            f[v] += h[k];
            if(k == N) {
                solution();
            }
            else {
                Try(k+1);
            }
            f[v] -= h[k];
        }
    }
}
void solve() {
    f_best = 1000000;
    for(int i = 1; i <= M; i++) {
        f[i] = 0;
    }
    Try(1);
    if(f_best == 1000000) printf("-1");
    else printf("%d", f_best);
}
int main() {
    input();
    solve();
}