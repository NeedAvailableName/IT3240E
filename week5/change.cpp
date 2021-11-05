#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, i = 0;
    int s[] = {500, 100, 50, 10, 5, 1};
    cin >> N;
    int money = 1000 - N;
    int num_note = 0;
    while(money > 0) {
        num_note += money / s[i];
        money = money % s[i];
        i++;
    }
    cout << num_note;
    return 0;
}