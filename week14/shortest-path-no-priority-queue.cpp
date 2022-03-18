#include<bits/stdc++.h>
using namespace std;
struct Arc {
    int node;
    int weight;
    Arc(int _node, int _weight) {
        node = _node;
        weight = _weight;
    }
};
const int N = 10e5+1;
const int INF = 10e9;
int n, m;
vector<Arc> A[N];
int s, t;
int d[N], p[N];
set<int> F;
void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
    cin >> s >> t;
}
int selectMin() {
    int minD = INF;
    int sel_node = -1;
    for(set<int> :: iterator it = F.begin(); it != F.end(); it++) {
        int v = *it;
        if(d[v] < minD) {
            minD = d[v];
            sel_node = v;
        }
    }
    return sel_node;
}
int dijktra() {
    for(int v = 1; v <= n; v++) {
        d[v] = INF;
    }
    d[s] = 0;
    for(int i = 0; i < A[s].size(); i++) {
        Arc e = A[s][i];
        int v = e.node;
        d[v] = e.weight;
    }
    for(int v = 1; v <= n; v++) {
        if(v != s) F.insert(v);
    }
    while(F.size() > 0) {
        int u = selectMin();
        if(u == t) return d[u];
        F.erase(u);
        for(int i = 0; i < A[u].size(); i++) {
            Arc e = A[u][i];
            int v = e.node;
            int w = e.weight;
            if(d[v] > d[u]+w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    return -1;
}
int main() {
    input();
    cout << dijktra();
    return 0;
}