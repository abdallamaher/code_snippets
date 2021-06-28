#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll a, b;
const int N = 1e6 + 5;
ll modA, modB[N];

ll power_mod(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % b;
        p /= 2;
        n = (n * n) % b;
    }
    return res;
}


int main() {
    cin >> s >> a >> b;
    for (int i = s.size() - 1, n = 0; i >= 0; i--, n++) {
        modB[i] = (modB[i + 1] + (power_mod(10, n) * (s[i] - '0')) % b) % b;
    }

    for (int i = 0;i < s.size() - 1; i++) {
        modA = (modA * 10 + (s[i] - '0')) % a;
        if (!modA && !modB[i + 1] && s[i + 1] != '0') {
            puts("YES");
            for (int j = 0; j < s.size(); j++) {
                printf("%c", s[j]);
                if (j == i)puts("");
            }
            return 0;
        }
    }


    puts("NO");
}