#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == v[0] || v[i] == v[n - 1])continue;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}