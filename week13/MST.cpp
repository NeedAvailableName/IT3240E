#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define N 100001
struct Edge {
    int u, v;
    ull w;
    Edge(int _u, int _v, ull _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};
int n, m;
vector<Edge> E;
int p[N], r[N];
void makeSet(int x) {
    p[x] = x;
    r[x] = 0;
}
int Find(int x) {
    if(x != p[x]) p[x] = Find(p[x]);
    return p[x];
}
void unify(int x, int y) {
    if(r[x] > r[y]) p[y] = x;
    else {
        p[x] = y;
        if(r[x] == r[y]) r[y] += 1;
    }
}
void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        ull w;
        cin >> u >> v >> w;
        E.push_back(Edge(u, v, w));
    }
}
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}
void solve() {
    for(int v = 1; v <= n; v++) {
        makeSet(v);
    }
    ull ans = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int u = E[i].u;
        int v = E[i].v;
        int ru = Find(u);
        int rv = Find(v);
        if(ru != rv) {
            cnt++;
            ans += E[i].w;
            unify(ru, rv);
        }
        if(cnt == n-1) break;
    }
    cout << ans;
}
int main() {
    input();
    sort(E.begin(), E.end(), cmp);
    solve();
}