#include<bits/stdc++.h>
using namespace std;
typedef struct info {
    string name;
    int price;
} info;

int main() {
    int N;
    cin >> N;
    info S[N];
    for(int i = 0; i < N; i++) {
        cin >> S[i].name >> S[i].price;
    }
    int max = S[0].price;
    for(int i = 1; i < N; i++) {
        if(S[i].price > max) max = S[i].price;
    }
    for(int i = 0; i < N; i++) {
        if(max == S[i].price) {
            cout << S[i].name;
            break;
        }
    }
    return 0;
}