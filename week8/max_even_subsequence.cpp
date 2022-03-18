#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int F[1000001];
int S[1000001];
bool f[1000001], s[1000001];
bool found = false;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans;
    if(a[1] % 2 == 0) {
        F[1] = a[1];
        f[1] = true;
        s[1] = false;
        ans = F[1];
        found = true;
    }
    else {
        S[1] = a[1];
        s[1] = true;
        f[1] = false;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] % 2 == 0) {
            if(f[i-1] == true) {
                F[i] = max(F[i-1] + a[i], a[i]);
                f[i] = true;
            }
            else {
                F[i] = a[i];
                f[i] = true;
            }
            if(s[i-1] == false) {
                s[i] = false;
            }
            else {
                S[i] = S[i-1] + a[i];
                s[i] = true;
            }
        }
        else {
            if(s[i-1] == false) {
                f[i] = false;
            }
            else {
                F[i] = S[i-1] + a[i];
                f[i] = true;
            }
            if(f[i-1] == true) {
                S[i] = max(F[i-1] + a[i], a[i]);
                s[i] = true; 
            }
            else {
                S[i] = a[i];
                s[i] = true;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        ans = max(ans, F[i]);
        found = true;
    }
    if(found) cout << ans;
    else cout << "NOT_FOUND";
    return 0;
}