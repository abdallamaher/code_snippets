#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = ((n % 10) - 1) * (1 + 2 + 3 + 4);
        int j = 1;
        while (n) {
            sum += j;
            j++;
            n /= 10;
        }
        cout << sum << '\n';
    }



    return 0;

    vector<int> v;
    for (int i = 1; i < 10; i++) {
        int t = i;
        while (t < 10000) {
            v.push_back(t);
            t = t * 10 + i;
        }
    }
    while (t--) {
        int n; cin >> n;
        ll ans = 0;
        for (int i = 0; i < v.size(); i++) {
            stringstream s;
            s << v[i];
            ans += int(s.str().size());
            if (v[i] == n) break;

        }
        cout << ans << '\n';

    }
    return 0;
}