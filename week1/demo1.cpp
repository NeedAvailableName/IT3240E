using namespace std;
#include<iostream>
int n, a[100];
bool check(int j, int k) {
    for(int i = 0; i <= k-1; i++) {
        if(j == a[i]) return false;
    }
    return true;
}
void PrintSolution() {
    for(int k = 1; k <= n; k++) {
        cout << a[k] << " ";
    }
    cout << "\n";
}
void Try(int k) {
    for(int i = 1; i <= n; i++) {
        if(check(i, k)) {
            a[k] = i;
            if(k == n) PrintSolution();
            else Try(k+1);
        }
    }
}
int main() {
    cout << "Enter n: ";
    cin >> n;
    Try(1);
    return 0;
}