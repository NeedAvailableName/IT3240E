#include<bits/stdc++.h>
using namespace std;
int N;
int s[1000001];
vector<int> S;
void input() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
}
bool cmp(int x, int y) {
    return x >= y;
}

int main() {
    input();
    int max = 0;
    sort(s, s+N, cmp);
    for(int i = 0; i < N; i++)  {
        S.push_back(s[i]+i);
    }
    for(int i = 0; i < S.size(); i++) {
        if(max < S[i]) max = S[i];
    }
    cout << max+2;
    return 0;
}