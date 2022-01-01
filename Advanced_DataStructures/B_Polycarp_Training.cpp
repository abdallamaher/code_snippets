#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > res)res++;
    }
    cout << res;

    return 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }
    int ans = 0;
    for (auto& it : mp) {
        while (ans < it.first && it.second) {
            ans++;
            it.second--;
        }
    }
    cout << ans;
}