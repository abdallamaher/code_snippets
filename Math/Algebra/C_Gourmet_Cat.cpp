#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int a, b, c; cin >> a >> b >> c;
    // { b, a, a, b, c, a, c };
    // Mod then number_ok_weaks
    // brute_foce
    int mn = min({ a / 3, b / 2, c / 2 });
    a -= 3 * mn, b -= 2 * mn, c -= 2 * mn;
    vector<int> day = { 1, 0, 0, 1, 2, 0, 2 };
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int j = i;
        int tmp = 0;
        int cur[] = { a, b , c };
        while (j < i + 7) {
            if (day[j] == 2 && cur[2])tmp++, cur[2]--;
            else if (day[j] == 1 && cur[1])tmp++, cur[1]--;
            else if (day[j] == 0 && cur[0])tmp++, cur[0]--;
            else break;
            j = (j + 1) % 7;
        }
        ans = max(ans, tmp);
    }
    cout << ans + mn * 7;
}