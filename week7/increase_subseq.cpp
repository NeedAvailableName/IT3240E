#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int F[10001];
int selected;
int trace[10001];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    F[1] = 1;
    int ans = F[1];
    for(int i = 1; i <= n; i++) {
        trace[i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        F[i] = 1;
        for(int j = 1; j <= i-1; j++) {
            if(a[i] > a[j]) {
                F[i] = max(F[i], F[j]+1);
                if(F[j] + 1 > F[i]) {
                    trace[i] = j;
                }
            }
            ans = max(F[i], ans);
            if(ans < F[i]) selected = i;
        }
    }
    stack<int> S;
    cout << ans << "\n";
    while(true) {
        S.push(a[i]);
        i = trace[i];
        if(i == -1) break;
    }
    while(!S.empty()) {
        cout << S.pop();
    }
    return 0;
}