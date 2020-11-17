#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n, k, mn;
ll ar[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 2; i <= n; i++) {
        ar[i] += ar[i - 1];
    }
    ll sum = 1e12;
    for (int i = k; i <= n; i++) {
        if (ar[i] - ar[i - k] < sum) {
            mn = i;
            sum = ar[i] - ar[i - k];
        }
    }
    cout << mn - k + 1;
}