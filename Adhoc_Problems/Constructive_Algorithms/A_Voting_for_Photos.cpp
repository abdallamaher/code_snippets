#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    int mx = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
        if (mp[x] > mp[mx]) {
            mx = x;
        }
    }
    cout << mx << endl;
    return 0;
}