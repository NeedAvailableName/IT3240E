#include<bits/stdc++.h>
using namespace std;
int S0[1001], S1[1001];
int N, K1, K2;
int c = 10e9+7;
int main() {
    cin >> N >> K1 >> K2;
    S0[0] = 1;
    S0[1] = 1;
    if(K1 <= 1) S1[1] = 1;
    else S1[1] = 0;
    for (int i = 2; i <= N; i++) {
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int j = K1; j <= K2; j++) {
            if(i - j >= 0) {
                S1[i] += S0[i-j];
                S1[i] = S1[i] % c;
            }
        }
    }
    int ans = (S0[N] + S1[N]) % c;
    cout << ans;
}