#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int f = 0;
    for (int i = 2; i < v.size(); i++) {
        if (v[i] == v[i - 1] + 1 && v[i] == v[i - 2] + 2) f = 1;

    }
    puts(f ? "YES" : "NO");
    return 0;
}