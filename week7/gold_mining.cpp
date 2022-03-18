#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, L1, L2;
    int a[100001];
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int F[100001];
    F[1] = a[1];
    int ans = F[1];
    for(int i = 2; i <= n; i++) {
        int maxj = 0;
        for(int j = i-L2; j <= i-L1; j++) {
            if(j >= 0) {
                maxj = max(maxj, F[j]);
            } 
        }
        F[i] = maxj + a[i];
        ans = max(ans, F[i]);
    }
    cout << ans;
    return 0;
}