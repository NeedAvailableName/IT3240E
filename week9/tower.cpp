#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
struct block {
    int w, l, h;
    bool operator < (block& b) {
        return w < b.w && l < b.l;
    }
};
block b[N];
int S[N];

block sort(block a, block b) {
    if((a.w > b.w) || ((a.w == b.w) && (a.l > b.l)) || ((a.w == b.w) && (a.l == b.l) && (a.h > b.h)))
    return a;
    else return b;
}
bool cmp(block& b1, block& b2) {
    if(b1.w != b2.w) return b1.w > b2.w;
    if(b1.l != b2.l) return b1.l;
}
int main() {
    int T = 0;
    int n, m = 0;
    int ans = 0;
    while(1) {
        cin >> n;
        if(n == 0) break;
        T++;
        m--;
        ans = 0;
        for(int i = 0; i < n; i++) {
            int x[3];
            cin >> x[0] >> x[1] >> x[2];
            sort(x, x+3);
            do {
                m += 1;
                b[m].w = x[0];
                b[m].l = x[1];
                b[m].h = x[2];
            } while(next_permutation(x, x+3));
        }
        sort(b, b+m+1, cmp);
        S[0] = b[0].h;
        ans = S[0];
        for(int i = 1; i <= m; i++) {
            S[i] = b[i].h;
            for(int j = 0; j <= i-1; j++) {
                if(b[i] < b[j]) {
                    S[i] = max(S[i], S[j] + b[i].h);
                }
            }
            ans = max(ans, S[i]);
        }
        cout << "Case " << T << " maximum height = " << ans << "\n";
    }
}