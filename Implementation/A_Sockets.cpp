#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, d, s; scanf("%d%d%d", &n, &d, &s);
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.rbegin(), v.rend());
    int sum = s;
    if (sum >= d)return cout << 0 << endl, 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] - 1;
        if (sum >= d)return cout << i+1 << endl, 0;
    }
    cout << -1 << endl;
    return 0;
} 