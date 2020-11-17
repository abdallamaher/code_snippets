#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, int> mp;
vector<ll> v, ans1, ans2;


void dfs1(ll x) {
    ans1.push_back(x);
    if (mp[x * 2])dfs1(x * 2);
    else if (x % 3 == 0 && mp[x / 3])dfs1(x / 3);
}

void dfs2(ll x) {
    if (x % 2 == 0 && mp[x / 2])dfs2(x / 2);
    else if (mp[x * 3])dfs2(x * 3);
    ans2.push_back(x);
}

int main() {
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        mp[v[i]]++;
    }
    sort(v.begin(), v.end(), [](ll f, ll s) {
        //cout << f << ' ' << s << endl;
        int threes1 = 0, threes2 = 0;
        while (f % 3==0)f /= 3, threes1++;
        while (s % 3==0)s /= 3, threes2++;
        if (threes1 != threes2) return threes1 > threes2;

        int twos1 = 0, twos2 = 0;
        while (f % 2==0)f /= 2, twos1++;
        while (s % 2==0)s /= 2, twos2++;
        return twos1 < twos2;
        });
    for (auto it : v)printf("%lld ", it);


    return 0;
    dfs1(v[0]);
    dfs2(v[0]);
    for (int i = 0; i < ans2.size(); i++)printf("%lld ", ans2[i]);
    for (int i = 1; i < ans1.size(); i++)printf("%lld ", ans1[i]);

    return 0;
}