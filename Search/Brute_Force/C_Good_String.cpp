#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int get(int i, int j) {
    string tmp;
    for (int x = 0, f = 1; x < s.size(); x++) {
        if ((f && s[x] == i) || (!f && s[x] == j))f = 1 - f, tmp += s[x];
    }
    if (i != j && tmp.size() & 1)tmp.pop_back();
    return s.size() - tmp.size();
}

inline void solve() {
    cin >> s;
    for (auto& it : s)it -= '0';
    int mn = 1e9;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mn = min(get(i, j), mn);
        }
    }
    cout << mn << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}