#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string ar[110];
map<char, vector<char>> mp;
map<char, bool> vis, track;
vector<char> ans;

void dfs(char c) {
    vis[c] = 1;
    track[c] = 1;
    for (auto it : mp[c]) {
        if (!vis[it])
            dfs(it);
        else if(track[it]){
            cout << "Impossible";
            exit(0);
        }
    }
    track[c] = 0;
    ans.push_back(c);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 1; i < n; i++) {
        int f = 0;
        for (int j = 0; j < ar[i - 1].size() && j < ar[i].size(); j++)
            if (ar[i][j] != ar[i - 1][j]) {
                mp[ar[i][j]].push_back(ar[i-1][j]);
                f = 1;
                break;
            }
        if(!f && ar[i].size() < ar[i-1].size()) {
            cout << "Impossible";
            exit(0);
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (!vis[i])
            dfs(i);
    }
    for (auto& it : ans)cout << it;
    return 0;
}