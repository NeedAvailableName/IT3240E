#include<bits/stdc++.h>
using namespace std;
int n, k, i;
int a[1000001];
int cnt = 0;

bool check(int j, int v) {
    if(j < i) return true;
    else {
        for(int m = j-i+1; m <= j; m++) {
            if(a[m] == 1) return true;
        }
    }
    return false;
}
void printSolution() {
    cnt++;
    if(cnt == k) {
        for(int j = 1; j <= n; j++) {
            cout << a[j] << " ";
        }
        //break;
    }
}
void Try(int j) {
    for(int v = 0; v <= 1; v++) {
        if(check(j, v)) {
            a[j] = v;
            if(j == n) printSolution();
            else Try(j+1);
        }
    }
}
int main() {
    cin >> n >> k >> i;
    Try(1);
    return 0;
}