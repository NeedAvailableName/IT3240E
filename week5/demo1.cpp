#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
struct Segment {
    int a, b;
};
vector<Segment> S;
Segment s[N];
int n;
void input() {
    cin >> n;
    for(int i = 0; i <= n-1; i++) {
        cin >> s[i].a >> s[i].b;
    }
}
bool cmp(Segment x, Segment y) {
    return x.b < y.b;
}
bool check(Segment x) {
    for(int i = 0; i < S.size(); i++) {
        if(!S[i].b < x.a || x.b < S[i].a) return true;
    }
    return false;
}
void greedy() {
    sort(s, s+n, cmp);
    int maxRightCoordinate = -1e9;
    for(int i = 0; i <= n-1; i++) {
        if(s[i].a > maxRightCoordinate) {
            S.push_back(s[i]);
            maxRightCoordinate = s[i].b;
        }
    }
    cout << S.size();
}
int main() {
    input();
    greedy();
    return 0;
}