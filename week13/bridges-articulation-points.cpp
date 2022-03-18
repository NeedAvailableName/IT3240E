#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m;
vector<int> A[N];
bool visited[N];
int low[N], num[N];
int t;
int nbBridges, nbArti;
int root, nbChildren;
bool art[N];
void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void dfs(int u, int pu) {
    t += 1;
    visited[u] = true;
    low[u] = t;
    num[u] = t;
    for(int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if(v == pu) continue;
        if(visited[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            if(u == root) nbChildren += 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) {
                nbBridges += 1;
            }
            if(low[v] >= num[u] && u != root) {
                art[u] = true;
            }
        }
    }
}
int main() {
    input();
    for(int v = 1; v <= n; v++) {
        visited[v] = false;
        art[v] = false;
    }
    nbBridges = 0;
    nbArti = 0;
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            t = 0;
            root = v;
            nbChildren = 0;
            dfs(v, 0);
            if(nbChildren > 1) art[v] = true;
        }
    }
    for(int v = 1; v <= n; v++) {
        if(art[v]) nbArti += 1;
    }
    cout << nbArti << " " << nbBridges;
    return 0;
}