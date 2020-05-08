#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s, ss;
vector<int> adj[30];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> ss;
    for (int i = 0; i < s.size(); ++i) {
        adj[s[i] - 'a'].push_back(i);
    }
    int ans = 1, p = -1;
    for (auto it : ss) {
        if (adj[it - 'a'].size() == 0) return cout << -1, 0;

        int next = upper_bound(adj[it - 'a'].begin(), adj[it - 'a'].end(), p) - adj[it - 'a'].begin();
        if (next < adj[it - 'a'].size()) {
            p = adj[it-'a'][next];
        }
        else {
            ans++;
            p = adj[it - 'a'][0];
        }
        //printf("%c %d %d\n",it, p, ans);
    }
    cout << ans;
    return 0;
}