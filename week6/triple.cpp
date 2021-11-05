#include<bits/stdc++.h>
using namespace std;
int N, K;
int a[5001];
bool cmp(int a, int b) {
    return a <= b;
}
int binsearch(int first, int last, int key) {
    if(first <= last) {
        int mid = (last + first) / 2;
        if(a[mid] == key) return 1+binsearch(first, mid-1, key)+binsearch(mid+1, last, key);
        else {
            if(a[mid] > key) binsearch(first, mid-1, key);
            else binsearch(mid+1, last, key);
        }
    }
    else return 0;
}
int main() {
    cin >> N >> K;
    for(int i = 0; i <= N-1; i++) {
        cin >> a[i];
    }
    sort(a, a+N, cmp);
    int cnt = 0;
    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            cnt += binsearch(j+1, N-1, K-a[i]-a[j]);
        }
    }
    cout << cnt;
}