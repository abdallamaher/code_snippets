#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s; cin >> n >> s;
    string st;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')st.push_back('0'), l++;
        else break;
    }
    string st2;
    int r = n - 1;
    for (int i = n - 1; i >= l; i--) {
        if (s[i] == '1')st2.push_back('1'), r--;
        else break;
    }
    if(l < r)st.push_back('0');
    cout << st + st2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}