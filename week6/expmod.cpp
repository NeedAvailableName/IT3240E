#include<bits/stdc++.h>
#include<math.h>
using namespace std;
unsigned long long a, b;
int c = pow(10,9) + 7;
unsigned long long exp(unsigned long long a, unsigned long long b) {
    a = a % c;
    if(b == 1) return a;
    unsigned long long d = exp(a, b/2);
    d = (d * d) % c;
    if(b % 2 == 1) d = (d * a) % c;
    return d;
}
int main() {
    cin >> a >> b;
    cout << exp(a,b);
    return 0;
}