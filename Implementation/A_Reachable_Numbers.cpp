#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, bool> mp;
    int ans = 0;
    while (mp[n] == false) {
        mp[n] = true;
        ++ans;
        ++n;
        while (n % 10 == 0) {
            n /= 10;
        }
    }
    cout << ans << '\n';
    return 0;
}