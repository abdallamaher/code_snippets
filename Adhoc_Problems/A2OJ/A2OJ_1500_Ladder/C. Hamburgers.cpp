#include <bits/stdc++.h>
using namespace std;
#define ll long long
string st;
ll s, b, c, ps, pb, pc, mon, one, has;
map<char, int> mp;

inline bool can(ll x) {
    ll need = 0;
    ll needB = (x * mp['B'] - b) * pb;
    if (needB > 0)need += needB;

    ll needS = (x * mp['S'] - s) * ps;
    if (needS > 0)need += needS;

    ll needC = (x * mp['C'] - c) * pc;
    if (needC > 0)need += needC;

    return has >= need;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> st >> 
        b >> s >> c >>
        pb >> ps >> pc >>
        has;
    for (auto c : st)mp[c]++;
    
    ll st = 0, en = 1e15, mid;
    while (st < en) {
        mid = (st + en + 1) >> 1;
        if (can(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << en << endl;
    return 0;
}

