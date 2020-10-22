#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(2 * n + 5);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.begin() + 2 * n);
    vector<int> sum(v);
    for (int i = 1; i < 2 * n; i++)sum[i] += sum[i - 1];
    if (sum[2 * n - 1] - sum[n - 1] == sum[n - 1])return cout << -1, 0;
    // if(v[0] == v[2 * n - 1])return cout << -1, 0;
    for (int i = 0; i < 2 * n; i++) cout << v[i] << ' ';
    return 0;
}