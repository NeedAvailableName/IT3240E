#include<bits/stdc++.h>
using namespace std;
int match(char a, char b) {
    if(a == '(' && b == ')') return 1;
    else if(a == '[' && b == ']') return 1;
    else if(a == '{' && b == '}') return 1;
    else return 0;
}
int check(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        }
        else {
            if(match(s.top(), str[i]) == 1) s.pop();
        }
    }
    if(!s.empty()) {
        while(!s.empty()) s.pop();
        return 0;
    }
    else return 1;
}
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; T++) {
        string str;
        cin >> str;
        fflush(stdin);
        cout << check(str);
    }
    return 0;
}