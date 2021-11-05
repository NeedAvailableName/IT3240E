#include<bits/stdc++.h>
using namespace std;
int n;
int x[10];
bool check(int i, int v) {
    return true;
}
void printSolution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << "\n";
}
void Try(int i) {
    for(int v = 0; v <= 1; v++) {
        if(check(v, i)) x[i] = v;
        if(i == n) printSolution();
        else Try(i+1);
    }
}

int main() {
    cin >> n;
    Try(1);
}