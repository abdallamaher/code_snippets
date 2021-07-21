#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
string s;

int main() {
    cin >> n >> k >> s;

    string t = s.substr(0, k);
    for (int i = k; i < n; i++) {
        t += t[i - k];
    }
    if (t >= s) {
        cout << n << endl << t;
        return 0;
    }

    for (int i = k - 1; i >= 0; i--) {
        if (s[i] == '9') s[i] = '0';
        else {
            s[i]++;
            break;
        }
    }
    for (int i = k; i < n; i++) {
        s[i] = s[i - k];
    }
    cout << n << endl << s;
}