#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, q;cin >> n >> q;
    vector<int> v(n), ans(n + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    set<int> s;
    for (int i = n - 1; i >= 0;i--) {
        s.insert(v[i]);
        ans[i] = s.size();
    }
    //cerr << "her";
    while (q--) {
        int x; scanf("%d", &x);
        printf("%d\n", ans[x - 1]);
    }
}