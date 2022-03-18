#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int F[1000001];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    F[1] = a[1];
    int max = F[1];
    for(int i = 2; i <= n; i++) {
        if(F[i-1] > 0) F[i] = F[i-1] + a[i];
        else F[i] = a[i];
        if(F[i] > max) max = F[i];
    }
    cout << max;
    return 0;
}