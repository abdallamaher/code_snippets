#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 0; i < n; i++)scanf("%d", &b[i]), sum += b[i];

    int ok = 1;
    if (sum == n || !sum) {
        for (int i = 1; i < n;i++) {
            if (a[i - 1] > a[i]) {
                ok = 0;
                break;
            }
        }
    }
    puts(ok ? "Yes" : "No");

}


int main() {
    int t; cin >> t;
    while (t--)solve();
}