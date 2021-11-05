#include<bits/stdc++.h>
using namespace std;
int main() {
    map<int,int> l;
    for(int i = 1; i <= 5; i++) {
        l.insert(pair<int,int>(i, 10*i));
    }
    l[6] = 100;
    for(int i = 1; i <= 6; i++) cout << l[i] << "\n";
    map<string, string> l1;
    l1["abc"] = "abcabc";
    l1["xyz"] = "xyzxyz";
    string k = "abc";
    cout << "l1["<< k <<"] = " << l1[k] << "\n";
    return 0;
}