#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 7;
string s;
char ans[N];
map<int,vector<int>> prime;
int vis[N];
map<char, int> mp;
void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            int flag = 0;
            for (int j = i; j <= n; j += i) {
                if (vis[j]) {
                    flag = vis[j];
                    break;
                }
                prime[i].push_back(j);
                vis[j] = i;
            }
            if (flag) {
                prime[i].clear();
                for (int j = i; j<=n; j += i) {
                    if (vis[j] == flag)continue;
                    prime[flag].push_back(j);
                    vis[j] = flag;
                }
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    sieve(s.size());
    for (auto c : s)mp[c]++;
    for (auto g : prime) {
        if (!g.second.size())continue;
        int f = 0;
        for (auto &it : mp) {
            if (it.second >= g.second.size()) {
                f = 1;
                for (int i = 0; i < g.second.size(); i++) {
                    ans[g.second[i]] = it.first;
                    it.second--;
                }
                break;
            }
        }
        if(!f)return puts("NO"), 0;
    }
    for (int i = 1; i <= s.size(); i++) {
        if (!isalpha(ans[i])) {
            int f = 0;
            for (auto& it : mp) {
                if (it.second) {
                    ans[i] = it.first;
                    it.second--;
                    f = 1;
                    break;
                }
            }
            if(!f)return puts("NO"), 0;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= s.size(); i++) {
        printf("%c", ans[i]);
    }
    return 0;
}