
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<string> v(n);
    for (auto& it : v)
        cin >> it;
    int f = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string ss = v[i] + v[j];
            if (ss.find(s) != string::npos)f = 1;
        }
    }
    puts(f ? "YES" : "NO");
    return 0;
}