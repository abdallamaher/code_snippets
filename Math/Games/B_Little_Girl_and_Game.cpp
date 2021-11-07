#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    vector<int> cnt(27);
    for (auto& c : s)cnt[c - 'a']++;
    int odd = 0;
    for (int i = 0; i < 26; i++)if (cnt[i] & 1) {
        odd++;
    }
    if (!odd || (odd & 1))cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}