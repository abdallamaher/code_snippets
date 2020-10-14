#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[n - 1]) {
            ans = max(n - 1 - i, ans);
        }
        if (v[n - 1 - i] != v[0]) {
            ans = max(n - 1 - i, ans);
        }
    }
    cout << ans << '\n';
    return 0;
    int s = 0, en = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[n - 1]) {
            s = i + 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] != v[0]) {
            en = i + 1;
            break;
        }
    }
    // cout << s << ' ' << en << endl;
    cout << max(n - s, en - 1) << '\n';
    return 0;
}