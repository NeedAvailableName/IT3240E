#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n;
vector<int> A[N];
vector<int> C[N];
int w[N];
int p[N];
int d[N];
bool visited[N];
int root;
int F0[N], F1[N], F[N];
int ans;
void input() {
    cin >> n;
    for(int v = 1; v <= n; v++) {
        cin >> w[v];
    }
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void initDFS() {
    for(int v = 1; v <= n; v++) {
        visited[v] = false;
    }
}
void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if(!visited[v]) {
            p[v] = u;
            C[u].push_back(v);
            d[u] += 1;
            dfs(v);
        }
    }
}
void dfs() {
    initDFS();
    root = 1;
    visited[root] = true;
    dfs(root);
}
void solve() {
    for(int v = 1; v <= n; v++) {
        F0[v] = 0;
        F1[v] = w[v];
    }
    dfs();
    queue<int> Q;
    for(int v = 1; v <= n; v++) {
        if(C[v].size() == 0) {
            Q.push(v);
            F[0] = 0;
            F1[v] = w[v];
            F[v] = max(F0[v], F1[v]);
        }
    }
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        F[v] = max(F0[v], F1[v]);
        if(v == root) break;
        int pv = p[v];
        F0[pv] += F[v];
        F1[pv] += F0[v];
        d[pv] -= 1;
        if(d[pv] == 0) {
            Q.push(pv);
        } 
    }
    ans = F[root];
    cout << ans;
}
int main() {
    input();
    solve();
    return(0);
}