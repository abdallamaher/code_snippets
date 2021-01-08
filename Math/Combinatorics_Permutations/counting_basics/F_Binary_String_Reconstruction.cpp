#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b, c;cin >> a >> b >> c;
    string s;


    if (c) for (int i = 0; i < c + 1; i++)s.push_back('1');
    if (a) for (int i = 0; i < a + 1; i++)s.push_back('0');



    if (a && c && b)b--;
    if (s.size() == 0)s.push_back('1'); // a+c==0
    for (int i = 0; i < b; i++) {
        s.push_back((char)('1' - s.back() + '0'));
    }
    cout << s << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}