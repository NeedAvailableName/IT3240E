#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int> l;
    for(int i = 1; i <= 10; i++) {
        l.insert(i);
    }
    set<int> :: iterator it;
    for(it = l.begin(); it != l.end(); it++) {
        cout << *it << "\n";
    }
    if(l.find(7) != l.end()) cout << "l contains 7\n";
    else cout << "l don't contain 7\n";
    return 0;
}