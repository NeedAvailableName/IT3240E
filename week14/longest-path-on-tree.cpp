#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int N;
vector<int> A[MAX];
vector<int> c[MAX];
int d[MAX];
int p[MAX];
void input() {
    cin >> N;
    for(int i = 1; i <= N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[v].push_back(u);
        A[u].push_back(v);
        c[u].push_back(w);
        c[v].push_back(w);
    }
}
void BFS(int u) {
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i++) {
            int x = A[v][i];
            if(d[x] == -1) {
                int w = c[v][i];
                Q.push(x);
                d[x] = d[v] + w;
                p[x] = v;
            }
        }
    }
}
int findMax() {
    int max_d = -1;
    int u = -1;
    for(int v = 1; v <= N; v++) {
        if(max_d < d[v]) {
            max_d = d[v];
            u = v;
        }
    }
    return u;
}
void init() {
    for(int v = 1; v <= N; v++) {
        d[v] = -1;
        p[v] = -1;
    }
}
void solve() {
    init();
    BFS(1);
    int u = findMax();
    init();
    BFS(u);
    u = findMax();
    cout << d[u];
}
int main() {
    input();
    solve();
}