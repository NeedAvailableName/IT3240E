#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T != 0) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum = (sum % m + (i * (n - i + 1)) % m) % m;
        }
        cout << sum << "\n";
        T--;
    }
    return 0;
}