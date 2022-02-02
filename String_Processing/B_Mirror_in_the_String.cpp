#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int i = 1;
    while (i < n && (s[i - 1] > s[i] || 
                    (i > 1 && s[i - 1] == s[i])))i++;
    for (int j = 0; j < i; j++)cout << s[j];
    for (int j = i - 1; j >= 0; j--)cout << s[j];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}