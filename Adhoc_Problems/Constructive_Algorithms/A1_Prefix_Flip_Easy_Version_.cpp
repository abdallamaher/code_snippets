#include <bits/stdc++.h>
using namespace std;
#define ll long long 


inline void solve() {
    int n; string a, b; cin >> n >> a >> b;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans.push_back(i + 1);
            ans.push_back(1);
            ans.push_back(i + 1);
        }
    }
    n = ans.size();
    printf("%d ", n);
    for (int i = 0; i < n; i++)printf("%d ", ans[i]);
    puts("");
}


int main() {
    int t; cin >> t;
    while (t--)solve();
}