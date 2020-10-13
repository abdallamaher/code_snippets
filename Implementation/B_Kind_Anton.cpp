#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);

        vector<int> a(n);
        for (auto& it : a)scanf("%d", &it);

        int pos = 0, neg = 0, ok = 1;
        for (int i = 0; i < n;i++) {
            int b; scanf("%d", &b);
            if (b > a[i] && !pos)ok = 0;
            else if (b < a[i] && !neg) ok = 0;

            if (a[i] > 0)pos = 1;
            else if (a[i] < 0)neg = 1;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}