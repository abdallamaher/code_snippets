#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &v[i]);
    }
    ll sum = n;
    for (int i = 1, cnt = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            cnt++;
        }
        if (v[i] != v[i - 1] || i == n - 1) {
            sum += (1ll * cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
    }
    cout << sum << endl;
    return 0;
}