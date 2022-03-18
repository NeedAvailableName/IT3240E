#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
int C[N], D[N];
int d[N];
int dist[N][N];
vector<int> A[N];
int n, k;
set<int> NF;
void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    for(int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void BFS(int s) {
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        d[i] = -1;
    }
    d[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < A[u].size(); i++) {
            int v = A[u][i];
            if(d[v] == -1) {
                d[v] = d[u] + 1;
                if(d[v] <= D[s]) {
                    dist[s][v] = C[s];
                    Q.push(v);
                }
            }
        }

    }
}
void buildGraph() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= n; i++) BFS(i);
}
int findMin() {
    int minD = 1e9;
    int sel = -1;
    for(set<int> :: iterator it = NF.begin(); it != NF.end(); it++) {
        if(d[*it] < minD) {
            minD = d[*it];
            sel = *it;
        }
    }
    return sel;
}
void findShortestPath() {
    for(int v =1; v <= n; v++) {
        d[v] = dist[1][v];
        if(v != 1) NF.insert(v);
    }
    d[1] = 0;
    while(NF.size() > 0) {
        int u = findMin();
        if(u == n) break;
        NF.erase(u);
        for(set<int> :: iterator it = NF.begin(); it != NF.end(); it++) {
            int v = *it;
            if(d[v] > d[u] + dist[u][v]) {
                d[v] = d[u] + dist[u][v];
            }
        }   
    }
    cout << d[n];
}
int main() {
    input();
    buildGraph();
    findShortestPath();
    return 0;
}