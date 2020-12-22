#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    for (int x = n, y = 0; y <= m && x >= 0; x--, y++) {
        v.push_back({ x, y });
    }
    printf("%d\n", v.size());
    for (auto it : v)printf("%d %d\n", it.first, it.second);
}