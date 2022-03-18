#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> a[N];
char color[N];
int n, m;
int t;
int nbCC;
//int d[N], f[N], p[N];
void DFS(int u) {
    //t++;
    color[u] = 'G';
    //d[u] = t;
    for(int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(color[v] == 'W') {
            //p[v] = u;
            DFS(v);
        }
    }
    //t++;
    //f[u] = t;
    color[u] = 'B';
}
void DFS() {
    for(int v = 1; v <= n; v++) {
        color[v] = 'W';
        nbCC = 0;
    }
    for(int v = 1; v <= n; v++) {
        if(color[v] == 'W') {
            nbCC++;
            DFS(v);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS();
    printf("%d", nbCC);
    return 0;
}