#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            v[i] = abs(v[i]);
        }

        for (int i = 1; i < n - 1; i += 2) {
            if (v[i - 1] < v[i] && v[i] > v[i + 1]) v[i];
            else v[i] *= -1;
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }cout << '\n';

    }

    return 0;
}