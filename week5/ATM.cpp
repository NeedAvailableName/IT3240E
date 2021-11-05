#include<bits/stdc++.h>
using namespace std;
int W;
int c;
vector<int> S;
void input() {
    cin >> W >> c;
    for(int i = c; i >= 0; i--) {
        S.push_back(5000 * pow(10, i));
        S.push_back(3000 * pow(10, i));
        S.push_back(2000 * pow(10, i));
        S.push_back(1000 * pow(10, i));
    }
}
int main() {
    int T, i = 0;
    cin >> T;
    while(T > 0) {
        input();
        int num_note = 0;
        while(W > 0) {
            num_note += W / S[i];
            W = W % S[i];
            i++;
        }
        cout << num_note << " 1\n";
        T--;
    }
    return 0;
}