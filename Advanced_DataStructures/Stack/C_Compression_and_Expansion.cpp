#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) {
            v.push_back(1);
        }
        else {
            while (v.size() && v.back() + 1 != x) {
                v.pop_back();
            }
            assert(v.size());
            v.back()++;
        }
        for (int j = 0; j < v.size(); j++) {
            if (j)printf(".");
            printf("%d", v[j]);
        }
        puts("");
    }
    return;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}