#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<int, int> mp;
int n;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x == 50) {
            if (mp[25])
                mp[25]--;
            else
                return puts("NO"), 0;
        }
        else if (x == 100) {
            if (mp[25] && mp[50])
                mp[25]--, mp[50]--;
            else if (mp[25] > 2)
                mp[25] -= 3;
            else
                return puts("NO"), 0;
        }
        mp[x]++;
    }
    puts("YES");
    return 0;
}