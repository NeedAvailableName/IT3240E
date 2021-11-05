#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define pii pair<int, int>
int a, b, c;
bool visited[N][N];

bool finalState(pii s) {
    return s.first == c || s.second == c;
}
bool legalState(pii s) {
    return !visited[s.first][s.second];
}

int main() {
    cin >> a >> b >> c;
    for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++) {
            visited[x][y] = false;
        }
    }
    pii is = make_pair(0, 0);
    queue<pii> Q;
    map<pii, int> step;
    visited[0][0] = true;
    Q.push(is);
    step[is] = 0;
    bool found = false;
    int ans;
    while(!Q.empty()) {
        pii s = Q.front();
        Q.pop();
        pii ns = make_pair(a, s.second);
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

        ns = make_pair(s.first, b);
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

        ns = make_pair(0, s.second);
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

        ns = make_pair(s.first, 0);
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

        if(s.first + s.second > b) {
            ns = make_pair(s.first + s.second - b, b);
        }
        else {
            ns = make_pair(0, s.first + s.second);
        }
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

        if(s.first + s.second > a) {
            ns = make_pair(a, s.first + s.second - a);
        }
        else {
            ns = make_pair(s.first + s.second, 0);
        }
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
    else {
        cout << "-1";
    }
    return 0;
}