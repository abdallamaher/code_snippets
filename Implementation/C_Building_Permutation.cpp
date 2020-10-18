#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(i + 1 - v[i]);
    }
    printf("%lld", sum);
    return 0;
}