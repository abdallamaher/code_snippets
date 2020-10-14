#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    map<int, int> mp;
    for (int i = 0; i < 6; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ok = 0;
    for (auto& it : mp)if (it.second > 3) {
        ok++;
        it.second -= 4;
        break;
    }
    if (!ok)return puts("Alien"), 0;
    for (auto& it : mp)if (it.second > 1) {
        return puts("Elephant"), 0;
    }
    puts("Bear");
    return 0;
}