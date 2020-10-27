#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)cin >> v[i];
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            if (i < n / 2) {
                int x = v[i] * v[j];
                if (x < 0)x *= -1;
                cout << x/v[j] << ' ';
            }
            else {
                int x = v[i] * v[j];
                if (x > 0)x *= -1;
                cout << x/v[j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}