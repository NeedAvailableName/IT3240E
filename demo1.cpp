#include<bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0; 
    for(int i = 5; i <= 10; i++) {
        int sum = i;
        for(int j = 5; j <= 10; j++) {
            sum += j;
            for(int m = 5; m <= 10; m++) {
                sum += m;
                for(int n = 5; n <= 10; n++) {
                    sum += n;
                    if(sum >= 25) cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}