#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> Element;
struct Arc {
    int node;
    int weight;
    Arc(int _node, int _weight) {
        node = _node;
        weight = _weight;
    }
};
const int N = 1e5+1;
const int INF = 1e9;
int n, m;
vector<Arc> A[N];
int s, t;
int d[N];
int p[N];
priority_queue<Element, vector<Element>, greater<Element>> pq;
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
    Element e = pq.top();
    return e.second;
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
        pq.push(make_pair(d[v], v));
    }
    while(pq.size() > 0) {
        int u = selectMin();
        if(u == t) return d[u];
        pq.pop();
        for(int i = 0; i < A[u].size(); i++) {
            Arc e = A[u][i];
            int v = e.node;
            int w = e.weight;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                pq.push(make_pair(d[v], v));
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