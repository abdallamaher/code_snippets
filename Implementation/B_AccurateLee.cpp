#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        string s; cin >> s;
        int f = 0;
        for(int i=1; i<n; i++)f &= bool(s[i] < s[i-1]);
        if(f){
            cout << s << '\n';
            continue;
        }

        string a, b;
        for (int i = n - 1; i >= 0; i--) {
            a = s[i] + a;
            if (s[i] == '0') break;
        }
        for (int i = 0; i < n - a.size(); i++) {
            if (s[i] == '1')break;
            b.push_back(s[i]);
        }
        cout << b + a << '\n';
    }
    return 0;
}