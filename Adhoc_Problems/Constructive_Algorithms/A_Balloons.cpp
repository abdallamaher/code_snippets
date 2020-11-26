#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n + 5);
    for (int i = 0; i < n;i++) {
        scanf("%d", &v[i].first);
        v[i].second = i + 1;
    }
    sort(v.begin(), v.begin() + n);
    if (n < 3 && v[0].first == v[n - 1].first)return cout << -1, 0;
    printf("1\n%d\n", v[0].second);
    return 0;
}