#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < b.size(); j++) {
            if (a[i + j] == b[j])cnt++;
            else break;
        }
        if (cnt == b.size())return 1;
    }
    return 0;
}

inline void solve() {
    int n; cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), [](string& f, string& s) {
        return (int)f.size() < (int)s.size();
        });
    int ok = 1;
    for (int i = 1; i < n; i++) {
        ok &= check(v[i], v[i - 1]);
    }
    if (ok) {
        cout << "YES" << endl;
        for (auto& it : v)cout << it << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}