#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    vector<int> v;
    vector<string> ans;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '.')v.push_back(i);
    }
    if(!v.size() || v[0] == 0 || v[0] > 8)return puts("NO"), 0;
    v.push_back(s.size());

    int l = 0, r=1;
    for (int i = 1; i < v.size(); i++) {
        int len = v[i] - v[i-1];
        len--;
        if (i == v.size() - 1) {
            if (len > 3 || len < 1)return puts("NO"), 0;
            r = s.size();
        }
        else if (len > 11 || len < 2)return puts("NO"), 0;
        else if (len > 3)
            r = v[i-1] + 3;
        else 
            r = v[i-1] + 1;

        //printf("*** %d %d %d %d %d\n", l, r, len, v[i], v[i-1]);
        string st = s.substr(l, r - l + 1);
        ans.push_back(st);
        l = r + 1;
        //cout << st << endl;
    }
    puts("YES");
    for (auto it : ans)
        printf("%s\n", it.c_str());
    return 0;
}

