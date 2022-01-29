#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    vector<int> v;
    for (int i = 0;i < s.size(); i++) {
        if (s[i] == 'B' && v.size() && (v.back() == 'B' || v.back() == 'A')) {
            v.pop_back();
        }
        else {
            v.push_back(s[i]);
        }
    }
    cout << v.size() << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}