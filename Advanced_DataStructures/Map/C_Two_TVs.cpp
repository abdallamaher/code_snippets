#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n;
map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        mp[a]++;
        mp[b + 1]--;
    }
    int cur = 0, ok = 1;
    for (auto& it : mp) {
        cur += it.second;

        if (cur > 2)ok = 0;
    }

    puts(ok ? "YES" : "NO");

}