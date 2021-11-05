#include<bits/stdc++.h>
#define MAX_N 30
#define MAX_M 10
int N, M;
int c[MAX_N];
int A[MAX_N][MAX_N];
int x[MAX_N];
int f_best;
int load[MAX_M];
int check(int v, int k) {
    for(int i = 1; i <= k-1; i++) {
        if(A[i][k] == 1) {
            if(x[i] >= v) return 0;
        }
        else if(A[k][i] == 1) {
            if(v >= x[i]) return 0;
        }
    }
    return 1;
}
void solution() {
    int max = load[1];
    for(int i = 2; i <= M; i++) {
        max = max < load[i] ? load[i] : max;
    }
    if(max < f_best) f_best = max;
}
void Try(int k) {
    for(int v = 1; v <= M; v++) {
        if(check(v, k)) {
            x[k] = v;
            load[v] += c[k];
            if(k == N) solution();
            else Try(k+1);
            load[v] -= c[k];
        }
    }
}
void input() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", A[i][j]);
        }
    }
}
void solve() {
    for(int i = 1; i <= M; i++) {
        load[i] = 0;
    }
    f_best = 1000000;
    Try(1);
    printf("%d\n", f_best);
}
int main() {
    input();
    solve();
}