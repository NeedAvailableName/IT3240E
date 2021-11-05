#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main() {
    stack<char> s1, s2, s3;
    string a, b;
    cin >> a >> b;
    int i = 0;
    while(i < a.length()) {
        s1.push(a[i]);
        i++;
    }
    int j = 0;
    while(j < b.length()) {
        s2.push(b[i]);
        j++;
    }
    int carry = 0;
    while(!s1.empty() && !s2.empty()) {
        int n = s1.pop()-'0' + s2.pop()-'0';
        if(n <= 9) {
            s3.push(n + carry + '0');
            carry = 0;
        }
        else {
            s3.push(n + carry + '0');
            carry = n-10;
        }
    }
    if(s1.empty() && !s2.empty()) {
        s3.push(s2.pop());
    }
    if(!s1.empty() && s2.empty()) {
        s3.push(s1.pop());
    }
    while(!s3.empty()) {
        cout << s3.pop();
    }
    return 0;
}