#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
struct Job {
    int deadline;
    int profit;
};
Job s[N];
int n;
bool mark[N];
void input() {
    cin >> n;
    for(int i = 0; i <= n-1; i++) {
        cin >> s[i].deadline >> s[i].profit;
    }
}
bool cmp(Job x, Job y) {
    return x.profit >= y.profit;
}
void greedy() {
    int sum = 0;
    sort(s, s+n, cmp);
    int M = 0;
    for(int i = 0; i < n; i++) {
        M = max(M, s[i].deadline);
    }
    for(int i = 0; i <= M; i++) {
        mark[i] = false;
    }
    for(int i = 0; i < n; i++) {
        int slot = -1;
        for(int j = s[i].deadline-1; j >= 0; j--) {
            if(mark[j] == false) {
                slot = j;
                break;
            }
        }
        if(slot == -1) {

        }
        else {
            mark[slot] = true;
            sum += s[i].profit;
        }
    }
    cout << sum;
}
int main() {
    input();
    greedy();
    return 0;
}