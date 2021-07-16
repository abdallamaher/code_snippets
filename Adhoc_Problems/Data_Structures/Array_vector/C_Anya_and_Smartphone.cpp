#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;
const int N = 1e5 + 5;
int idx[N], ar[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        idx[x] = i;
        ar[i] = x;
    }

    ll sum = 0;
    while (m--) {
        int x; scanf("%d", &x);
        int p = idx[x];
        sum += (p + k - 1) / k;

        if (p > 1) {
            swap(idx[ar[p]], idx[ar[p - 1]]);
            swap(ar[p], ar[p - 1]);
        }

    }

    cout << sum << endl;
}