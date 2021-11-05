#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<int, int> L[n];
    queue<pair<int, int>> Q;
    for(int i = 1; i <= n; i++) {
        cin >> L[i].first >> L[i].second;
    }
    for(int i = 1; i < n; i++) {
        if(L[i].second > L[i+1].second) {
            int tmp = L[i].second;
            L[i].second = L[i+1].second;
            L[i+1].second = tmp;
        }
        Q.push(L[i]);
    }
    while(!Q.empty()) {
        
        Q.pop();

    }
    
}