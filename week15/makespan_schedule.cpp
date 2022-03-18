#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+1;
int n, m;
int d[N];
int F[N];
int deg[N];
vector<int> A[N];
vector<int> L;
int makespan;
void input() {
    cin >> n >> m;
    for(int v = 1; v <= n; v++) {
        cin >> d[v];
        deg[v] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        deg[v] += 1;
    }
}
void topo() {
    queue<int> Q;
    for(int v = 1; v <= n; v++) {
        if(deg[v] == 0) Q.push(v);
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        L.push_back(u);
        for(int i = 0; i < A[u].size(); i++) {
            int v = A[u][i];
            deg[v] -= 1;
            if(deg[v] == 0) Q.push(v);
        }
    }
}
void solve() {
    makespan = 0;
    for(int v = 1; v <= n; v++) F[v] = 0;
    for(int i = 0; i < L.size(); i++) {
        int u = L[i];
        makespan = max(makespan, F[u] + d[u]);
        for(int i = 0; i < A[u].size(); i++) {
            int v = A[u][i];
            F[v] = max(F[v], F[u] + d[u]);
        }
    }
    cout << makespan;
}
int main() {
    input();
    topo();
    solve();
}