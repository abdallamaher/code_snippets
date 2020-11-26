#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (auto &it : v) scanf("%d", &it);
    sort(v.rbegin(), v.rend());
    if (k > n)
        cout << -1 << endl;
    else
        cout << 0 << ' ' << v[k - 1] << endl;
    return 0;
}