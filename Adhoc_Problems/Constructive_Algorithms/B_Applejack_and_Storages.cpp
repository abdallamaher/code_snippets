#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        mp[x]++;
    }

    int four = 0, two = 0;
    for (auto it : mp) {
        if (it.second >= 4)four += it.second / 4;
        if (it.second >= 2)two += (it.second % 4) / 2;
    }

    int q; cin >> q;
    while (q--) {
        char c; int x;
        scanf(" %c %d", &c, &x);
        if (mp[x] >= 4)four -= mp[x] / 4;
        if (mp[x] >= 2)two -= (mp[x] % 4) / 2;

        if (c == '-')mp[x]--;
        else mp[x]++;

        if (mp[x] >= 4)four += mp[x] / 4;
        if (mp[x] >= 2)two += (mp[x] % 4) / 2;

        if (four > 1 || (four == 1 && two > 1))puts("YES");
        else puts("NO");
    }
}