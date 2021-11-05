#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n, k;
int c[2*n+1][2*n+1];
int cm;
int x[MAX];
bool mark[MAX];
int load = 0;
int f = 0, f_min = 10e6;

bool check(int v, int i) {
    if(mark[v] == true) return false;
    if(v > n) {
        if(!mark[v-n]) return false;
    }
    else {
        if(load+1 > k) return false;
    }
    return true;
}
void printSolution() {
    if(f + c[x[2*n]][0] < f_min) {
        f_min = f + c[x[2*n]][0];
    }
}
void Try(int i) {
    for(int v = 1; v <= 2*n; v++) {
        if(check(v, i)) {
            x[i] = v;
            f += c[x[i-1]][x[i]];
            if(v <= n) load += 1;
            else load -= 1;
            mark[v] = true;
            if(i == 2*n) printSolution();
            else {
                if(f + (2*n+1-i)*cm < f_min) Try(i+1);
            }
            if(v <= n) load -= 1;
            else load -= -1;
            mark[v] = false;
            f -= c[x[i-1]][x[i]];
        }
    }
}
void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if(cm > c[i][j]) cm = c[i][j];
        }
    }
}
int main() {
    input();
    for(int i = 1; i <= 2*n; i++) mark[i] = 0;
    x[0] = 0;
    Try(1);
    cout << f_min;
    return 0;
}