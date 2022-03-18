#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> a[N];
vector<int> at[N];
bool visited[N];
vector<int> x;
int n, m;
int ans;
void DFS1(int u) {
    visited[u] = true;
    for(int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(!visited[v]) DFS1(v);
    }
    x.push_back(u);
}
void dfs1() {
    for(int v = 1; v <= n; v++) {
        visited[v] = false;
    }
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) DFS1(v);
    }
}

void makeGraph() {
    for(int v = 1; v <= n; v++) {
        for(int i = 0; i < a[v].size(); i++) {
            int u = a[v][i];
            at[u].push_back(v);
        }
    }
}

void DFS2(int u) {
    visited[u] = true;
    for(int i = 0; i < at[u].size(); i++) {
        int v = at[u][i];
        if(!visited[v]) DFS2(v);
    }
}
void dfs2() {
    for(int v = 1; v <= n; v++) {
        visited[v] = false;
    }
    ans = 0;
    for(int i = x.size()-1; i >= 0; i--) {
        int v = x[i];
        if(!visited[v]) {
            ans += 1;
            DFS2(v);
        }
    }
    printf("%d", ans);
}
void input() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
}
int main() {
    input();
    dfs1();
    makeGraph();
    dfs2();
    return 0;
}