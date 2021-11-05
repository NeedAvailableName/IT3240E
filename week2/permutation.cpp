#include<bits/stdc++.h>
using namespace std;
int n, K, x[20];
bool mark[20];
int a[20][20];
int cnt = 0;

bool check(int v, int i) {
    if(mark[v] == true) return false;
    for(int j = 1; j <= i-1; j++) {
        if(a[v][x[j]]) return false;
    }
    return true;
}

void printSolution() {
    for(int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int i) {
    for(int v = 1; v <= n; v++) {
        if(check(v,i)) {
            x[i] = v;
            mark[v] = true;
            if(i == n) {
                printSolution();
                cnt += 1;
            }
            else Try(i+1);
            mark[v] = false;
        }
    }
}

void input() {
    cin >> n >> K;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    for(int k = 1; k <= K; k++) {
        int i, j;
        cin >> i >> j;
        a[i][j] = 1;
    }
}

int main() {
    input();
    for(int v = 1; v <= n; v++) {
        mark[v] = false;
    }
    Try(1);
    cout << cnt;
    return 0;
}