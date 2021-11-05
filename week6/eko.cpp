#include<bits/stdc++.h>
using namespace std;
int N, M;
int a[1000000];
int cut(int first, int last, int key) {
    int sum = 0;
    int mid = (first + last) / 2;
    int height = (a[first] + a[last]) / 2;
    for(int i = mid; i <= last; i++) {
        sum += a[i] - height;
    }
    if(sum < M) cut(mid+1, last, key);
    else if(sum > M) cut(first, mid-1, key);
    else return height;
}
int main() {
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    cout << cut(1, N, M);
    return 0;
}