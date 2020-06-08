#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 5;
int n;
int a[N], b[N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += abs(i - a[i]);
    }
    cout << sum;
    return 0;
}