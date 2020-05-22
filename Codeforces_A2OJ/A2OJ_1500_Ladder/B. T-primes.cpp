#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 6;
int n;
int p[N];

void sieve() {
    p[0] = 1; p[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        for (int j = i + i; j <= N; j += i)p[j] = 1;
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();
    cin >> n;
    while (n--) {
        ll x; cin >> x;
        if ((double)sqrt(x) == (int)sqrt(x) && !p[(int)sqrt(x)])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
