#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool mark[20];

bool check(int i, int v) {
    if(mark[v] == true) return false;
    return true;
}
void printSolution() {
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
void Try(int i) {
    for(int v = 1; v <= n; v++) {
        if(check(i, v)) {
            a[i] = v;
            mark[v] = true;
            if(i == n) printSolution();
            else Try(i+1);
            mark[v] = false;
        }
    }
}
int main() {
    cin >> n;
    Try(1);
    return 0;
}