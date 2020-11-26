#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1;i <= n; i++) {
        int x; scanf("%d", &x);
        v[i] = v[i - 1] + x;;

    }
    int q; cin >> q;
    while (q--) {
        int x;scanf("%d", &x);
        printf("%d\n", lower_bound(v.begin(), v.end(), x) - v.begin());
    }
    return 0;
}