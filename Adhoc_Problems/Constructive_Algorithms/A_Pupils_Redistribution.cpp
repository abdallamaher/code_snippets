#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    map<int, int> mp, a;
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        a[x]++;
        mp[x]++;
    }
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }

    int ans = 0;
    for (auto it : mp) {
        if (it.second & 1)return cout << -1, 0;
        int x = it.second / 2;
        if (a[it.first] > x)ans += (a[it.first] - x);
    }

    cout << ans << '\n';
    return 0;
}