#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        string st = s;
        reverse(st.begin(), st.end());
        cout << (s == st ? "-1" : st) << '\n';
    }
    return 0;
}