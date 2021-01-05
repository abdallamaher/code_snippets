#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N = 1e5 + 5;
int ar[N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        auto l = lower_bound(ar, ar + n, (ar[i]+1) / 2) - ar;
        if (l < i) {
            ans = max(int(i - l + 1), ans);
        }
        
    }
    cout << n - ans << '\n';
    return 0;
}

