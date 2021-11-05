#include<bits/stdc++.h>
using namespace std;
int main() {
    list<int> l;
    for(int i = 1; i <= 5; i++) {
        l.push_back(i);
    }
    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); it++) {
        int v = *it;
        cout << v << "\n";
    }
    int v = 3;
    it = find(l.begin(), l.end(), v);
    if(it != l.end()) cout << "Found" << v << "\n";
    else cout << "Not found\n";
    l.insert(it, 10);
    for(it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
