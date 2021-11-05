#include<bits/stdc++.h>
using namespace std;
int main() {
    double a[6] = {1, 2, 3, 4, 5, 6};
    sort(a, a+6, greater<double>());
    for(int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    return 0;
}