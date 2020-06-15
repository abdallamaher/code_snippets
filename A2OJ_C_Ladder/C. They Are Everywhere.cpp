#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n;
string s;
vector<map<char, int>>v(N);
map<char, int> mp;
bool ok(int x) {
    if (x >= n)return 1;
    for (int i = x; i <= n; i++) {
        int f = 1;
        for (auto it : mp) {
            f&=v[i][it.first]-v[i-x][it.first] > 0 ? 1 : 0;
        }
        if (f)return 1;
    }
    return 0;
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (auto it : v[i - 1]) {
            v[i][it.first] = it.second;
        }
        v[i][s[i-1]]++;
        mp[s[i-1]]++;
    }
    int st = 0, en = N, mid;
    while (st < en) {
        mid = (st + en) >> 1;
        if (ok(mid))
            en = mid;
        else
            st = mid + 1;
    }
    cout << en;
    return 0;
}

