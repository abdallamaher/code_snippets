#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, x;
ll sum;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int p = 1;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x >= p)sum += (x-p);
        else sum += (n-p + x);
        p = x;
    }
    cout << sum << endl;
    return 0;
}