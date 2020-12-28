#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s; cin >> s;
    int n = s.size();
    string s2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')s2.push_back('0');
        if (s[i] == '2')break;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')s2.push_back('1');
    }
    int f2 = s.find('2');
    for (int i = f2; i >= 0 && i < n; i++) {
        if (s[i] != '1')s2.push_back(s[i]);
    }
    cout << s2 << endl;
}