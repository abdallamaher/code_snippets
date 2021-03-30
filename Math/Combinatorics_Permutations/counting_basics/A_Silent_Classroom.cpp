#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int ar[30] = {};
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ar[s[0] - 'a']++;
    }
    ll ans = 0;
    for (int i = 0; i < 27; i++) {
        //cout << ar[i] << endl;
        int a = ar[i] / 2;
        int b = (ar[i] + 1) / 2;
        ans += 1ll * a * (a - 1) / 2 + 1ll * b * (b - 1) / 2;
    }
    cout << ans << endl;
}