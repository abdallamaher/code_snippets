#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n;i++) {
        scanf("%d", &v[i]);
        mp[v[i]]++;
        if (mp[mx] < mp[v[i]])mx = v[i];
    }
    cout << n - mp[mx] << endl;
    int p = find(v.begin(), v.end(), mx) - v.begin();
    for (int i = p; i < n;i++) {
        if (v[i] == mx)continue;
        printf("%d %d %d\n", (v[i] > mx) ? 2 : 1, i + 1, i);
    }
    for (int i = p; i >= 0; i--) {
        if (v[i] == mx)continue;
        printf("%d %d %d\n", (v[i] > mx) ? 2 : 1, i + 1, i + 2);
    }
}