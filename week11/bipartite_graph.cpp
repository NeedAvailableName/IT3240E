#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<int> A[100001];
int d[100001];
bool BFS(int u) {
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i++) {
            int x = A[v][i];
            if(d[x] > -1) {
                if((d[v] + d[x]) % 2 == 0) {
                    return false;
                }
            }
            else {
                d[x] = d[v] + 1;
                Q.push(x);
            }
        }
    }
    return true;
}
void BFS() {
    for(int v = 1; v <= N; v++) {
        d[v] = -1;
    }
    int ans = 1;
    for(int v = 1; v <= N; v++) {
        if(d[v] == -1) {
            bool ok = BFS(v);
            if(!ok) {
                ans = 0;
                break;
            }
        }
    }
    printf("%d", ans);
}
int main() {
    scanf("%d%d", &N, &M);
    int u, v;
    for(int i = 1; i <= M; i++) {
        scanf("%d%d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
    BFS();
    return 0;
}