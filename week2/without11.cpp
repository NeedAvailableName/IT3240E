#include<bits/stdc++.h>
using namespace std;
int n;
int x[16];
bool check(int i, int v) {
    if(x[i-1] + v <= 1) return true;
    else return false;
}
void printSolution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << "\n";
}
void Try(int i) {
    for(int v = 0; v <= 1; v++) {
        if(check(i, v)) x[i] = v;
        if(i == n) printSolution();
        else Try(i+1);
    }
}

int main() {
    cin >> n;
    Try(1);
}