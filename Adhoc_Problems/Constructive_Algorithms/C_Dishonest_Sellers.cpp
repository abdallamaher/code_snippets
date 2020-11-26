#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0;i < n; i++) {
        int x; scanf("%d", &x);
        a[i].first = x;
    }
    for (int i = 0;i < n; i++) {
        int x; scanf("%d", &x);
        a[i].second = x;
    }

    for (int i = 0; i < n; i++) {
        b[i].first = a[i].second - a[i].first;
        b[i].second = i;
    }

    sort(b.begin(), b.end());

    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k || b[i].first > 0) {
            int idx = b[i].second;
            sum += a[idx].first;
            k = max(--k, 0);
        }
        else {
            int idx = b[i].second;
            sum += a[idx].second;
        }
    }
    cout << sum << endl;
}