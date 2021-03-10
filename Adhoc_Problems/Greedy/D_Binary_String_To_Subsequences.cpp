#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

inline void solve() {
    int n; string s; cin >> n >> s;
    vector<int> v[3];
    int ar[N] = {};
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (v[!x].size()) {
            int lst = v[!x].back();
            v[x].push_back(lst);
            ar[i] = lst;
            v[!x].pop_back();
        }
        else {
            v[x].push_back(++cnt);
            ar[i] = cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n;i++)
        cout << ar[i] << ' ';cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}