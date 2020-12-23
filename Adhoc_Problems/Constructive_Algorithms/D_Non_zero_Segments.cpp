#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<int> arr(n + n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    ll prefix = 0;
    map<ll, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n;i++) {
        prefix += arr[i];
        if (mp[prefix] > 0) {
            ans++;
            mp.clear();
            mp[0]++;
            prefix = arr[i];
        }
        mp[prefix]++;
    }
    printf("%d\n", ans);
}