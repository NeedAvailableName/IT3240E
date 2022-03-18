#include<bits/stdc++.h>
using namespace std;
int LCS(int X[], int Y[], int m, int n) {
    int cur[n+1], prev;
    for(int i = 0; i <= m; i++) {
        prev = cur[0];
        for(int j = 0; j <= n; j++) {
            int backup = cur[j];
            if(i == 0 || j == 0) {
                cur[j] = 0;
            }
            else {
                if(X[i-1] == Y[j-1]) {
                    cur[j] = prev+1;
                }
                else {
                    cur[j] = max(cur[j], cur[j-1]);
                }
            }
            prev = backup;
        }
    }
    return cur[n];
}
int main() {
    int n, m;
    cin >> n >> m;
    int x[n], y[m];
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    cout << LCS(x, y, n, m);
    return 0;
}