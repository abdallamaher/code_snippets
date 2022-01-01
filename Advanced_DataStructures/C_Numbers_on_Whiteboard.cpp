#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n; cin >> n;
    puts("2");
    vector<int> v;
    for (int i = 1; i <= n; i++)v.push_back(i);
    while (v.size() > 1) {
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        v.push_back((a + b + 1) / 2);
        printf("%d %d\n", a, b);
    }
}


int main() {
    int t; cin >> t;
    while (t--)solve();
    return 0;
}