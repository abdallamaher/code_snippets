#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2;i++) {
        if (v[i] && v[i] == v[i + 2])return cout << -1, 0;
    }
    int ans = 0;
    for (int i = 0;i < n - 1;i++) {
        if (v[i] && v[i] == v[i + 1])ans++;
    }
    cout << ans << '\n';


    return 0;

    

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (!x)continue;
        mp[x]++;
        if (mp[x] > 2)return cout << -1, 0;
    }
    int res = 0;
    for (auto it : mp) {
        if (it.second == 2)res++;
    }
    cout << res << "\n";
    return 0;
}