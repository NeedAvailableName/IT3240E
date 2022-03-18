#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int a[N];
int n;
struct sum{
    int even;
    int odd;
};
sum F[N];
struct exist{
    bool even;
    bool odd;
};
exist b[N];

int ans = - 1e8;
// int sel_prob;
// int start_index[N];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
}

bool isEven(int i){
    return i % 2 == 0;
}

void solve(){
    int ans = -1e8;
    bool found = false;
    if(isEven(a[1])){
        F[1].even = a[1];
        b[1].even = true;
        b[1].odd = false;
    }else{
        F[1].odd = a[1];
        b[1].odd = true;
        b[1].even = false;
    }

    for(int i = 2; i <= n; i ++){
        if(isEven(a[i])){
            if(b[i - 1].even && F[i - 1].even > 0){
                F[i].even = F[i - 1].even + a[i];
                b[i].even = true;
            }else{
                F[i].even = a[i];
                b[i].even = true;
            }

            if(F[i - 1].odd > 0 && b[i - 1].odd){
                F[i].odd = F[i - 1].odd + a[i];
                b[i].odd = true;
            }else if(!b[i - 1].odd){
                b[i].odd = false;
            }else{
                F[i].odd = F[i - 1].odd + a[i];
                b[i].odd = true;
            }
        }else{
            if(!b[i - 1].odd){
                b[i].even = false;
            }else{
                F[i].even = F[i - 1].odd + a[i];
                b[i].even = true;
            }

            if(b[i - 1].even && F[i - 1].even > 0){
                F[i].odd = F[i - 1].even + a[i];
                b[i].odd = true;
            }else{
                F[i].odd = a[i];
                b[i].odd = true;
            }
        }
        if(b[i].even && ans < F[i].even){
            ans = F[i].even;
            found = true;
        }
    }
    if(found)
        cout << ans <<endl;
    else
        cout << "NOT_FOUND" <<endl;
}
int main() {
    input();
    solve();
}