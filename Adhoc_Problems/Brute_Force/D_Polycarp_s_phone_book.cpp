#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 9;
string ar[N];
map<string, vector<int>> pos;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ar[i] = s;


        map<string, int> cnt;
        for (int a = 0; a < 9; a++) {
            string tmp = "";
            for (int b = a; b < 9; b++) {
                tmp += s[b];                // each substring
                if (cnt[tmp] == 0) pos[tmp].push_back(i);
                cnt[tmp]++;
            }
        }
    }

    vector<string> ans(n, "12345678910");
    for (auto& it : pos) {
        string s = it.first;
        vector<int>& v = it.second;
        if (v.size() == 1 && s.size() < ans[v[0]].size()) {
            ans[v[0]] = s;
        }
    }

    for (auto& it : ans) {
        cout << it << endl;
    }
    return 0;
}