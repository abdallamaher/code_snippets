#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
vector<ll> ans;

void go(ll s = 0) {
    if(s > 1e9)return;
    ans.push_back(s);
    go(s * 10 + 4);
    go(s * 10 + 7);
}

int main() {
    int n; cin >> n;
    // go();
    ans.push_back(0);
    ans.push_back(4);
    ans.push_back(7);
    for(int i=1; ans[i] < 1e9; i++){
        ans.push_back(ans[i] * 10 + 4);
        ans.push_back(ans[i] * 10 + 7);
    }
    sort(ans.begin(), ans.end());
    //for(auto it: ans)cout << it << endl;
    cout << (lower_bound(ans.begin(), ans.end(), n) - ans.begin()) << '\n';
    return 0;
}