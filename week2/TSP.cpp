#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100, INF = 10000000;
int A[N][N];
int x[N];
bool mark[N];
int f = 0, f_min = INF;
int cm = INF;

bool check(int i, int v) {
    return(!mark[v]);
}
void printSolution() {
    if(f + A[x[n]][x[1]] < f_min) f_min = f + A[x[n]][x[1]];
}
void Try(int i) {
    for(int v = 2; v <= n; v++) {
        if(check(i, v)) {
            x[i] = v;
            mark[v] = true;
            f += A[x[i-1]][x[i]];
            if(i == n) printSolution();
            else {
                int gk = f + (n-i+1)*cm;
                if(gk < f_min) Try(i+1);
            }
            mark[v] = false;
            f -= A[x[i-1]][x[i]];
        }
    }
}
void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            A[i][j] = INF;
        }
    }
    for(int k = 1; k <= m; k++) {
        int i, j, c;
        cin >> i >> j >> c;
        A[i][j] = c;
        if(cm > A[i][j]) {
            cm = A[i][j];
        }
    }
}
int main() {
    input();
    for(int v = 1; v <= N; v++) {
        mark[v] = false;
    }
    x[1] = 1;
    mark[1] = true;
    Try(2);
    cout << f_min;
    return 0;
}
