#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while (v[(v.size() + 1) / 2 - 1] != x) {
        v.push_back(x);
        sort(v.begin(), v.end());
        ans++;
    }
    cout << ans << endl;
}