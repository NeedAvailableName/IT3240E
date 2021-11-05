#include<bits/stdc++.h>
using namespace std;
#define MAX 901
#define pii pair<int, int>
int N, M, start_row, start_column, ans;
int A[MAX][MAX];
bool visited[MAX][MAX], found;

bool finalState(pii s) {
    if(s.first < 1 || s.first > N || s.second < 1 || s.second > M) return true;
    else return false;
}
bool legalState(pii s) {
    return A[s.first][s.second] == 0 && !visited[s.first][s.second];
}

int main() {
    cin >> N >> M >> start_row >> start_column;
    pii is = make_pair(start_row, start_column);
    queue<pii> Q;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
            visited[i][j] = false;
        }
    }
    map<pii, int> step;
    Q.push(is);
    step[is] = 0;
    bool found = false;
    int ans = 0;
    while(!found) {
        pii s = Q.front();
        Q.pop();
        pii ns = make_pair(s.first-1, s.second);
        if(finalState(ns)) {
            step[ns] = step[s] + 1;
            ans = step[ns];
            found = true;
            break;
        }
        if(legalState(ns)) {
            visited[ns.first][ns.second] = true;
            step[ns] = step[s] + 1;
            Q.push(ns);
        }
    
        ns = make_pair(s.first+1, s.second);
        if(finalState(ns)) {
            step[ns] = step[s] + 1;
            ans = step[ns];
            found = true;
            break;
        }
        if(legalState(ns)) {
            visited[ns.first][ns.second] = true;
            step[ns] = step[s] + 1;
            Q.push(ns);
        }
    
        ns = make_pair(s.first, s.second-1);
        if(finalState(ns)) {
            step[ns] = step[s] + 1;
            ans = step[ns];
            found = true;
            break;
        }
        if(legalState(ns)) {
            visited[ns.first][ns.second] = true;
            step[ns] = step[s] + 1;
            Q.push(ns);
        }
    
        ns = make_pair(s.first, s.second+1);
        if(finalState(ns)) {
            step[ns] = step[s] + 1;
            ans = step[ns];
            found = true;
            break;
        }
        if(legalState(ns)) {
            visited[ns.first][ns.second] = true;
            step[ns] = step[s] + 1;
            Q.push(ns);
        }
    }
    if(found) {
        cout << ans;
    }
    else cout << "-1";
    return 0;
}