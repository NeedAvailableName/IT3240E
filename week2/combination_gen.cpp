#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int check = m;
    for(int i = m; i > 0; i--) {
        if(a[i] == n-(m-i)) check--;
    }
    if(check == 0) cout << "-1";
    else {
        int i = m;
        while(a[i] == n-m+i) {
            i -= 1;
        }
        a[i] = a[i] + 1;
        for(int j = i+1; j <= m+1; j++) {
            a[j] = a[i] + j - i;
        }
        for(int i = 1; i <= m; i++) {
            cout << a[i] << " ";
        }
    }
    return 0;
}