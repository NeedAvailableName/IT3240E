#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int n, m;
vector<int> A[N];
int d[N]; // = -1 means not visited

void input(){
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i ++){
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }

}

bool BFS(int u){
    d[u] = 0;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i ++){
            int x = A[v][i];
            if(d[x] > -1){
                if((d[x] + d[v]) % 2 == 0){
                    return false;
                }
            }else{
                d[x] = d[v] + 1;
                Q.push(x);
            }
        }
    }
    return true;
}

void BFS(){
    for(int i = 1; i <= n; i ++){
        d[i] = -1;
    }
    int ans = 1;

    for(int v = 1; v <= n; v ++){
        if(d[v] == -1){
            bool check = BFS(v);
            if(!check){
                ans = 0;
                break;
            }
        }
    }
    cout << ans <<endl;

}

int main(){
    input();
    BFS();
}