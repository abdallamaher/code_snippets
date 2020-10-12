#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        int p = upper_bound(v.begin(), v.end(), x) - v.begin();
        printf("%d\n", p);
    }
    return 0;
}