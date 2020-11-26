#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 1, rem = n, checked= 0; i <= n; i++, rem--, checked++) {
        sum += 1ll * rem * i - checked;
    }
    cout << sum << '\n';
    return 0;
}