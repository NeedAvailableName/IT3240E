#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int x[N];
int n, C;
void input(){
    scanf("%d%d",&n,&C);
    for(int i = 1; i <= n; i++)
        scanf("%d",&x[i]);
}
bool P(int d){
    // return true if there exists a solution of selecting C staff
    // such that the minimum distance between two staffs is greater or equal to d
    // use greedy algorithm
    int last = 0-1e9;
    int cnt = 0;
    for(int i =1 ; i <= n; i++){
        if(x[i] - last >= d){
            last = x[i]; cnt += 1;
        }
    }
    return cnt >= C;
}
void solve(){
    int ans = 0;
    int L = 0; int R = 1e9;
    sort(x+1,x+n+1);// use indices from 1, 2, ..., n
    while(L < R-1){
        int d = (L+R)/2;
        if(P(d) == true){
                L = d; ans = max(ans,d);
        }else{
            R = d;
        }
    }
    if(P(R) == true) ans  = max(ans,R);
    else ans = max(ans,L);
    printf("%d\n",ans);
}
int main(){

    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        input();
        solve();
    }
    return 0;
}
